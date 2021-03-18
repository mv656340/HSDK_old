//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cadelpkg.h
//
// DESCRIPTION:        Declares the CaDeletePackage class.
//
// AUTHOR:             Donald Faul
//
// REVISION HISTORY:
// PR#4664   01/12/07 faud001 Originated
//
// Copyright (c) 2007 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaDeletePackage_H)
#define CaDeletePackage_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHDeletePackage;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaDeletePackage
//
//  DESCRIPTION:
//      CaDeletePackage is the HSDK class that represents the Harvest RenameItem object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaDeletePackage 
{
    private:
        // Member Variables
		CPtHDeletePackage*	m_pHDeletePackage;			// Hapi DeletePackage Object
        CaContext*			m_pContext;                 // CA Context Object
		CaHarvest*			m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
        CaDeletePackage(CaHarvest& rHarvest);							// Can only be created by CaContext
        CaDeletePackage(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaDeletePackage(void);

        // Public Member Functions
	
        HINT32         Execute(void);
		HINT32         Execute(LPTSTR SourcePackage);
		HINT32         Execute(HAROBJID SourcePackage);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaDeletePackage &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaDeletePackage &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaDeletePackage

#endif

