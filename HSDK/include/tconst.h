 //----------------------------------------------------+-------------------------------------------------																																																									
// FILENAME:           tconst.h																																																									
//																																																									
// DESCRIPTION:        Declares constant values shared accross Harvest layers.																																																									
//																																																									
// REVISION HISTORY:																																																									
// PR# 633:	02-05-02	YN	Load Repository changes file access permission																																																									
//     04-04-02        MAS     Added Password Policy																																																									
// PR# 1785 07-10-03   MAS     Add CLIENTPATH and VIEWPATH system variables																																																									
// PR#  2379    LP  11-13-03    Switch to enforce server & client to be at same patch level 																																																									
// PR# 2065 04-27-04        Per/Post Link UDP Being Called Several Times by Hco Command																																																									
// PR# 2997 05-18-04   DY   LATEST_IN_PACKAGE/ALL_IN_PACKAGE missing in HSDK.																																																									
// PR# 4490 04-05-05   YU	Add log file formated header to hserver log file																																																									
// PR# 4443 04-13-05   LP   HChgtype fails on item																																																			
// PR# 4660 06-14-05   medku01 New System Variable Mode																																																				
// PR#4997 09-07-05    lanad02 Change to 7.1 from 7.01																																																								
// PR# 3400 07-05-05 faudo01 Add constants for the CCaAuthServer and the derived class																																																			
//                           CCaLDAPAuthServer																																																				
// PR# 3400 07-06-05 azana01 Add constants utilized in HServer transactions																																																							
// PR# 3400 07-27-05 azana01 Add constants utilized by the Broker																																																							
// PR# 3400 09-17-05 faudo01 Add LDAPS encryption mode constant																																																			
// PR# 4930 09-21-05 chiji01 Firewall friendly for direct connect																																																			
// PR# 3400 10-18-05 azana01 Removed Authentication Directory Type and LDAP Version																																																		
// PR# 3400 10-18-05 azana01 Added LDAP Debug Level																																															
																					
// PR# 4975 11-08-05 lanad02 VCI N tag only																																															
// PR# 5253 12-09-05 azana01 Added functionality to support mixed authentication mode 																										
// PR# 2480 05-19-06 faudo01 Database for Release 12 (Sigma)														
// PR# 2384 06-06-06 faudo01 Single Workstation Login													
// PR# 4760 06-07-06 k$$ra02 Suport for enable/disbale user account													
// PR# 5123 06-08-06 k$$ra02 Lock/unlock user account													
// PR# 5782 06-12-06 ni$ya01 Process type filter													
// PR# 4664 04-28-06 neewi01 Refactoring									
// PR# 5819 09-20-06 faudo01 Add ACCESS enum value									
// PR# 4664 09-20-06 wurma01 Refactoring					
// PR# 4664 10-30-06 bersa02 hsync - compatibility with item/path refactoring support					
// PR# 5877 10-04-06 faudo01 Add contants for Auditing Phase One					
// PR# 5878 10-25-06 neewi01 Shared Item Management					
// PR# 5782 01-03-07 faudo01 Adjust enumeration name					
// PR# 6222 02-16-07 bersa02 Rebrand HCORE, HDATA, HINFST
// PR# 5726 03-10-07 alimo02 External user group support
// PR# 6222 03-04-07 bersa02 Make HCORE-HDATA-HINFST compatible with re-branded installation
// PR# 6348 05-15-07 faudo01 Add constant used to set HARUSER.ENCRYPTPSSWD.
// PR# 6382 09-11-07 faudo01 Expose VCIBinding Corrections changes in HAPI																																																															
// PR# 6911 10-18-07 polve01 External User group support
// PR# 7808 04-25-08 polve01 ADMIN UI FORCE PASSWORD CHANGE
// PR# 8485 11/08/09 faudo01 System Variables Cross Project Merge
// PR# 8714 06/29/11 khasu03 Find Empty Package
//
// Copyright (c) 2002-2007 CA. All rights reserved. 																																																																																																																	
//----------------------------------------------------+-------------------------------------------------																																																									
																																																									
#if !defined(_TCONST)																																																									
#define _TCONST																																																									
								
					
		
#define HAR_PRODUCT_NAME  _T("CA Harvest SCM")	
// Harvest client and server version must match
//Defect 1565 - changes Deffered																																																						
//#define HAR_PRODUCT_VERSION  _T("12.1.1")	
#define HAR_PRODUCT_VERSION  _T("14.0.0")	

// PR# 8924 - Large File Support
#define HAR_PRODUCT_VERSION2        140000
#define HAR_PRODUCT_VERSION_LARGE_FILE_SUPPORT  120600	//tadje01: When you rebrand don't change this constant value. 
																																																									
//Defect 1565 - changes Deffered - End																																																								
#define HAR_PRODUCT_BUILD    _T(".369")
																																																			
// PR5009 - MDB Server to database connection must use MDB version (reverse compat)																																																			
//Defect 1565 - changes Deffered	
//#define HAR_DB_VERSION	120101
//#define HAR_DB_VERSION	120001			
// R12.1 SP2
//#define HAR_DB_VERSION	120102
// R12.1 SP3
//#define HAR_DB_VERSION	120103

#define HAR_DB_VERSION	140000
// R12.5
//#define HAR_DB_VERSION	120500
// R12.6
//#define HAR_DB_VERSION	131000
//Defect 1565 - changes Deffered - End
#define HAR_MDB_VERSION	30																																																			
																																																									
//pr# 2379 : Add define for Product patch																																																									
#define HAR_PRODUCT_PATCH    _T("0")																																																									
//end of pr#2379																																																									

//PR#4490																																																									
#define HAR_SERVER_LOG_FILE_HEADER _T("---------------------------------------------\n")																																																									
// PR 6222 Rebrand server log				
//#define HAR_SERVER_COMPONENT_NAME _T(" AllFusion Harvest Change Manager Server %s\n")																																																									
#define HAR_SERVER_COMPONENT_NAME  _T("     CA Harvest SCM Server %s\n")																																																									
#define HAR_AGENT_COMPONENT_NAME  _T("     CA Harvest SCM Agent %s\n")	
#define HAR_CLIENT_COMPONENT_NAME  _T("     CA Harvest SCM Client %s\n")
#define HAR_BROKER_SERVICE_NAME  _T("CA Harvest SCM Broker Service")
#define HAR_SERVER_SYNCHRONIZE_SERVICE_NAME  _T("CA Harvest SCM Synchronize Service")
#define HAR_AGENT_SERVICE_NAME _T("CA Harvest SCM Agent Service")

