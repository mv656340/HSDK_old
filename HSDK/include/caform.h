//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caform.h
//
// DESCRIPTION:        Declares the CaForm class.
//
// REVISION HISTORY:
//     06-14-05        sevle01     File Creation
//     10-31-05        sevle01     PR5052 - Add server notification
//     01/21/06        sevle01     PR5475 - remove notification code except setting bool flag on form
//                                        - add GetName()
//     02/15/06        sevle01     PR5589 - add optional CaPackage to constructor
//     03-09-08        kalpr01     PR6261 - Requirement for a API getformOBJID
//     01-09-09        chiji01     PR8296 - RTserverless agent
//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaForm_H)
#define CaForm_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
//#include <hhapiinc.h>
#include "hsdk.h"


//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHarvest;
class CPtHarvestSession;
class CPtHUser;
class CPtHAgent;
class CPtHForm;
class CaHarvest;
class CaFormType;
class CaFormAttachment;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaForm
//
//  DESCRIPTION:
//      CaForm is the HSDK class that encapsulates the HAPI CPtHForm class.
//
//  NOTES:
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaForm
{
    private:

        // Member Variables
		CPtHForm*		m_pHForm;						// HAPI Form Object
		CaContainer*	m_pFormAttachmentList;
		CaPackageList*	m_pPackageList;
		CaPackageList*	m_pNotInPackageList;
		CaContainer *	m_pHistory;
		CaData *		m_pColValue;
		static ostream* m_pLog;					        // Log Stream
		CaFormType *m_pFormType;
		CPtHAgent       *m_aFileAgent;
		LPTSTR			m_szAgentUser;
		LPTSTR			m_szRemoteMachineName;
        LPTSTR          m_szPortNumber; // PR# 8296
		LPTSTR			m_szRemoteUserName;
		LPTSTR			m_szRemotePassword;
		LPTSTR			m_szClientPath;
        bool            m_bOwnsHData;
		CaHarvest*		m_pCaHarvest;				// HSDK Harvest pointer

		// Private member functions
        void            Init(void);
        CaForm(const CPtHForm &rSrc);

    public:
        // Constructors
        CaForm(CaPackage& rPackage);
        CaForm(CaFormType& rFormType, LPCTSTR szName=_T(""), CaPackage *rPackage = NULL); // PR5589
        CaForm(const CaForm &src);

        CaForm(CaPackage& rPackage, CaHarvest& rHarvest);
        CaForm(CaHarvest& rHarvest, CaFormType& rFormType, LPCTSTR szName=_T(""), CaPackage *rPackage = NULL);
        CaForm(const CaForm &src, CaHarvest& rHarvest);

		HINT32 Get(HAROBJID iObjId);

        // Destructor
        virtual ~CaForm(void);

        // Public Member Functions
		CaContainer&	GetHistory();
		bool			GetColumnHasValue(LPCTSTR szColName);
		CaFormType&		GetFormType(void);
		CaData&			GetColumnValue(LPCTSTR szColName);
		bool			SetColumnValue(LPCTSTR szColName, const CaData& rValue);
		LPCTSTR			GetFormTypeName(void);
		HAROBJID		GetFormTypeObjId(void);
		HAROBJID        GetFormObjId(void) const; // PR# 6261
		bool			AddPackage(CaPackage *pPackage);
		bool			RemovePackage(CaPackage& rPackage);
		CaPackageList&	GetPackageList(void);
		CaPackageList&	GetNotInPackageList(void);
		CaContainer&	GetFormAttachmentList(void);
		bool			AddFormAttachment(CaString szAttachmentName, int iType, bool bCompress);
		bool			RemoveFormAttachment(CaString szAttachmentName);
		bool			RemoveFormAttachment(HAROBJID iObjId);
		CaFormAttachment* GetFormAttachmentById(HAROBJID ObjId);

        // HAPI log is not static, HSDK log is static.
        static void         SetStaticLog(ostream &rLogStream); // Sets static log but not HAPI instance log
        bool                SetLog(ostream &rLogStream); // Sets static log and current HAPI instance
        static ostream&     GetLog(void);
		HINT32				SetFileAccess(LPCTSTR szFullPath, LPCTSTR szAccess);
		HINT32				Update(void);
		void				SetFileAgent( LPTSTR szRemoteMachineName = _T(""), LPTSTR szRemoteUserName = _T(""), LPTSTR szRemotePassword = _T(""), LPTSTR szClientPath = _T(""), LPTSTR szPortNumber = _T("") ); // PR# 8296 added szPortNumber
        HINT32              Delete(void);
        bool                SetName(LPCTSTR szName);

        // b. PR#5052, PR#5475
        bool            SetNotification(bool bFlag);
        LPCTSTR         GetName(void) const;
        // e. PR#5052, PR#5475

        // Operators
#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( ostream &o, const CaForm &Form );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaForm &Form );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaFormAttachment;
		friend class HSDKDLL_CLASS_DECLSPEC CaFormList;
		friend class HSDKDLL_CLASS_DECLSPEC CaFormTypeList;
}; // end class CaForm

#endif

