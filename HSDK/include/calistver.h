//------------------------------------------------------+-----------------------------------------------
// FILENAME:           calistver.h
//
// DESCRIPTION:        Declares the CaListVersion class.
//
// AUTHOR:             Ali Mobrem
//
// REVISION HISTORY:
//    06-30-2003       AM    File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaListVersion_H)
#define CaListVersion_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHListVersion;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaListVersion
//
//  DESCRIPTION:
//      CaListVersion is the HSDK class that represents the Harvest ListVersion object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaListVersion 
{
    private:

        // Member Variables
		CPtHListVersion*	m_pHListVersion;					    // Hapi ListVersion Object
		CaContext*      m_pContext;    
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init( void );
		CaListVersion(CaHarvest& rHarvest);								// Can only be created by CaContext
		CaListVersion(CaContext& rContext);  			    // Can only be created by CaContext
    public:
        // Constructors

        // Destructor
        virtual ~CaListVersion(void);


        // Public Member Functions

		bool				SetShowActualChangesFlag( bool bFlag );         
        bool				GetShowActualChangesFlag(void) const;            
        bool				SetShowDescriptionFlag( bool bFlag );           
        bool				GetShowDescriptionFlag(void) const; 

        HINT32              Execute(void);

        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaListVersion &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaListVersion &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
}; // end class CaListVersion

#endif