// PR 6222 Installs have been rebranded			
#define INSTALLREBRAND true				
// PR# 4930																																																			
#if defined(WIN32)																																																			
// PR 6222 Rebrand registry key				
#if defined(INSTALLREBRAND)					
#define REGKEY_AGENTCONNECTION _T("Software\\ComputerAssociates\\Software Change Manager\\12.1\\AgentConnection")																																																			
#define REGKEY_PRODUCT _T("Software\\ComputerAssociates\\Software Change Manager\\12.1")				
#else				
#define REGKEY_AGENTCONNECTION "Software\\ComputerAssociates\\AllFusion Harvest Change Manager\\AgentConnection"																																																			
#define REGKEY_PRODUCT _T("Software\\ComputerAssociates\\AllFusion Harvest Change Manager")				
#endif				
#endif																																																			
// END PR# 4930					
				
// PR 6222 - Define home directory environment variables here				
#if defined(INSTALLREBRAND)				
#define INSTALL_HOMEENV	    _T("CA_SCM_HOME")				
#define LOCAL_HOMEENV	    _T("CA_SCM_LOCALHOME")				
#else				
#define INSTALL_HOMEENV	    _T("HARVESTHOME")				
#define LOCAL_HOMEENV	    _T("LOCALHARVESTHOME")				
#endif				
				
// Harvest's default user and usergroups																																																									
const HINT32 HARVEST_ADM_GRPOBJID=1; 																																																									
const HINT32 HARVEST_PUBLIC_GRPOBJID=2; 																																																									
const HINT32 HARVEST_USROBJID=1;																																																									

																																																		
// SETTINGS FOR EMPTY ITEM PATH																																																									
enum EmptyPathModes																																																									
{																																																									
	FUTURE_BASELINE = 1,																																																									
	CURRENT_PROJECT = 2,																																																									
	ALL_BASELINE																																																									
};																																																									
																																																									
// PR# 633	Add one const for HAR_LOAD_REPOSITORY																																																									
const HINT32 HAR_LOAD_REPOSITORY=10;																																																									
																																																									
// needed for checkin and checkout																																																									
enum MVSFileTypes																																																									
{																																																									
  HAR_MVS_PDS             = 1,																																																									
  HAR_MVS_SEQUENTIAL      = 2,																																																									
  HAR_MVSFileTypes_COUNT																																																									
};																																																									
																																																									
enum MVSFileMappingTypes																																																									
{																																																									
  HAR_MVS_MAPPING       	= 1,																																																									
  HAR_DIR_MAPPING               = 2,																																																									
  HAR_MVSFileMappingTypes_COUNT																																																									
};																																																									
																																																									
// enums needed for checkin																																																									
enum checkinModes																																																									
{																																																									
  HAR_UPDATE_AND_RELEASE 	= 0,																																																									
  HAR_UPDATE_AND_KEEP		= 1,																																																									
  HAR_RELEASE_ONLY		    = 2,																																																									
  HAR_CHECKIN_WITHOUT_CHECKOUT  = 3,																																																									
  HAR_KEEP = 4,																																																									
  HAR_checkinModes_COUNT																																																									
};																																																									
//PR#4664								
enum ProcessRefactorModes								
{ 								
	REFACTOR_UPDATE          = HAR_UPDATE_AND_RELEASE, 								
	REFACTOR_KEEP            = HAR_KEEP, 								
	REFACTOR_UPDATE_AND_KEEP = HAR_UPDATE_AND_KEEP								
};								
// end of PR#4664								
																																																								
enum checkinFilters																																																									
{																																																									
  CI_FILTER_NEW_OR_EXISTING_ITEMS = 0,																																																									
  CI_FILTER_NEW_ITEMS_ONLY        = 1,																																																									
  CI_FILTER_EXISTING_ITEMS_ONLY   = 2,
  CI_FILTER_NEW_FIRST_OR_EXISTING_ITEMS = 3,
  CI_FILTER_checkinFilters_COUNT   																																																									
};																																																									
																																																									
enum checkinSetPathOptions																																																									
{																																																									
  CI_OPTION_PRESERVE_DIR		= 0,																																																									
  CI_OPTION_PRESERVE_AND_CREATE_PATH    = 1,																																																									
  CI_OPTION_ALL_FILE_TO_SAME_PATH 	= 2,																																																									
  CI_OPTION_checkinSetPathOptions_COUNT																																																									
};																																																									
																																																									
// enum needed for checkout																																																									
enum checkoutModes																																																									
{																																																									
  CO_MODE_BROWSE		= 1,																																																									
  CO_MODE_UPDATE		= 2,																																																									
  CO_MODE_RESERVE_ONLY	        = 3,																																																									
  CO_MODE_SYNCHRONIZE	        = 4,																																																									
  CO_MODE_CONCURRENT	        = 5,																																																									
  CO_MODE_checkoutModes_COUNT																																																									
};																																																									
																																																									
enum checkoutTagFilter
{																																																									
  	CO_TAG_FILTER_RESERVED = 1,																																																									
	CO_TAG_FILTER_MERGED = 2,																																																									
	CO_TAG_FILTER_DELETED	= 4,
	CO_TAG_FILTER_ALL_TAGS	= 7		
  																																																						
};					
																																																									
enum checkoutSetPathOptions																																																									
{																																																									
  CO_OPTION_PRESERVE		         = 1,																																																									
  CO_OPTION_PRESERVE_AND_CREATE          = 2,																																																									
  CO_OPTION_ALL_ITEM_TO_SAME_DIRECTORY   = 3,																																																									
  CO_OPTION_checkoutSetPathOptions_COUNT																																																									
};																																																									
																																																									
