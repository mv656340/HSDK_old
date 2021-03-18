//------------------------------------------------------+-----------------------------------------------
// FILENAME:           carempath.h
//
// DESCRIPTION:        Declares the CaRemovePath class.
//
// AUTHOR:             Donald Faul
//
// REVISION HISTORY:
// PR# 4664   01-03-07 faudo01 File Creation
//
// Copyright (c) 2007 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaRemovePath_H)
#define CaRemovePath_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHRemovePath;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaRemovePath
//
//  DESCRIPTION:
//      CaRemovePath is the HSDK class that represents the Harvest RemovePath object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaRemovePath 
{
    private:

        // Member Variables
		CPtHRemovePath*	m_pHRemovePath;					// Hapi RemovePath Object
        CaContext*      m_pContext;                     // CA Context Object
		HAROBJID        m_iItemPathObjId;               // If not NULL_HAROBJID use it
        CaString        m_szItemPathName;               // If no Item Id use this
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
      
		// Private member functions
        void            Init( void );
        CaRemovePath(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaRemovePath(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaRemovePath(void);

        // Public Member Functions
		void           SetItemPathObjId(HAROBJID iItemPathObjId) {m_iItemPathObjId = iItemPathObjId;}
        void           SetItemPath(LPCTSTR szItemPathName) {m_szItemPathName = szItemPathName;}
		//  HAPI wrappers
	    bool           SetDescription(LPCTSTR szDesc);
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);

        HAROBJID       GetItemPathObjId(void) const { return m_iItemPathObjId;}
        LPCTSTR        GetItemPath(void) const { return m_szItemPathName;}
		//  HAPI wrappers
		LPCTSTR        GetDescription(void) const;
		bool           GetCreateOnBranch (void) const;
		bool           GetCreateOnTrunk(void) const;
		bool           GetBranchOut(void) const;

        HINT32         Execute(void);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaRemovePath &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaRemovePath &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaRemovePath

#endif

