// dllmain.h : Declaration of module class.

class CLab3COMModule : public ATL::CAtlDllModuleT< CLab3COMModule >
{
public :
	DECLARE_LIBID(LIBID_Lab3COMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LAB3COM, "{00935c8a-ac6c-4452-821d-0b8b467912ce}")
};

extern class CLab3COMModule _AtlModule;
