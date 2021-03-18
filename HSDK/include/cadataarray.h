//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cadataarray.h
//
// DESCRIPTION:        Declares the CaDataArray class.
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

#if !defined(CaDataArray_H)
#define CaDataArray_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHDataArray;
class CPtHContainer;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaDataArray
//
//  DESCRIPTION:
//      CaDataArray is the HSDK class that encapsulates the Harvest CPtHDataArray class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaDataArray 
{
    private:

        // Member Variables
        CPtHDataArray*	    m_pHDataArray;					    // HUtilities DataArray Object
        CPtHContainer*	    m_pHCaDataContainer;    		    // CaData Objects assoc w/array
        bool                m_bOwnsHData;                       // Can delete HDataArray when destroyed

	    // Private member functions
        CaDataArray( const CPtHDataArray &rSrc );
        void EmptyAssocContainer(void);
        void Init(void);

    public:
        // Constructors
        CaDataArray(HINT32 nSize=0);
        CaDataArray( const CaDataArray &rSrc );


        // Destructor
        virtual ~CaDataArray(void);

        // Public Member Functions
        void          Clear(void);
        bool          Find(const CaData& rData, HUINT32& rIndex) const;
        int           GetSize(void) const;

        // Public Inline Functions
		
        // Operators
        CaDataArray&  operator=( const CaDataArray& rSrc );
        CaData&       operator[](HUINT32 index);

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaDataArray& a);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaDataArray& a);
#endif
		friend class HSDKDLL_CLASS_DECLSPEC CaContainer;


}; // end class CaDataArray

#endif

