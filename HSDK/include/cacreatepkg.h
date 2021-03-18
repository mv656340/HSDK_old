//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cacreatepkg.h
//
// DESCRIPTION:        Declares the CaCreatePackage class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
// pr# 5923 08/14/06   lawph01 ENHANCEMENT TO GET PACKAGEOBJID IN CACREATEPACKAGE IN HSDK
// PR# 8724 07/04/11   khasu03 PR8724 - SetNote for JCaPackage in JHSDK
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaCreatePackage_H)
#define CaCreatePackage_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHCreateChangePackage;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaCreatePackage
//
//  DESCRIPTION:
//      CaCreatePackage is the HSDK class that represents the Harvest CreateChangePackage object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaCreatePackage 
{
    private:

        // Member Variables
		CPtHCreateChangePackage*	m_pHCreateChangePackage; // Hapi CreateChangePackage Object
        CaString                    m_szPackageName;
        CaString                    m_szAssignedUserName;
        CaString                    m_szDescription;
		CaString					m_szPackageNote;
        HINT32                      m_iPriority;
		CaHarvest*					m_pCaHarvest;		// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaCreatePackage(CaHarvest& rHarvest);								// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaCreatePackage(void);

        // Public Member Functions

		LPCTSTR	            GetDefaultName(void) const;

        HINT32              Execute(void);
	    HINT32              Execute(CaContainer& rout); //pr# 5923

        // Public Inline Functions
        void                SetPackageName(LPCTSTR szPackageName) {m_szPackageName = szPackageName;}
        void	            SetAssignedUserName( LPCTSTR szAssignedUserName) {m_szAssignedUserName = szAssignedUserName;}
        void	            SetDescription(LPCTSTR szDescription) {m_szDescription = szDescription;}
        void	            SetPackageNote(LPCTSTR szNote) {m_szPackageNote = szNote;}
        void	            SetPriority(HINT32 iPriority) {m_iPriority = iPriority;}

        LPCTSTR				GetPackageName(void) const {return m_szPackageName;} // Contains new package name if Execute succeeds
        LPCTSTR				GetAssignedUserName(void) const {return m_szAssignedUserName;}
        HINT32				GetPriority(void) const {return m_iPriority;}
        LPCTSTR				GetDescription(void) const {return m_szDescription;}
		LPCTSTR				GetPackageNote(void) const {return m_szPackageNote;}
		
		HINT32				GetInitialStateId (void);
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaCreatePackage &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaCreatePackage &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaContext;
}; // end class CaCreatePackage

#endif

