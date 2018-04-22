// OrderCalculator.h : Declaration of the COrderCalculator

#pragma once
#include "resource.h"       // main symbols



#include "PizVizServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// COrderCalculator

class ATL_NO_VTABLE COrderCalculator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COrderCalculator, &CLSID_OrderCalculator>,
	public IDispatchImpl<IOrderCalculator, &IID_IOrderCalculator, &LIBID_PizVizServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	COrderCalculator()
	{
		prices[0] = new CComCurrency(0, 0);
		prices[1] = new CComCurrency(29, 7500);
		prices[2] = new CComCurrency(35, 0000);
		prices[3] = new CComCurrency(37, 5000);
		prices[4] = new CComCurrency(38, 0000);
		prices[5] = new CComCurrency(39, 7500);
		prices[6] = new CComCurrency(40, 0000);
		prices[7] = new CComCurrency(39, 7500);
		prices[8] = new CComCurrency(41, 7500);
		prices[9] = new CComCurrency(43, 0000);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ORDERCALCULATOR)


BEGIN_COM_MAP(COrderCalculator)
	COM_INTERFACE_ENTRY(IOrderCalculator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:


private:
	CComCurrency *prices[99];
public:
	STDMETHOD(CalcOrder)(SAFEARRAY ** count, SAFEARRAY ** pizzaNo, CY* total);
};

OBJECT_ENTRY_AUTO(__uuidof(OrderCalculator), COrderCalculator)