enum serverSyncOptions
{
	SERVER_SYNC_ALL_ITEMS        = 0,
	SERVER_SYNC_CLIENT_ITEMONLY  = 1

};

enum serverAtomicCommitOptions
{
	ATOMIC_COMMIT_OPTION_OFF = 0,
	ATOMIC_COMMIT_OPTION_CLIENT = 1,
	ATOMIC_COMMIT_OPTION_ON = 2
};

// Text file extension options for repositories																																																									
enum repTextFileExtensionOptions																																																									
{																																																									
  REP_NO_TEXT_FILE_EXTENSION_DEFINITION         = 0,																																																									
  REP_GLOBAL_TEXT_FILE_EXTENSION_DEFINITION     = 1,																																																									
  REP_REPOSITORY_TEXT_FILE_EXTENSION_DEFINITION = 2,																																																									
  REP_OPTION_repTextFileExtensionOptions_COUNT																																																									
};																																									
																																																									
enum approveStatusFilters																																																									
{																																																									
	APPROVE_STATUS_APPROVED			= 0,																																																									
	APPROVE_STATUS_REJECTED			= 1,																																																									
	APPROVE_STATUS_NOT_APPROVED		= 2,																																																									
	APPROVE_STATUS_ALL				= 3,									
	// PR#5819, n.									
	APPROVE_STATUS_DISPLAY			= 4 																																																																		
};																																																									

//PR:8714
enum emptyPackageCheckFilters																																																									
{																																																									
	PACKAGE_EMPTY_ONLY				= 0,																																																									
	PACKAGE_NONEMPTY_ONLY			= 1																																																									
};	

enum repositoryAccessFilters																																																									
{																																																									
	FULL_ACCESS						= 0,																																																									
	VIEW_ACCESS_ONLY				= 1,																																																									
	NO_ADMIN_ACCESS					= 2																																																									
};																																																									
																																																									
// PR#3400 b.Add available authentication server settings																																																			
enum tAuthenticationServerSettings																																																			
{																																																			
    AUTHSERV_EDIT_PASSWORD          = 0,																																																			
    AUTHSERV_EDIT_USERNAME          = 1,																																																			
    AUTHSERV_EDIT_REALNAME          = 2,																																																			
    AUTHSERV_EDIT_PHONE             = 3,																																																			
    AUTHSERV_EDIT_EXT               = 4,																																																			
    AUTHSERV_EDIT_FAX               = 5,																																																			
    AUTHSERV_EDIT_EMAIL             = 6,																																																			
    AUTHSERV_EDIT_NOTE              = 7,																																																			
    AUTHSERV_GET_PASSPOLICY         = 8,																																																			
    AUTHSERV_EDIT_PASSPOLICY        = 9,																																																			
    AUTHSERV_AUTOCREATE_USERNAME    = 10, // on create user, allow NULL to generated a default username?																																					
													
// PR# 5253: n.Added support for mixed authentication mode																										
    AUTHSERV_EDIT_ACCOUNTEXTERNAL = 11,													
													
    AUTHSERV_EDIT_SWLOGIN         = 12, // PR# 2384													
	AUTHSERV_EDIT_ACCOUNTLOCKED   = 13, // PR# 5123 													
	AUTHSERV_EDIT_ACCOUNTDISABLED = 14, // PR# 4760														
	AUTHSERV_EDIT_FORCEPASSCHANGE = 15  //PR# 7808
//													
};   																																																			
// PR#3400 e.Add available authentication server settings																																																			

// PR#6382, b.Add available HSDK VCI Binding settings server settings																																																																																										
enum tCorrectVCIBindingSettings																																																																																										
{
    VCI_DISABLE_BINDING_CORRECTION  = 0,
    VCI_ENABLE_BINDING_CORRECTION   = 1,
    VCI_USE_HSERVER_SETTING         = 2
};
// PR#6382, e.Add available HSDK VCI Binding settings server settings																																																																																										
																																																									
// Other constansts																																																									
																																																									
const     HINT32    HARVEST_BINARY_FILE = 0;																																																									
const     HINT32    HARVEST_TEXT_FILE = 1;																																																									
const     HINT32    HARVEST_UNKNOWN_FILE = 2;																																																									
																																																									
const     HINT32    HARVEST_PATH = 0;																																																									
const     HINT32    HARVEST_ITEM = 1;																																																									
																																																									
const     HINT32    HARVEST_GLOBAL_REPOSITORY_ID = 0;																																																									
																																																									
const     HINT32    VERSION_FILTER_ITEM_MODIFIED    =    0x00000001;																																																									
const     HINT32    VERSION_FILTER_ITEM_BASELINE    =    0x00000010;																																																									
																																																									
// INGRES - version chooser addition																																																									
const     HINT32    VERSION_FILTER_ITEM_NOTMODIFIED =    0x00000100;																																																									
																																																									
const     HINT32    VERSION_FILTER_ALL              =    0x00000001;																																																									
const     HINT32    VERSION_FILTER_ALL_IN_VIEW      =    0x00000010;																																																									
const     HINT32    VERSION_FILTER_LATEST_IN_VIEW   =    0x00000100;																																																									
const     HINT32    VERSION_FILTER_LATEST           =    0x00001000;																																																									
// PR# 2997 05-18-04   DY   LATEST_IN_PACKAGE/ALL_IN_PACKAGE missing in HSDK.																																																									
const     HINT32 	VERSION_FILTER_LATEST_IN_PACKAGE  =	   0x00010000;																																																									
const	  HINT32	VERSION_FILTER_ALL_IN_PACKAGE	    =	   0x00000010;																																																									
// end PR# 2997																																																									
const     HINT32    VERSION_FILTER_ALL_NOT_IN_VIEW  =    0x01000000;	
																																																									
const     HINT32    VERSION_FILTER_NORMAL_VERSION   =    0x00000001;																																																									
const     HINT32    VERSION_FILTER_RESERVED_VERSION =    0x00000010;																																																									
const     HINT32    VERSION_FILTER_MERGED_VERSION   =    0x00000100;																																																									
const     HINT32    VERSION_FILTER_DELETED_VERSION  =    0x00001000;																																																									
const     HINT32    VERSION_FILTER_FROZEN_VERSION   =    0x00010000;																																																									
const     HINT32    VERSION_FILTER_VCI_RESERVED		=    0x00100000;																																																									
																																																									
