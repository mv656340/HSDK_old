//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cadelver.h
//
// DESCRIPTION:        Declares the CaDeleteVersion class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaDeleteVersion_H)
#define CaDeleteVersion_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHDeleteVersion;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaDeleteVersion
//
//  DESCRIPTION:
//      CaDeleteVersion is the HSDK class that represents the Harvest DeleteVersion object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaDeleteVersion 
{
    private:

        // Member Variables
		CPtHDeleteVersion*	m_pHDeleteVersion;					// Hapi DeleteVersion Object
        CaContext*      m_pContext;                             // CA Context Object
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

     
		// Private member functions
        void            Init( void );
        CaDeleteVersion(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaDeleteVersion(CaContext& rContext);  			    // Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaDeleteVersion(void);

        // Public Member Functions


        HINT32              Execute(void);

        // Public Inline Functions
		
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaDeleteVersion &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaDeleteVersion &Context );
#endif
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaDeleteVersion

#endif

