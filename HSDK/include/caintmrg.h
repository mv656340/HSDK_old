//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cainteractivemerge.h
//
// DESCRIPTION:        Declares the CaInteractiveMerge class.
//
// AUTHOR:             Ying Deng
//
// REVISION HISTORY:
//           06-16-05        DY      File Creation
// pr# 5212  01/10/06    lawph01     Invalid CaInteractivermergeapi

//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaInteractiveMerge_H)
#define CaInteractiveMerge_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHInteractiveMerge;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaInteractiveMerge
//
//  DESCRIPTION:
//      CaInteractiveMerge is the HSDK class that represents the Harvest InteractiveMerge Process.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaInteractiveMerge 
{
private:

	 // Member Variables
	CPtHInteractiveMerge*	m_pHInteractiveMerge;
	CaContext*      m_pContext;  
	CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer


		// Private member functions
    void            Init( void );
    CaInteractiveMerge(CaHarvest& rHarvest);								// Can only be created by CaContext
	CaInteractiveMerge(CaContext& rContext);  
public:

	virtual ~CaInteractiveMerge(void);


	LPCTSTR GetCompress(void);
	LPCTSTR GetDescription(void);
	HINT32  GetExecuteFlag(void);
	LPCTSTR GetParentPackageName(void);
	LPCTSTR GetParentStateName(void);        
	LPCTSTR GetParentMappedVer(void); 
	LPCTSTR GetMergedEnvName(void);        
	LPCTSTR GetMergedStateName(void); 
	LPCTSTR GetMergedPackageName(void); 
	LPCTSTR GetMergedMappedVer (void); 
	bool    GetExtMergeToolFlag(void);
	LPCTSTR GetMergedFile(void);
	LPCTSTR GetResolveFlag(void);
	LPCTSTR GetScriptFile(void);

	HINT32 Resolve(HINT32 iVersionObjid);
	HINT32 Execute(HINT32 iVersionObjid);
//pr# 5212
	//void  SetCompress(LPCTSTR szCompress);
//end of pr# 5212

	bool  SetDescription(LPCTSTR szDesc);
	void  SetExecuteFlag(HINT32  iExecuteFlag);
	void  SetExtMergeToolFlag(bool bExtTool);
	void  SetMergedFile(LPCTSTR szMergedFile);
	void  SetResolveFlag(LPCTSTR szResolveFlag);
	void  SetScriptFile(LPCTSTR szScriptFile);


        
    operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

	#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaInteractiveMerge &Context );
	#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaInteractiveMerge &Context );
	#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
};

#endif 