const     HINT32    BRANCH_FILTER_TRUNK_ONLY        =    0x00000001;																																																									
const     HINT32    BRANCH_FILTER_BRANCH_ONLY       =    0x00000010;																																																									
const     HINT32    BRANCH_FILTER_UNMERGED_ONLY     =    0x00000100;																																																									
const     HINT32    BRANCH_FILTER_MERGED_ONLY       =    0x00001000;																																																									
const     HINT32    BRANCH_FILTER_VCI_ONLY          =    0x00010000;																																															
const     HINT32    BRANCH_FILTER_VCI_NORMAL_ONLY   =    0x00100000;  // PR4975																																																							
																																																									
// PR# 2065 04-27-04        Per/Post Link UDP Being Called Several Times by Hco Command																																																									
const     HINT32    NOLINK_UDP = 0;																																																									
const	  HINT32    PERLINK_UDP = 1;																																																									
const	  HINT32    POSTLINK_UDP = 2;																																																									
const	  HINT32    PER_POST_UDP = 3;																																																									
																																																									
#define	  VERSION_FILTER_ITEM_BOTH   (VERSION_FILTER_ITEM_MODIFIED |VERSION_FILTER_ITEM_BASELINE ) 																																																									
#define   VERSION_FILTER_ALL_TAG     (VERSION_FILTER_NORMAL_VERSION | VERSION_FILTER_RESERVED_VERSION | VERSION_FILTER_MERGED_VERSION | VERSION_FILTER_DELETED_VERSION | VERSION_FILTER_FROZEN_VERSION)																																																									
#define   VERSION_FILTER_ANY_TAG     (VERSION_FILTER_RESERVED_VERSION | VERSION_FILTER_MERGED_VERSION | VERSION_FILTER_DELETED_VERSION | VERSION_FILTER_FROZEN_VERSION)																																																									
#define   BRANCH_FILTER_TRUNK_AND_BRANCH (BRANCH_FILTER_TRUNK_ONLY | BRANCH_FILTER_BRANCH_ONLY | BRANCH_FILTER_UNMERGED_ONLY)																																																									
																																																									
#define   NORMAL_TAG_VERSION        _T("N")																																																									
#define   RESERVED_TAG_VERSION      _T("R")																																																									
#define   MERGED_TAG_VERSION        _T("M")																																																									
#define   DELETED_TAG_VERSION       _T("D")																																																									
#define   FROZEN_TAG_VERSION        _T("F")									
#define   MOVED_TAG_VERSION         _T("V")									
#define   RENAMED_TAG_VERSION       _T("A")															
																																																									
																																																									
// view path separator																																																									
#define   SERVER_PATH_SEPARATOR     _T("\\")																																																									
// used in FindFile()'s search pattern list, List of extensions of files that should not be compressed																																																									
#define   STRING_LIST_SEPARATOR     _T(",")																																																									
																																																									
#define     VERSION_OPTION_DATE_ALL         0																																																									
#define     VERSION_OPTION_DATE_BETWEEN     1																																																									
																																																									
//////////////////////////////////////																																																									
// MERGE RULES																																																									
// in Developer process execution																																																									
#define MERGE_RULE_TRUNK_MERGE         _T("T")																																																									
#define MERGE_RULE_BRANCH_MERGE        _T("B")																																																									
#define MERGE_RULE_CONFLICT_TAG        _T("C")																																																									
#define MERGE_RULE_ALWAYS_TAG          _T("A")																																																									
																																																									
//////////////////////////////////////////////																																																									
/* The encoded combination of merge rule 																																																									
	 settings in ADM interface 																																																									
A= YYYY																																																									
B= YYYN																																																									
C= YYNY																																																									
D= YYNN																																																									
E= YNYY																																																									
F= YNYN																																																									
G= YNNY																																																									
H= YNNN																																																									
I= NYYY																																																									
J= NYYN																																																									
K= NYNY																																																									
L= NYNN																																																									
M= NNYY																																																									
N= NNYN																																																									
O= NNNY																																																									
*/																																																									
																																																									
#define TRUNK_MERGE         MERGE_RULE_TRUNK_MERGE[0]																																																									
#define BRANCH_MERGE        MERGE_RULE_BRANCH_MERGE[0]																																																									
#define CONFLICT_TAG        MERGE_RULE_CONFLICT_TAG[0]																																																									
#define ALWAYS_TAG          MERGE_RULE_ALWAYS_TAG[0]																																																									
																																																									
// ALWAYS_TAG																																																									
#define DEFAULT_MERGE_RULE  MERGE_RULE_ALWAYS_TAG																																																									
																																																									
#define MERGE_OPTION_TRUNK_ONLY					_T("T")       																																																									
#define MERGE_OPTION_BRANCH_ONLY    			_T("B") 																																																									
#define MERGE_OPTION_TRUNK_OR_BRANCH			_T("A")																																																									
																																																									
#define TRUNK_PLACEMENT         MERGE_OPTION_TRUNK_ONLY[0]																																																									
#define BRANCH_PLACEMENT        MERGE_OPTION_BRANCH_ONLY[0]																																																									
#define ANY_PLACEMENT           MERGE_OPTION_TRUNK_OR_BRANCH[0]																																																									
																																																									
																																																									
#define DEFAULT_PLACEMENT_OPTION			MERGE_OPTION_TRUNK_OR_BRANCH																																																									
/* The encoded combination of placement option 																																																									
	 settings in ADM interface 																																																									
A= YYY																																																									
B= YYN																																																									
C= YNY																																																									
D= YNN																																																									
E= NYY																																																									
F= NYN																																																									
G= NNY																																																									
*/																																																									
//////////////////////////////////////																																																									
// RESOLVE INTERACTIVE MERGE OPTIONS																																																									
#define IA_MERGE_OPTION_TRUNK            _T("T")																																																									
#define IA_MERGE_OPTION_BRANCH           _T("B")																																																									
#define IA_MERGE_OPTION_CANCEL           _T("C")																																																									
#define IA_MERGE_OPTION_MERGE            _T("M")																																																									
//////////////////////////////////////////////////																																																									
//  NTERACTIVE MERGE OPTIONS																																																									
#define IA_MERGE_EXECUTE_OPTION_3_WAY		0																																																											
#define IA_MERGE_EXECUTE_OPTION_2_WAY		1																																																											
//////////////////////////////////////																																																									
// DELTA CONSTANTS																																																									
#define HDELTA_FILEACCESS_ALL   _T("vexvexvex")																																																									
																																																									
