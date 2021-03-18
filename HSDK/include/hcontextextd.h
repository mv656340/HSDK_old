//------------------------------------------------------+-----------------------------------------------
// FILENAME:           hcontextextd.h
//
// DESCRIPTION:        Declares the CPtHContextExtd class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//  PR# 2732  3-09-04:   LU  HTTPS Doesn't Work For HTTPS
//  Pr# 3291  04/28/05	 Raser01   Provide chsdk access in harvest project
//  PR# 4778  6-21-05	 YD	 Interactive Merge
//  PR# 4664  01-04-07   faudo01   Refactoring changes and additions
//  PR# 8296  01-09-09   chiji01  RTserverless agent
//
// Copyright (c) 2004-2007 Computer Associates inc. All rights reserved. 
//
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CPtHContextExtd_H)
#define CPtHContextExtd_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include <hhapiinc.h>
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CPtHContextExtd
//
//  DESCRIPTION:
//      CPtHContextExtd is the HSDK class that represents the Harvest Context object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class  CPtHContextExtd : public CPtHContext
{
    private:

        // Member Variables
        CPtHApprove*               m_pApprove;
        CPtHPromote*               m_pPromote;
        CPtHDemote*                m_pDemote;
		CPtHCreateChangePackage*   m_pCreateChangePackage;
		CPtHDeleteVersion*         m_pDeleteVersion;
		CPtHRemoveItem*            m_pRemoveItem;
		CPtHRenameItem*            m_pRenameItem;
		CPtHConcurrentMerge*       m_pConcurrentMerge;
		//PR4778
		CPtHInteractiveMerge*	   m_pInteractiveMerge;

		CPtHCreateSnapshot*        m_pCreateSnapshot;
		CPtHUDP*                   m_pHUDP;
		CPtHCrossProjectMerge*     m_pCrossProjectMerge;
		CPtHSwitchPackage*		   m_pSwitchPackage;
		CPtHMovePackage*		   m_pMovePackage;
		CPtHListVersion*		   m_pListVersion;
//PR#4664, b.Refactoring Processes
		CPtHMoveItem*              m_pMoveItem;
		CPtHMovePath*              m_pMovePath;
		CPtHRemovePath*            m_pRemovePath;
		CPtHRenamePath*            m_pRenamePath;
		CPtHDeletePackage*         m_pDeletePackage;
//PR#4664, e.Refactoring Processes


		CPtHAgent			       m_aFileAgent;
		CPtHString				   m_szAgentUser;
        CPtHString                 m_szWebserverName;
//PR# 2732
		bool                       m_bUseHttps;
	    
		// Private member functions
        void            Init(CPtHarvestSession * pParentSession);
        CPtHContextExtd(void);								// Can only be created by CaHarvest

    public:
        // Constructors
        CPtHContextExtd( CPtHarvestSession* pParentSession );
        CPtHContextExtd( CPtHarvestSession* rParentSession, 
                         HAROBJID           iUserObjId,
                         HAROBJID           iEnvironmentObjId, 
                         HAROBJID           iSnapshotViewObjId,
                         HAROBJID           iStateObjId, 
                         HAROBJID           iProcObjId,
                         HAROBJID           iChangePackageObjId,
                         HAROBJID           iCheckinObjId,
                         HAROBJID           iCheckoutObjId,
                         CPtHString         szViewPath,
                         CPtHString         szClientPath
                        );
                    

        CPtHContextExtd( CPtHarvestSession*       pParentSession, 
                         const CPtHUser&          rUser, 
                         const CPtHEnvironment&   rEnvironment, 
                         const CPtHSnapshotView&  rSnapshotView,
                         const CPtHState&         rState, 
                         const CPtHProcess&       rProcess,
                         const CPtHChangePackage& rChangePackage,
                         const CPtHCheckin&       rCheckin,
                         const CPtHCheckout&      rCheckout,
                         CPtHString               szViewPath,
                         CPtHString               szClientPath
                       );

        // Destructor
        virtual ~CPtHContextExtd(void);

        // Public Member Functions
        bool                    SetState( const CPtHState& rState);

        bool                    SetApprove( const CPtHApprove& rApprove);
		bool					SetApproveById( HAROBJID iId);
        CPtHApprove&            GetApprove(void) const {return *m_pApprove;}
        bool                    SetPromote( const CPtHPromote& rPromote);
		bool					SetPromoteById( HAROBJID iId);
        CPtHPromote&            GetPromote(void) const {return *m_pPromote;}
        bool                    SetDemote( const CPtHDemote& rDemote);
		bool					SetDemoteById( HAROBJID iId);
        CPtHDemote&             GetDemote(void) const {return *m_pDemote;}
        bool                    SetCreateChangePackage( const CPtHCreateChangePackage& rCreateChangePackage);
		bool					SetCreateChangePackageById( HAROBJID iId);
        CPtHCreateChangePackage& GetCreateChangePackage(void) const {return *m_pCreateChangePackage;}
        bool                    SetDeleteVersion( const CPtHDeleteVersion& rDeleteVersion);
		bool					SetDeleteVersionById( HAROBJID iId);
        CPtHDeleteVersion&      GetDeleteVersion(void) const {return *m_pDeleteVersion;}
        bool                    SetRemoveItem( const CPtHRemoveItem& rRemoveItem);
		bool					SetRemoveItemById( HAROBJID iId);
        CPtHRemoveItem&         GetRemoveItem(void) const {return *m_pRemoveItem;}
        bool                    SetRenameItem( const CPtHRenameItem& rRenameItem);
		bool					SetRenameItemById( HAROBJID iId);
        CPtHRenameItem&         GetRenameItem(void) const {return *m_pRenameItem;}
        bool                    SetConcurrentMerge( const CPtHConcurrentMerge& rConcurrentMerge);
		bool					SetConcurrentMergeById( HAROBJID iId);
        CPtHConcurrentMerge&    GetConcurrentMerge(void) const {return *m_pConcurrentMerge;}
//PR4778
		bool                    SetInteractiveMerge( const CPtHInteractiveMerge& rInteractiveMerge);
		bool					SetInteractiveMergeById( HAROBJID iId);
		CPtHInteractiveMerge&   GetInteractiveMerge(void) const {return *m_pInteractiveMerge;}

		bool                    SetCreateSnapshot( const CPtHCreateSnapshot& rCreateSnapshot);
		bool					SetCreateSnapshotById( HAROBJID iId);
        CPtHCreateSnapshot&     GetCreateSnapshot(void) const {return *m_pCreateSnapshot;}
		bool                    SetHUDP( const CPtHUDP& rHUDP);
		bool					SetHUDPById( HAROBJID iId);
        CPtHUDP&				GetHUDP(void) const {return *m_pHUDP;}
		bool					SetCrossProjectMerge( const CPtHCrossProjectMerge& rCrossProjectMerge );
		bool					SetCrossProjectMergeById( HAROBJID iId);
		CPtHCrossProjectMerge&	GetCrossProjectMerge(void) const {return *m_pCrossProjectMerge;}
		bool					SetSwitchPackage( const CPtHSwitchPackage& rSwitchPackage );
		bool					SetSwitchPackageById( HAROBJID iId);
		CPtHSwitchPackage&		GetSwitchPackage(void) const {return *m_pSwitchPackage;}
		bool					SetMovePackage( const CPtHMovePackage& rMovePackage );
		bool					SetMovePackageById( HAROBJID iId);
		CPtHMovePackage&		GetMovePackage(void) const {return *m_pMovePackage;}
		bool					SetListVersion( const CPtHListVersion& rListVersion );
		bool					SetListVersionById( HAROBJID iId);
		CPtHListVersion&		GetListVersion(void) const {return *m_pListVersion;}

//PR#4664, b.new Refactoring Processes
		bool					SetMoveItem( const CPtHMoveItem& rMoveItem );
		bool					SetMoveItemById( HAROBJID iId);
		CPtHMoveItem&			GetMoveItem(void) const {return *m_pMoveItem;}
		bool					SetMovePath( const CPtHMovePath& rMovePath );
		bool					SetMovePathById( HAROBJID iId);
		CPtHMovePath&			GetMovePath(void) const {return *m_pMovePath;}
        bool                    SetRemovePath( const CPtHRemovePath& rRemovePath);
		bool					SetRemovePathById( HAROBJID iId);
        CPtHRemovePath&         GetRemovePath(void) const {return *m_pRemovePath;}
        bool                    SetRenamePath( const CPtHRenamePath& rRenamePath);
		bool					SetRenamePathById( HAROBJID iId);
        CPtHRenamePath&         GetRenamePath(void) const {return *m_pRenamePath;}
        bool                    SetDeletePackage( const CPtHDeletePackage& rDeletePackage);
		bool					SetDeletePackageById( HAROBJID iId);
        CPtHDeletePackage&      GetDeletePackage(void) const {return *m_pDeletePackage;}
//PR#4664, e.new Refactoring Processes

		CPtHAgent&				GetFileAgent( LPCTSTR m_szRemoteMachineName = _T(""), LPCTSTR m_szRemoteUserName = _T(""), LPCTSTR m_szRemotePassword = _T(""), LPCTSTR szClientPath = _T(""), LPCTSTR szPortNumber = _T("") ); // PR# 8296 added szPortNumber
		
		LPCTSTR                 GetWebserverName(void) const {return m_szWebserverName;}
        void                    SetWebserverName(LPCTSTR szWebserverName = _T("")) {m_szWebserverName = szWebserverName;}
//PR# 2732
		bool                    GetUseHttps(void) const {return m_bUseHttps;}
        void                    SetUseHttps(bool bFlag) {m_bUseHttps = bFlag;}


        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?
        CPtHContextExtd & operator=(const CPtHContextExtd &CRight);
        bool operator==(const CPtHContextExtd &CRight) const;
        bool operator!=(const CPtHContextExtd &CRight) const;
        friend ostream & operator<<( ostream &o, const CPtHContextExtd &Context );

		// PR3291
		// If the session was passed in from the GUI, we need to restore 
		// the sessions original hapi context object in session when 
		// CPtHContextExtd is destoryed.
		CPtHarvestSession* m_pParentSession;
		CPtHContext* m_pOriginalContext;
		//end of pr# 3291

}; // end class CPtHContextExtd

#endif

