//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cacontext.h
//
// DESCRIPTION:        Declares the CaContext class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//PR# 2732    03-09-04  LU      HTTPS Doesn't Work For HTTPS
//pr# 3214    07/27/04  lisla01 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//PR# 4144    02/24/05  DY      Need get PROCESS ID by process type
//PR# 4145	  02/24/05  DY      Get/Set Viewpath by ID
//PR# 4586	  04/27/05  DY      COM SDK HUP HDLP
//PR# 4778	  06/21/05  DY      Interactive Merge
//PR# 4850    08/15/05  LS      Form changes
//PR# 4664    01-04-07  faudo01 Refactoring Changes
//
// Copyright (c) 2004-2007 Computer Associates inc. All rights reserved. 
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaContext_H)
#define CaContext_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHContextExtd;
class CaHarvest;
class CaVisdiff;
class CPtHView;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaContext
//
//  DESCRIPTION:
//      CaContext is the HSDK class that represents the Harvest Context object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaContext 
{
    private:

        // Member Variables
		CaHarvest*			 m_pCaHarvest;		// HSDK Harvest pointer
		CPtHContextExtd*     m_pHContext;		// Extended Hapi Context Object
        CaPackageChooser*    m_pPackageChooser; // Package Chooser Object
        CaVersionChooser*    m_pVersionChooser; // Version Chooser Object
	    CaPackage* 	         m_pPackage;
        CaCheckout*          m_pCheckout;       // SDK Checkout Object
        CaPromote*           m_pPromote;        // SDK Promote Object
        CaApprove*           m_pApprove;        // SDK Approve Object
        CaDemote*            m_pDemote;         // SDK Demote Object
        CaCheckin*           m_pCheckin;        // SDK Checkin Object
        CaCreatePackage*     m_pCreatePackage;  // SDK CreatePackage Object
        CaDeleteVersion*     m_pDeleteVersion;  // SDK DeleteVersion Object
        CaRemoveItem*        m_pRemoveItem;     // SDK RemoveItem Object
		CaRenameItem*        m_pRenameItem;		// SDK RenameItem Object
        CaConcurrentMerge*   m_pConcurrentMerge; // SDK ConcurrentMerge Object
//PR4778
		CaInteractiveMerge*  m_pInteractiveMerge;

		CaTakeSnapshot*	     m_pTakeSnapshot;	// SDK TakeSnapshot Object
		CaUDP*				 m_pUDP;			// SDK UDP Object
		CaCrossProjectMerge* m_pCrossProjectMerge; // SDK CrossProjectMerge Object
		CaSwitchPackage*	 m_pSwitchPackage;	// SDK SwitchPackage Object
		CaMovePackage*		 m_pMovePackage;	// SDK MovePackage Object
		CaListVersion*		 m_pListVersion;	// SDK ListVersion Object

//PR#4664, b.Refactoring Changes
		CaMoveItem*		     m_pMoveItem;		// SDK MoveItem Object
		CaMovePath*		     m_pMovePath;		// SDK MovePath Object
		CaRenamePath*        m_pRenamePath;		// SDK RenamePath Object
        CaRemovePath*        m_pRemovePath;     // SDK RemovePath Object
		CaDeletePackage*     m_pDeletePackage;  // SDK DeletePackage Object
//PR#4664, e.Refactoring Changes

		CaSQL*				 m_pSQL;			// SDK SQL Object
        CaItemList*          m_pItemList;       // Root View Item List
        CaItem*              m_pViewPathItem;   // Item from View Path
     
		// Private member functions
        void                 Init( void );
        CaContext( CaHarvest& rHarvest );       // Can only be created by CaHarvest
		CPtHView*            GetView(void);	    // Utilitiy to find active view
		void			     ResetProcessSet(void);// Reset all Process
		CaVisdiff*           m_pVisualDiff;
        
    public:
        // Constructors

        // Destructor
        virtual ~CaContext(void);

        // Public Member Functions
		CaHarvest&           GetHarvestSession(void) const;
		LPCTSTR	             GetProjectName(void) const; 
		HAROBJID             GetProjectId(void) const; 
		LPCTSTR	             GetStateName(void) const; 
		HAROBJID             GetStateId(void) const; 
		LPCTSTR	             GetPackageName(void) const; 
		HAROBJID             GetPackageId(void) const; 
		bool                 IsPackageSet(void) const;

		LPCTSTR	             GetViewName(void) const; 
		HAROBJID             GetViewId(void) const; 
		LPCTSTR	             GetUserName(void) const; 
		HAROBJID             GetUserId(void) const;         
		LPCTSTR	             GetSnapshotViewName(void) const;
		HAROBJID             GetSnapshotViewId(void) const;
		LPCTSTR	             GetCheckoutName(void) const; 
		CaCheckout&          GetCheckout(void) const; 
		LPCTSTR	             GetApproveName(void) const; 
		CaApprove&           GetApprove(void) const; 
		LPCTSTR	             GetPromoteName(void) const; 
		CaPromote&           GetPromote(void) const; 
		LPCTSTR	             GetDemoteName(void) const; 
		CaDemote&            GetDemote(void) const; 
		LPCTSTR	             GetCheckinName(void) const; 
		CaCheckin&           GetCheckin(void) const; 
		LPCTSTR	             GetCreatePackageName(void) const; 
		CaCreatePackage&     GetCreatePackage(void) const; 
		LPCTSTR	             GetDeleteVersionName(void) const; 
		CaDeleteVersion&     GetDeleteVersion(void) const; 
		LPCTSTR	             GetRemoveItemName(void) const; 
		CaRemoveItem&        GetRemoveItem(void) const; 
		LPCTSTR	             GetRenameItemName(void) const; 
		CaRenameItem&        GetRenameItem(void) const; 
		LPCTSTR	             GetConcurrentMergeName(void) const; 
		CaConcurrentMerge&   GetConcurrentMerge(void) const; 
//PR4778
		LPCTSTR	             GetInteractiveMergeName(void) const; 
		CaInteractiveMerge&  GetInteractiveMerge(void) const; 

		LPCTSTR	             GetTakeSnapshotName(void) const; 
		CaTakeSnapshot&	     GetTakeSnapshot(void) const; 
		LPCTSTR	             GetUDPName(void) const;
		CaUDP&	             GetUDP(void) const;
		LPCTSTR	             GetCrossProjectMergeName(void) const; 
		CaCrossProjectMerge& GetCrossProjectMerge(void) const; 
		LPCTSTR	             GetSwitchPackageName(void) const; 
		CaSwitchPackage&	 GetSwitchPackage(void) const;
		LPCTSTR              GetMovePackageName(void) const; 
		CaMovePackage&       GetMovePackage(void) const; 
		LPCTSTR              GetListVersionName(void) const; 
		CaListVersion&       GetListVersion(void) const; 
		CaSQL&               GetSQL(void) const;

	    bool                 IsProcessSet(HINT32 iProcType) const;
//PR4144
		HAROBJID			 GetProcessId(HINT32 iProcType) const;
//end of PR4144

	
		LPCTSTR              GetViewPath(void) const;
		LPCTSTR              GetClientPath(void) const;
		CaItem&              GetViewPathItem(void);
//PR4145
		HAROBJID			 GetViewPathId() const;
//end of PR4145
		CaItem*              GetItemById(HAROBJID iItemId);
		CaItem*              GetItemPathInView(LPCTSTR szFullPath);
		CaVersion*           GetVersionById(HAROBJID iVersionId);

//PR4586
		CaPackage&	         GetPackage() const;
        CPtHChangePackage*   GetHPackage() { return &(m_pPackage->GetHPackage());}; // 7725 VCI Johnny -> performance improvement
		CaPackage*           GetPackageByName(LPCTSTR szPackageName);
		CaPackage*           GetPackageById(HAROBJID iPackageId);
		CaItemList&          GetItemList(bool bRefresh=false, HINT32 iItemPathOption=ITEMS_AND_PATHS_IN_VIEW);
		CaVisdiff&           GetVisDiffObj(void);

		CaPackageChooser&    GetPackageChooser(void) const;
		CaVersionChooser&    GetVersionChooser(void) const;
		CaContainer	         GetStateList(void) const;
		CaContainer	         GetViewList(void) const;
		CaContainer	         GetProcessList(void) const;

		bool                 SetProject(LPCTSTR szProjectName);
		bool                 SetProject(HAROBJID iObjId);
		bool                 SetState(LPCTSTR szStateName);
		bool                 SetState(HAROBJID iObjId);
		bool                 SetCheckout(LPCTSTR szCheckoutName);
		bool                 SetCheckout(HAROBJID iObjId);
		bool                 SetApprove(LPCTSTR szApproveName);
		bool                 SetApprove(HAROBJID iObjId);
		bool                 SetPromote(LPCTSTR szPromoteName);
		bool                 SetPromote(HAROBJID iObjId);
		bool                 SetDemote(LPCTSTR szDemoteName);
		bool                 SetDemote(HAROBJID iObjId);
		bool                 SetSnapshotView(LPCTSTR szSnapshotViewName);
		bool                 SetSnapshotView(HAROBJID iObjId);
		bool                 SetPackage(LPCTSTR szPackageName);
		bool                 SetPackage(HAROBJID iObjId);
		bool                 SetCheckin(LPCTSTR szCheckinName);
		bool                 SetCheckin(HAROBJID iObjId);
		bool                 SetCreatePackage(LPCTSTR szCreatePackageName);
		bool                 SetCreatePackage(HAROBJID iObjId);
		bool                 SetDeleteVersion(LPCTSTR szDeleteVersionName);
		bool                 SetDeleteVersion(HAROBJID iObjId);
		bool                 SetRemoveItem(LPCTSTR szRemoveItemName);
		bool                 SetRemoveItem(HAROBJID iObjId);
		bool                 SetRenameItem(LPCTSTR szRenameItemName);
		bool                 SetRenameItem(HAROBJID iObjId);
		bool                 SetConcurrentMerge(LPCTSTR szConcurrentMergeName);
		bool                 SetConcurrentMerge(HAROBJID iObjId);
//PR4778
		bool                 SetInteractiveMerge(LPCTSTR szInteractiveMergeName);
		bool                 SetInteractiveMerge(HAROBJID iObjId);

		bool                 SetTakeSnapshot(LPCTSTR szTakeSnapshotName);
		bool                 SetTakeSnapshot(HAROBJID iObjId);
		bool		         SetUDP(LPCTSTR szUDPName);
		bool	    	     SetUDP(HAROBJID iObjId);
		bool                 SetCrossProjectMerge(LPCTSTR szCrossProjectMergeName);
		bool                 SetCrossProjectMerge(HAROBJID iObjId);
		bool                 SetSwitchPackage(LPCTSTR szSwitchPackageName);
		bool                 SetSwitchPackage(HAROBJID iObjId);
		bool                 SetMovePackage(LPCTSTR szMoveName);
		bool                 SetMovePackage(HAROBJID iObjId);
		bool                 SetListVersion(LPCTSTR szListVersionName);
		bool                 SetListVersion(HAROBJID iObjId);
		void                 SetClientPath(LPCTSTR szClientPath = _T(""));
		void                 SetViewPath(LPCTSTR szViewPath = _T(""));
//PR#4145
		void				 SetViewPathById(HAROBJID iId);
//end of PR#4145

		void		         SetWebserverName(LPCTSTR szWebserverName = _T(""));
		LPCTSTR              GetWebserverName(void) const;
//PR# 2732 
		void		         SetUseHttps(bool bFlag);
		bool			     GetUseHttps(void) const;

//PR#4664, b.Refactoring additions and changes
		LPCTSTR	             GetMoveItemName(void) const; 
		CaMoveItem&          GetMoveItem(void) const; 
		LPCTSTR	             GetMovePathName(void) const; 
		CaMovePath&          GetMovePath(void) const; 
		LPCTSTR	             GetRemovePathName(void) const; 
		CaRemovePath&        GetRemovePath(void) const; 
		LPCTSTR	             GetRenamePathName(void) const; 
		CaRenamePath&        GetRenamePath(void) const; 
		LPCTSTR	             GetDeletePackageName(void) const; 
		CaDeletePackage&     GetDeletePackage(void) const; 

		bool                 SetMoveItem(LPCTSTR szMoveItemName);
		bool                 SetMoveItem(HAROBJID iObjId);
		bool                 SetMovePath(LPCTSTR szMovePathName);
		bool                 SetMovePath(HAROBJID iObjId);
		bool                 SetRemovePath(LPCTSTR szRemovePathName);
		bool                 SetRemovePath(HAROBJID iObjId);
		bool                 SetRenamePath(LPCTSTR szRenamePathName);
		bool                 SetRenamePath(HAROBJID iObjId);
		bool                 SetDeletePackage(LPCTSTR szDeletePackageName);
		bool                 SetDeletePackage(HAROBJID iObjId);
//PR#4664, e.Refactoring additions and changes
		
// Operators
	    operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
		friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaContext &Context );
#else
		friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaContext &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaHarvest;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaCheckout;
		friend class HSDKDLL_CLASS_DECLSPEC CaCheckin;
		friend class HSDKDLL_CLASS_DECLSPEC CaSwitchPackage;
		friend class HSDKDLL_CLASS_DECLSPEC CaListVersion;
		friend class HSDKDLL_CLASS_DECLSPEC CaInteractiveMerge;
		friend class HSDKDLL_CLASS_DECLSPEC CaForm;  // PR4850
//PR#4664, b.Refactoring changes
		friend class HSDKDLL_CLASS_DECLSPEC CaRenameItem;
		friend class HSDKDLL_CLASS_DECLSPEC CaMoveItem;
		friend class HSDKDLL_CLASS_DECLSPEC CaMovePath;
		friend class HSDKDLL_CLASS_DECLSPEC CaRemovePath;
		friend class HSDKDLL_CLASS_DECLSPEC CaRenamePath;
		friend class HSDKDLL_CLASS_DECLSPEC CaDeletePackage;
//PR#4664, e.Refactoring changes
}; // end class CaContext

#endif

