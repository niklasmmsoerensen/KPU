// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LAB1_1_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LAB1_1_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB1_1_EXPORTS
#define LAB1_1_API __declspec(dllexport)
#else
#define LAB1_1_API __declspec(dllimport)
#endif

// An exported function that add two int numbers.
extern "C" LAB1_1_API int myAdd(int number1, int number2);

// An exported function that concatenate two array of chars (the hard way)
extern "C" LAB1_1_API char* myAddStr(char* str1, char* str2);

// An exported function that concatenate two strings 
#pragma warning( disable : 4190 )  // Don't warn me about using the non standard C datatype string
extern "C" LAB1_1_API string myAddString(string str1, string str2);
#pragma warning( default : 4190 )

// An exported function that deletes the menory addressed by the pointer
extern "C" LAB1_1_API bool DeletePtr(char* ptr);