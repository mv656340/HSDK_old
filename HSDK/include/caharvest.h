//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caharvest.h
//
// DESCRIPTION:        Declares the CaHarvest class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// pr# 3291  05/02/05  raser01 Provide chsdk access in harvest project
// PR# 3400  08-25-05  sevle01 Add GetAuthenticationSetting/GetCaseSensLogin
// PR# 4850  12/16/05  sevle01 Add GetFormTypeList()
// PR# 5368  01/03/06  sevle01 Add GetProductInfo()
// PR# 5223-2 01/06/06 lawph01 make casql a friend class so that it can use the session object
// PR# 5475  01/27/06  sevle01 add server notifications
// PR# 5801  04/25/07  sevle01 add SetBroker()
// PR# 6382   09/11/07  faudo01 Expose VCIBinding Corrections changes in HAPI
// PR# 6261  03/09/08  shera01 add  NEW API getformList()
// PR# 8216    09/22/08 faudo01 Deactivate -correctvcibindings
//
// Copyright (c) 2005-2007 CA, Inc. All rights reserved. 
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaHarvest_H)
#define CaHarvest_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"


//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHarvest;
class CPtHarvestSession;
class CPtHUser;
class CaFormTypeList;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

// b. PR5475
// user is responsible for deleting bag
typedef void (*PFN_CANOTIFYCB)(CaContainer *bag, void *pData);
struct HapiNotifyCBData   // Structure to pass callback data to the HAPI Callback function
{
	PFN_CANOTIFYCB pCallback;
    void *pData;
};
// e. PR5475

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaHarvest
//
//  DESCRIPTION:
//      CaHarvest is the HSDK class that represents the main Harvest object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaHarvest 
{
    private:

        // Member Variables
        CaContext*      m_pContext;						// Current Context
		CaString		m_szBrokerName;					// Broker attached to
		CaString		m_szDFOFile;					// Broker attached to
		CPtHarvest*		m_pHarvest;						// Hapi Harvest Object
		CPtHarvestSession*	m_pSession;					// Hapi Session Object
		CPtHarvestSession*	m_pExpSession;				// Hapi Session Object
		CaString		m_szUserName;
		CaString		m_szLastMsg;
        CaFormTypeList* m_pFormTypeList;    // PR4850 // List of form types
		CaFormList*     m_pFormList;    // PR 6261 // List of forms in a Broker types

		static ostream* m_pLog;					    // Log Stream
		ostream*		m_pLog2;					        // Instance Log Stream

		// PR3291 If Harvest object is passed in from GUI scripting
		// it must not be destroyed by the CaHarvest destructor.
		bool			m_bExternalHarvestObj;
		//end of pr# 3291

        // b. PR5475
        PFN_CANOTIFYCB  m_pUserCallback;                // save user callback for notifications
        void *          m_pUserData;                    // save user data for notification callbacks
        bool            m_bStartNotification;           // has StartNotification been called yet
        HapiNotifyCBData *m_pHapiNotifyCBData;          // contains user callback & user data
        // e. PR5475


		// Private member functions
        void            Init( void );

    public:
        // Constructors
        CaHarvest(void);  
        CaHarvest( LPCTSTR szBrokerName );

		//pr#3291
		CaHarvest(CPtHarvest* pHarvest);
		//end of pr# 3291

        // Destructor
        virtual ~CaHarvest(void);

        // Public Member Functions
		CaString			GetHSDKRelease(void);
        HINT32              Login(LPCTSTR szBrokerName, LPCTSTR szUserName, LPCTSTR szPassword);
        HINT32              Login(LPCTSTR szUserName, LPCTSTR szPassword);
		HINT32              Login(LPCTSTR szDfoFile);
		void				Logout(void);
		HINT32				ChangePassword(LPCTSTR szPassword);
		LPCTSTR			GetLastMessage(void) {return (LPCTSTR)m_szLastMsg;}
		CaContainer			GetProjectList(void) const;
		CaContainer			GetActiveProjectList(void) const;
		CaContainer			GetInactiveProjectList(void) const;
		CaContainer			GetStateList( HAROBJID iProjectId);
		CaContainer			GetUserList(void) const;
                                // HAPI log is not static, HSDK log is static.
        static void         SetStaticLog(ostream &rLogStream); // Sets static log but not HAPI instance log
        bool                SetLog(ostream &rLogStream); // Sets static log and current HAPI instance
        static ostream&     GetLog(void);
        bool                SetLog2(ostream &rLogStream); // Sets non-static log and current HAPI instance
        ostream&			GetLog2(void);
        ostream&			GetLog2(void) const;
        CaContext&			GetContext(void) const;
		HINT32				SetFileAccess(LPCTSTR szFullPath, LPCTSTR szAccess);

        static bool         GetOSUserName(CaString &szUserName);
        LPCTSTR             GetDefaultBrokerName(void) const;
        bool                UseOSAuthentication(void) const;

        // PR#3400, n. Add access point to retrieve authentication server settings
        bool                GetAuthenticationSetting(enum tAuthenticationServerSettings nSetting);

        // PR# 3400: Add GetCaseSensLogin method
        bool                GetCaseSensLogin(void);

        // PR# 4850
        CaFormTypeList& GetFormTypeList(bool bRefresh);
        CaFormList& GetFormList(bool bRefresh); // PR#6261

        CaContainer         GetProductInfo(void) const; // PR5368

        // b. PR5475
        void            SetNotifyCallBack(PFN_CANOTIFYCB pfCallBack) {m_pUserCallback = pfCallBack;}
        PFN_CANOTIFYCB  GetNotifyCallBack(void) {return m_pUserCallback;}
        void*           GetNotifyCBUserData(void) {return m_pUserData;}
        void            SetNotifyCBUserData(void *pData) {m_pUserData = pData;}
        bool            StartNotification(void);
        // e. PR5475

		// b. PR5801
		HINT32 SetBroker(LPCTSTR szBroker);
		// e. PR5801

        // Public Inline Functions
		LPCTSTR				GetBrokerName(void) const {return m_szBrokerName;}

//PR#8216, n.deactivate
//PR#6382, n.
//        bool            GetCorrectVCIBindings(void);
		
        // Operators
#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( ostream &o, const CaHarvest &Harvest );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaHarvest &Harvest );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaForm;
		friend class HSDKDLL_CLASS_DECLSPEC CaFormType;
		friend class HSDKDLL_CLASS_DECLSPEC CaFormList; // PR# 6261
//pr# 5223-2
        friend class HSDKDLL_CLASS_DECLSPEC CaSQL;
//end of pr# 5223-2

}; // end class CaHarvest

#endif

