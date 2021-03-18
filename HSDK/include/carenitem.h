//------------------------------------------------------+-----------------------------------------------
// FILENAME:           carenitem.h
//
// DESCRIPTION:        Declares the CaRenameItem class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
// pr# 3214  07/27/04  lisla01 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// PR# 4664  01-05-07  faudo01 Refactoring changes
// PR# 8296  01-10-09  chiji01 RTserverless agent
//
//
// Copyright (c) 2001-2007 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaRenameItem_H)
#define CaRenameItem_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHRenameItem;
class CaContext;

//PR#4664, b.
class CPtHAgent;
class CaRenameItem;
class CaSignatureRec;
//PR#4664, e.


//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//PR#4664, b.Refactoring
// HSDK Callback is responsible for deleting pBag
typedef void  (*PFN_CARNICB)(int iBaseCBReturn, CaRenameItem  *pRenameItem, void *pUserData, CaContainer *pBag );

typedef void  (*PFN_CARNISIGCB)(int iBaseCBReturn, CaRenameItem *pRenameItem, void *pUserData, CaSignatureRec *pSigRec, int iMode);

struct CaRNICBData   // Structure to pass callback data to the HAPI Callback function
{
	PFN_CARNICB pCaRenameItemCB;
	CaRenameItem* pRenameItem;
    void* pUserData;
};

struct CaRNISIGCBData   // Structure to pass callback data to the fileagent Callback function
{
	PFN_CARNISIGCB pCaSignatureCB;
	CaRenameItem* pRenameItem;
    void* pUserData;
};

//PR#4664, e.Refactoring

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaRenameItem
//
//  DESCRIPTION:
//      CaRenameItem is the HSDK class that represents the Harvest RenameItem object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaRenameItem 
{
    private:

        // Member Variables
		CPtHRenameItem*	m_pHRenameItem;					// Hapi RenameItem Object
        CaContext*      m_pContext;                     // CA Context Object
		HAROBJID        m_iItemObjId;                   // If not NULL_HAROBJID use it
        CaString        m_szItemName;                   // If no Item Id use this
        CaString        m_szItemPath;                   // If by name use this path

//PR#4664, b.
        CaString        m_szRemoteMachineName;
        CaString        m_szPortNumber;                 // PR# 8296
        CaString        m_szRemoteUserName;
        CaString        m_szRemotePassword;

		PFN_CARNICB		m_pCallBack;					// Callback function
		void*			m_pUserData;					// Callback user data
        PFN_CARNISIGCB	m_pSignatureCallBack;			// Signature Callback function
		void*			m_pSignatureUserData;			// Signature Callback user data
//PR#4664, e.
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
      
		// Private member functions
        void            Init( void );
        CaRenameItem(CaHarvest &rHarvest);								// Can only be created by CaContext
        CaRenameItem(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaRenameItem(void);

        // Public Member Functions
		CaContext&     GetHarvestContext(void);

		void           SetItemObjId(HAROBJID iItemObjId) {m_iItemObjId = iItemObjId;}
        void           SetItemName(LPCTSTR szItemName) {m_szItemName = szItemName;}
        void           SetItemPath(LPCTSTR szItemPath) {m_szItemPath = szItemPath;}
		//  HAPI wrappers
		bool           SetDescription(LPCTSTR szDesc);
		bool           SetNewItemName(LPCTSTR szNewItemName);
//PR#4664, b.Refactoring changes
        void           SetRemoteMachineName(LPCTSTR szRemoteMachineName) {m_szRemoteMachineName = szRemoteMachineName;}
        void           SetAgentPortNumber(LPCTSTR szPortNumber) {m_szPortNumber = szPortNumber;} // PR# 8296
        void           SetRemoteUserName(LPCTSTR szRemoteUserName) {m_szRemoteUserName = szRemoteUserName;}
        void           SetRemotePassword(LPCTSTR szRemotePassword) {m_szRemotePassword = szRemotePassword;}

		void           SetCallBack( PFN_CARNICB pfCallBack );
		void           SetCBUserData( void* pUserData );
        void           SetSignatureCallBack( PFN_CARNISIGCB pfSignatureCallBack );
		void           SetSignatureCBUserData( void* pSignatureUserData );

		bool           SetClientDir(LPCTSTR szCDir);
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);
		bool           SetRefactorMode(HINT32 nIndex);
//PR#4664, e.Refactoring changes

        HAROBJID       GetItemObjId(void) const { return m_iItemObjId;}
        LPCTSTR        GetItemName(void) const { return m_szItemName;}
        LPCTSTR        GetItemPath(void) const { return m_szItemPath;}
		//  HAPI wrappers
		LPCTSTR        GetDescription(void) const;
		LPCTSTR        GetNewItemName(void) const;
//PR#4664, b.Refactoring changes
        LPCTSTR        GetRemoteMachineName(void) const {return m_szRemoteMachineName;}
        LPCTSTR        GetAgentPortNumber(void) const {return m_szPortNumber;} // PR# 8296
        LPCTSTR        GetRemoteUserName(void) const {return m_szRemoteUserName;}
        LPCTSTR        GetRemotePassword(void) const {return m_szRemotePassword;}

		PFN_CARNICB    GetCallBack(void);
		void*          GetCBUserData(void);
        PFN_CARNISIGCB GetSignatureCallBack(void);
		void*          GetSignatureCBUserData(void);

		LPCTSTR        GetClientDir(void) const;
		bool           GetCreateOnBranch (void) const;
		bool           GetCreateOnTrunk(void) const;
		bool           GetBranchOut(void) const;
		HINT32         GetRefactorMode(void) const;
//PR#4664, e.Refactoring changes

        HINT32         Execute(void);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaRenameItem &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaRenameItem &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaRenameItem

#endif

