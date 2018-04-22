// OrderCalculator.cpp : Implementation of COrderCalculator

#include "stdafx.h"
#include "OrderCalculator.h"


// COrderCalculator



STDMETHODIMP COrderCalculator::CalcOrder(SAFEARRAY ** count, SAFEARRAY ** pizzaNo, CY* total)
{
	CComCurrency tempTotal = CComCurrency(0, 0);

	// Get local copy of count.
	CComSafeArray<short> *csaCount = new CComSafeArray<short>(**count);
	// Get local copy of pizzaNo.
	CComSafeArray<short> *csaPizzaNo = new CComSafeArray<short>(**pizzaNo);

	// Be sure we have a 1 dimentional arrays.
	UINT numbOfDims = csaCount->GetDimensions();
	if (numbOfDims != 1)
		return E_INVALIDARG;

	numbOfDims = csaPizzaNo->GetDimensions();
	if (numbOfDims != 1)
		return E_INVALIDARG;

	// Be sure we have shorts in the array.
	VARTYPE vt = csaCount->GetType();
	if (vt != VT_I2)
		return E_INVALIDARG;

	vt = csaPizzaNo->GetType();
	if (vt != VT_I2)
		return E_INVALIDARG;

	// Get count of elements of array's 1st dimension.
	long orderCount = csaCount->GetCount(0);

	if (orderCount != csaPizzaNo->GetCount(0))
		return E_INVALIDARG;

	short tempPizzaNo = 0;
	short tempCount = 0;
	CComCurrency price;
	CComCurrency lineTotal;

	for (int i = 0; i < orderCount; i++)
	{
		// Fetch input data for order item i
		tempCount = (*csaCount)[i];				// 2 different ways to do the same
		tempPizzaNo = csaPizzaNo->GetAt(i);

		// Look up price in internal array
		price = *prices[tempPizzaNo];

		// Calc tempTotal
		lineTotal = price * tempCount;
		tempTotal += lineTotal;
	}

	*total = *tempTotal.GetCurrencyPtr();

	return S_OK;
}
