//------------------------------------------------------+-----------------------------------------------
// FILENAME:           camvitem.h
//
// DESCRIPTION:        Declares the CaMoveItem class.
//
// AUTHOR:             Donald Faul
//
// REVISION HISTORY:
// PR# 4664   01-03-07 faudo01 File Creation
// PR# 8296   01-10-09 chiji01 RTserverless agent
//
// Copyright (c) 2007 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaMoveItem_H)
#define CaMoveItem_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHMoveItem;
class CaContext;
//PR#4664, b.
class CPtHAgent;
class CaMoveItem;
class CaSignatureRec;
//PR#4664, e.

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//PR#4664, b.Refactoring
// HSDK Callback is responsible for deleting pBag
typedef void  (*PFN_CAMVICB)(int iBaseCBReturn, CaMoveItem  *pMoveItem, void *pUserData, CaContainer *pBag );

typedef void  (*PFN_CAMVISIGCB)(int iBaseCBReturn, CaMoveItem *pMoveItem, void *pUserData, CaSignatureRec *pSigRec, int iMode);

struct CaMVICBData   // Structure to pass callback data to the HAPI Callback function
{
	PFN_CAMVICB pCaMoveItemCB;
	CaMoveItem* pMoveItem;
    void* pUserData;
};

struct CaMVISIGCBData   // Structure to pass callback data to the fileagent Callback function
{
	PFN_CAMVISIGCB pCaSignatureCB;
	CaMoveItem* pMoveItem;
    void* pUserData;
};

//PR#4664, e.Refactoring


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaMoveItem
//
//  DESCRIPTION:
//      CaMoveItem is the HSDK class that represents the Harvest MoveItem object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaMoveItem 
{
    private:

        // Member Variables
		CPtHMoveItem*	m_pHMoveItem;					// Hapi MoveItem Object
        CaContext*      m_pContext;                     // CA Context Object
		HAROBJID        m_iItemObjId;                   // If not NULL_HAROBJID use it
        CaString        m_szItemName;                   // If no Item Id use this
        CaString        m_szItemPath;                   // If by name use this path
		HAROBJID        m_iTargetPathObjId;             // If not NULL_HAROBJID use it
        CaString        m_szTargetPathName;             // Target path for the move.

//PR#4664, b.
        CaString        m_szRemoteMachineName;
        CaString        m_szPortNumber;                 // PR# 8296
        CaString        m_szRemoteUserName;
        CaString        m_szRemotePassword;

		PFN_CAMVICB		m_pCallBack;					// Callback function
		void*			m_pUserData;					// Callback user data
        PFN_CAMVISIGCB	m_pSignatureCallBack;			// Signature Callback function
		void*			m_pSignatureUserData;			// Signature Callback user data
//PR#4664, e.  
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
        CaMoveItem(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaMoveItem(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaMoveItem(void);

        // Public Member Functions
		CaContext&     GetHarvestContext(void);
		void           SetItemObjId(HAROBJID iItemObjId) {m_iItemObjId = iItemObjId;}
        void           SetItemName(LPCTSTR szItemName) {m_szItemName = szItemName;}
        void           SetItemPath(LPCTSTR szItemPath) {m_szItemPath = szItemPath;}
		void           SetTargetItemPathObjId(HAROBJID iTargetPathObjId) {m_iTargetPathObjId = iTargetPathObjId;}
        void           SetTargetItemPath(LPCTSTR szTargetPathName) {m_szTargetPathName = szTargetPathName;}

		void           SetRemoteMachineName(LPCTSTR szRemoteMachineName) {m_szRemoteMachineName = szRemoteMachineName;}
        void           SetAgentPortNumber(LPCTSTR szPortNumber) {m_szPortNumber = szPortNumber;} // PR# 8296
        void           SetRemoteUserName(LPCTSTR szRemoteUserName) {m_szRemoteUserName = szRemoteUserName;}
        void           SetRemotePassword(LPCTSTR szRemotePassword) {m_szRemotePassword = szRemotePassword;}

		void           SetCallBack( PFN_CAMVICB pfCallBack );
		void           SetCBUserData( void* pUserData );
        void           SetSignatureCallBack( PFN_CAMVISIGCB pfSignatureCallBack );
		void           SetSignatureCBUserData( void* pSignatureUserData );

		//  HAPI wrappers
		bool           SetDescription(LPCTSTR szDesc);
		bool           SetClientDir(LPCTSTR szCDir);
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);
		bool           SetRefactorMode(HINT32 nIndex);

        HAROBJID       GetItemObjId(void) const { return m_iItemObjId;}
        LPCTSTR        GetItemName(void) const { return m_szItemName;}
        LPCTSTR        GetItemPath(void) const { return m_szItemPath;}
        HAROBJID       GetTargetItemPathObjId(void) const { return m_iTargetPathObjId;}
        LPCTSTR        GetTargetItemPath(void) const { return m_szTargetPathName;}

		LPCTSTR        GetRemoteMachineName(void) const {return m_szRemoteMachineName;}
        LPCTSTR        GetAgentPortNumber(void) const {return m_szPortNumber;} // PR# 8296
        LPCTSTR        GetRemoteUserName(void) const {return m_szRemoteUserName;}
        LPCTSTR        GetRemotePassword(void) const {return m_szRemotePassword;}

		PFN_CAMVICB    GetCallBack(void);
		void*          GetCBUserData(void);
        PFN_CAMVISIGCB GetSignatureCallBack(void);
		void*          GetSignatureCBUserData(void);

		//  HAPI wrappers
		LPCTSTR        GetDescription(void) const;
		LPCTSTR        GetClientDir(void) const;
		bool           GetCreateOnBranch (void) const;
		bool           GetCreateOnTrunk(void) const;
		bool           GetBranchOut(void) const;
		HINT32         GetRefactorMode(void) const;

        HINT32         Execute(void);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaMoveItem &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaMoveItem &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaMoveItem

#endif

