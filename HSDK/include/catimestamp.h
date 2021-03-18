//------------------------------------------------------+-----------------------------------------------
// FILENAME:           catimestamp.h
//
// DESCRIPTION:        Declares the CaTimeStamp class.
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

#if !defined(CaTimeStamp_H)
#define CaTimeStamp_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHTimeStamp;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaTimeStamp
//
//  DESCRIPTION:
//      CaTimeStamp is the HSDK class that encapsulates the Harvest CPtHTimeStamp class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaTimeStamp 
{
    private:

        // Member Variables
        CPtHTimeStamp*	    m_pHTimeStamp;			    // HUtilities TimeStamp Object
        bool                m_bOwnsHData;               // Can delete HTimeStamp when destroyed

	    // Private member functions
        CaTimeStamp( const CPtHTimeStamp &src );
        void Init(void);

    public:
        // Constructors
        CaTimeStamp(void);
        CaTimeStamp( const CaTimeStamp &src );
        CaTimeStamp(   HINT32   nYear,      HINT32      nMonth ,
                       HINT32   nDay ,      HINT32      nHour  ,
                       HINT32   nMinute,    HINT32      nSecond,
                       HINT32   nFraction=0 );


        // Destructor
        virtual ~CaTimeStamp(void);

        // Public Member Functions
        CaTimeStamp&  ChangeTime(HINT32 timezone);
        CaTimeStamp&  ConvertGMTime(void);
        HINT32        GetYear(void) const;
        HINT32        GetMonth(void) const;
        HINT32        GetDay(void) const;
        HINT32        GetHour(void) const;
        HINT32        GetMinute(void) const;
        HINT32        GetSecond(void) const;
        HINT32        GetFraction(void) const;
        CaTimeStamp&  SetYear(HINT32 nYear);
        CaTimeStamp&  SetMonth(HINT32 nMonth);
        CaTimeStamp&  SetDay(HINT32 nDay);
        CaTimeStamp&  SetHour(HINT32 nHour);
        CaTimeStamp&  SetMinute(HINT32 nMinute);
        CaTimeStamp&  SetSecond(HINT32 nSecond);
        CaTimeStamp&  SetFraction(HINT32 nFraction);


        // Public Inline Functions
		
        // Operators
        CaTimeStamp&  operator=( const CaTimeStamp& src );
        CaTimeStamp&  operator=( const CPtHTimeStamp& rSrc );
        bool          operator==( const CaTimeStamp& src ) const;
        bool          operator!=( const CaTimeStamp& src ) const;
                      operator CaString() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaTimeStamp& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaTimeStamp& src);
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaData;
		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaVersionChooser;

}; // end class CaTimeStamp

#endif

