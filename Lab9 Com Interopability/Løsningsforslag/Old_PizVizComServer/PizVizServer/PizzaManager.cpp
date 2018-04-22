// PizzaManager.cpp : Implementation of CPizzaManager

#include "stdafx.h"
#include "PizzaManager.h"
#include ".\pizzamanager.h"


// CPizzaManager

CPizzaManager::CPizzaManager()
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

STDMETHODIMP CPizzaManager::GetName(SHORT pizzaNr, BSTR* pizzaName)
{
	if ((0 <= pizzaNr) && (pizzaNr < 10))
	{
		*pizzaName = pizzaNames[pizzaNr].Copy();
		return S_OK;
	}
	else
		return E_INVALIDARG;
}
