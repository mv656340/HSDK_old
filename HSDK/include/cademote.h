//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cademote.h
//
// DESCRIPTION:        Declares the CaDemote class.
//
// AUTHOR:             Michael Scott
//
//             04-18-01  MAS    File Creation
// PR# 3214    07/27/04 lisla01 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// PR# 6382    09/11/07 faudo01 Expose VCIBinding Corrections changes in HAPI
// PR# 8216    09/22/08 faudo01 Deactivate -correctvcibindings
//
// Copyright (c) 2001-2007 CA, Inc. All rights reserved. 
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaDemote_H)
#define CaDemote_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHDemote;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaDemote
//
//  DESCRIPTION:
//      CaDemote is the HSDK class that represents the Harvest Demote object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaDemote 
{
    private:

        // Member Variables
		CPtHDemote*	m_pHDemote;					    // Hapi Demote Object
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaDemote(CaHarvest& rHarvest);								// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaDemote(void);

        // Public Member Functions
        bool                SetCheckPackageDependencies(bool bCheckPackageDependencies);
        bool                SetCheckPackageGroupBind( bool bFlag);
        bool                GetCheckPackageDependencies(void) const;
        bool                GetCheckPackageGroupBind(void) const;
        LPCTSTR             GetToStateName(void) const;
        HAROBJID            GetToStateObjId(void) const;

//PR#8216, b.deactivate
//PR#6382, b.Expose VCI Binding Correction changes in HAPI
//        void                SetCorrectVCIBindings(enum tCorrectVCIBindingSettings nSetting);
//        HINT32              GetCorrectVCIBindings(void) const;
//PR#6382, e.Expose VCI Binding Correction changes in HAPI
//PR#8216, e.deactivate

        HINT32              Execute(void);

        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaDemote &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaDemote &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaDemote

#endif

