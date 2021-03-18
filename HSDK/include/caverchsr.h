//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caverchsr.h
//
// DESCRIPTION:        Declares the CaVersionChooser class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     02-06-04        LU      PR#2663 Synchronization of WSAD slower in SP2
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     05-02-08        chiji01 pr#7840 WILD CARD CHAR PROB IN JHSDK
//
// Copyright (c) 2004 Computer Associates inc. All rights reserved. 
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaVersionChooser_H)
#define CaVersionChooser_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHFilter;
class CPtHView;


//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaVersionChooser
//
//  DESCRIPTION:
//      CaVersionChooser is the HSDK class that searches for Versions.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaVersionChooser 
{
    private:

        // Member Variables
	    CaContext*	    m_pContext;			            // Context Object
        CPtHFilter*     m_pFilter;                      // Filter
        CPtHView*       m_pView;                        // Current View
	    CaString	    m_szVersionNumber;		        // Version Number
        CaVersionList*  m_pVersionList;                 // List of versions
		CaHarvest*		m_pCaHarvest;					// HSDK Harvest pointer
     
		// Private member functions
       CaVersionChooser(void);   		        // Can only be created by CaContext
       CaVersionChooser(CaContext& rContext);           // Can only be created by CaContext
       void             Init( void );
       void             Reset(void);

       CaContainer      m_conViewPathIdCache;   // 7725 VCI Johnny -> performance improvement

       // PR# 7840
       bool             m_bExcludePaths;
       bool             m_bSetPackageId;
       void*            m_pFilterVersionList;
       // END PR# 7840

    public:
        // Constructors

        // Destructor
        virtual ~CaVersionChooser(void);

        // Public Member Functions
        void        Clear(void);                        // Reset all Version chooser filter values

        void        SetParentPath(LPCTSTR szParentPath);
        void        SetParentPathObjId( HINT32 iPathObjId );
        void        SetExcludePaths(bool bFlag);
        void        RemoveVersionFromList(HAROBJID iVersionObjId);
        void        SetItemObjId(HAROBJID iItemObjId, int iIndex = 0);
        void        SetItemName(LPCTSTR szItemName);
        void        SetPackageObjId(HAROBJID iPackageObjId, int iIndex = 0);
	    void        SetItemPackageObjId(HAROBJID iPackageObjId, int iIndex = 0);
        void        SetRecursive(bool bFlag);
	    void	    SetVersionNumber( LPCTSTR szVersion );
        void        SetVersionObjId(HAROBJID iVersionObjId, int iIndex = 0);
//PR# 2663
		void        SetPluginOption(bool bFlag);

        // Branch Filter Options
        //  BRANCH_FILTER_TRUNK_ONLY
        //  BRANCH_FILTER_BRANCH_ONLY
        //  BRANCH_FILTER_UNMERGED_ONLY
        //  BRANCH_FILTER_MERGED_ONLY
        //  BRANCH_FILTER_TRUNK_AND_BRANCH
        void        SetBranchOption(HINT32 iOptions);

        // Version Filter Options
        //  VERSION_FILTER_ALL_IN_VIEW
        //  VERSION_FILTER_LATEST_IN_VIEW
        void        SetVersionOption(HINT32 iOptions);

        // Version Item Options
        //  VERSION_FILTER_ITEM_MODIFIED
        //  VERSION_FILTER_ITEM_BASELINE
        //  VERSION_FILTER_ITEM_BOTH
	    void        SetVersionItemOption(HINT32 iOptions);

        // Version Item Options
        //  VERSION_FILTER_NORMAL_VERSION
        //  VERSION_FILTER_RESERVED_VERSION
        //  VERSION_FILTER_MERGED_VERSION
        //  VERSION_FILTER_DELETED_VERSION
        //  VERSION_FILTER_FROZEN_VERSION
        //  VERSION_FILTER_ALL_TAG
        //  VERSION_FILTER_ANY_TAG
        void        SetVersionStatusOption(HINT32 iOptions);

        // Version Date Options
        //  VERSION_OPTION_DATE_ALL
        //  VERSION_OPTION_DATE_BETWEEN
        // from and to date required if in between
        void        SetVersionDateOption(HINT32 iOptions);
        void        SetFromDate(CaTimeStamp& Time); // creation date
        void        SetToDate(CaTimeStamp& Time);   // creation date

        // Recursive must be set to true to include this option
        void        SetIncludeEmptyPaths(bool bFlag);

        void        Execute(void);
        CaContainer GetVersionList(void);
        CaVersionList& GetVersionListAsList(void);
		
        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaVersionChooser &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaVersionChooser &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
		friend class HSDKDLL_CLASS_DECLSPEC CaCheckout;
		friend class HSDKDLL_CLASS_DECLSPEC CaCheckin;
		friend class HSDKDLL_CLASS_DECLSPEC CaDeleteVersion;
		friend class HSDKDLL_CLASS_DECLSPEC CaRemoveItem;
		friend class HSDKDLL_CLASS_DECLSPEC CaUDP;
		friend class HSDKDLL_CLASS_DECLSPEC CaSwitchPackage;
		friend class HSDKDLL_CLASS_DECLSPEC CaListVersion;

}; // end class CaVersionChooser

#endif

