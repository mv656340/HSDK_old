
// AllFusion Harvest Change Manager HSDK
// HSDK R12 FP2
// CaHarvest::GetHSDKVersion(void) returns release number of HSDK binary and should match this value

//----------------------------------------------------+-------------------------------------------------
// FILENAME:           hsdk.h
//
// DESCRIPTION:        Unified HSDK include file.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
////PR#2467    03-24-04   LU   Improve Synchronization in WSAD
//  PR# 2401    06-28-03   LP      API return no file size
//  PR# 3450    11-16-04   XY      AIX build upgrade to XL C++ 7.0
//  PR# 4850    08-15-05   LS      Add form header files
//  PR# 5052    11-07-05   LS      Add notification attributes
//  PR# 4850    12-17-05   LS      Add form list/form type list header file
//  PR# 5368    01-03-06   LS      Add keys for GetProductInfo()
//  PR# 5433    01-11-06   LS      Add keys for form history.
//  PR# 5475    01-26-06   LS      Add key for notification, remove duplicate key
//  PR# 5689    03-23-06   LS      Add keys for package approval report
//  PR# 5123	 07-05-06 k$$ra02 Suport for Locked/Unlocked user Accounts
//  PR# 2384    06-10-06 k$$ra02 HSDK:Single Workstation Login
//  PR# 4760    07-05-06 k$$ra02 Suport for Enable/Disable user Account.
//  pr# 5923    07/27/06 lawph01 ENHANCEMENT TO GET PACKAGEOBJID IN CACREATEPACKAGE IN HSDK
//  PR# 5253  10-July-2006  k$$ra02  HSDK:Mixed Mode Authentication
//  PR# 4664    01-03-07 faudo01 Add refactoring processes
//
// Copyright (c) 2004-2007 Computer Associates inc. All rights reserved. 
//
//----------------------------------------------------+-------------------------------------------------


#ifndef HSDK_H
#define HSDK_H


#if (defined(_AIX) && (__IBMCPP__>=600))
using namespace std;
#endif
//  FORWARD DECLARATIONS:
//------------------------------------------------------+-----------------------------------------------

//  INCLUDE STATEMENTS FOR HUTILS:
//------------------------------------------------------+-----------------------------------------------
#include <hobjtype.h>
#include <tconst.h>


//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#define NULL_HAROBJID       -1
#define HLOADNOW            1
#define HCLEAN              4

// Linkage
#if defined(WIN32)
#define HDLLEXPORT __declspec(dllexport)
#define HDLLIMPORT __declspec(dllimport)
#else
#define HDLLEXPORT
#define HDLLIMPORT
#endif

#ifdef  _HSDKEXPORT // Exporting classes from a DLL (Win32)
#define HSDKDLL_CLASS_DECLSPEC HDLLEXPORT
#else               // Using classes in application, another DLL or Non-Windows platform
#define HSDKDLL_CLASS_DECLSPEC HDLLIMPORT
#endif // end exporting

//  Object Attribute Container Key Definitions:
//------------------------------------------------------+-----------------------------------------------

//  Projects, States, Forms, and Packages
#define CA_ATTRKEY_NAME         _T("CA_ATTRKEY_NAME")    // This Object Name
#define CA_ATTRKEY_OBJID        _T("CA_ATTRKEY_OBJID")   // This Object Id

#define CA_ATTRKEY_CREATORID    _T("CA_ATTRKEY_CREATORID")      
#define CA_ATTRKEY_CREATOR_NAME _T("CA_ATTRKEY_CREATOR_NAME")   
#define CA_ATTRKEY_CREATION_TIME  _T("CA_ATTRKEY_CREATION_TIME")  
#define CA_ATTRKEY_MODIFIERID   _T("CA_ATTRKEY_MODIFIERID")   
#define CA_ATTRKEY_MODIFIER_NAME  _T("CA_ATTRKEY_MODIFIER_NAME") 
#define CA_ATTRKEY_MODIFIED_TIME  _T("CA_ATTRKEY_MODIFIED_TIME") 

// States, Processes, and Packages
//pr# 5923
#define CA_ATTRKEY_PROJECTNAME    _T("CA_ATTRKEY_PROJECTNAME")
//end of pr# 5923  
#define CA_ATTRKEY_PROJECTID    _T("CA_ATTRKEY_PROJECTID") 
#define CA_ATTRKEY_ISACTIVE		_T("CA_ATTRKEY_ISACTIVE")

// Processes, and Packages
//pr# 5923
#define CA_ATTRKEY_STATENAME     _T("CA_ATTRKEY_STATENAME") 
//end of pr# 5923
#define CA_ATTRKEY_STATEID      _T("CA_ATTRKEY_STATEID") 

