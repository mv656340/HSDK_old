//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaFormTypeList.h
//
// DESCRIPTION:        Declares the CaFormTypeListList class.
//
// REVISION HISTORY:
//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaFormTypeList_H)
#define CaFormTypeList_H

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
//  CLASS:  CaFormTypeList
//
//  DESCRIPTION:
//      CaFormTypeList is the HSDK class that encapsulates the Harvest CPtHFormTypeList class. The CaFormTypeList
//      never owns the underlying CPtHFormTypeList.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaFormTypeList 
{
    private:

        // Member Variables
        void*	            m_pHFormTypeList;		// HAPI Form List Object, void 
        CPtHContainer*	    m_pHCaDataContainer;    // CaFormType Objects assoc w/list

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(const CaFormType& rForm);
        int GetIndex(LPCTSTR szFormName);
        CaFormTypeList(void);

    public:
        // Constructors

        // Destructor
        virtual ~CaFormTypeList(void);

        // Public Member Functions
        void          Clean(void);

        void          Refresh(void);

        CaFormType&   Find(const CaFormType& rForm);
        CaFormType&   Find(LPCTSTR szFormName);
        CaString      GetAllNames(void) const;
        long          GetSize(void) const;
        bool          IsEmpty(void) const;

        // Public Inline Functions
	
        // Operators
        CaFormType&   operator[](int i);
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaFormTypeList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaFormTypeList& src);
#endif

//	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
	friend class HSDKDLL_CLASS_DECLSPEC CaForm;
	friend class HSDKDLL_CLASS_DECLSPEC CaPackage;
	friend class HSDKDLL_CLASS_DECLSPEC CaHarvest;
}; // end class CaFormTypeList

#endif

