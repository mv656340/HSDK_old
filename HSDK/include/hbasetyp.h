
//----------------------------------------------------+-------------------------------------------------
// FILENAME:           hbasety.h
//
// DESCRIPTION:        harvest base data type
//                     This file should contain the definitions of all REAL BASIC types used by Harvest 
//                     source code. It should contain appropriate #define depending on platform
//                     This file should be modified to define the types as appropreate for each 
//                     platform.
//
// AUTHOR:             Paul Poolkasem
//
// REVISION HISTORY:
//     08-18-98        Paul File Creation
//     10-06-98        MAS  Updated for ISPF V.S.
//     29-09-04:medku01:PR 2593- Date Format Incorrect.
//     07/22/04        XY   pr3214 har521sp1 Port code to compile on SuSE8 ES (gcc3.x)
//     09-02-04  LP     PR# 2828 hco log doen't output in append mode to the log file
//     09-20-04 yu$xi01 pr#3450 solaris build upgrade to CC5.5 and stlport4
//     10-04-04  LS     PR# 3450 ifdef include for Redhat
// PR# 3450 11-11-04, neewi01,  USS (MVS) build upgrade to V1R4 compiler and STLport-4.6.2
// PR# 3400 09-01-05, alimo02, add _ttol type definition for unix
// PR# 4935 07/25/2006 wurma01  .NET 2003 upgrade
// PR 5724-3	alimo02	02-07-2007	Replace CACrypto with ETPKI
// PR 6184-3 02-26-07 faudo01   Define UNREFERENCED_PARAMETER for UNIX
// PR# 3374 09-24-2004 BSR Added _taccess definition to the list.
// PR# 6668   08-20-07  faudo01  Japanese/Korean multibyte issues
// PR# 8924   10-17-13  neewi01 Large file support.
// PR# 6668   06-11-14  vemma02	 rollback changes done for multi-byte character strings on Linux
//
// Copyright (c) 2004 Computer Associates inc. All rights reserved. 
//----------------------------------------------------+-------------------------------------------------


#ifndef _HBASETYPE_H_
#define _HBASETYPE_H_

// pr3214 har521sp1 suse8, gcc3
#if (defined(__GNUC__) && (__GNUC__>=3))
#include <iostream>
//#include <algorithm>
#include<string.h>//bhanu
#if !defined(LINUX64) || !defined(T_I86_64_LINUX24) || !defined(T_IA64_DARWIN)//bhanu
#include <iterator>
#endif

// PR3450
#if defined(RHEL_AS3) || defined(LINUX64)
#include <ext/slist>
#elif (defined(__GNUC__) && (__GNUC__>=3))
#include <ext/slist>
#else
#include <slist>
#endif
// PR3450 end
#elif defined(_MSC_VER) && (_MSC_VER >= 1300) //PR#4935
#include <algorithm>
#include <iostream>
#else
#include <iostream.h>
#endif

#include <stdio.h>
#if !defined(__APPLE__)
#include <stdarg.h>
#endif
//pr#3450, yu$xi01, 9/20/04, solaris build upgrade to CC5.5 and stlport4 
#if (__SUNPRO_CC >= 0x500) || (defined(_MSC_VER) && (_MSC_VER >= 1300)) //PR#4935

#include <string.h>
#include <stdlib.h>
#endif
//end pr#3450

#if defined(__HHW_370__)      // IBM/C Compiler
#define CBLINKAGE extern "C"
#else
#define CBLINKAGE static
#endif

//define the null object so ALL other classes have access to it
#define NULL_OBJECT(aType)  (*((aType *)NULL))


#if defined(WIN32)

#include <winsock2.h>   // PR6372 - winsock2 must come before windows.h
#include <windows.h>
#include <tchar.h>

// With windows either import or export unless testing statically
#ifdef  _HUNIT_TEST_LIB     // Class unit tests link to a static lib without dll exports 
#define HDLLEXPORT
#define HDLLIMPORT
#else
#define HDLLEXPORT __declspec(dllexport)
#define HDLLIMPORT __declspec(dllimport)
#endif


#else
  //
  // NON WINDOWS PLATFORM DEFINITION
  //
typedef char            TCHAR;
typedef int             BOOL;
typedef char *          LPTSTR;
typedef const char *    LPCTSTR;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define __cdecl

#define _T(s)           s
#define _tprintf        printf
#define _stprintf       sprintf
#define _vstprintf      vsprintf
#define _stscanf        sscanf
#define _tcscmp         strcmp
#define _tcsicmp        stricmp         // case insensitive comparison
#define _tcsncmp        strncmp
#define _tcscat         strcat
#define _tcscpy         strcpy
#define _tcsncpy        strncpy
#define _tcschr         strchr
#define _tcsncat        strncat
#define _tcsrchr        strrchr
#define _tcsdup         strdup
#define _tcsupr         strupr          // For Unix and MVS, it is in hstring.cpp
#define _tcslwr         strlwr          // For Unix and MVS, it is in hstring.cpp
#define _tcstok         strtok
#define _ttoi           atoi
#define _ttol           atol			//PR#3400 - alimo02
#define _itot           itoa
#define _stscanf        sscanf
#define _tcslen         strlen          // map to strlen in MBCS, counts number of bytes
#define _tcsclen        strlen          // map to _mbstlen in MBCS, counts number of char
#define _tcsftime       strftime
#define _tcsnccmp       strncmp
#define _tcsstr         strstr

