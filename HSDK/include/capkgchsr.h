//------------------------------------------------------+-----------------------------------------------
// FILENAME:           capkgchsr.h
//
// DESCRIPTION:        Declares the CaPackageChooser class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-19-02        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2002 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaPackageChooser_H)
#define CaPackageChooser_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHFilter;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaPackageChooser
//
//  DESCRIPTION:
//      CaPackageChooser is the HSDK class that searches for Packages.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaPackageChooser 
{
    private:

        // Member Variables
	CaContext*	m_pContext;			// Context Object
        CPtHFilter*     m_pFilter;                      // Filter
        CaPackageList*  m_pPackageList;                 // List of packages
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

     
		// Private member functions
       CaPackageChooser(CaHarvest& rHarvest);				// Can only be created by CaHarvest
       CaPackageChooser(CaContext& rContext);   	// Can only be created by CaContext
       void            Init( void );

    public:
        // Constructors

        // Destructor
        virtual ~CaPackageChooser(void);

        // Public Member Functions
        void        Clear(void); // Reset all package chooser filter values

        void	    SetPackageName(LPCTSTR szName, int iIndex = 0);
        void        SetPackageObjId(HAROBJID iObjId, int iIndex = 0); 
//        void        SetFormObjId(HAROBJID iObjId, int iIndex = 0); Future release
        void        SetProjectObjId(HAROBJID iObjId); 
        void        SetStateObjId(HAROBJID iObjId); 
        void        SetPkgGroupObjId(HAROBJID iObjId);
        void        SetAssigneeObjId(HAROBJID iObjId);
        void        SetFromDate(CaTimeStamp& Time); // creation date
        void        SetToDate(CaTimeStamp& Time);   // creation date
        void        SetCreatorObjId(HAROBJID iObjId);
        void        SetModifierObjId(HAROBJID iObjId);
        void        SetApproveUserObjId(HAROBJID iObjId);
        void        SetPriority(HINT32 iPriority);
        void        SetSubString(LPCTSTR szString); // substring within Note

        // Valid Package Approval Status Values:
        //      APPROVE_STATUS_APPROVED,
	    //      APPROVE_STATUS_REJECTED
	    //      APPROVE_STATUS_NOT_APPROVED
	    //      APPROVE_STATUS_ALL
        void        SetPkgStatus(HINT32 iPkgStatus); // approval status

        void        SetPkgEntryFromDate(CaTimeStamp& Time); // state entry date
        void        SetPkgEntryToDate(CaTimeStamp& Time);   // state entry date
        void        Execute(bool bUseCurrentContext = true);
        CaContainer GetPackageList(void);
        CaPackageList& GetPackageListAsList(void);
		
        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaPackageChooser &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaPackageChooser &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaPackageChooser

#endif

