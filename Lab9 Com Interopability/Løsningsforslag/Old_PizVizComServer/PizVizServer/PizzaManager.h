// PizzaManager.h : Declaration of the CPizzaManager

#pragma once
#include "resource.h"       // main symbols


// IPizzaManager
[
	object,
	uuid("DA36D0CF-E5A2-45E9-85B1-A86FD49DAB57"),
	dual,	helpstring("IPizzaManager Interface"),
	pointer_default(unique)
]
__interface IPizzaManager : IDispatch
{
	[id(1), helpstring("method GetName")] HRESULT GetName([in] SHORT pizzaNr, [out,retval] BSTR* pizzaName);
};



// CPizzaManager

[
	coclass,
	threading("apartment"),
	vi_progid("PizVizServer.PizzaManager"),
	progid("PizVizServer.PizzaManager.1"),
	version(1.0),
	uuid("8D4E072C-C732-41A7-AC12-E09C8C2053F4"),
	helpstring("PizzaManager Class")
]
class ATL_NO_VTABLE CPizzaManager : 
	public IPizzaManager
{
public:
	CPizzaManager();


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() 
	{
	}

public:

	STDMETHOD(GetName)(SHORT pizzaNr, BSTR* pizzaName);

private:
	CComBSTR  pizzaNames[99];
};

