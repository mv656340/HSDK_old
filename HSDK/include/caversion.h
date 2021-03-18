//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caVersion.h
//
// DESCRIPTION:        Declares the CaVersion class.
//
// AUTHOR:             Michael Scott
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// REVISION HISTORY:
//         06-19-02   MAS     File Creation
// PR#4664 01-10-07  faudo01  Refactoring additions.
//
// Copyright (c) 2002 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaVersion_H)
#define CaVersion_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHVersion;
class CaVersionList;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaVersion
//
//  DESCRIPTION:
//      CaVersion is the HSDK class that encapsulates the Harvest CPtHVersion class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaVersion 
{
    private:

        // Member Variables
        CPtHVersion*	   m_pHVersion;	        		// HAPI Version Object
        bool               m_bOwnsHData;                // Can delete HVersion when destroyed
        CaTimeStamp     m_creationTime;                 // Holder for creation time
        CaTimeStamp     m_modifiedTime;                 // Holder for modified time

	    // Private member functions
        CaVersion(void){Init();}
        CaVersion( const CPtHVersion &rSrc );
        void Init(void);

    public:
        // Constructors
        CaVersion( const CaVersion &src );


        // Destructor
        virtual ~CaVersion(void);

        // Public Member Functions
        LPCTSTR       GetName(void) const;
        HAROBJID      GetObjId(void) const;
        LPCTSTR       GetCreatorName(void) const;
        HAROBJID      GetCreatorObjId(void) const;
        CaTimeStamp&  GetCreationTime(void);
        LPCTSTR       GetModifierName(void) const;
        HAROBJID      GetModifierObjId(void) const;
        CaTimeStamp&  GetModifiedTime(void);      
	    HAROBJID      GetViewObjId(void) const;
        LPCTSTR       GetPathFullName(void) const;
        HAROBJID      GetPackageObjId (void) const;
        HAROBJID      GetItemObjId(void) const;
        HINT32        GetItemType(void) const;
        HINT32        GetParentVersionObjId(void) const;
        HINT32        GetMergedVersionId(void) const;
        LPCTSTR       GetMappedVersionName(void) const;
        LPCTSTR       GetVersionStatus(void) const;
        HINT32        GetVersionDataObjId(void) const;
        LPCTSTR       GetDescription(void) const;
        LPCTSTR       GetPackageName(void) const;

        LPCTSTR       GetClientMachine(void) const;
        LPCTSTR       GetClientPath(void) const;

//PR#4664, b.Refactoring method additions
        LPCTSTR		  GetRefactorType(void) const;
        HAROBJID      GetRefactorByPathVersionObjId(void) const;
        HAROBJID      GetPathVersionObjId(void) const;
//PR#4664, e.Refactoring method additions


        // Public Inline Functions
		
        // Operators
        CaVersion&    operator=( const CaVersion& src );
        bool          operator==( const CaVersion& src ) const;
        bool          operator!=( const CaVersion& src ) const;
                      operator bool() const;

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaVersion& src);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaVersion& src);
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaVersionList;
	friend class HSDKDLL_CLASS_DECLSPEC CaContext;


}; // end class CaVersion

#endif

