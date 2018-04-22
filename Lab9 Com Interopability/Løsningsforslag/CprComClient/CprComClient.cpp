// CprComClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#import "C:\Windows\Microsoft.NET\Framework64\v4.0.30319\mscorlib.tlb" \
	rename("ReportEvent", "ReflectionReportEvent")
#import "..\CprSharedDll\bin\Debug\CprSharedDll.tlb"

using namespace std;
using namespace mscorlib;
using namespace CprSharedDll;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);
	CprError err;
	try
	{
		cout << " Wait...Wait...Wait\n";
		// Create the CprdotNetComServer class.
		_CprTestPtr spCpr(__uuidof(CprTest));

		VARIANT_BOOL cprOk = spCpr->CheckCPR("1212121238", &err);  // Ignore intellisense errors - Intellisense is not to be trusted!

		if (cprOk)

			cout << "The cpr number 1212121238 is OK!\n";
		else
			cout << "The cpr number 1212121238 is BAD!!!\n";

		cprOk = spCpr->CheckCPR("1212121234", &err);

		if (cprOk)

			cout << "The cpr number 1212121234 is OK!\n";
		else
			cout << "The cpr number 1212121234 is BAD!!!\n";


		cout << "That's all folks.\nPress enter to terminate...";
		char  dummy[2];
		cin.getline(dummy, 1);
		// COM clean up.
		spCpr = NULL;
		CoUninitialize();
	}
	catch (_com_error &ce)
	{
		cout << ce.ErrorMessage() << endl;
	}

	return 0;
}

