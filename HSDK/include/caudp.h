//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caudp.h
//
// DESCRIPTION:        Declares the CaUDP class.
//
// AUTHOR:             Scott Humphries
//
// REVISION HISTORY:
//     09-18-01        humda02	File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     01-12-06        faudo01 PR5420 Add CaUDPExitHandler class.
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaUDP_H)
#define CaUDP_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHUDP;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//PR#5420, b.Exit handling

#undef UNIXSIGCHLDHANDLER
#if !defined(__HWW_370__) && !defined(WIN32)
#  define UNIXSIGCHLDHANDLER 1
#endif

//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaUDPExitHandler
//
//  DESCRIPTION:
//      CaUDPExitHandler is the HSDK class that provides setting/restoring the 
//      state of the sigaction structure for the SIGCHLD signal for UNIX 
//      systems.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
#if defined(UNIXSIGCHLDHANDLER)
class HSDKDLL_CLASS_DECLSPEC CaUDPExitHandler {
public:
    // Constructor
    CaUDPExitHandler(void);

    // Deconstructor
    virtual ~CaUDPExitHandler(void);

protected:
    static bool m_bSavedSIGCHLDaction;
    static int  m_iCounter;
    static struct sigaction m_iact;
    static struct sigaction m_oact;
};
//PR#5420, e.Exit handling
#endif


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaUDP
//
//  DESCRIPTION:
//      CaUDP is the HSDK class that represents the Harvest CPtHUDP object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaUDP 
{
    private:

        // Member Variables
        CaContext*      m_pContext;                     // CA Context Object
		CPtHUDP*		m_pHUDP;				// Hapi UDP Object

		bool			m_bUsePackageList;		// Use Package Chooser for list of packages
		bool			m_bUseVersionList;		// Use Version Chooser for list of versions/items
		CaStringList	m_szFileList;
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer
		
		// Private member functions
        void            Init( void );
		CaUDP(CaHarvest& rHarvest);						// Can only be created by CaContext
		CaUDP(CaContext& rContext);  	    // Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual		~CaUDP(void);

        // Public Member Functions

		
		bool		SetUsePackageList( bool bUsePackageChooser );
		bool		SetUseVersionList( bool bUseVersionChooser );
		void		SetInput( LPCTSTR szAddInput );
		void		SetAddCmdLineArg( LPCTSTR szCmdLineArg ); // Supplants File List argument of HSIK
		
		LPCTSTR		GetUDPType( void );
		LPCTSTR		GetProgramName( void );
		LPCTSTR		GetDescription( void );
		LPCTSTR		GetNote( void );
		bool		GetUserCanModifyInput(void );
		bool		GetUsePackageList( void );
		bool		GetUseVersionList( void );
		LPCTSTR		GetAddCmdLineArg( void );
		LPCTSTR		GetInput( void );

        HINT32		Execute( );
		
        // Public Inline Functions
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaUDP &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaUDP &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaUDP

#endif

