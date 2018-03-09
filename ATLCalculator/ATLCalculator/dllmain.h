// dllmain.h : Declaration of module class.

class CATLCalculatorModule : public ATL::CAtlDllModuleT< CATLCalculatorModule >
{
public :
	DECLARE_LIBID(LIBID_ATLCalculatorLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCALCULATOR, "{3852d0d9-2108-46f7-8f23-4b8a7dba93ae}")
};

extern class CATLCalculatorModule _AtlModule;
