//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaPackageList.h
//
// DESCRIPTION:        Declares the CaPackageList class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-19-02        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     08/15/05        LS      PR4850 - added CaForm as friend for form changes
//
//
// Copyright (c) 2002 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaPackageList_H)
#define CaPackageList_H

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
//  CLASS:  CaPackageList
//
//  DESCRIPTION:
//      CaPackageList is the HSDK class that encapsulates the Harvest CPtHChangePackageList class. The CaPackageList
//      never owns the underlying CPtHChangePackageList.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaPackageList 
{
    private:

        // Member Variables
        void*	            m_pHPackageList;		// HAPI Package List Object, void 
        CPtHContainer*	    m_pHCaDataContainer;        // CaPackage Objects assoc w/list
//      bool                m_bOwnsHData;               // Can delete HPackageList when destroyed
//      CPtHChild*          m_pParent;                  // Parent of the list
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(const CaPackage& rPackage);
        int GetIndex(LPCTSTR szPackageName);
		CaPackageList(void){Init();}
        CaPackageList(CaHarvest& rHarvest);

    public:
        // Constructors
        //CaPackageList( const CaPackageList &src );


        // Destructor
        virtual ~CaPackageList(void);

        // Public Member Functions
//      bool          Add(CaPackage* pPackage);
//      CaPackage*       Remove(const CaPackage& rPackage);
//      CaPackage*       Remove(LPCTSTR szName);
//      CaPackage*       Remove(HAROBJID iObjId);
        void          Clean(void);
        void          Refresh(void);
        //HUINT32       Load(HUINT32 iOptions);
        CaPackage&    Find(const CaPackage& rPackage);
        CaPackage&    Find(LPCTSTR szPackageName);
        CaString      GetAllNames(void) const;
        long          GetSize(void) const;
        bool          IsEmpty(void) const;


        // Public Inline Functions
		
        // Operators
//      CaPackageList&   operator=( const CaPackageList& src );
//      CaPackageList&   operator+=( const CaPackageList& src );
//      CaPackageList&   operator-=( const CaPackageList& src );
        CaPackage&       operator[](int i);
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaPackageList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaPackageList& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
	friend class HSDKDLL_CLASS_DECLSPEC CaPackage;
	friend class HSDKDLL_CLASS_DECLSPEC CaForm; // PR4850

}; // end class CaPackageList

#endif

