// dllmain.h : Declaration of module class.

class CPizVizServerModule : public ATL::CAtlDllModuleT< CPizVizServerModule >
{
public :
	DECLARE_LIBID(LIBID_PizVizServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_PIZVIZSERVER, "{1F7232B2-37E9-4AD9-830C-3A6F7599E882}")
};

extern class CPizVizServerModule _AtlModule;
