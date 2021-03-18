//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caconmrg.h
//
// DESCRIPTION:        Declares the CaConcurrentMerge class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//PR# 3411 09-10-04    AC      Description passed incorrectly to HAPI
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaConcurrentMerge_H)
#define CaConcurrentMerge_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHConcurrentMerge;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaConcurrentMerge
//
//  DESCRIPTION:
//      CaConcurrentMerge is the HSDK class that represents the Harvest ConcurrentMerge object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaConcurrentMerge 
{
    private:

        // Member Variables
        CaContext*      m_pContext;                     // CA Context Object
		CPtHConcurrentMerge*	m_pHConcurrentMerge;	// Hapi ConcurrentMerge Object
     
		// Private member functions
        void            Init( void );
        CaConcurrentMerge(CaHarvest& rHarvest);						// Can only be created by CaContext
        CaConcurrentMerge(CaContext& rContext);  	    // Can only be created by CaContext

		//PR# 3411
		CaString		m_szDescription;

		CaHarvest*					m_pCaHarvest;		// HSDK Harvest pointer

	public:
        // Constructors

        // Destructor
        virtual ~CaConcurrentMerge(void);

        // Public Member Functions

        // Merge Rule Options
        //  MERGE_RULE_TRUNK_MERGE
        //  MERGE_RULE_BRANCH_MERGE
        //  MERGE_RULE_CONFLICT_TAG
        //  MERGE_RULE_ALWAYS_TAG
        void      SetMergeRule( LPCTSTR szRule );
        void      SetVersionDescription( LPCTSTR szDescription );

        LPCTSTR   GetMergeRule(void) const;
		LPCTSTR   GetVersionDescription(void) const;

        HINT32    Execute(bool bUseCurrentContext = true);
		// bUserCurrentContext
		// true - use package set in context (default)
		// false - use packages set in package chooser

        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaConcurrentMerge &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaConcurrentMerge &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaConcurrentMerge

#endif

