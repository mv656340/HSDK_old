//------------------------------------------------------+-----------------------------------------------
// FILENAME:           cadata.h
//
// DESCRIPTION:        Declares the CaData class.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     06-18-01        MAS     File Creation
//     07/27/04        lisla01 pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     08/15/05        LS      PR4850 - new constructor, = operator for form changes
//
//
// Copyright (c) 2001 Computer Associates inc. All rights reserved. 
//
//
//------------------------------------------------------+-----------------------------------------------

#if !defined(CaData_H)
#define CaData_H

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------
class CPtHData;
class CPtHDataArray;

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//------------------------------------------------------+-----------------------------------------------
//  CLASS:  CaData
//
//  DESCRIPTION:
//      CaData is the HSDK class that encapsulates the Harvest CPtHData class.
//
//  NOTES:
//      1) This is required to remove the HSDK need for STL.
//
//------------------------------------------------------+-----------------------------------------------
 
class HSDKDLL_CLASS_DECLSPEC CaData 
{
    private:

        // Member Variables
        CPtHData*	    m_pHData;					    // HUtilities Data Object
        bool            m_bOwnsHData;                   // Can delete HData when destroyed
        bool            m_bIndirect;                    // CPtHData object not in this object
        CPtHDataArray*  m_pHDataArray;                  // Located in this data array    
        HINT32          m_iIndex;                       // Index into CPtHDataArray for object
        CaBlob*         m_pBlob;                        // Pointer to CaBlob if type is blob
        CaTimeStamp*    m_pTimeStamp;                   // Pointer to CaTimeStamp if type is TimeStamp

	    // Private member functions
        CaData(CPtHDataArray* pDataArray, HINT32 iIndex); // The HData object's location
        CaData(CPtHData& pData); // PR4850
        void Init(void);
        void SetIndirect(bool bFlag);
        CPtHData* GetHData(void) const;
        bool SetTimeStamp(void);
        bool SetBlob(void);

    public:
        enum	Types { NO_TYPE = 0, INTEGER, STRING, BLOB, TIMESTAMP };

        // Constructors
        CaData(void);
        CaData( const CaData &rSrc );
        CaData(HINT32 nInt);
        CaData(LPCTSTR szString);
        CaData(const CaBlob& rBlob);

        // Destructor
        virtual ~CaData(void);

        // Public Member Functions
        CaData::Types GetType(void) const;
        bool		  IsNull(void) const;
        void          SetNull(void);


        // Public Inline Functions
		
        // Operators
        CaData&       operator=( const CaData& aData );
        CaData&       operator=( HINT32 nValue );
        CaData&       operator=( LPCTSTR szValue );
        CaData&       operator=( const CaBlob& rBlob );
        CaData&       operator=( const CPtHBlob& rBlob );
        CaData&       operator=( const CPtHData& rData ); // PR4850
        CaData&       operator=( const CaTimeStamp& rTimeStamp );
        CaData&       operator=( const CPtHTimeStamp& rTimeStamp );
        bool          operator<( const CaData& rSrc ) const;
        bool          operator!=( const CaData& rSrc ) const;
        bool          operator==( const CaData& rSrc ) const;
				      operator HINT32() const;
                      operator LPCTSTR() const;
                      operator CaString() const;
                      operator CaBlob&() const;
                      operator CaTimeStamp&() const;
#if (defined(__GNUC__) && (__GNUC__>=3))
	// pr3214 har521sp1 suse8, gcc3-- lisla01 ostream in std namespace
        friend HSDKDLL_CLASS_DECLSPEC std::ostream & operator<<( std::ostream &o, const CaData& d);
#else
        friend HSDKDLL_CLASS_DECLSPEC ostream & operator<<( ostream &o, const CaData& d);
#endif

		friend class HSDKDLL_CLASS_DECLSPEC CaDataArray;
		friend class HSDKDLL_CLASS_DECLSPEC CaContainer;
        friend class HSDKDLL_CLASS_DECLSPEC CaForm;
        friend class HSDKDLL_CLASS_DECLSPEC CaFormType;

}; // end class CaData

#endif

