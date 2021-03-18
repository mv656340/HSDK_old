//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caremitem.h
//
// DESCRIPTION:        Declares the CaRemoveItem class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
// pr# 3214  07/27/04  lisla01 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// PR# 4664  01-05-07  faudo01 Refactoring changes
//
//
// Copyright (c) 2001-2007 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaRemoveItem_H)
#define CaRemoveItem_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHRemoveItem;
class CaContext;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaRemoveItem
//
//  DESCRIPTION:
//      CaRemoveItem is the HSDK class that represents the Harvest RemoveItem object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaRemoveItem 
{
    private:

        // Member Variables
		CPtHRemoveItem*	m_pHRemoveItem;					// Hapi RemoveItem Object
        CaContext*      m_pContext;                     // CA Context Object
        HAROBJID        m_iItemObjId;                   // If not NULL_HAROBJID use it
        CaString        m_szItemName;                   // If no Item Id use this
        CaString        m_szItemPath;                   // If by name use this path
        bool            m_bRecursive;                   // If by name search this path recursively
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaRemoveItem(CaHarvest& rHarvest);								// Can only be created by CaContext
        CaRemoveItem(CaContext& rContext);  			// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaRemoveItem(void);

        // Public Member Functions
		//  HAPI wrappers
        bool           SetDescription(LPCTSTR szDesc);
//PR#4664, b.Refactoring changes
		bool           SetCreateOnBranch (bool bFlag);
		bool           SetCreateOnTrunk (bool bFlag);
		bool           SetBranchOut(bool bFlag);
//PR#4664, e.Refactoring changes

		//  HAPI wrappers
        LPCTSTR        GetDescription(void) const;
//PR#4664, b.Refactoring changes
		bool           GetCreateOnBranch (void) const;
		bool           GetCreateOnTrunk(void) const;
		bool           GetBranchOut(void) const;
//PR#4664, e.Refactoring changes


        HINT32              Execute(void);

        // Public Inline Functions
        void           SetItemObjId(HAROBJID iItemObjId) {m_iItemObjId = iItemObjId;}
        void           SetItemName(LPCTSTR szItemName) {m_szItemName = szItemName;}
        void           SetItemPath(LPCTSTR szItemPath) {m_szItemPath = szItemPath;}
        void           SetRecursive(bool bRecursive) {m_bRecursive = bRecursive;}
		
        HAROBJID       GetItemObjId(void) const { return m_iItemObjId;}
        LPCTSTR        GetItemName(void) const { return m_szItemName;}
        LPCTSTR        GetItemPath(void) const { return m_szItemPath;}
        bool           GetRecursive(void) const { return m_bRecursive;}
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaRemoveItem &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaRemoveItem &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaRemoveItem

#endif

