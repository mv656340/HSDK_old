//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caformatt.h
//
// DESCRIPTION:        Declares the CaFormAttachment class.
//
// REVISION HISTORY:
//     06-14-05        sevle01     File Creation - PR4850
//     01-10-09        chiji01     RTserverless agent - PR8296
//
// Copyright (c) 2005 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaFormAttachment_H)
#define CaFormAttachment_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

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
class CPtHFormAttachment;
class CPtHAgent;

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
 
class HSDKDLL_CLASS_DECLSPEC CaFormAttachment
{
    private:

        // Member Variables
		CPtHFormAttachment*		m_pHFormAttachment;		// HAPI Form Object
		static ostream* m_pLog;					        // Log Stream
		CPtHAgent *     m_aFileAgent;
		LPTSTR			m_szAgentUser;
		LPTSTR			m_szRemoteMachineName;
        LPTSTR          m_szPortNumber;                 // PR# 8296
		LPTSTR			m_szRemoteUserName;
		LPTSTR			m_szRemotePassword;
		LPTSTR			m_szClientPath;
		bool			m_bOwnsHData;

		// Private member functions
        void            Init(void);
        CaFormAttachment( const CPtHFormAttachment &rSrc );
        CaFormAttachment(void){Init();}

    public:
        // Constructors
        CaFormAttachment( const CaFormAttachment &src );
		CaFormAttachment(const CaForm &src);

        // Destructor
        virtual ~CaFormAttachment(void);

        // Public Member Functions
		bool			GetCompression(void);
		void			SetCompression(bool bCompression);
		HINT32			GetAttachmentType(void);
		void			SetAttachmentType(HINT32 iType);
		void			SetFormObjId(HINT32 ObjId);
		HINT32			GetFileSize(void);
		bool			CopyFileData(void);
		void			SetFileAgent( LPTSTR szRemoteMachineName = _T(""), LPTSTR szRemoteUserName = _T(""), LPTSTR szRemotePassword = _T(""), LPTSTR szClientPath = _T(""), LPTSTR szPortNumber = _T("") ); // PR# 8296 added szPortNumber

        // Operators
#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( ostream &o, const CaFormAttachment &FormAttachment );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaFormAttachment &FormAttachment );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaForm;


}; // end class CaForm

#endif

