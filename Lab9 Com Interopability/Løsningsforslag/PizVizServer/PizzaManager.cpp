// PizzaManager.cpp : Implementation of CPizzaManager

#include "stdafx.h"
#include "PizzaManager.h"


// CPizzaManager

STDMETHODIMP CPizzaManager::GetName(SHORT pizzaNo, BSTR* pizzaName)
{
	if ((0 <= pizzaNo) && (pizzaNo < 10))
	{
		*pizzaName = pizzaNames[pizzaNo].Copy();
		return S_OK;
	}
	else
		return E_INVALIDARG;
}
