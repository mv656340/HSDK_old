//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaStringList.h
//
// DESCRIPTION:        Declares the CaStringListList class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaStringList_H)
#define CaStringList_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHStringList;
class CPtHContainer;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaStringList
//
//  DESCRIPTION:
//      CaStringList is the HSDK class that encapsulates the Harvest CPtHStringList class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaStringList 
{
    private:

        // Member Variables
        CPtHStringList*	    m_pHStringList;				// HUtilities StringList Object
        CPtHContainer*	    m_pHCaDataContainer;        // CaString Objects assoc w/list

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(LPCTSTR szString);

    public:
        // Constructors
        CaStringList(void);
        CaStringList( const CaStringList &src );


        // Destructor
        virtual ~CaStringList(void);

        // Public Member Functions
        bool            Add(const CaString szString);
        bool            Add(LPCTSTR szString);
        void            Clean(void);
        CaString&       Find(const CaString szString);
        CaString&       Find(LPCTSTR szString);
        CaString        GetAllNames(void) const;
        long            GetSize(void) const;
        bool            IsEmpty(void) const;
        bool			Remove(const CaString szString);
        bool			Remove(LPCTSTR szString);


        // Public Inline Functions
		
        // Operators
        CaStringList&   operator=( const CaStringList& src );
        bool            operator==( const CaStringList& src ) const;
        bool            operator!=( const CaStringList& src ) const;
        CaStringList&   operator+=( const CaStringList& src );
        CaStringList&   operator-=( const CaStringList& src );
        CaString&       operator[](int i);
                        operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaStringList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaStringList& src);
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContainer;
		friend class HSDKDLL_CLASS_DECLSPEC CaCheckin;

}; // end class CaStringList

#endif

