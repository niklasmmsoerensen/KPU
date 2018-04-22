// PizzaManager.h : Declaration of the CPizzaManager

#pragma once
#include "resource.h"       // main symbols



#include "PizVizServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CPizzaManager

class ATL_NO_VTABLE CPizzaManager :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPizzaManager, &CLSID_PizzaManager>,
	public IDispatchImpl<IPizzaManager, &IID_IPizzaManager, &LIBID_PizVizServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPizzaManager()
	{
		pizzaNames[0] = "No Name";
		pizzaNames[1] = "Margarita";
		pizzaNames[2] = "Vesavio";
		pizzaNames[3] = "Banan pizza";
		pizzaNames[4] = "Calzone";
		pizzaNames[5] = "Marinara";
		pizzaNames[6] = "Capriccoisa";
		pizzaNames[7] = "Vegetar";
		pizzaNames[8] = "Pepperoni";
		pizzaNames[9] = "Amore";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PIZZAMANAGER)


BEGIN_COM_MAP(CPizzaManager)
	COM_INTERFACE_ENTRY(IPizzaManager)
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



	STDMETHOD(GetName)(SHORT pizzaNo, BSTR* pizzaName);

private:
	CComBSTR  pizzaNames[99];
};

OBJECT_ENTRY_AUTO(__uuidof(PizzaManager), CPizzaManager)
