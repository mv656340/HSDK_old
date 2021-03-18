//------------------------------------------------------+-----------------------------------------------
// FILENAME:           camvpkg.h
//
// DESCRIPTION:        Declares the CaMovePackage class.
//
// AUTHOR:             Ali Mobrem
//
// REVISION HISTORY:
//     06-19-2003       AM	File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaMovePackage_H)
#define CaMovePackage_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHMovePackage;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaMovePackage
//
//  DESCRIPTION:
//      CaMovePackage is the HSDK class that represents the Harvest ConcurrentMerge object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaMovePackage 
{
    private:

        // Member Variables
        CaContext*      m_pContext;                     // CA Context Object
		CPtHMovePackage*	m_pHMovePackage;			// Hapi MovePackage Object
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaMovePackage(CaHarvest &rHarvest);						// Can only be created by CaContext
        CaMovePackage(CaContext& rContext);  	    // Can only be created by CaContext
		
    public:
        // Constructors

        // Destructor
        virtual ~CaMovePackage(void);

        // Public Member Functions

		// Source Location, must specify either 
		//  Project name and State Name 
		//	 	OR
		//  Project ID and State ID
		void		SetToState( LPCTSTR szProjectName, LPCTSTR szStateName );	//\ REQUIRED
		void		SetToState( HAROBJID szProjectId, HAROBJID szStateId );	///
		
        
		bool		SetIncludePkgHistory( bool bFlag );						// REQUIRED
		
		HAROBJID	GetToProjectId( void ) const;								// OPTIONAL
		LPCTSTR		GetToProjectName( void ) const;							// OPTIONAL
		HAROBJID	GetToStateId( void ) const;								// OPTIONAL
		LPCTSTR		GetToStateName( void ) const;								// OPTIONAL

	    bool		GetIncludePkgHistory( void ) const;									// OPTIONAL
	

		// Set current context to select destination project/state/package
		// Specify source Project & State before selecting packages with Package Chooser
		// CaPackageChooser::SetProjectObjId( iProject);
		// CaPackageChooser::SetStateObjId( iState );	
		// Use CaPackageChooser.Execute(false) to allow selecting packages from any States & Projects
        HINT32    Execute(void);

        // Public Inline Functions
		
		// Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaMovePackage &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaMovePackage &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaMovePackage

#endif

