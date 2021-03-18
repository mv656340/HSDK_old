//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caswpkg.h
//
// DESCRIPTION:        Declares the CaSwitchPackage class.
//
// AUTHOR:             Ali Mobrem
//
// REVISION HISTORY:
//     06-16-2003	AM   File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2003 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaSwitchPackage_H)
#define CaSwitchPackage_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHSwitchPackage;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaSwitchPackage
//
//  DESCRIPTION:
//      CaSwitchPackage is the HSDK class that represents the Harvest RenameItem object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaSwitchPackage 
{
    private:

        // Member Variables
		CPtHSwitchPackage*	m_pHSwitchPackage;			// Hapi SwitchPackage Object
        CaContext*      m_pContext;                     // CA Context Object
		CaHarvest*			m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
        CaSwitchPackage(CaHarvest& rHarvest);			// Can only be created by CaContext
        CaSwitchPackage(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaSwitchPackage(void);

        // Public Member Functions
	
        HINT32         Execute(void);
		HINT32         Execute(LPTSTR SourcePackage, LPTSTR TargetPackage); // PR#1225: change from LPCSTR to LPTSTR for unix
		HINT32         Execute(HAROBJID SourcePackage, HAROBJID TargetPackage);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaSwitchPackage &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaSwitchPackage &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaSwitchPackage

#endif

