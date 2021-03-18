//------------------------------------------------------+-----------------------------------------------
// FILENAME:           carenpath.h
//
// DESCRIPTION:        Declares the CaRenamePath class.
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

#if !defined(CaRenamePath_H)
#define CaRenamePath_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHRenamePath;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaRenamePath
//
//  DESCRIPTION:
//      CaRenamePath is the HSDK class that represents the Harvest RenamePath object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaRenamePath 
{
    private:

        // Member Variables
		CPtHRenamePath*	m_pHRenamePath;					// Hapi RenamePath Object
        CaContext*      m_pContext;                     // CA Context Object
		HAROBJID        m_iItemPathObjId;                   // If not NULL_HAROBJID use it
        CaString        m_szItemPathName;               // If by name use this path
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
      
		// Private member functions
        void            Init( void );
        CaRenamePath(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaRenamePath(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaRenamePath(void);

        // Public Member Functions
		void           SetItemPathObjId(HAROBJID iItemPathObjId) {m_iItemPathObjId = iItemPathObjId;}
        void           SetItemPath(LPCTSTR szItemPath) {m_szItemPathName = szItemPath;}
		//  HAPI wrappers
	    bool           SetDescription(LPCTSTR szDesc);
        bool           SetNewItemPathName(LPCTSTR szNewItemPath);
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);
		bool           SetRefactorMode(HINT32 nIndex);

        HAROBJID       GetItemPathObjId(void) const { return m_iItemPathObjId;}
        LPCTSTR        GetItemPathName(void) const { return m_szItemPathName;}
		//  HAPI wrappers
		LPCTSTR        GetDescription(void) const;
        LPCTSTR        GetNewItemPathName(void) const;
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
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaRenamePath &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaRenamePath &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaRenamePath

#endif

