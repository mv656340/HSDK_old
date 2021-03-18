//------------------------------------------------------+-----------------------------------------------
// FILENAME:           capackage.h
//
// DESCRIPTION:        Declares the CaPackage class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-19-02        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     Pr#4436  04/01/2005  denyi01 JHSDK has no Delete Package
//     PR#4850  08/15/2005  sevle01 Added CaForm as a friend class for form changes
//     10/19/05        sevle01 PR#5052 - add web service notification
//     12/17/2005      sevle01 PR#4850 - Added GetFormList() returning CaFormList
//     01/27/06        sevle01 PR#5475 - Change server notification names
//     04/09/07        nanra01 PR#6251 - expose update access check function to HSDK/JHSDK
//     07/04/11        khasu03 PR#8724 - SetNote for JCaPackage in JHSDK
//
//
// Copyright (c) 2003 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaPackage_H)
#define CaPackage_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHChangePackage;
class CaPackageList;
class CaFormList;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaPackage
//
//  DESCRIPTION:
//      CaPackage is the HSDK class that encapsulates the Harvest CPtHChangePackage class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaPackage 
{
    private:

        // Member Variables
        CPtHChangePackage* m_pHPackage;	                // HAPI Package Object
        bool            m_bOwnsHData;                   // Can delete HPackage when destroyed
        CaVersionList*  m_pVersionList;                 // List of versions 
        CaFormList*     m_pFormList;  // PR4850         // List of forms
        CaTimeStamp     m_creationTime;                 // Holder for creation time
        CaTimeStamp     m_modifiedTime;                 // Holder for modified time
        CaTimeStamp     m_stateEntryTime;               // Holder for state entry time
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

	    // Private member functions
        CaPackage(CaHarvest &rHarvest);
        CaPackage( const CPtHChangePackage &rSrc, CaHarvest &rHarvest );
        void Init(void);

    public:
        // Constructors
        CaPackage( const CaPackage &src );
		CaPackage(const CaPackage &src, CaHarvest &rHarvest);

        // Destructor
        virtual ~CaPackage(void);

        // Public Member Functions
        bool            SetName(LPCTSTR szNewName);
        bool            SetAssignedUser(LPCTSTR szUserName);
        bool            SetAssignedUser(HINT32 iUserId);
        bool            SetPriority(HINT32 iPriority);
        bool            SetDescription(LPCTSTR szDescription);
        bool            SetNote(LPCTSTR szDescription);
        bool            Update(void);
		//PR4436
		bool			Delete(void);

		bool HasUpdatePackageAccess(void); // PR# 6251

        LPCTSTR         GetName(void) const;
        HAROBJID        GetObjId(void) const;
        LPCTSTR         GetCreatorName(void) const;
        HAROBJID        GetCreatorObjId(void) const;
        CaTimeStamp&    GetCreationTime(void);
        LPCTSTR         GetModifierName(void) const;
        HAROBJID        GetModifierObjId(void) const;
        CaTimeStamp&    GetModifiedTime(void);      
        CaVersionList&  GetVersionList(bool bRefresh = false, HINT32 iVersionFilter=VERSION_FILTER_ALL_IN_VIEW, 
                                      HINT32 iVersionStatusFilter=VERSION_FILTER_ALL_TAG);

        HAROBJID        GetEnvironmentObjId(void) const;
        HAROBJID        GetStateObjId(void) const;

        LPCTSTR	        GetEnvironmentName(void) const;
        LPCTSTR	        GetStateName(void) const;
        HAROBJID        GetViewObjId(void) const;
        LPCTSTR	        GetViewName(void) const;
        HAROBJID        GetAssignedUserObjId(void) const;
        LPCTSTR	        GetAssignedUserName(void) const;
        CaTimeStamp&    GetStateEntryTime(void);

        HINT32	        GetPriority(void) const;
        LPCTSTR	        GetDescription(void) const;
	LPCTSTR			GetNote(void) const;

        HAROBJID        GetBindPackageGroupObjId(void) const;
        CaContainer     GetFormList(void);
        CaContainer     GetHistory(void);
	    CaContainer     GetApprovalReport(void);        

        // b. PR#5052
        bool            SetNotification(bool bFlag);
        bool            GetNotification(void);
        // e. PR#5052

        CaFormList&     GetFormListAsList(bool bRefresh= false);     // PR4850


        CPtHChangePackage&   GetHPackage( ) { return *m_pHPackage;};    // 7725 VCI Johnny -> performance improvement

        // Operators
        CaPackage&    operator=( const CaPackage& src );
        bool          operator==( const CaPackage& src ) const;
        bool          operator!=( const CaPackage& src ) const;
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaPackage& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaPackage& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaPackageList;
	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
	friend class HSDKDLL_CLASS_DECLSPEC CaForm; // PR4850
    friend class HSDKDLL_CLASS_DECLSPEC CaFormList; //PR4850


}; // end class CaPackage

#endif

