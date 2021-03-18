//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caitem.h
//
// DESCRIPTION:        Declares the CaItem class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-19-02        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2002 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaItem_H)
#define CaItem_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHItem;
class CaItemList;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaItem
//
//  DESCRIPTION:
//      CaItem is the HSDK class that encapsulates the Harvest CPtHItem class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaItem 
{
    private:

        // Member Variables
        CPtHItem*	m_pHItem;			                // HAPI Item Object
        bool            m_bOwnsHData;                   // Can delete HItem when destroyed
        CaItemList*     m_pItemList;                    // List of child items 
        CaItemList*     m_pItemPathList;                // List of child item paths
        CaVersionList*  m_pVersionList;                 // List of versions 
        CaTimeStamp     m_creationTime;                 // Holder for creation time
        CaTimeStamp     m_modifiedTime;                 // Holder for modified time

	    // Private member functions
        CaItem(void){Init();}
        CaItem( const CPtHItem &rSrc );
        void Init(void);

    public:
        // Constructors
        CaItem( const CaItem &src );


        // Destructor
        virtual ~CaItem(void);

        // Public Member Functions
        LPCTSTR       GetName(void) const;
        HAROBJID      GetObjId(void) const;
        LPCTSTR       GetCreatorName(void) const;
        HAROBJID      GetCreatorObjId(void) const;
        CaTimeStamp&  GetCreationTime(void);
        LPCTSTR       GetModifierName(void) const;
        HAROBJID      GetModifierObjId(void) const;
        CaTimeStamp&  GetModifiedTime(void);      
        HAROBJID      GetParentRepositoryObjId(void) const;
        HAROBJID      GetViewObjId(void) const;
        bool          IsItemPath(void) const;
        LPCTSTR       GetParentPathName(void) const;
        LPCTSTR       GetPathFullName(void) const;
        LPCTSTR       GetViewType(void) const;
        CaItemList&   GetItemList(bool bRefresh = false);
        CaItemList&   GetItemPathList(bool bRefresh= false);		
        CaVersionList& GetVersionList(bool bRefresh = false, HINT32 iVersionFilter=VERSION_FILTER_ALL_IN_VIEW, 
                                      HINT32 iVersionStatusFilter=VERSION_FILTER_ALL_TAG);


        // Public Inline Functions
		
        // Operators
        CaItem&       operator=( const CaItem& src );
        bool          operator==( const CaItem& src ) const;
        bool          operator!=( const CaItem& src ) const;
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaItem& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaItem& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaItemList;
	friend class HSDKDLL_CLASS_DECLSPEC CaContext;


}; // end class CaItem

#endif

