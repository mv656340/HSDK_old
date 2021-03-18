//------------------------------------------------------+-----------------------------------------------
// FILENAME:           CaFormList.h
//
// DESCRIPTION:        Declares the CaFormListList class.
//
// REVISION HISTORY:
//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
// PR# 6261 Shera01 Required for NEW API getformList()
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaFormList_H)
#define CaFormList_H

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
//  CLASS:  CaFormList
//
//  DESCRIPTION:
//      CaFormList is the HSDK class that encapsulates the Harvest CPtHFormList class. The CaFormList
//      never owns the underlying CPtHFormList.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaFormList 
{
    private:

        // Member Variables
        void*	            m_pHFormList;		// HAPI Form List Object, void 
        CPtHContainer*	    m_pHCaDataContainer;        // CaForm Objects assoc w/list

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);
        int GetIndex(const CaForm& rForm);
        int GetIndex(LPCTSTR szFormName);
        CaFormList(void);

    public:
        // Constructors

        // Destructor
        virtual ~CaFormList(void);

        // Public Member Functions
        void          Clean(void);

        void          Refresh(void);

        CaForm&       Find(const CaForm& rForm);
        CaForm&       Find(LPCTSTR szFormName);
        CaString      GetAllNames(void) const;
        long          GetSize(void) const;
        bool          IsEmpty(void) const;

        // Public Inline Functions
	
        // Operators
        CaForm&       operator[](int i);
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaFormList& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaFormList& src);
#endif

//	friend class HSDKDLL_CLASS_DECLSPEC CaContext;
	friend class HSDKDLL_CLASS_DECLSPEC CaForm;
	friend class HSDKDLL_CLASS_DECLSPEC CaPackage;
	friend class HSDKDLL_CLASS_DECLSPEC CaHarvest; // PR6261
}; // end class CaFormList

#endif

