//------------------------------------------------------+-----------------------------------------------
// FILENAME:           catakess.h
//
// DESCRIPTION:        Declares the CaTakeSnapshot class.
//
// AUTHOR:             Scott Humphries
//
// REVISION HISTORY:
//     08-24-2001      humda02     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     10/16/2010      kalpr01 PR8591 JHSDK ENHANCE SNAPHOT CREATION WITH PATHID
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaTakeSnapshot_H)
#define CaTakeSnapshot_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHCreateSnapshot;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
const CaTimeStamp NULL_CATIMESTAMP(0,0,0,0,0,0,0);

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaTakeSnapshot
//
//  DESCRIPTION:
//      CaTakeSnapshot is the HSDK class that represents the Harvest CreateSnapshot object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaTakeSnapshot 
{
    private:

        // Member Variables
		CPtHCreateSnapshot*	m_pHCreateSnapshot;			// Hapi CreateSnapshot Object
		bool				m_bCanViewExternally;
		CaContext*			m_pContext;                     // CA Context Object
		CaHarvest*			m_pCaHarvest;				// HSDK Harvest pointer
		//PR8591 JHSDK ENHANCE SNAPHOT CREATION WITH PATHID
		HINT32			m_iParentpathid;
		// Private member functions
        void            Init( void );
        CaTakeSnapshot(CaHarvest& rHarvest);								// Can only be created by CaContext
		CaTakeSnapshot(CaContext& rContext);								// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaTakeSnapshot(void);


        // Public Member Functions
		bool     SetBaselineFlag(bool bFlag);
        bool     SetCanViewExternallyFlag(bool bFlag);
		//PR8591 JHSDK ENHANCE SNAPHOT CREATION WITH PATHID
		bool	 SetParentPathId(HINT32 iParentPathId);
		HINT32	 GetParentPathId();
		//PR8591 - End
        bool     GetCanViewExternallyFlag(void) {return m_bCanViewExternally;}
		

        HINT32   Execute( LPCTSTR szViewName, CaTimeStamp snapshottime = NULL_CATIMESTAMP, LPCTSTR szReferenceSnapshot = NULL);
		HINT32   Execute( bool baseline, LPCTSTR szViewName);
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaTakeSnapshot &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaTakeSnapshot &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaPromote

#endif

