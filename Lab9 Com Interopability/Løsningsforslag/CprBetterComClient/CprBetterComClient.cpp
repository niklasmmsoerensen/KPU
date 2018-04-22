// CprBetterComClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#import "..\CprBetterComServer\bin\Debug\CprBetterComServer.tlb"

using namespace std;
using namespace CprBetterComServer;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);
	CprError err;
	try
	{
		cout << " Wait...Wait...Wait\n";
		// Create the CprdotNetComServer class.
		ICprCtrlPtr spCpr(__uuidof(CprTest));
		//__CprBetterComServer spCpr(__uuidof(CprTest));

		VARIANT_BOOL cprOk = spCpr->CheckCPR("1212121238", &err);

		if (cprOk)

			cout << "The cpr number 1212121238 is OK!\n";
		else
			cout << "The cpr number 1212121238 is BAD!!!\n";

		cprOk = spCpr->CheckCPR("1212121234", &err);

		if (cprOk)

			cout << "The cpr number 1212121234 is OK!\n";
		else
			cout << "The cpr number 1212121234 is BAD!!!\n";

		cout << "---------------------\n";

		cprOk = spCpr->CheckCPR("9999999999", &err);

		if (cprOk)

			cout << "The cpr number 9999999999 is OK!\n";
		else
			cout << "The cpr number 9999999999 is BAD!!!\n";

		cout << "Setting Allow9 to true\n";
		spCpr->PutAllow9(VARIANT_TRUE);
		cprOk = spCpr->CheckCPR("9999999999", &err);

		if (cprOk)

			cout << "The cpr number 9999999999 is OK!\n";
		else
			cout << "The cpr number 9999999999 is BAD!!!\n";

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

