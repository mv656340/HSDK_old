//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cacheckin.h
//
// DESCRIPTION:        Declares the CaCheckin class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     01-10-01        MAS     Add support for Ci w/o Co
//PR# 1262 03-18-03    LU      Resource out of sync with signature file in WSAD
//PR# 1782 08-06-03    Usha    Checkin fails for file renamed with Case change.  
//PR# 6143 01-04-07    chiji01 Add an option for updating Signature file
//PR# 4664 01-05-07  faudo01   Refactoring changes
//PR# 8296 01-10-09    chiji01 RTserverless agent
//
// Copyright (c) 2003-2007 Computer Associates inc. All rights reserved. 
//
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaCheckin_H)
#define CaCheckin_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHCheckin;
class CPtHAgent;
class CaContext;
class CaCheckin;
class CaSignatureRec;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

// HSDK Callback is responsible for deleting pBag
typedef void  (*PFN_CACICB)(int iBaseCBReturn, CaCheckin  *pCheckin, void *pUserData, CaContainer *pBag );

typedef void  (*PFN_CACISIGCB)(int iBaseCBReturn, CaCheckin *pCheckin, void *pUserData, CaSignatureRec *pSigRec, int iMode);

struct CaCICBData   // Structure to pass callback data to the HAPI Callback function
{
	PFN_CACICB pCaCheckinCB;
	CaCheckin* pCheckin;
    void* pUserData;
};