//  Process Objects
#define CA_ATTRKEY_PROCTYPE     _T("CA_ATTRKEY_PROCTYPE")// Process Type - string representation
#define CA_ATTRKEY_EXECUTEACCESS _T("CA_ATTRKEY_EXECUTEACCESS") // Has execute access for process. 
                                                                // 1 if true, 0 if false.

//  User Objects
#define CA_ATTRKEY_REALNAME     _T("CA_ATTRKEY_REALNAME")// Full name
#define CA_ATTRKEY_EMAIL        _T("CA_ATTRKEY_EMAIL")   // Email Address
#define CA_ATTRKEY_ACCOUNTEXTERNAL	_T("CA_ATTRKEY_ACCOUNTEXTERNAL") //PR#5253 – Mixed Mode Authentication

#define CA_ATTRKEY_SWLOGIN	   _T("CA_ATTRKEY_SWLOGIN") //// PR#2384   HSDK:Single Workstation Login

//  Package Objects
#define CA_ATTRKEY_ASSIGNEEID   _T("CA_ATTRKEY_ASSIGNEEID")// Assignee Id
#define CA_ATTRKEY_ASSIGNEE_NAME  _T("CA_ATTRKEY_ASSIGNEE_NAME") // Assignee Name
#define CA_ATTRKEY_PRIORITY     _T("CA_ATTRKEY_PRIORITY") // Package Priority

//  State Objects
#define CA_ATTRKEY_SNAPSHOT     _T("CA_ATTRKEY_SNAPSHOT") // Is Snapshot 1 if true, 0 if false
#define CA_ATTRKEY_VIEWID       _T("CA_ATTRKEY_VIEWID")     // View Id
#define CA_ATTRKEY_VIEW_NAME    _T("CA_ATTRKEY_VIEW_NAME") // View Name

//  View Objects
#define CA_ATTRKEY_VIEW_TYPE    _T("CA_ATTRKEY_VIEW_TYPE") // View Type

#define CA_ATTRKEY_ACCOUNTLOCKED	_T("CA_ATTRKEY_ACCOUNTLOCKED") // PR# 5123
#define CA_ATTRKEY_ACCOUNTDISABLED  _T("CA_ATTRKEY_ACCOUNTDISABLED")  //4760


//  Version Objects
#define CA_ATTRKEY_PACKAGEID            _T("CA_ATTRKEY_PACKAGEID") 
#define CA_ATTRKEY_ITEMID               _T("CA_ATTRKEY_ITEMID") 
#define CA_ATTRKEY_ITEM_TYPE            _T("CA_ATTRKEY_ITEM_TYPE") 
#define CA_ATTRKEY_PARENT_VERSIONID     _T("CA_ATTRKEY_PARENT_VERSIONID")
#define CA_ATTRKEY_MERGED_VERSIONID     _T("CA_ATTRKEY_MERGED_VERSIONID") 
#define CA_ATTRKEY_MAPPED_VERSION_NAME  _T("CA_ATTRKEY_MAPPED_VERSION_NAME") 
#define CA_ATTRKEY_VERSION_STATUS       _T("CA_ATTRKEY_VERSION_STATUS") 
#define CA_ATTRKEY_PACKAGE_NAME         _T("CA_ATTRKEY_PACKAGE_NAME") 
#define CA_ATTRKEY_FULL_PATH_NAME       _T("CA_ATTRKEY_FULL_PATH_NAME") 
#define CA_ATTRKEY_CLIENT_MACHINE       _T("CA_ATTRKEY_CLIENT_MACHINE") 
#define CA_ATTRKEY_CLIENT_PATH          _T("CA_ATTRKEY_CLIENT_PATH") 
#define CA_ATTRKEY_DESCRIPTION          _T("CA_ATTRKEY_DESCRIPTION")
//pr# 2401
#define CA_ATTRKEY_VERSIONDATASIZE      _T("CA_ATTRKEY_VERSIONDATASIZE")
//end of pr# 2401

//PR# 2467
#define CA_ATTRKEY_FULL_NAME       _T("CA_ATTRKEY_FULL_NAME") 

//  Utility
#define CA_ATTRKEY_VIEWID  _T("CA_ATTRKEY_VIEWID") 

//  Form Objects
#define CA_ATTRKEY_FORMTYPENAME         _T("CA_ATTRKEY_FORMTYPENAME")
#define CA_ATTRKEY_FORMTYPEOBJID        _T("CA_ATTRKEY_FORMTYPEOBJID")

