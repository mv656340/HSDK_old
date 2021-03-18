//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caxproj.h
//
// DESCRIPTION:        Declares the CaCrossProjectMerge class.
//
// AUTHOR:             Scott Humphries
//
// REVISION HISTORY:
//             10-10-01 humda02	File Creation
// PR# 3214    07/27/04 lisla01 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// PR# 6382    09/11/07 faudo01 Expose VCIBinding Corrections changes in HAPI
// PR# 8216    09/22/08 faudo01 Deactivate -correctvcibindings
//
// Copyright (c) 2001-2007 CA, Inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaCrossProjectMerge_H)
#define CaCrossProjectMerge_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHCrossProjectMerge;

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
 
class HSDKDLL_CLASS_DECLSPEC CaCrossProjectMerge 
{
    private:

        // Member Variables
        CaContext*      m_pContext;                     // CA Context Object
		CPtHCrossProjectMerge*	m_pHCrossProjectMerge;	// Hapi ConcurrentMerge Object
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaCrossProjectMerge(CaHarvest& rHarvest);						// Can only be created by CaContext
        CaCrossProjectMerge(CaContext& rContext);  	    // Can only be created by CaContext
		
    public:
        // Constructors

        // Destructor
        virtual ~CaCrossProjectMerge(void);

        // Public Member Functions

		// Source Location, must specify either 
		//  Project name and State Name 
		//	 	OR
		//  Project ID and State ID
		void		SetFromState( LPCTSTR szProjectName, LPCTSTR szStateName );	//\ REQUIRED
		void		SetFromState( HAROBJID szProjectId, HAROBJID szStateId );	///
		// Merge Rule Option -- Method to resolve conflicts
		//  MERGE_RULE_ALWAYS_TAG
        //  MERGE_RULE_CONFLICT_TAG
		//  MERGE_RULE_TRUNK_TAG	(To/Trunk/Target)
        //  MERGE_RULE_BRANCH_TAG	(From/Branch/Source)
        void		SetMergeRule( LPCTSTR szRule );								// REQUIRED
		// Placement Options -- Destination for Merged Version
		//  MERGE_OPTION_TRUNK_ONLY
		//  MERGE_OPTION_BRANCH_ONLY
		//  MERGE_OPTION_TRUNK_OR_BRANCH
		void		SetPlacement( LPCTSTR szPlacement );						// REQUIRED
		void		SetVersionDescription( LPCTSTR szDescription );				// OPTIONAL

		HAROBJID	GetFromProjectId( void ) const;								// OPTIONAL
		LPCTSTR		GetFromProjectName( void ) const;							// OPTIONAL
		HAROBJID	GetFromStateId( void ) const;								// OPTIONAL
		LPCTSTR		GetFromStateName( void ) const;								// OPTIONAL

		LPCTSTR		GetMergeRule( void ) const;									// OPTIONAL
		LPCTSTR		GetPlacement( void ) const;									// OPTIONAL
		LPCTSTR		GetVersionDescription( void ) const;						// OPTIONAL

//PR#8216, b.Deacivate
//PR#6382, b.Expose VCI Binding Correction changes in HAPI
//        void        SetCorrectVCIBindings(enum tCorrectVCIBindingSettings nSetting);
//        HINT32      GetCorrectVCIBindings(void) const;
//PR#6382, e.Expose VCI Binding Correction changes in HAPI
//PR#8216, e.Deacivate


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
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaCrossProjectMerge &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaCrossProjectMerge &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaCrossProjectMerge

#endif

