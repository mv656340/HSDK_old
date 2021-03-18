//------------------------------------------------------+-----------------------------------------------
// FILENAME:           caapprove.h
//
// DESCRIPTION:        Declares the CaApprove class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaApprove_H)
#define CaApprove_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "hsdk.h"

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHApprove;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaApprove
//
//  DESCRIPTION:
//      CaApprove is the HSDK class that represents the Harvest Approve object.
//
//  NOTES:
//      1) None.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaApprove 
{
    private:

        // Member Variables
		CPtHApprove*	m_pHApprove;					// Hapi Approve Object
		bool	        m_bApprove;					    // Approve or Reject
        CaString        m_szDescription;                // Approve/Reject Comment
		CaHarvest*		m_pCaHarvest;					// HSDK Harvest pointer
     
		// Private member functions
        void            Init( void );
        CaApprove(CaHarvest& rHarvest);								// Can only be created by CaContext

    public:
        // Constructors

        // Destructor
        virtual ~CaApprove(void);

        // Public Member Functions
        HINT32              Execute(void);

        // Public Inline Functions
        void                SetApprove(bool bFlag=true) {m_bApprove = bFlag;}
        void                SetDescription(LPCTSTR szDescription) {m_szDescription = szDescription;}
        bool                GetApprove(void) const {return m_bApprove;}
        LPCTSTR             GetDescription(void) const {return m_szDescription;}
		
        // Operators
        operator bool (void) const { return (this!=NULL); }  // Is This a valid object?

#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaApprove &Context );
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaApprove &Context );
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaPackageChooser;
		friend class HSDKDLL_CLASS_DECLSPEC CaContext;

}; // end class CaApprove

#endif

