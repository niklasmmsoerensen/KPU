// Calculator.cpp : Implementation of CCalculator

#include "stdafx.h"
#include "Calculator.h"


// CCalculator



STDMETHODIMP CCalculator::Add(LONG num1, LONG num2, LONG* result)
{
	// TODO: Add your implementation code here
	*result = num1 + num2 + offset;
	return S_OK;
}


STDMETHODIMP CCalculator::get__offset(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = offset;
	return S_OK;
}


STDMETHODIMP CCalculator::put__offset(LONG newVal)
{
	// TODO: Add your implementation code here
	offset = newVal;
	return S_OK;
}
