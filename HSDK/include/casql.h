//------------------------------------------------------+-----------------------------------------------
// FILENAME:           casql.h
//
// DESCRIPTION:        Declares the CaSQL class.
//
// AUTHOR:             Scott Humphries
//
// REVISION HISTORY:
//     10-09-2001      humda02     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaSQL_H)
#define CaSQL_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHSQL;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaSQL
//
//  DESCRIPTION:
//      CaSQL is the HSDK class that represents the Harvest HSQL object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaSQL
{
    private:

        // Member Variables
		CPtHSQL*			m_pHSQL;			// Hapi CreateSnapshot Object
		CaContext*			m_pContext;                     // CA Context Object
		CaContainer			m_SQLResult;		// HSDK Container for results
		CaHarvest*			m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
        CaSQL(CaHarvest& rHarvest);								// Can only be created by CaContext
		CaSQL(CaContext& rContext);								// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaSQL(void);


        // Public Member Functions
        
		void	SetSQLStatement( LPCTSTR szSQLStr );

		CaContainer	GetSQLResult() { return m_SQLResult; }

	//	HINT32	First(); // HSIK compat
	//	HINT32	Next(); // HSIK compat
	//	HINT32	Close(); // HSIK compat
        
		HINT32	Execute( );
	
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaSQL &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaSQL &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaSql

#endif

