//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caformtype.h
//
// DESCRIPTION:        Declares the CaFormType class.
//
// REVISION HISTORY:
//     06-14-05        sevle01     File Creation
//     10-28-05        sevle01     Add SetWebServiceNotification()
//     01-24-06        sevle01 PR5475 remove WebServices from calls, add GetName()
//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaFormType_H)
#define CaFormType_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"


//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHarvest;
class CPtHarvestSession;
class CPtHUser;
class CPtHFormType;
class CaHarvest;


//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaFormType
//
//  DESCRIPTION:
//      CaFormType is the HSDK class that encapsulates the HAPI CPtHFormType class.
//
//  NOTES:
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaFormType
{
    private:

        // Member Variables
		CPtHFormType*	m_pHFormType;						// HAPI Form Object
		CaHarvest*      m_pHarvest;						// Current Context
		CaData *		m_pColDefVal;
        bool            m_bOwnsHData;
		static ostream* m_pLog;					        // Log Stream
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init(void);
        CaFormType(const CPtHFormType &rSrc);

    public:
        // Constructors
		CaFormType(void);
        CaFormType(const CaFormType &src);

		CaFormType(CaHarvest &rHarvest);
        CaFormType(CaHarvest &rHarvest, const CaFormType &src);

		// Destructor
        virtual ~CaFormType(void);

        // Public Member Functions
		CaData& GetColumnDefaultValue(HINT32 iIndex);
		LPCTSTR GetTableName(void);
		HINT32 GetColumnIndex(LPCTSTR szColumnName);
		HINT32 GetColumnMaxLength(HINT32 iIndex);
		LPCTSTR GetColumnName(HINT32 iIndex);
		CaData::Types GetColumnType(HINT32 iIndex);
		HUINT32 GetColumnCount(void);
        HINT32 Get(HAROBJID iObjId);

        bool SetNotification(bool bFlag);  // PR#5052, PR#5475
        LPCTSTR GetName(void) const; // PR#5475


        // Operators
#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( ostream &o, const CaFormType &FormType );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaFormType &FormType );
#endif

	friend class HSDKDLL_CLASS_DECLSPEC CaForm;
	friend class HSDKDLL_CLASS_DECLSPEC CaFormTypeList;
}; // end class CaFormType

#endif

