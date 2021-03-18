//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cablob.h
//
// DESCRIPTION:        Declares the CaBlob class.
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

#if !defined(CaBlob_H)
#define CaBlob_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHBlob;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaBlob
//
//  DESCRIPTION:
//      CaBlob is the HSDK class that encapsulates the Harvest CPtHBlob class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaBlob 
{
    private:

        // Member Variables
        CPtHBlob*	    m_pHBlob;					    // HUtilities Blob Object
        bool            m_bOwnsHData;                   // Can delete HBlob when destroyed

	    // Private member functions
        CaBlob(void);
        CaBlob( const CPtHBlob &src );
        void Init(void);

    public:
        // Constructors
        CaBlob(HINT32 nSize, void * lpData);
        CaBlob( const CaBlob &src );


        // Destructor
        virtual ~CaBlob(void);

        // Public Member Functions
        long          GetSize(void) const;
        void*         GetData(void) const;
        bool		  IsValid(void) const;


        // Public Inline Functions
		
        // Operators
        CaBlob&       operator=( const CaBlob& src );
        CaBlob&       operator=( const CPtHBlob& rSrc );
        bool          operator==( const CaBlob& src ) const;
        bool          operator!=( const CaBlob& src ) const;
                      operator LPCTSTR() const;
				      operator unsigned char*() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaBlob& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaBlob& src);
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaData;


}; // end class CaBlob

#endif

