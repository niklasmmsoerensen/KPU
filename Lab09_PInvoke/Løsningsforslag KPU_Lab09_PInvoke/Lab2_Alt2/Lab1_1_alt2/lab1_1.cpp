// lab1_1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
using namespace std;
#include "lab1_1.h"

// An exported function that add two int numbers.
extern "C" LAB1_1_API int myAdd(int number1, int number2)
{
	return number1 + number2;
}

// An exported function that concatenate two array of chars (the hard way)
extern "C" LAB1_1_API char* myAddStr(char* str1, char* str2)
{
	size_t len = strlen(str1) + strlen(str2) + 1;
	//char* retVal = new char[len];
	// Allocate memory by use of a Win32 API found in Kernel32.dll
	char* retVal = (char*)LocalAlloc(LMEM_FIXED, len);
	retVal[0] = 0;  // Empty string
	strcat_s(retVal, len, str1);
	strcat_s(retVal, len, str2);
	return retVal;
}

// An exported function that concatenate two strings
#pragma warning( disable : 4190 )  // Don't warn me about using the non standard C datatype string
extern "C" LAB1_1_API string myAddString(string str1, string str2)
{
	return str1 + str2;
}
#pragma warning( default : 4190 )

//extern "C" LAB1_1_API bool DeletePtr(char* ptr)
//{
//	delete[] ptr;
//	return true;
//}
