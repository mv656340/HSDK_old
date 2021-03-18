//------------------------------------------------------+-----------------------------------------------
// FILENAME:           castring.h
//
// DESCRIPTION:        Declares the CaString class.
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
// PR# 4935 wurma01 07/25/2006 .NET 2003 upgrade
#if !defined(CaString_H)
#define CaString_H

//  INCLUDE STATEMENTS:
#if defined (_MSC_VER) && (_MSC_VER >= 1300) //PR#4935
#include <iostream>
using namespace std;
#endif

//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHString;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaString
//
//  DESCRIPTION:
//      CaString is the HSDK class that encapsulates the Harvest CPtHString class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaString 
{
    private:

        // Member Variables
        CPtHString*	    m_pHString;					    // HUtilities String Object
        bool            m_bOwnsHData;                   // Can delete HString when destroyed

	    // Private member functions
        CaString( const CPtHString &rSrc );
        void Init(void);

    public:
        // Constructors
        CaString(void);
        CaString( const CaString &src );
        CaString( LPCTSTR lpStr );
        CaString( char* lpStr );


        // Destructor
        virtual ~CaString(void);

        // Public Member Functions
        CaString&       Append( LPCTSTR src );
        long            GetLength(void) const;
        const char*     GetMultiByteString(void);
        bool            IsEmpty(void) const;
        bool			IsValid(void) const;
        CaString&       MakeEmpty(void);
        CaString&       ToLower(void);
        CaString&       ToUpper(void);
        CaString&       Trim(void);


        // Public Inline Functions
		
        // Operators
        CaString&       operator=( const CaString& src );
        CaString&       operator=( LPCTSTR src );
        CaString&       operator=( char* src );
        bool            operator==( const CaString& src ) const;
        bool            operator!=( const CaString& src ) const;
        bool            operator==( LPCTSTR src ) const;
        bool            operator!=( LPCTSTR src ) const;
        CaString&       operator+=( LPCTSTR src );
        CaString&       operator-=( LPCTSTR src );
                        operator LPCTSTR() const;
						operator char*() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaString& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaString& src);
#endif
		friend class HSDKDLL_CLASS_DECLSPEC CaStringList;


}; // end class CaString

#endif