//pr# 2828
#define _tsetlocale     setlocale
//end of pr#2828
#define _tgetenv        getenv
#define _istalpha       isalpha
#define _istspace       isspace
#define _istprint       isprint
#define _istalnum       isalnum
#define _istdigit       isdigit
#define _istlower       islower
#define _istupper       isupper  
// Dir I/O
#define _trmdir         rmdir           // UNIX mkdir takes 2 params but Win32 _mkdir takes only one

// File I/O
#define _tfopen         fopen
#define _tgetcwd        getcwd
#define _tremove        remove
#define _trename        rename
#define _tchmod         chmod
#define _tutime         utime
#define _tchdir         chdir
#define _fgetts         fgets
#define _fgettc         fgetc
#define _fputts         fputs
#define _putts          puts
#define _getts          gets
#define _ftprintf       fprintf
#define _vftprintf      vfprintf
#define _ttempnam       tempnam
#define _tsystem        system

// Functions to Get and Set the local settings, on the current system.
// Pr 2593: Defines _tsetlocale to setlocale.
// #define _tsetlocale     setlocale // done by 2828.- identified during merge.
//PR#3377
//this function is used to check whether the user has write access or not.
#define _taccess access
//end of PR#3377

#define HDLLEXPORT
#define HDLLIMPORT

#endif

#ifdef  _HEXPORT // Exporting classes from a DLL (Win32)
#define HDLL_CLASS_DECLSPEC HDLLEXPORT
#else               // Using classes in application, another DLL or Non-Windows platform
#define HDLL_CLASS_DECLSPEC HDLLIMPORT
#endif // end exporting

// Define integer

typedef int             HINT32;
typedef HINT32 *        LPHINT32;
typedef HINT32 &        RHINT32;


// PR# 8924   10-17-13  neewi01 Large file support.
#if defined WIN32

typedef __int64            HINT64;
typedef unsigned __int64   HUINT64;

#elif defined(_AIX) || defined(__HHW_370__)

typedef long long	         HINT64;
typedef unsigned long long	HUINT64;

#elif defined(__sun)

typedef longlong_t         HINT64;
typedef u_longlong_t       HUINT64;






#elif defined(__GNUC__)|| defined(__s390__) || defined(__hpux)

typedef long long          HINT64;
typedef unsigned long long HUINT64;

#endif 



// Define unsigned integer

typedef unsigned int    HUINT32;
typedef HUINT32 *       LPHUINT32;
typedef HUINT32 &       RHUINT32;

// PR6184 - change from huint32 to int
typedef HINT32         HAROBJID; // Harvest Object Id from Harvest Repository

// PR 5724-3 - enable etpki on z/OS
// Definitions for encryption.
#if defined (__digital__) || defined(__sgi)
#define NO_CA_CRYPT
#endif

#if defined (NO_CA_CRYPT)
 // Copied right out of the catypes.h file
#define _signed		signed
typedef unsigned char 	CRBYTE, 	*LPCRBYTE;
typedef unsigned short 	CRWORD, 	*LPCRWORD;
typedef unsigned long 	CRDWORD,	*LPCRDWORD;
typedef void			CRVOID,		*LPCRVOID;
typedef LPCRVOID	 	CRHANDLE,	*LPCRHANDLE;
typedef CRHANDLE	 	CRHKEY, 	*LPCRHKEY;
typedef CRDWORD			CRALGID, 	*LPCRALGID;
typedef unsigned char 	CRAUID[64];
typedef CRAUID 			*LPCRAUID;
typedef _signed long	CRSTATUS,	*LPCRSTATUS;
typedef CRBYTE			CRBOOL,		*LPCRBOOL;
#ifdef UNIX
typedef char 			CRTCHAR, 	*LPCRTCHAR;
#else
typedef unsigned char 	CRTCHAR, 	*LPCRTCHAR;
#endif

#endif /* NO_CA_CRYPT */
//
// bool is not built in to compilers used on MVS, Sun, and AIX
// This definition was copied from stlconfg.h
// stlconfg.h is not included so that HSDK users are not required to have STL
//
//pr#3450 neewi01, 11/8/2004, USS (MVS) build upgrade to V1R4 compiler and STLport-4.6.2
#if (defined(__HHW_370__) && (__IBMCPP__ < 41020))  // sdk not designed to work with MVS so include stlconfg.h
#include <stlconfg.h>

#else

# if defined (__IBMCPP__) && (__IBMCPP__ < 400)
#  include <isynonym.hpp>
#  typedef int bool;
# else
#  if defined(__sun)
//pr#3450, yu$xi01, 9/20/04, solaris build upgrade to CC5.5 and stlport4
#if (__SUNPRO_CC < 0x500)
     typedef int bool;
#endif
//end pr#3450

#    define true 1
#    define false 0
#  endif
#endif
#endif  // end hhw_370 define


// Define Verify
#if !defined(VERIFY)
#ifdef _DEBUG
	#define VERIFY(f)          assert(f)
#else
	#define VERIFY(f)          ((void)(f))
#endif
#endif

//PR#6184-3, n.Define this VC2005 for other platforms
#if !defined(WIN32) || (defined(_MSC_VER) && (_MSC_VER <= 1300) )
#undef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)   
#endif


#endif