struct CaCISIGCBData   // Structure to pass callback data to the fileagent Callback function
{
	PFN_CACISIGCB pCaSignatureCB;
	CaCheckin* pCheckin;
    void* pUserData;
};

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaCheckin
//
//  DESCRIPTION:
//      CaCheckin is the HSDK class that represents the Harvest Checkin object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaCheckin 
{
    private:

        // Member Variables
		CaHarvest*		m_pCaHarvest;					// HSDK Harvest pointer
		CPtHCheckin*	m_pHCheckin;					// Hapi Checkin Object
        CaContext*      m_pContext;                     // CA Context Object
        CaString        m_szRemoteMachineName;
        CaString        m_szPortNumber;                 // PR# 8296
        CaString        m_szRemoteUserName;
        CaString        m_szRemotePassword;
		CaString		m_szFilePattern;

        CaStringList    m_FileList;
        CaStringList    m_ParentTrunkMappedVersionList; // Used only for CI w/o CO

		PFN_CACICB		m_pCallBack;					// Callback function
		void*			m_pUserData;					// Callback user data
     
        PFN_CACISIGCB	m_pSignatureCallBack;			// Signature Callback function
		void*			m_pSignatureUserData;			// Signature Callback user data
        // PR# 6143
        bool            m_bUpdateSigFile;
        // END PR# 6143

		// Private member functions
        void            Init( void );
        CaCheckin(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaCheckin(CaContext& rContext);  			    // Can only be created by CaContext
		HINT32 GetFilesByWildcard(LPCTSTR szFileNamePattern, bool bRecursive, CPtHAgent& FileAgent, LPCTSTR pszClientPath,  CaString szDCP, CaStringList& FileNames/*, ostream & LogFile*/);
			
    public:
        // Constructors

        // Destructor
        virtual ~CaCheckin(void);

        // Public Member Functions
		CaContext&           GetHarvestContext(void);

        // Mode Options
        //  HAR_UPDATE_AND_RELEASE
        //  HAR_UPDATE_AND_KEEP
        //  HAR_RELEASE_ONLY
        //  HAR_CHECKIN_WITHOUT_CHECKOUT
        bool                SetCheckinMode(HINT32 iMode);

        // Path Options
        //  CI_OPTION_PRESERVE_DIR
        //  CI_OPTION_PRESERVE_AND_CREATE_PATH
        //  CI_OPTION_ALL_FILE_TO_SAME_PATH
        bool                SetPathOption(HINT32 iOption);

        // Item Options
        //  CI_FILTER_NEW_OR_EXISTING_ITEMS
        //  CI_FILTER_NEW_ITEMS_ONLY
        //  CI_FILTER_EXISTING_ITEMS_ONLY
        bool                SetItemOption(HINT32 iOption);

        bool                SetClientDir(LPCTSTR szCDir);
        bool                SetViewPath(LPCTSTR szVPath);
        bool                SetDeleteAfterCI(bool bFlag);
		bool                SetAtomicCommit(bool bFlag); //PR9116
		bool                GetAtomicCommit(void) const;
        bool                SetDescription(LPCTSTR szDesc);

//PR# 1782
		bool                SetPluginOption(bool bFlag);



		void				SetCallBack( PFN_CACICB pfCallBack );
		void				SetCBUserData( void* pUserData );

        // PR# 6143
        // void				SetSignatureCallBack( PFN_CACISIGCB pfSignatureCallBack );
        void				SetSignatureCallBack( PFN_CACISIGCB pfSignatureCallBack, bool bUpdateSigFile = false );
        // END PR# 6143
		void				SetSignatureCBUserData( void* pSignatureUserData );

        // Call this function with an argument of false to 
        // not create a signature file
        void                SetSignatureOption(bool bFlag);

//PR#4664, b.Refactoring changes
		bool				SetNewItemOnBranch (bool bFlag);
		bool				SetNewItemOnTrunk (bool bFlag);
		bool				SetBranchOut(bool bFlag);
//PR#4664, e.Refactoring changes


        // The following four functions return true if that 
        // check in item option or owner option is supported.
        bool                GetNewOnly(void) const;
        bool                GetNewOrExisting(void) const;
        bool                GetExistingOnly(void) const;
        bool                GetOwnerOnly(void) const;


        HINT32              GetItemOption(void) const;
        LPCTSTR             GetDescription(void) const;
        HINT32              GetCheckinMode(void) const;
        HINT32              GetPathOption(void) const;
        LPCTSTR             GetClientDir(void) const;
        LPCTSTR             GetViewPath(void) const;
        bool                GetDeleteAfterCI(void) const;
        bool                GetForceDescription(void) const;
//PR#4664, b.Refactoring changes
		bool				GetNewItemOnBranch (void) const;
		bool				GetNewItemOnTrunk(void) const;
		bool				GetBranchOut(void) const;
//PR#4664, e.Refactoring changes


		PFN_CACICB			GetCallBack(void);
		void*				GetCBUserData(void);

        PFN_CACISIGCB		GetSignatureCallBack(void);
		void*				GetSignatureCBUserData(void);

        HINT32              CreateItemPath(LPCTSTR szPathName, LPCTSTR szParentPath );

        HINT32              Execute(bool bFileList=true); // if true use File List, if false us Version Chooser

        // Public Inline Functions
        void                SetRemoteMachineName(LPCTSTR szRemoteMachineName) {m_szRemoteMachineName = szRemoteMachineName;}
        void                SetAgentPortNumber(LPCTSTR szPortNumber) {m_szPortNumber = szPortNumber;} // PR# 8296
        void                SetRemoteUserName(LPCTSTR szRemoteUserName) {m_szRemoteUserName = szRemoteUserName;}
        void                SetRemotePassword(LPCTSTR szRemotePassword) {m_szRemotePassword = szRemotePassword;}
        void                SetFileList(CaStringList &FileList) {m_FileList = FileList;}
        void                SetParentTrunkMappedVersionList(CaStringList &List) {m_ParentTrunkMappedVersionList = List;}
		void				SetRecursive(LPCTSTR szFilePattern){m_szFilePattern = szFilePattern;}
        LPCTSTR             GetRemoteMachineName(void) const {return m_szRemoteMachineName;}
        LPCTSTR             GetAgentPortNumber(void) const {return m_szPortNumber;} // PR# 8296
        LPCTSTR             GetRemoteUserName(void) const {return m_szRemoteUserName;}
        LPCTSTR             GetRemotePassword(void) const {return m_szRemotePassword;}
        CaStringList        GetFileList(void) const {return m_FileList;}
        CaStringList        &GetParentTrunkMappedVersionList(void)
            {return m_ParentTrunkMappedVersionList;}
        void                ClearParentTrunkMappedVersionList(void)
            {m_ParentTrunkMappedVersionList.Clean();}
		
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaCheckin &Context );
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
}; // end class CaCheckin

#endif

