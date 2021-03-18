//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaVersionList.h
//
// DESCRIPTION:        Declares the CaVersionList class.
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

#if !defined(CaVersionList_H)
#define CaVersionList_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHContainer;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaVersionList
//
//  DESCRIPTION:
//      CaVersionList is the HSDK class that encapsulates the Harvest CPtHStringList class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaVersionList 
{
    private:

        // Member Variables
        void*	            m_pHVersionList;		// HAPI Version List Object, void 
        CPtHContainer*	    m_pHCaDataContainer;        // CaVersion Objects assoc w/list
       // CPtHView*           m_pParentView;              // HAPI View

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(const CaVersion& rVersion);
        int GetIndex(LPCTSTR szVersionName);
        CaVersionList(void);

    public:
        // Constructors
        //CaVersionList( const CaVersionList &src );


        // Destructor
        virtual ~CaVersionList(void);

        // Public Member Functions
        //bool          Add(const CaVersion& rVersion);
        void          Clean(void);
        //HUINT32       Load(HUINT32 iOptions);
        void          Refresh(void);
        CaVersion&    Find(const CaVersion& rVersion);
        CaVersion&    Find(LPCTSTR szVersionName);
        CaString      GetAllNames(void) const;
        long          GetSize(void) const;
        bool          IsEmpty(void) const;


        // Public Inline Functions
		
        // Operators
        //CaVersionList&   operator=( const CaVersionList& src );
        //CaVersionList&   operator+=( const CaVersionList& src );
        //CaVersionList&   operator-=( const CaVersionList& src );
        CaVersion&       operator[](int i);
                         operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaVersionList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaVersionList& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
	friend class HSDKDLL_CLASS_DECLSPEC CaVersion;
	friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
	friend class HSDKDLL_CLASS_DECLSPEC CaItem;
	friend class HSDKDLL_CLASS_DECLSPEC CaPackage;

}; // end class CaVersionList

#endif