/* Harvest Create Session Flags for GUI */																																																									
const   HINT32    HARVEST_SESSION_OK  = 0;																																																									
const	HINT32    HARVEST_BAD_LOGIN   = 1;																																																									
const	HINT32    HARVEST_BAD_SESSION = 2;																																																									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Password Policy Constants																																																									
#define HARVEST_USER_LOCKOUT		3   // Login status: user locked out  																																																									
#define HARVEST_PW_EXPIRED		    4   // Login status: User's password expired and user may change it  																																																									
#define PR_UO_NONE		           -2   // User-level override: None																																																									
#define PR_NEVER_EXPIRE		       -1   // Never expire setting for Max. Age (global or user-level override)																																																									
#define PR_UO_CHANGE_AT_NEXT_LOGON	0   // User-level override: Change password at next login. 																																																									
#define PR_UO_ANY		           -3   // User-level override: Any. Filter to list users for whom there is any user-level override. 																																																									
#define PR_REUSE_HISTORY_LIMIT	   24   // Upper limit for password reuse rule 																																																									
#define PR_USER_CHANGE_EXP		    0   // User may change own expired password  																																																									
#define PR_DISABLED		           -1   // Indicates that rule is not used in the current password policy. 																																																									
																																																									
// Compare Views process flags (not visible to user, not in DB)																																																									
#define     VIEW1_ONLY				1																																																									
#define     VIEW2_ONLY				2									 																																																									
#define     VIEW1_VIEW2				3																																																									
#define     VIEW1_VIEW2_SAME_DATA	4																																																									
									
// PR 4664 - refactoring									
// Compare Views refactor flags (also not visible to user, not in DB)																																																									
#define     VIEW1_VIEW2_REFACTOR_SAME   1																																																									
#define     VIEW1_VIEW2_DIFFERENT_NAME  2																																																									
#define     VIEW1_VIEW2_DIFFERENT_PATH  3																																																									
// end PR 4664 - refactoring									
									
																																																									
//////////////////////////////////////																																																									
//      View Types																																																									
#define VIEW_SNAPSHOT       _T("Snapshot")																																																									
#define VIEW_BASELINE       _T("Baseline")																																																									
#define VIEW_WORKING        _T("Working")																																																									
#define VIEW_REPOSITORY     _T("Repository")																																																									
																																																									
//////////////////////////////////////////																																																									
// List items in view options																																																									
const   HINT32    ITEMS_AND_PATHS_IN_VIEW  = 0;																																																									
const	HINT32    ONLY_ITEMS_IN_VIEW   = 1;																																																									
const	HINT32    ONLY_PATHS_IN_VIEW = 2;																																																									
const	HINT32    ONLY_PATHS_RECURSIVE_IN_VIEW = 3;																																																									
																																																									
																																																									
//////////////////////////////////////																																																									
//  formatting function names 																																																									
//  used to generate package names																																																									
//																																																									
#define PACKAGE_NAME_DATE       _T("%D")																																																									
#define PACKAGE_NAME_COUNTER    _T("%N")						
					
// PR 5878  																																																	
#define PACKAGE_NAME_SOURCE_PACKAGE_NAME _T("%P")					
																																																		
#define PACKAGE_NAME_DEFAULT_FORMAT _T("Package-%N('999')")																																																									
//////////////////////////////////////																																																									
//  MP: System Variable																																																									
//  Only non primitive variables are defined here.																																																									
//  Primitive variables (environment, state, view,... ones that has always has value)																																																									
//  are hardcoded for performance reason in CPtHProcess::ResolveSysVar() function																																																									
																																																									
#define SYSVAR_NEXTENV          _T("NEXTENVIRONMENT")																																																									
#define SYSVAR_NEXTPROJ         _T("NEXTPROJECT")																																																									
#define SYSVAR_NEXTSTATE        _T("NEXTSTATE")																																																									
#define SYSVAR_PACKAGE          _T("PACKAGE")																																																									
#define SYSVAR_PACKAGE2         _T("\"PACKAGE\"")																																																									
#define SYSVAR_PACKAGEGROUP     _T("PACKAGEGROUP")																																																									
#define SYSVAR_PACKAGEGROUP2    _T("\"PACKAGEGROUP\"")																																																									
#define SYSVAR_FILE             _T("FILE")																																																									
#define SYSVAR_FILE2            _T("\"FILE\"")																																																									
#define SYSVAR_VERSION          _T("VERSION")																																																									
#define SYSVAR_VERSION2         _T("\"VERSION\"")																																																									
#define SYSVAR_TOPACKAGE        _T("TOPACKAGE")																																																									
#define SYSVAR_TOPACKAGE2       _T("\"TOPACKAGE\"")																																																									
// Begin PR 1785 MAS																																																									
#define SYSVAR_CLIENTPATH       _T("CLIENTPATH")																																																									
#define SYSVAR_VIEWPATH         _T("VIEWPATH")																																																									
// End PR 1785 MAS																																																				
																																																			
// PR#4660																																																			
#define SYSVAR_MODE				_T("MODE")																																																			
// PR#4660					
// Begin PR 4664 for RDSU					
#define SYSVAR_ITEMOBJID        _T("ITEMOBJID")					
#define SYSVAR_PATHVERSION      _T("PATHVERSION")					
#define SYSVAR_PATHVERSION2     _T("\"PATHVERSION\"")					
// End PR 4664 for RDSU																																																								