// b. PR#5052
#define CA_ATTRKEY_FROM_ENVNAME     _T("CA_ATTRKEY_FROM_ENVNAME")
#define CA_ATTRKEY_FROM_STATENAME   _T("CA_ATTRKEY_FROM_STATENAME")
#define CA_ATTRKEY_TO_ENVNAME       _T("CA_ATTRKEY_TO_ENVNAME")
#define CA_ATTRKEY_TO_STATENAME     _T("CA_ATTRKEY_TO_STATENAME")
#define CA_ATTRKEY_PACKAGEOBJID     _T("CA_ATTRKEY_PACKAGEOBJID")
#define CA_ATTRKEY_OPERATION        _T("CA_ATTRKEY_OPERATION")
#define CA_ATTRKEY_USERNAME         _T("CA_ATTRKEY_USERNAME")
#define CA_ATTRKEY_NAME             _T("CA_ATTRKEY_NAME")
#define CA_ATTRKEY_BROKERNAME       _T("CA_ATTRKEY_BROKERNAME")
#define CA_ATTRKEY_FORMNAME         _T("CA_ATTRKEY_FORMNAME")
#define CA_ATTRKEY_FORMOBJID        _T("CA_ATTRKEY_FORMOBJID")
// e. PR#5052

// b. PR#5368
#define CA_ATTRKEY_CLIENT_VERSION   _T("CA_ATTRKEY_CLIENT_VERSION")
#define CA_ATTRKEY_CLIENT_BUILD     _T("CA_ATTRKEY_CLIENT_BUILD")
#define CA_ATTRKEY_CLIENT_PATCH     _T("CA_ATTRKEY_CLIENT_PATCH")
// e. PR#5368

// b. PR#5433
#define CA_ATTRKEY_EXECDTIME        _T("CA_ATTRKEY_EXECDTIME")
#define CA_ATTRKEY_ACTION           _T("CA_ATTRKEY_ACTION")
// e. PR#5433

// b. PR#5475
#define CA_ATTRKEY_USEROBJID        _T("CA_ATTRKEY_USEROBJID")
// e. PR#5475

// b. PR#5689
#define CA_ATTRKEY_PROCESSOBJID     _T("CA_ATTRKEY_PROCESSOBJID")
#define CA_ATTRKEY_NOTE             _T("NOTE") // matches JHSDK definition
#define CA_ATTRKEY_USERGROUPNAME    _T("CA_ATTRKEY_USERGROUPNAME")
#define CA_ATTRKEY_USERGROUPOBJID   _T("CA_ATTRKEY_USERGROUPOBJID")
#define CA_ATTRKEY_PROCESSNAME      _T("CA_ATTRKEY_PROCESSNAME")
// e. PR#5689

#if (defined(_AIX) && (__IBMCPP__>=600)) || defined(T_I86_64_LINUX24) || (__APPLE__) || (defined(__linux__)&& defined(__i386__)) || defined(__s390__)
//PRE-DECRALATION of CLASS SYMBOLS

class CaPackageChooser;
class CaVersionChooser;

#endif

//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include "castring.h"
#include "castringlist.h"
#include "cablob.h"
#include "catimestamp.h"
#include "cadata.h"
#include "cadataarray.h"
#include "cacontainer.h"
#include "hsdkerrkey.h"
#include "caexception.h"
#include "cacheckout.h"
#include "cacheckin.h"
#include "cacreatepkg.h"
#include "cadelver.h"
#include "caversion.h"
#include "caversionlist.h"
#include "caitem.h"
#include "caitemlist.h"
#include "capackage.h"
#include "capackagelist.h"
#include "caremitem.h"
#include "carenitem.h"
#include "caapprove.h"
#include "capromote.h"
#include "cademote.h"
#include "caconmrg.h"
#include "caintmrg.h"
#include "catakess.h"
#include "caudp.h"

//PR#4664, b.Add refactoring processes
#include "camvitem.h"
#include "camvpath.h"
#include "carempath.h"
#include "carenpath.h"
#include "cadelpkg.h"

//PR#4664, e.Add refactoring processes
#include "casql.h"
#include "caxproj.h"
#include "caswpkg.h"
#include "camvpkg.h"
#include "calistver.h"
#include "caformtype.h"
#include "caform.h"
#include "caformatt.h"
#include "cacontext.h"
#include "capkgchsr.h"
#include "caverchsr.h"
#include "caharvest.h"
#include "casignaturerec.h"
#include "caformlist.h"
#include "caformtypelist.h"
//Add for vidiff
#include "cavisdiff.h"


#endif
