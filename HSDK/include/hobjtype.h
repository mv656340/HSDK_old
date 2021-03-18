//----------------------------------------------------+------------------------
// FILENAME:           hobjtype.h
//
// DESCRIPTION:        Header file for object type definitions that are used by
//                       both the client and server.
//
// AUTHOR:             Sabina Beraha
//
// REVISION HISTORY:
//         10-15-98    SB     File Creation
//         01-22-99   MAS     Set values for types as CHAPI needs them but 
//                            can't include this file.
//         04-04-02   MAS     Added Password Policy
// PR#2480    05-24-06        ni$ya01 Add Delete Package process
// PR#4664 02-24-06 neewi01   Refactoring Project changes
// PR#5878 11-22-06 neewi01   Shared code
//
// Copyright © 2006 Computer Associates International, Inc. All rights reserved. 
//
//----------------------------------------------------+------------------------


#if !defined(CPTHOBJTYPE_H)
#define CPTHOBJTYPE_H

// only include the base types if we don't wnat only the defines.
#ifndef _HAPI_DEFINES_ONLY

#include "hbasetyp.h"

#endif

//    TYPE DEFINITIONS:
//-----------------------------------------------------------------------------
// HAROBJTYPE is an enumerated type which defines an identifier for each 
// persistent harvest object type. These identifiers are sequential so that
// they can be used to index into an array of related objects.
//  
enum HAROBJTYPE
{
    HAR_NOOBJ_TYPE              = -1,
    HAR_LOW_LIM_OBJ_TYPE        = 0,     // Not a type! Use to identify lower limit

    HAR_HARVEST_TYPE            = 1,
    HAR_ENVIRONMENT_TYPE        = 2,    // MVS component expects environment 
                                        // object type to be 2
    HAR_CHANGEPACKAGE_TYPE      = 3,
    HAR_CHANGEPACKAGEGROUP_TYPE = 4,
    HAR_REPOSITORY_TYPE         = 5,
    HAR_STATE_TYPE              = 6,
    HAR_REPOSITORYVIEW_TYPE     = 7,
    HAR_BASELINEVIEW_TYPE       = 8,
    HAR_WORKINGVIEW_TYPE        = 9,
    HAR_SNAPSHOTVIEW_TYPE       = 10,
    HAR_ITEM_TYPE               = 11,
    HAR_ITEMPATH_TYPE           = 12,
    HAR_VERSION_TYPE            = 13,
    HAR_USERGROUP_TYPE          = 14,
    HAR_USER_TYPE               = 15,
    HAR_SESSION_TYPE            = 16,
    HAR_LIST_TYPE               = 17,
    HAR_REPOSITORYANDVIEW_TYPE  = 18,
    HAR_FORMTYPE_TYPE           = 19,
    HAR_FORM_TYPE               = 20,
    HAR_FORMTYPE_FIELDDESC_TYPE = 21,
    HAR_FORM_ATTACHMENT         = 22,
    HAR_PASSWORD_POLICY         = 23,
    //
    // Process types - group together or change HAR_IS_PROCESS_TYPE() below
    //
    // If you change the first or last process type,
    // then you must change HAR_IS_PROCESS_TYPE().
    //
    HAR_APPROVE_PROCESS_TYPE            = 200,    // First process type
    HAR_CHECKIN_PROCESS_TYPE            = 201,
    HAR_CHECKOUT_PROCESS_TYPE           = 202,
    HAR_DELETEVERSIONS_PROCESS_TYPE     = 203,
    HAR_DEMOTE_PROCESS_TYPE             = 204,
    HAR_LISTDIFFERENCE_PROCESS_TYPE     = 205,
    HAR_LISTVERSION_PROCESS_TYPE        = 206,
    HAR_CONCURRENT_MERGE_PROCESS_TYPE   = 207,
    HAR_CROSSPROJECT_MERGE_PROCESS_TYPE = 208,
    HAR_INTERACTIVE_MERGE_PROCESS_TYPE  = 209,
    HAR_NOTIFY_PROCESS_TYPE             = 210,     
    HAR_CREATE_PACKAGE_PROCESS_TYPE     = 211,
    HAR_MOVE_PACKAGE_PROCESS_TYPE       = 212,
    HAR_PROMOTE_PROCESS_TYPE            = 213,
    HAR_REMOVEITEM_PROCESS_TYPE         = 214,     
    HAR_TAKESNAPSHOT_PROCESS_TYPE       = 215,
    HAR_UDP_PROCESS_TYPE                = 216,
    HAR_RENAMEITEM_PROCESS_TYPE         = 217,       // Last process type
	HAR_SWITCH_PACKAGE_PROCESS_TYPE		= 218,
	HAR_DELPKG_PROCESS_TYPE     	    = 219,
// PR# 4664 - HCORE - New processes in Admin  
    HAR_MOVEITEM_PROCESS_TYPE           = 220,  
    HAR_REMOVEPATH_PROCESS_TYPE         = 221,  
    HAR_MOVEPATH_PROCESS_TYPE           = 222,  
    HAR_RENAMEPATH_PROCESS_TYPE         = 223,  
// PR# 5878 - Shared code
    HAR_SHAREDITEM_PROCESS_TYPE         = 224,  

    HAR_UP_LIM_OBJ_TYPE                 = 225        // Not a type! 
                                                     // Identifies the upper limit.
 };


#ifndef _HAPI_DEFINES_ONLY

//    INLINE FUNCTIONS:
// --------------------------------------------------------------------------
// Use HAR_IS_PROCESS_TYPE to identify process object types.
//
inline bool HAR_IS_PROCESS_TYPE( HINT32 iHarObjectType)
{   
    return (iHarObjectType >= HAR_APPROVE_PROCESS_TYPE && 
            iHarObjectType < HAR_UP_LIM_OBJ_TYPE);
}

#endif // _HAPI_DEFINES_ONLY

#endif