//PR#*8485, b.
#define SYSVAR_FROMPACKAGE      _T("FROMPACKAGE")
#define SYSVAR_FROMPACKAGE2     _T("\"FROMPACKAGE\"")
#define SYSVAR_FROMSTATE        _T("FROMSTATE")
#define SYSVAR_FROMPROJECT      _T("FROMPROJECT")
#define SYSVAR_FROMVIEW         _T("FROMVIEW")
//PR#*8485, e.

																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Access methods for  securable objects 																																																									
#define UPDATEACCESS           _T("UpdateAccess")																																																									
#define VIEWACCESS				_T("ViewAccess")																																																									
#define EXLUSIVE_VIEWACCESS    _T("ViewAccess")																																																									
#define SECUREACCESS          _T("SecureAccess")																																																									
#define EXECUTEACCESS         _T("ExecuteAccess")																																																									
#define USEACCESS			   _T("ExecuteAccess")																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Access methods for HARVEST																																																									
#define SECUREHARVEST		_T("SecureHarvest")																																																									
#define ADMINUSER			_T("AdminUser")                    																																																									
#define VIEWUSER            _T("ViewUser")  																																																									
#define ADMINENVIRONMENT    _T("AdminEnvironment")              																																																									
#define VIEWENVIRONMENT		_T("ViewEnvironment")   																																																									
#define ADMINREPOSITORY    _T("AdminRepository")																																																									
#define VIEWREPOSITORY     _T("ViewRepository")																																																									
#define ADMINFORMTYPE      _T("AdminFormType")																																																									
#define VIEWFORMTYPE       _T("ViewFormType")  																																																									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Form attachment types																																																									
#define ATTACHMENT_FILE		0  																																																									
#define ATTACHMENT_URL		1  																																																									
																																																									
// PACKAGE LIST																																																									
#define  DB_MAX_PKGID_LIST_SIZE            100																																																									
#define  DB_MAX_PKGNAME_LIST_SIZE          50																																																									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Maximum number of columns allowed in a (form) table																																																									
const HINT32 HAR_MAX_ATTRIBUTES=500;																																																									
																																																									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//PR2413 sepcial character to brask UDP system vairable [password]																																																									
const HINT32    UNREADABLE_CHAR_1  = 1;																																																									
																																																									
																																																									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//  HPUX Bug with FILENAME_MAX (default 14!). Set to a reasonable																																																									
//        value.  Also must modify this value in fileagent/agent.h																																																									
#if defined(__hpux)																																																									
#undef FILENAME_MAX																																																									
#define FILENAME_MAX 1024																																																									
#endif																																																									
																																																									
//PR#5682, n. Moved down to end													
//#endif									
																																																									
////////////////////////////////////////////////////////////////////																																																									
//  Database Types																																																									
#define DBTYPE_ORACLE 1																																																									
#define DBTYPE_INGRES 2																																																									
#define DBTYPE_SQLSERVER 3																																																			
																																																			
//pr# 4443 Minimum size for zip utility																																																			
#define ZIP_MIN_FILE_SIZE	150																																																			
																																																								
//PR#3400 b.Constants for CCaAuthServer and derived classes																																																			
#define AUTHMODE_INTERNAL               _T("internal")																																																			
#define AUTHMODE_EXTERNAL               _T("external")																																																			
#define AUTHMODE_OPENLDAP               _T("openldap")																																																			
#define AUTHMODE_PAM	_T("pam")
																																																			
//PR#3400 e.Constants for CCaAuthServer and derived classes																																																			
																																																			
// PR# 3400 Add constants utilized in HServer transactions																																																							
																																																			
#define UPDATE_PASSWORD_POLICY _T("Update Password Policy")																																																			
#define QUERY_PASSWORD_POLICY _T("Query Password Policy")																																																			
#define CHANGE_PASSWORD _T("Change Password")																																																			
#define UNLOCK_USER _T("Unlock User")																																																			
																																																			
#define HARVEST_USER _T("Harvest user")																																																			
																																																			
#define DEFAULT_LDAP_NORMAL_PORT 389																																																			
#define DEFAULT_LDAP_SECURE_PORT 636																																																			
#define MIN_LDAP_PORT 1																																																			
#define MAX_LDAP_PORT 9999																																																			
																																																			
#define DEFAULT_LDAP_FILTER _T("(&(objectclass=Person)(uid=<uid>))")																																																			
#define DEFAULT_LDAPGRP_FILTER _T("(&(objectclass=Group)(uid=<uid>))")//PR# 6911

#define LDAP_ENCRYPTMODE_NONE _T("none")																																																			
#define LDAP_ENCRYPTMODE_TLS _T("tls")																																																			
#define LDAP_ENCRYPTMODE_SSL _T("ssl")																																																			
#define DEFAULT_LDAP_ENCRYPTMODE _T("tls")																																																			
																																																			
#define DEFAULT_LDAP_SEARCH_TIMEOUT  60
#define DEFAULT_LDAP_NETWORK_TIMEOUT  300
#define MIN_LDAP_SEARCH_TIMEOUT  1																																																			
																																																			
#define DEFAULT_LDAP_ATTRUSRNAME     _T("uid")																																																			
#define DEFAULT_LDAP_ATTRUSRFULLNAME _T("fullName")																																																			
#define DEFAULT_LDAP_ATTRUSRPHONE    _T("telephoneNumber")																																																			
#define DEFAULT_LDAP_ATTRUSRPHONEEXT _T("")																																																			
#define DEFAULT_LDAP_ATTRUSRFAX      _T("facsimileTelephoneNumber")																																																			
#define DEFAULT_LDAP_ATTRUSREMAIL    _T("mail")																																																			
																																																			
#define DEFAULT_LDAP_ATTRUSRUNIXUID     _T("uidNumber")																																																			
#define DEFAULT_LDAP_ATTRUSRUNIXGID     _T("gidNumber")																																																			
#define DEFAULT_LDAP_ATTRUSRUNIXHOMEDIR _T("homeDirectory")																																																			
#define DEFAULT_LDAP_ATTRUSRUNIXSHELL   _T("shell")																																																			
																																																			
// PR# 3400 Add constants utilized by the Broker																																																						
																																																		
