// OrderCalculator.h : Declaration of the COrderCalculator

#pragma once
#include "resource.h"       // main symbols


// IOrderCalculator
[
	object,
	uuid("C065E87F-AA6D-4674-917D-2C8EA5240977"),
	dual,	helpstring("IOrderCalculator Interface"),
	pointer_default(unique)
]
__interface IOrderCalculator : IDispatch
{
	[id(1), helpstring("method CalcOrder")] HRESULT CalcOrder([in, satype(short)] SAFEARRAY** count, [in, satype(short)] SAFEARRAY** pizzaNo, [out,retval] CY* total);
};



// COrderCalculator

[
	coclass,
	threading("apartment"),
	vi_progid("PizVizServer.OrderCalculator"),
	progid("PizVizServer.OrderCalculator.1"),
	version(1.0),
	uuid("92604E05-4667-425D-BE7C-82F6F528B8B9"),
	helpstring("OrderCalculator Class")
]
class ATL_NO_VTABLE COrderCalculator : 
	public IOrderCalculator
{
public:
	COrderCalculator();


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() 
	{
	}

public:

	STDMETHOD(CalcOrder)(SAFEARRAY** count, SAFEARRAY** pizzaNo, CY* total);

private:
	CComCurrency *prices[99];
};

