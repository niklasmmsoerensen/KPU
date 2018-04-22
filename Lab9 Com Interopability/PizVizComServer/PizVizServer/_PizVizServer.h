

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Dec 05 14:26:53 2006
 */
/* Compiler settings for _PizVizServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef ___PizVizServer_h__
#define ___PizVizServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOrderCalculator_FWD_DEFINED__
#define __IOrderCalculator_FWD_DEFINED__
typedef interface IOrderCalculator IOrderCalculator;
#endif 	/* __IOrderCalculator_FWD_DEFINED__ */


#ifndef __IPizzaManager_FWD_DEFINED__
#define __IPizzaManager_FWD_DEFINED__
typedef interface IPizzaManager IPizzaManager;
#endif 	/* __IPizzaManager_FWD_DEFINED__ */


#ifndef __COrderCalculator_FWD_DEFINED__
#define __COrderCalculator_FWD_DEFINED__

#ifdef __cplusplus
typedef class COrderCalculator COrderCalculator;
#else
typedef struct COrderCalculator COrderCalculator;
#endif /* __cplusplus */

#endif 	/* __COrderCalculator_FWD_DEFINED__ */


#ifndef __CPizzaManager_FWD_DEFINED__
#define __CPizzaManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class CPizzaManager CPizzaManager;
#else
typedef struct CPizzaManager CPizzaManager;
#endif /* __cplusplus */

#endif 	/* __CPizzaManager_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IOrderCalculator_INTERFACE_DEFINED__
#define __IOrderCalculator_INTERFACE_DEFINED__

/* interface IOrderCalculator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOrderCalculator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C065E87F-AA6D-4674-917D-2C8EA5240977")
    IOrderCalculator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcOrder( 
            /* [in] */ SAFEARRAY * *count,
            /* [in] */ SAFEARRAY * *pizzaNo,
            /* [retval][out] */ CY *total) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOrderCalculatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOrderCalculator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOrderCalculator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOrderCalculator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOrderCalculator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOrderCalculator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOrderCalculator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOrderCalculator * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CalcOrder )( 
            IOrderCalculator * This,
            /* [in] */ SAFEARRAY * *count,
            /* [in] */ SAFEARRAY * *pizzaNo,
            /* [retval][out] */ CY *total);
        
        END_INTERFACE
    } IOrderCalculatorVtbl;

    interface IOrderCalculator
    {
        CONST_VTBL struct IOrderCalculatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOrderCalculator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOrderCalculator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOrderCalculator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOrderCalculator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOrderCalculator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOrderCalculator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOrderCalculator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOrderCalculator_CalcOrder(This,count,pizzaNo,total)	\
    (This)->lpVtbl -> CalcOrder(This,count,pizzaNo,total)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOrderCalculator_CalcOrder_Proxy( 
    IOrderCalculator * This,
    /* [in] */ SAFEARRAY * *count,
    /* [in] */ SAFEARRAY * *pizzaNo,
    /* [retval][out] */ CY *total);


void __RPC_STUB IOrderCalculator_CalcOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOrderCalculator_INTERFACE_DEFINED__ */


#ifndef __IPizzaManager_INTERFACE_DEFINED__
#define __IPizzaManager_INTERFACE_DEFINED__

/* interface IPizzaManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPizzaManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA36D0CF-E5A2-45E9-85B1-A86FD49DAB57")
    IPizzaManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ SHORT pizzaNr,
            /* [retval][out] */ BSTR *pizzaName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPizzaManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPizzaManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPizzaManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPizzaManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPizzaManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPizzaManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPizzaManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPizzaManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IPizzaManager * This,
            /* [in] */ SHORT pizzaNr,
            /* [retval][out] */ BSTR *pizzaName);
        
        END_INTERFACE
    } IPizzaManagerVtbl;

    interface IPizzaManager
    {
        CONST_VTBL struct IPizzaManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPizzaManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPizzaManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPizzaManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPizzaManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPizzaManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPizzaManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPizzaManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPizzaManager_GetName(This,pizzaNr,pizzaName)	\
    (This)->lpVtbl -> GetName(This,pizzaNr,pizzaName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPizzaManager_GetName_Proxy( 
    IPizzaManager * This,
    /* [in] */ SHORT pizzaNr,
    /* [retval][out] */ BSTR *pizzaName);


void __RPC_STUB IPizzaManager_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPizzaManager_INTERFACE_DEFINED__ */



#ifndef __PizVizServer_LIBRARY_DEFINED__
#define __PizVizServer_LIBRARY_DEFINED__

/* library PizVizServer */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_PizVizServer;

EXTERN_C const CLSID CLSID_COrderCalculator;

#ifdef __cplusplus

class DECLSPEC_UUID("92604E05-4667-425D-BE7C-82F6F528B8B9")
COrderCalculator;
#endif

EXTERN_C const CLSID CLSID_CPizzaManager;

#ifdef __cplusplus

class DECLSPEC_UUID("8D4E072C-C732-41A7-AC12-E09C8C2053F4")
CPizzaManager;
#endif
#endif /* __PizVizServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