#define DEFAULT_AUTH_SYNCH_INTERVAL 86400  // 1 Day in seconds																																																		
#define MIN_AUTH_SYNCH_INTERVAL      3600  // 1 Hour in seconds																																																		
																																																		
// PR# 3400 Added debug level																																																		
																																																		
#define DEFAULT_LDAP_DEBUG_LEVEL    0 // no debugging																																																		
																																																			
//	PR 5726 Add support for Ext User Group Support
#define DEFAULT_LDAP_EXTERNALGROUPENABLED		0
#define DEFAULT_LDAP_ATTRUSRGRPNAME			_T("");
#define DEFAULT_LDAP_ATTRUSRINGRP			_T("");
#define DEFAULT_LDAP_ATTRGRPINUSR			_T("");
																																															
																																															
// PR#5782, b.Process type enum													
enum tProcessTypesBitMap													
{													
	PROCTYPE_NONE=				 0x000000,													
	PROCTYPE_APPROVE=			 0x000001,													
	PROCTYPE_CHECKIN=			 0x000002,													
	PROCTYPE_CHECKOUT=			 0x000004,													
	PROCTYPE_DELETEVERSIONS=	 0x000008,													
	PROCTYPE_DEMOTE=			 0x000010,													
	PROCTYPE_LISTDIFFERENCE=	 0x000020,													
	PROCTYPE_LISTVERSION=		 0x000040,													
	PROCTYPE_CONCURRENT_MERGE=	 0x000080,													
	PROCTYPE_CROSSPROJECT_MERGE= 0x000100,													
	PROCTYPE_INTERACTIVE_MERGE=	 0x000200,													
	PROCTYPE_NOTIFY=			 0x000400,    													
	PROCTYPE_CREATE_PACKAGE=	 0x000800,													
	PROCTYPE_MOVEPACKAGE=		 0x001000,													
	PROCTYPE_PROMOTE=			 0x002000,													
	PROCTYPE_REMOVEITEM=		 0x004000,   													
	PROCTYPE_TAKESNAPSHOT=		 0x008000,													
	PROCTYPE_UDP=				 0x010000,													
	PROCTYPE_RENAMEITEM=		 0x020000,													
	PROCTYPE_SWITCHPACKAGE=		 0x040000,													
	PROCTYPE_DELETEPACKAGE=		 0x080000, //R12													
	PROCTYPE_REMOVEPATH=		 0x100000, //R12													
	PROCTYPE_MOVEPATH=			 0x200000, //R12													
	PROCTYPE_RENAMEPATH=		 0x400000, //R12													
	PROCTYPE_MOVEITEM=			 0x800000, //R12													
	PROCTYPE_ALL=				 0xFFFFFF,													
    PROCTYPE_ALL_R71=            0x07FFFF  // All R7.1 processes													
};													
// PR#5782, e.Process type enum					
					
// PR#5877, b.Auditing Phase One					
#define AUDITPOLICYTYPE_GLOBAL		_T("G")					
#define AUDITPOLICYTYPE_LOCAL		_T("L")					
#define CREATE_GLOBAL_AUDITPOLICY	_T("Create Global Audit Policy")					
#define DELETE_GLOBAL_AUDITPOLICY	_T("Delete Global Audit Policy")					
#define CREATE_LOCAL_AUDITPOLICY	_T("Create Local Audit Policy")					
#define UPDATE_LOCAL_AUDITPOLICY	_T("Update Local Audit Policy")					
#define DELETE_LOCAL_AUDITPOLICY	_T("Delete Local Audit Policy")					
#define LIST_LOCAL_AUDITPOLICY		_T("List Local Audit Policy")					
#define ACTION_SUCCESS				_T("S")					
#define ACTION_FAILURE				_T("F")					
					
#define DEFAULT_AUDITLOG_PURGE_INTERVAL		86400 // 1 Day in seconds					
#define MIN_AUDITLOG_PURGE_INTERVAL			3600  // 1 Hour in seconds					
					
#define DEFAULT_AUDITLOG_RETENTION_DAYS		30    // 30 Days					
#define MIN_AUDITLOG_RETENTION_DAYS			1     // 1 Day					
					
#define DEFAULT_AUDITLOG_MAX_EVENTS			0     // No maximum					
#define MIN_AUDITLOG_MAX_EVENTS				0     // No maximum					
					
					
enum tResourceTypes					
{					
	RESOURCETYPE_NONE = 0,					
	RESOURCETYPE_BROKER = 1,					
	RESOURCETYPE_ENVIRONMENT = 2,					
	RESOURCETYPE_FORM_TYPE = 3,					
	RESOURCETYPE_USER = 4,					
	RESOURCETYPE_USERGROUP = 5,					
	RESOURCETYPE_REPOSITORY = 6,					
	RESOURCETYPE_STATE = 7,					
	RESOURCETYPE_BASELINE_VIEW = 8,					
	RESOURCETYPE_WORKING_VIEW = 9,					
	RESOURCETYPE_SNAPSHOT_VIEW = 10,					
	RESOURCETYPE_USERGROUP_MEMBERSHIP = 11,					
	RESOURCETYPE_ITEM = 12,					
	RESOURCETYPE_STATE_PROCESS = 13,					
	RESOURCETYPE_PACKAGE = 14,					
	RESOURCETYPE_VERSION = 15,					
	RESOURCETYPE_FORM = 16,					
	RESOURCETYPE_LINKED_PROCESS = 17					
};					
					
enum tActions					
{					
	ACTION_CREATE_ENVIRONMENT = 200,					
	ACTION_UPDATE_ENVIRONMENT = 201,					
	ACTION_VIEW_ENVIRONMENT = 202,					
	ACTION_LIST_ENVIRONMENT = 203,					
	ACTION_DELETE_ENVIRONMENT = 204,					
	ACTION_SECURE_ENVIRONMENT = 205,					
					
	ACTION_CREATE_FORM_TYPE = 300,					
	ACTION_UPDATE_FORM_TYPE = 301,					
	ACTION_VIEW_FORM_TYPE = 302,					
	ACTION_LIST_FORM_TYPE = 303,					
	ACTION_DELETE_FORM_TYPE = 304,					
	ACTION_SECURE_FORM_TYPE = 305,					
					
