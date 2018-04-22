// PizVizCppClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PizVizCppClient.h"

#include "COMerrorUtility.h"

#import "..\PizVizServer\Debug\PizVizServer.tlb" no_namespace named_guids

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	HRESULT hr = S_OK;
	hr = CoInitialize(NULL);
	{
		// Use the SUCCEEDED macro to check for any errors, and if any display them 
		// using ShowErrorMessage
		if (!SUCCEEDED(hr))
		{
			ShowErrorMessage(hr);
			return 1;
		}

		// *** Create a PizViz COM-server and get an smart interface pointer to IPizzaManager
		IPizzaManagerPtr spPizzaMan(__uuidof(PizzaManager));
		if (NULL == spPizzaMan)
		{
			cout << "COM error: Unable to create PizzaManager COM-server!\n";
			return 1;
		}

		// *** Query for pizza names until user enter 0
		short pizzaNo = 1;
		//CComBSTR pizzaName;
		_bstr_t pizzaName;

		while (pizzaNo > 0)
		{
			try
			{
				cout << "Enter pizza no. (or 0 for taking an order): ";
				cin >> pizzaNo;
				if (pizzaNo > 0)
				{
					// Look up pizza name in the PizViz COM-server by use of the IPizzaManager interface
					pizzaName = spPizzaMan->GetName(pizzaNo);
					cout << "  The name is: " << pizzaName << "." << endl;
				}
			}
			catch (_com_error e)
			{
				cout << e.ErrorMessage() << endl;
			}
		}

		// *** Take an order
		cout << "\n\n***** Ready to take an order *********\n";
		short count = 1;
		short tempOrder[100][2];
		short orderLine = 0;

		while (count > 0)
		{
			try
			{
				cout << "Enter no. of pizzas (or 0 for closing the order): ";
				cin >> count;
				if (count > 0)
				{
					cout << "Enter pizza no. (or 0 to abort count): ";
					cin >> pizzaNo;
					if (pizzaNo > 0)
					{

						pizzaName = spPizzaMan->GetName(pizzaNo);
						cout << "  The name is: " << pizzaName << "." << endl;
						tempOrder[orderLine][0] = count;
						tempOrder[orderLine][1] = pizzaNo;
						orderLine++;
					}
				}
			}
			catch (_com_error e)
			{
				cout << e.ErrorMessage() << endl;
			}
			catch (exception e) // catch of IO-errors - cin!
			{
				cout << e.what() << endl;
			}
		}

		// *** Create the safearrays for count and pizzaNo by use of ATLs CComSafeArray wrapper
		// Create 2 new 1-dimensionel safearrays with the same number of elements
		ULONG noOrderLines = orderLine;

		CComSafeArray<short> *pCount = new CComSafeArray<short>(noOrderLines);
		CComSafeArray<short> *pPizzaNo = new CComSafeArray<short>(noOrderLines);

		// Use SetAt to store count and pizzaNo for each order line in the each array
		for (ULONG oLine = 0; oLine < noOrderLines; oLine++)
		{
			ATLASSERT(pCount->SetAt(oLine, tempOrder[oLine][0]) == S_OK);
			ATLASSERT(pPizzaNo->SetAt(oLine, tempOrder[oLine][1]) == S_OK);
		}

		// *** Calculate the order
		// Get an smart interface pointer to ICalcOrder
		IOrderCalculatorPtr spOrderCalc(__uuidof(OrderCalculator));
		if (NULL == spOrderCalc)
		{
			cout << "COM error: Unable to create OrderCalculator COM-server!\n";
			return 1;
		}

		// *** Ask COM-server to calculate the order ********************
		CComCurrency total = spOrderCalc->CalcOrder(pCount->GetSafeArrayPtr(), pPizzaNo->GetSafeArrayPtr());

		// Same using simple Currency type
		// CY total  = spOrderCalc->CalcOrder(pCount->GetSafeArrayPtr(), pPizzaNo->GetSafeArrayPtr());


		// *** Print the total price on the screen ***************************************
		cout << "------------------------------------------------------\n";
		cout << "*** Total: " << total.GetInteger() << "." << total.GetFraction() / 100 << " kr ***\n";
		// Same using simple Currency type
		// cout << "*** Total: " << fixed << setprecision(2) << showpoint << (total.int64 / 10000.0) << " kr ***\n";
		cout << "========================\n";

		cout << "\nProgram entering shut down. Press enter to exit";
		char dummy[3];
		cin.getline(dummy, 1);
		cin.getline(dummy, 1);
		cout << "\nGoodbye\n";

	}	// destroy smartpointers ~ Clean up all COM related stuff

	CoUninitialize();
	return 0;
}
