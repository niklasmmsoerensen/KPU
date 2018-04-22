// PizVizServer.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"

// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{BB80764E-235E-4E1B-BFCD-EFE87D33FFB0}", 
		 name = "PizVizServer", 
		 helpstring = "PizVizServer 1.0 Type Library",
		 resource_name = "IDR_PIZVIZSERVER") ]
class CPizVizServerModule
{
public:
// Override CAtlDllModuleT members
};
		 
