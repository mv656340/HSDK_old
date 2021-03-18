//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cahvisdiff.h
//
// DESCRIPTION:        Declares the hvisdiff class.
//
// AUTHOR:             Rajbhan Bhadoria
//
// REVISION HISTORY:
//     
//
//
// Copyright (c) 2010 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaVisdiff_H)
#define CaVisdiff_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CaContext;
//PR#4664, b.
class CPtHAgent;
class CPtHVisualDifference;
class CPtHString;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaVisdiff
//
//  DESCRIPTION:
//      
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaVisdiff 
{
    private:

        // Member Variables
		CPtHVisualDifference*	m_pHVisualDifference;					// Hapi Visdiff Object
		CaHarvest*		m_pCaHarvest;					// HSDK Harvest pointer
		 LPCTSTR		m_strScriptFile;
     CPtHarvestSession*	m_pSession;	
		// Private member functions
        void            Init( void );
		
        CaVisdiff(CaHarvest& rHarvest);								// Can only be created by CaContext

    public:
        // Constructors
		CaVisdiff(const CPtHVisualDifference &rSrc);
        // Destructor
        virtual ~CaVisdiff(void);

        // Public Member Functions
        HINT32              Execute(HAROBJID iVersion1,HAROBJID iVersion2);
		LPCTSTR             GetScriptFile(void) { return m_strScriptFile; } 
        void                SetScriptFile(LPCTSTR szScriptFile)  ;

        // Public Inline Functions
        
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaApprove &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaVisdiff &Context );
#endif

		
}; // end class CaVisdiff class

#endif

