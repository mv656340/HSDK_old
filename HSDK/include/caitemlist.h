//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaItemList.h
//
// DESCRIPTION:        Declares the CaItemListList class.
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

#if !defined(CaItemList_H)
#define CaItemList_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHContainer;
class CPtHChild;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaItemList
//
//  DESCRIPTION:
//      CaItemList is the HSDK class that encapsulates the Harvest CPtHItemList class. The CaItemList
//      never owns the underlying CPtHItemList.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaItemList 
{
    private:

        // Member Variables
        void*	            m_pHItemList;		// HAPI Item List Object, void 
        CPtHContainer*	    m_pHCaDataContainer;        // CaItem Objects assoc w/list
//      bool                m_bOwnsHData;               // Can delete HItemList when destroyed
//      CPtHChild*          m_pParent;                  // Parent of the list

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(const CaItem& rItem);
        int GetIndex(LPCTSTR szItemName);
        CaItemList(void);

    public:
        // Constructors
        //CaItemList( const CaItemList &src );


        // Destructor
        virtual ~CaItemList(void);

        // Public Member Functions
//      bool          Add(CaItem* pItem);
//      CaItem*       Remove(const CaItem& rItem);
//      CaItem*       Remove(LPCTSTR szName);
//      CaItem*       Remove(HAROBJID iObjId);
        void          Clean(void);

		// PR4141 (-1 is default so other usages will not be affected by this change).
        // void          Refresh(void);
        void          Refresh(HINT32 iItemPathOption = -1);

        //HUINT32       Load(HUINT32 iOptions);
        CaItem&       Find(const CaItem& rItem);
        CaItem&       Find(LPCTSTR szItemName);
        CaString      GetAllNames(void) const;
        long          GetSize(void) const;
        bool          IsEmpty(void) const;


        // Public Inline Functions
		
        // Operators
//      CaItemList&   operator=( const CaItemList& src );
//      CaItemList&   operator+=( const CaItemList& src );
//      CaItemList&   operator-=( const CaItemList& src );
        CaItem&       operator[](int i);
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaItemList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaItemList& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
	friend class HSDKDLL_CLASS_DECLSPEC CaItem;

}; // end class CaItemList

#endif

