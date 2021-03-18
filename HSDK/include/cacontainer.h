//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cacontainer.h
//
// DESCRIPTION:        Declares the CaContainer class.
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

#if !defined(CaContainer_H)
#define CaContainer_H

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
//  CLASS:  CaContainer
//
//  DESCRIPTION:
//      CaContainer is the HSDK class that encapsulates the Harvest CPtHContainer class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaContainer 
{
    private:

        // Member Variables
        CPtHContainer*	    m_pHContainer;					    // HUtilities Container Object
        CPtHContainer*	    m_pHCaDataContainer;    		    // CaDataArray Objects assoc w/container

	    // Private member functions
        void EmptyAssocContainer(void);
        void Init(void);

    public:
        // Constructors
        CaContainer(void);
        CaContainer(const CaContainer& CRight);

        // Destructor
        virtual ~CaContainer(void);

        // Public Member Functions
        void          Clear(void);
        CaDataArray   FindData(LPCTSTR strKey, LPCTSTR strValue) const;
        CaDataArray   FindData(LPCTSTR strKey, HINT32 iValue) const;
        HINT32        GetKeyCount(void) const;
        HINT32        GetKeyElementCount(LPCTSTR strKey) const;
        CaStringList  GetKeyList(void) const;
        bool          IsEmpty(void) const;
        bool          IsKeyExist(LPCTSTR strKey) const;
        CaData&       Props(LPCTSTR strKey, HINT32 iIndex = 0);

        // Public Inline Functions
		
        // Operators
		CaContainer&  operator=(const CPtHContainer& CHRight);
        CaContainer&  operator=(const CaContainer& CRight);
        CaContainer&  operator+=(const CaContainer& CRight);
        bool          operator==(const CaContainer& CRight) const;
        bool          operator!=(const CaContainer& CRight) const;
                      operator const CPtHContainer&();

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<(std::ostream &o, const CaContainer& c);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<(ostream &o, const CaContainer& c);
#endif
		friend class HSDKDLL_CLASS_DECLSPEC CaException;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;

}; // end class CaContainer

#endif