	ACTION_CREATE_USER = 400,					
	ACTION_UPDATE_USER = 401,					
	ACTION_VIEW_USER = 402,					
	ACTION_LIST_USER = 403,					
	ACTION_DELETE_USER = 404,					
	ACTION_SECURE_USER = 405,					
	ACTION_LOGIN_USER = 411,					
					
	ACTION_CREATE_USERGROUP = 500,					
	ACTION_UPDATE_USERGROUP = 501,					
	ACTION_VIEW_USERGROUP = 502,					
	ACTION_LIST_USERGROUP = 503,					
	ACTION_DELETE_USERGROUP = 504,					
	ACTION_SECURE_USERGROUP = 505,					
					
	ACTION_CREATE_REPOSITORY = 600,					
	ACTION_UPDATE_REPOSITORY = 601,					
	ACTION_VIEW_REPOSITORY = 602,					
	ACTION_LIST_REPOSITORY = 603,					
	ACTION_DELETE_REPOSITORY = 604,					
	ACTION_SECURE_REPOSITORY = 605,					
					
	ACTION_CREATE_STATE = 700,					
	ACTION_UPDATE_STATE = 701,					
	ACTION_VIEW_STATE = 702,					
	ACTION_LIST_STATE = 703,					
	ACTION_DELETE_STATE = 704,					
	ACTION_SECURE_STATE = 705,					
					
	ACTION_CONFIGURE_BASELINE_VIEW = 801,					
	ACTION_VIEW_BASELINE_VIEW = 802,					
	ACTION_SECURE_BASELINE_VIEW = 805,					
					
	ACTION_CREATE_WORKING_VIEW = 900,					
	ACTION_UPDATE_WORKING_VIEW = 901,					
	ACTION_VIEW_WORKING_VIEW = 902,					
	ACTION_LIST_WORKING_VIEW = 903,					
	ACTION_DELETE_WORKING_VIEW = 904,					
	ACTION_SECURE_WORKING_VIEW = 905,					
					
	ACTION_CREATE_SNAPSHOT_VIEW = 1000,					
	ACTION_VIEW_SNAPSHOT_VIEW = 1002,					
	ACTION_LIST_SNAPSHOT_VIEW = 1003,					
	ACTION_DELETE_SNAPSHOT_VIEW = 1004,					
	ACTION_SECURE_SNAPSHOT_VIEW = 1005,					
					
	ACTION_CREATE_USERGROUP_MEMBERSHIP = 1100,					
	ACTION_LIST_USERGROUP_MEMBERSHIP = 1103,					
	ACTION_DELETE_USERGROUP_MEMBERSHIP = 1104,					
					
	ACTION_CREATE_ITEM = 1200,					
	ACTION_UPDATE_ITEM = 1201,					
	ACTION_VIEW_ITEM = 1202,					
	ACTION_LIST_ITEM = 1203,					
	ACTION_DELETE_ITEM = 1204,					
	ACTION_SECURE_ITEM = 1205,					
	ACTION_RENAME_ITEM = 1207,					
	ACTION_MOVE_ITEM = 1208,					
	ACTION_REMOVE_ITEM = 1209,		
    ACTION_CHANGE_ITEM_FILETYPE = 1210, // R12.1 8393 change file type auditing
					
	ACTION_CREATE_STATE_PROCESS = 1300,					
	ACTION_UPDATE_STATE_PROCESS = 1301,					
	ACTION_VIEW_STATE_PROCESS = 1302,					
	ACTION_LIST_STATE_PROCESS = 1303,					
	ACTION_DELETE_STATE_PROCESS = 1304,					
	ACTION_SECURE_STATE_PROCESS = 1305,					
	ACTION_EXECUTE_STATE_PROCESS = 1306,					
					
	ACTION_CREATE_PACKAGE = 1400,					
	ACTION_UPDATE_PACKAGE = 1401,					
	ACTION_VIEW_PACKAGE = 1402,					
	ACTION_LIST_PACKAGE = 1403,					
	ACTION_DELETE_PACKAGE = 1404,					
	ACTION_SECURE_PACKAGE = 1405,					
					
	ACTION_CREATE_VERSION = 1500,					
	ACTION_UPDATE_VERSION = 1501,					
	ACTION_VIEW_VERSION = 1502,					
	ACTION_LIST_VERSION = 1503,					
	ACTION_DELETE_VERSION = 1504,					
	ACTION_SECURE_VERSION = 1505,					
					
	ACTION_CREATE_FORM = 1600,					
	ACTION_UPDATE_FORM = 1601,					
	ACTION_VIEW_FORM = 1602,					
	ACTION_LIST_FORM = 1603,					
	ACTION_DELETE_FORM = 1604,					
	ACTION_SECURE_FORM = 1605,					
	ACTION_REMOVE_FORM = 1609,					
	ACTION_ADD_FORM = 1610,					
					
	ACTION_CREATE_LINKED_PROCESS = 1700,					
	ACTION_UPDATE_LINKED_PROCESS = 1701,					
	ACTION_VIEW_LINKED_PROCESS = 1702,					
	ACTION_LIST_LINKED_PROCESS = 1703,					
	ACTION_DELETE_LINKED_PROCESS = 1704,					
	ACTION_EXECUTE_LINKED_PROCESS = 1706					
};					
// PR#5877, e.Auditing Phase One													
		
// PR 5795 CMSDK, to specify client api, default should be HAPI		
#define		CLIENT_HAPI			0		
#define		CLIENT_CMSDK		1		

//PR#6348, n.Add constant used to set HARUSER.ENCRYPTPSSWD
#define ETPKI_ENCRYPTION_LEVEL  _T("ETPKI-12,0000,0000,0")

//PR 9113 Git bundle extenstion
#define GIT_BUNDLE_EXT _T(".bundle")

#ifdef MAX_FILE_PATH
#undef MAX_FILE_PATH
#endif
#define MAX_FILE_PATH 4096 //MAX_PATH

//#ifndef _AIX
#if !defined(MAX_PATH)
#define MAX_PATH 260
#endif
//#endif


#endif	// !defined(_TCONST)																																																													
																																																				
