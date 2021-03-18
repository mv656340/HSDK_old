//------------------------------------------------------+-----------------------------------------------
// FILENAME:           casignaturerec.h
//
// DESCRIPTION:        Declares the CaSignatureRec class.
//
// AUTHOR:             Anthony Candappa
//
// REVISION HISTORY:
//     12-02-03        AC     File Creation
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaSignatureRec_H)
#define CaSignatureRec_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtSignatureRecord;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaSignatureRec
//
//  DESCRIPTION:
//      CaSignatureRec is the HSDK class that represents the Harvest SignatureRec object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaSignatureRec 
{
    private:

        // Member Variables
        CPtSignatureRecord*	    m_pHSignatureRec;					    // FileAgent SignatureRecord Object
        bool					m_bOwnsHData;                // Can delete CPtSignatureRecord when destroyed
		
		void Init(void);

    public:
        // Constructors
        CaSignatureRec(const CPtSignatureRecord &rSrc);

        // Destructor
        virtual ~CaSignatureRec(void);

		void SetFileName (LPCTSTR sFileName);
		void SetItem (LPCTSTR sItem);
		void SetTag (LPCTSTR sTag);
		void SetPackage (LPCTSTR sPackage);
		void SetEnvironment (LPCTSTR sEnvironment);
		void SetState (LPCTSTR sState);
		void SetViewPath (LPCTSTR sViewPath);
		void SetDirectory (LPCTSTR sDirectory);
		void SetStatus (long lStatus);
		void SetSize (long lSize);
      // PR# 8924 - Large File Support
      void SetSize2 (HINT64 lSize);
		void SetVersionNumber (LPCTSTR sVersionNumber);
		void SetVersionId (long lVersionId);
		void SetUser (LPCTSTR sUser);
		void SetAuthor (LPCTSTR sAuthor);

		void SetCreateYear (HINT32 nYear);
		void SetCreateMonth (HINT32 nMonth); 
		void SetCreateDay (HINT32 nDay); 
		void SetCreateHour (HINT32 nHour); 
		void SetCreateMinute (HINT32 nMinute); 
		void SetCreateSecond (HINT32 nSecond); 
		void SetCreateFraction (HINT32 nFraction); 

		void SetModifiedTime (long lModifiedTime);


		LPCTSTR GetFileName ();
		LPCTSTR GetItem ();
		LPCTSTR GetTag ();
		LPCTSTR GetPackage ();
		LPCTSTR GetEnvironment ();
		LPCTSTR GetState ();
		LPCTSTR GetViewPath ();
		LPCTSTR GetDirectory ();
		long GetStatus ();
		long GetSize ();
      // PR# 8924 - Large File Support
      HINT64 GetSize2 ();
		LPCTSTR GetVersionNumber ();
		long GetVersionId ();
		LPCTSTR GetUser ();
		LPCTSTR GetAuthor ();

		HINT32 GetCreateYear ();
		HINT32 GetCreateMonth (); 
		HINT32 GetCreateDay (); 
		HINT32 GetCreateHour (); 
		HINT32 GetCreateMinute (); 
		HINT32 GetCreateSecond (); 
		HINT32 GetCreateFraction ();
		
		long GetModifiedTime ();

        //friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<(ostream &o, const CaContainer& c);
		//friend class HSDKDLL_CLASS_DECLSPEC CaException;
}; // end class CaCaSignatureRec

#endif
