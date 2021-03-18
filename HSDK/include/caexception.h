//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caexception.h
//
// DESCRIPTION:        Declares the CaException class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// PR# 4142  02/23/05  denyi01   Error codes on Rename/Remove failure		 		
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaException_H)
#define CaException_H
// begin PR# 3214 Jiantao 8-30-04
#if (defined(__GNUC__) && (__GNUC__>=3))
	using std::ostream;
	#endif
//using std::ostream;
// end PR# 3214 Jiantao 8-30-04
//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHContext;
class CPtHErrorMsgHandler;
class CaHarvest;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#define DEFAULT_EXCEPTION_CODE -10000                   // Arbitrary Default Value 
#define HSDKOK				0
#define HSDKBAD				-1
//PR4142
#define HSDKBAD_INVALID_ITEM	-2
#define HSDKBAD_MULTIPLE_ITEMS	-3
#define HSDKBAD_NO_PACKAGE		-4
//end of PR4142

//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaException
//
//  DESCRIPTION:
//      CaException is the HSDK exception class. I provides message formatting and logging features.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaException 
{
    private:

        // Member Variables
		CaContainer	m_bagErrorInfo;					    // Container to hold exception information
        static CPtHErrorMsgHandler *s_pErrMsgHandler;   // Static so all can use it.
        bool m_bKey;                                    // Message text is Key, not literal.
        HINT32 m_iReturnCode;                           // Return code

     
		// Private member functions
        void            Init( void );
        CaException(void);								

    public:
        // Constructors
        CaException( const CaException &CRight);
        CaException(bool bKey, LPCTSTR szMessage );								
        CaException(LPCTSTR szKey, ...);								

        // Destructor
        virtual ~CaException(void);

        // Public Member Functions
        CaString GetMessage(void);
        void LogMessage(void);
        void LogMessage2(CaHarvest& rHarvest);
        void LogMessage2(const CaHarvest& rHarvest);

        // Public Inline Functions
        void SetReturnCode(HINT32 iReturnCode) {m_iReturnCode = iReturnCode;}
        HINT32 GetReturnCode(void) {return m_iReturnCode;}
		
		
        // Operators
        const CaException & operator=(const CaException &CRight);
                            operator const CPtHContainer&();

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaException &Exception );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaException &Exception );
#endif

        friend HSDKDLL_CLASS_DECLSPEC CaContainer& operator<<(CaContainer& bag, const CaException& ex);
		friend class HSDKDLL_CLASS_DECLSPEC CaHarvest;

}; // end class CaException

#endif

