//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cacheckout.h
//
// DESCRIPTION:        Declares the CaCheckout class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//PR# 6143 01-04-07    chiji01 Add an option for updating Signature file
//PR# 7761 04-18-08  chaga04 Add replace writeable file option to checkout in HSDK and JHSDK
//PR# 8296 01-10-09    chiji01 RTserverless agent
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaCheckout_H)
#define CaCheckout_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHCheckout;
class CaContext;
class CaCheckout;
class CaSignatureRec;
//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


// HSDK Callback is responsible for deleting CaContainer pBag
typedef void  (*PFN_CACOCB)(int iBaseCBReturn, CaCheckout *pCheckout, void *pUserData, CaContainer *pBag );

typedef void  (*PFN_CACOSIGCB)(int iBaseCBReturn, CaCheckout *pCheckout, void *pUserData, CaSignatureRec *pSigRec, int iMode);

struct CaCOCBData   // Structure to pass callback data to the HAPI Callback function
{
	PFN_CACOCB pCaCheckoutCB;
	CaCheckout* pCheckout;
    void* pUserData;
};

struct CaCOSIGCBData   // Structure to pass callback data to the fileagent Callback function
{
	PFN_CACOSIGCB pCaSignatureCB;
	CaCheckout* pCheckout;
    void* pUserData;
};

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaCheckout
//
//  DESCRIPTION:
//      CaCheckout is the HSDK class that represents the Harvest Checkout object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaCheckout 
{
    private:

        // Member Variables
		CPtHCheckout*	m_pHCheckout;					// Hapi Checkout Object
        CaContext*      m_pContext;                     // CA Context Object
        CaString        m_szRemoteMachineName;
        CaString        m_szPortNumber;                 // PR# 8296
        CaString        m_szRemoteUserName;
        CaString        m_szRemotePassword;

		PFN_CACOCB		m_pCallBack;					// Callback function
		void*			m_pUserData;					// Callback user data

		PFN_CACOSIGCB	m_pSignatureCallBack;			// Signature Callback function
		void*			m_pSignatureUserData;			// Signature Callback user data
        // PR# 6143
        bool            m_bUpdateSigFile;
        // END PR# 6143
		CaHarvest*		m_pCaHarvest;					// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
        CaCheckout(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaCheckout(CaContext& rContext);  			    // Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaCheckout(void);

        // Public Member Functions
		CaContext&           GetHarvestContext(void);

        // Mode Options
        //  CO_MODE_BROWSE
        //  CO_MODE_UPDATE
        //  CO_MODE_RESERVE_ONLY
        //  CO_MODE_SYNCHRONIZE
        //  CO_MODE_CONCURRENT
        bool                SetCheckoutMode(HINT32 iMode);

        // Path Options
        //  CO_OPTION_PRESERVE
        //  CO_OPTION_PRESERVE_AND_CREATE
        //  CO_OPTION_ALL_ITEM_TO_SAME_DIRECTORY
        bool                SetPathOption(HINT32 iOption);
    
        bool                SetVersionStatusFilter(HINT32 iVStFilter);


        bool                SetClientDir(LPCTSTR szCDir);
        bool                SetViewPath(LPCTSTR szVPath);
        bool                SetAddEmptyDirOption(bool bFlag);

        bool                SetReplaceFile(bool bFlag);
		bool                SetReplaceWriteableFile(bool bFlag); //PR# 7761
        bool                SetShareWorkDir(bool bFlag);
        bool                SetUseCITimeStamp(bool bFlag);
        bool                SetMVSFileTypes(HINT32 iOption);

		void				SetCallBack( PFN_CACOCB pfCallBack );
		void				SetCBUserData( void* pUserData );

        // PR# 6143
		// void				SetSignatureCallBack( PFN_CACOSIGCB pfSignatureCallBack );
		void				SetSignatureCallBack( PFN_CACOSIGCB pfSignatureCallBack, bool bUpdateSigFile = false );
        // END PR# 6143
		void				SetSignatureCBUserData( void* pSignatureUserData );

        // Call this function with an argument of false to 
        // not create a signature file
        void                SetSignatureOption(bool bFlag);

        HINT32              GetCheckoutMode(void) const;
        HINT32              GetPathOption(void) const;
        HINT32              GetVersionStatusFilter(void) const;
        LPCTSTR             GetClientDir(void) const;
        LPCTSTR             GetViewPath(void) const;
        bool                GetAddEmptyDirOption(void) const;

        // The following four functions return true if that 
        // check out mode is supported.
        bool                GetBrowseMode(void) const;
        bool                GetConcUpdateMode(void) const;
        bool                GetSyncMode(void) const;
        bool                GetUpdateMode(void) const;

        bool                GetReplaceFile(void) const;
		bool                GetReplaceWriteableFile(void) const; //PR# 7761
        bool                GetShareWorkDir(void) const;
        bool                GetUseCITimeStamp(void) const;
		
		PFN_CACOCB			GetCallBack(void);
		void*				GetCBUserData(void);

		//AC
		PFN_CACOSIGCB		GetSignatureCallBack(void);
		void*				GetSignatureCBUserData(void);

        // Path Options
        //  HAR_MVS_PDS
        //  HAR_MVS_SEQUENTIAL
        HINT32              GetMVSFileTypes(void) const;



        HINT32              Execute( void );

        // Public Inline Functions
        void                SetRemoteMachineName(LPCTSTR szRemoteMachineName) {m_szRemoteMachineName = szRemoteMachineName;}
        void                SetAgentPortNumber(LPCTSTR szPortNumber) {m_szPortNumber = szPortNumber;} // PR# 8296
        void                SetRemoteUserName(LPCTSTR szRemoteUserName) {m_szRemoteUserName = szRemoteUserName;}
        void                SetRemotePassword(LPCTSTR szRemotePassword) {m_szRemotePassword = szRemotePassword;}

        LPCTSTR             GetRemoteMachineName(void) const {return m_szRemoteMachineName;}
        LPCTSTR             GetAgentPortNumber(void) const {return m_szPortNumber;} // PR# 8296
        LPCTSTR             GetRemoteUserName(void) const {return m_szRemoteUserName;}
        LPCTSTR             GetRemotePassword(void) const {return m_szRemotePassword;}
		
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaCheckout &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaCheckout &Context );
#endif
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
}; // end class CaCheckout

#endif

