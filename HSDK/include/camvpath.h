//------------------------------------------------------+-----------------------------------------------
// FILENAME:           camvpath.h
//
// DESCRIPTION:        Declares the CaMovePath class.
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

#if !defined(CaMovePath_H)
#define CaMovePath_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHMovePath;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaMovePath
//
//  DESCRIPTION:
//      CaMovePath is the HSDK class that represents the Harvest MovePath object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaMovePath 
{
    private:

        // Member Variables
		CPtHMovePath*	m_pHMovePath;					// Hapi MovePath Object
        CaContext*      m_pContext;                     // CA Context Object
		HAROBJID        m_iItemPathObjId;               // If not NULL_HAROBJID use it
        CaString        m_szItemPathName;               // If no Item Id use this
		HAROBJID        m_iTargetPathObjId;             // If not NULL_HAROBJID use it
        CaString        m_szTargetPathName;             // Target path for the move.
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
      
		// Private member functions
        void            Init( void );
        CaMovePath(CaHarvest& rHarvest);					        // Can only be created by CaContext
        CaMovePath(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaMovePath(void);

        // Public Member Functions
		void           SetItemPathObjId(HAROBJID iItemPathObjId) {m_iItemPathObjId = iItemPathObjId;}
        void           SetItemPath(LPCTSTR szItemPath) {m_szItemPathName = szItemPath;}
		void           SetTargetItemPathObjId(HAROBJID iTargetPathObjId) {m_iTargetPathObjId = iTargetPathObjId;}
        void           SetTargetItemPath(LPCTSTR szTargetPathName) {m_szTargetPathName = szTargetPathName;}
		//  HAPI wrappers
	    bool           SetDescription(LPCTSTR szDesc);
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);
		bool           SetRefactorMode(HINT32 nIndex);

		HAROBJID       GetItemPathObjId(void) const { return m_iItemPathObjId;}
        LPCTSTR        GetItemPath(void) const { return m_szItemPathName;}
        HAROBJID       GetTargetItemPathObjId(void) const { return m_iTargetPathObjId;}
        LPCTSTR        GetTargetItemPath(void) const { return m_szTargetPathName;}
		//  HAPI wrappers
		LPCTSTR        GetDescription(void) const;
		bool           GetCreateOnBranch (void) const;
		bool           GetCreateOnTrunk(void) const;
		bool           GetBranchOut(void) const;
		HINT32         GetRefactorMode(void) const;

        HINT32         Execute(void);

        // Public Inline Functions	

        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaMovePath &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaMovePath &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaMovePath

#endif

