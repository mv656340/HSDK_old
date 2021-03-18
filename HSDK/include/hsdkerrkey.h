//----------------------------------------------------+-------------------------------------------------
// FILENAME:           hsdkerrkey.h
//
// DESCRIPTION:        Error Message Key Definition File.
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//     04-18-01        MAS     File Creation
//     09-29-05        LS      PR4996 - Added invalid index, invalid key
//     12-16-05        LS      PR4850 - Added form type list error
//     01-12-06        faudo01 PR5420 - Error keys for CaUDPExitHandler
//     01-17-06        sevle01 PR5444 - Error keys for form creation/retrieval
//     01-04-07        faudo01 PR4664 - Refactoring additions and changes
//     05-22-07        nanra01 PR5740 - ToProject and ToState for MovePackage process
//
// Copyright (c) 2001-2007 Computer Associates inc. All rights reserved. 
//
//----------------------------------------------------+-------------------------------------------------

#ifndef HSDKERRKEY_H
#define HSDKERRKEY_H

//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------

#define		HSDK_W_NO_MESSAGEKEY	           _T("HSDK_W_NO_MESSAGEKEY")
#define		HSDK_E_NO_HARVEST	               _T("HSDK_E_NO_HARVEST")
#define		HSDK_E_NO_LOGIN	                   _T("HSDK_E_NO_LOGIN")
#define		HSDK_E_NO_CONTEXT_GET	           _T("HSDK_E_NO_CONTEXT_GET")
#define		HSDK_E_NO_CONTEXT_SET	           _T("HSDK_E_NO_CONTEXT_SET")
#define		HSDK_E_NO_BROKER_CONNECT           _T("HSDK_E_NO_BROKER_CONNECT")
#define		HSDK_E_NO_LOGGEDIN                 _T("HSDK_E_NO_LOGGEDIN")
#define		HSDK_E_NO_PROJECT_LIST             _T("HSDK_E_NO_PROJECT_LIST")
#define		HSDK_E_NO_PROJECT                  _T("HSDK_E_NO_PROJECT")
#define		HSDK_E_NO_STATE_LIST               _T("HSDK_E_NO_STATE_LIST")
#define		HSDK_E_NO_STATE                    _T("HSDK_E_NO_STATE")
#define		HSDK_E_NO_PROCESS_LIST             _T("HSDK_E_NO_PROCESS_LIST")
#define		HSDK_E_NO_PROCESS                  _T("HSDK_E_NO_PROCESS")
#define		HSDK_E_NO_USER_LIST                _T("HSDK_E_NO_USER_LIST")
#define		HSDK_E_NO_USER                     _T("HSDK_E_NO_USER")
#define		HSDK_E_NO_PACKAGE_LIST             _T("HSDK_E_NO_PACKAGE_LIST")
#define		HSDK_E_NO_PACKAGE                  _T("HSDK_E_NO_PACKAGE")
#define		HSDK_E_UNEXPECTED                  _T("HSDK_E_UNEXPECTED")
#define		HSDK_E_NO_CONTEXT_SET_BYID         _T("HSDK_E_NO_CONTEXT_SET_BYID")
#define		HSDK_E_NO_CHECKOUT_CONTEXT         _T("HSDK_E_NO_CHECKOUT_CONTEXT")
#define		HSDK_E_INVALID_PROCESS             _T("HSDK_E_INVALID_PROCESS")
#define		HSDK_E_NO_PROMOTE_CONTEXT          _T("HSDK_E_NO_PROMOTE_CONTEXT")
#define		HSDK_E_NO_DEMOTE_CONTEXT           _T("HSDK_E_NO_DEMOTE_CONTEXT")
#define		HSDK_E_INVALID_PACKAGE             _T("HSDK_E_INVALID_PACKAGE")
#define		HSDK_E_NO_VIEW_LIST                _T("HSDK_E_NO_VIEW_LIST")
#define		HSDK_E_NO_VIEW                     _T("HSDK_E_NO_VIEW")
#define		HSDK_E_NOT_SSVIEW                  _T("HSDK_E_NOT_SSVIEW")
#define		HSDK_E_INVALID_VIEWPATH            _T("HSDK_E_INVALID_VIEWPATH")
#define		HSDK_E_NO_VERSION_LIST             _T("HSDK_E_NO_VERSION_LIST")
#define		HSDK_E_NO_VERSION                  _T("HSDK_E_NO_VERSION")
#define		HSDK_E_NO_FILEAGENT                _T("HSDK_E_NO_FILEAGENT")
#define		HSDK_E_NO_FILEAGENT_LOGIN          _T("HSDK_E_NO_FILEAGENT_LOGIN")
#define		HSDK_E_NO_FILEAGENT_SETDIR         _T("HSDK_E_NO_FILEAGENT_SETDIR")
#define		HSDK_E_INVALID_VERSION_LIST        _T("HSDK_E_INVALID_VERSION_LIST")
#define		HSDK_E_INVALID_PACKAGE_LIST        _T("HSDK_E_INVALID_PACKAGE_LIST")
#define		HSDK_E_INVALID_FILE_LIST           _T("HSDK_E_INVALID_FILE_LIST")
#define		HSDK_E_INVALID_SNAPSHOT_OPTIONS    _T("HSDK_E_INVALID_SNAPSHOT_OPTIONS")
#define		HSDK_E_NO_CHECKIN_CONTEXT          _T("HSDK_E_NO_CHECKIN_CONTEXT")
#define		HSDK_E_INVALID_ATTRIBUTES          _T("HSDK_E_INVALID_ATTRIBUTES")
#define		HSDK_E_NO_CREATEPACKAGE_CONTEXT    _T("HSDK_E_NO_CREATEPACKAGE_CONTEXT")
#define		HSDK_E_NO_PACKAGE_CREATE           _T("HSDK_E_NO_PACKAGE_CREATE")
#define		HSDK_E_NO_APPROVE_CONTEXT          _T("HSDK_E_NO_APPROVE_CONTEXT")
#define		HSDK_E_NO_DELETEVERSION_CONTEXT    _T("HSDK_E_NO_DELETEVERSION_CONTEXT")
#define		HSDK_E_NO_TAKESNAPSHOT_CONTEXT     _T("HSDK_E_NO_TAKESNAPSHOT_CONTEXT")
#define		HSDK_E_NO_REMOVEITEM_CONTEXT       _T("HSDK_E_NO_REMOVEITEM_CONTEXT")
#define		HSDK_E_NO_RENAMEITEM_CONTEXT       _T("HSDK_E_NO_RENAMEITEM_CONTEXT")
#define		HSDK_E_INVALID_ITEM                _T("HSDK_E_INVALID_ITEM")
#define		HSDK_E_MULTIPLE_ITEMS              _T("HSDK_E_MULTIPLE_ITEMS")
#define		HSDK_E_NO_CONCURRENTMERGE_CONTEXT  _T("HSDK_E_NO_CONCURRENTMERGE_CONTEXT")
#define		HSDK_E_NO_INTERACTIVEMERGE_CONTEXT _T("HSDK_E_NO_INTERACTIVEMERGE_CONTEXT")
#define		HSDK_E_NO_REF_SNAPSHOT             _T("HSDK_E_NO_REF_SNAPSHOT")
#define		HSDK_E_NOT_SNAPSHOT			       _T("HSDK_E_NOT_SNAPSHOT")
#define		HSDK_E_INVALID_UDP_TYPE		       _T("HSDK_E_INVALID_UDP_TYPE")
#define		HSDK_E_UDP_ADD_ARG			       _T("HSDK_E_UDP_ADD_ARG")
#define		HSDK_E_UDP_ADD_INPUT			   _T("HSDK_E_UDP_ADD_INPUT")
#define		HSDK_E_NO_UDP_CONTEXT		       _T("HSDK_E_NO_UDP_CONTEXT")
#define		HSDK_E_UDP_INPUTSECURE		       _T("HSDK_E_UDP_INPUTSECURE")
#define		HSDK_E_SQL_ZERORESULTS		       _T("HSDK_E_SQL_ZERORESULTS")
#define		HSDK_E_SQL_BADSTATEMENT		       _T("HSDK_E_SQL_BADSTATEMENT")
#define		HSDK_E_NO_CROSSPROJECTMERGE_CONTEXT	_T("HSDK_E_NO_CROSSPROJECTMERGE_CONTEXT")
#define		HSDK_E_NO_SWITCHPACKAGE_CONTEXT	   _T("HSDK_E_NO_SWITCHPACKAGE_CONTEXT")
#define		HSDK_E_NO_MOVEPACKAGE_CONTEXT	   _T("HSDK_E_NO_MOVEPACKAGE_CONTEXT")
#define		HSDK_E_NO_LISTVERSION_CONTEXT	   _T("HSDK_E_NO_LISTVERSION_CONTEXT")
#define		HSDK_E_INVALID_AGENT_LOGIN_INFO    _T("HSDK_E_INVALID_AGENT_LOGIN_INFO")
#define		HSDK_E_INVALID_AGENT_LOGIN_FAILURE _T("HSDK_E_INVALID_AGENT_LOGIN_FAILURE")
#define		HSDK_E_INVALID_VERSION_NUMBER	   _T("HSDK_E_INVALID_VERSION_NUMBER")
#define		HSDK_E_INVALID_PARENTPATH	       _T("HSDK_E_INVALID_PARENTPATH")
#define		HSDK_E_INVALID_CALLBACK_USERDATA   _T("HSDK_E_INVALID_USERDATA")
#define		HSDK_E_INVALID_CALLBACK_CONTAINER  _T("HSDK_E_INVALID_CALLBACK_CONTAINER")
#define		HSDK_E_INVALID_CALLBACK_FUNCTION   _T("HSDK_E_INVALID_CALLBACK_FUNCTION")
#define		HSDK_E_INVALID_CALLBACK_CHECKOUT   _T("HSDK_E_INVALID_CALLBACK_CHECKOUT")
#define		HSDK_E_INVALID_CALLBACK_CHECKIN	   _T("HSDK_E_INVALID_CALLBACK_CHECKIN")
#define		HSDK_E_UNABLE_CHANGE_PASSWORD      _T("HSDK_E_UNABLE_CHANGE_PASSWORD")
#define		HSDK_E_ACCOUNT_LOCKOUT		       _T("HSDK_E_ACCOUNT_LOCKOUT")
#define		HSDK_E_EXPIRED_PASSWORD		       _T("HSDK_E_EXPIRED_PASSWORD")

#define		HSDK_I_LOGGEDOUT                   _T("HSDK_I_LOGGEDOUT")
#define		HSDK_I_LOGGEDIN                    _T("HSDK_I_LOGGEDIN")

#define		HSDK_E_INVALID_PACKAGE_HISTORY     _T("HSDK_E_INVALID_PACKAGE_HISTORY")
#define		HSDK_E_INVALID_APPROVAL_REPORT     _T("HSDK_E_INVALID_APPROVAL_REPORT")
#define		HSDK_E_NO_FORM_LIST                _T("HSDK_E_NO_FORM_LIST")
#define		HSDK_E_NO_FORM                     _T("HSDK_E_NO_FORM")
#define		HSDK_E_NO_FORM_ATTACHMENT          _T("HSDK_E_NO_FORM_ATTACHMENT")

#define     HSDK_E_NO_ITEM_INVALID_ID          _T("HSDK_E_NO_ITEM_INVALID_ID")
#define     HSDK_E_NO_VERSION_INVALID_ID       _T("HSDK_E_NO_VERSION_INVALID_ID")

#define		HSDK_E_DESC_REQ					   _T("HSDK_E_DESC_REQ")

#define		HSDK_E_INVALID_INDEX               _T("HSDK_E_INVALID_INDEX")
#define		HSDK_E_INVALID_KEY                 _T("HSDK_E_INVALID_KEY")

#define		HSDK_E_INVALID_FORM_HISTORY        _T("HSDK_E_INVALID_FORM_HISTORY")
// b. PR4850
#define		HSDK_E_NO_FORM_TYPE_LIST	       _T("HSDK_E_NO_FORM_TYPE_LIST")
#define		HSDK_E_NO_FORM_TYPE		           _T("HSDK_E_NO_FORM_TYPE")
// e. PR4850

//PR#5420, b.CaUDPExitHandler
#define     HSDK_E_UDP_SIGCHLD_QUERY           _T("HSDK_E_UDP_SIGCHLD_QUERY")
#define     HSDK_E_UDP_SIGCHLD_RESTORE         _T("HSDK_E_UDP_SIGCHLD_RESTORE")
//PR#5420, e.CaUDPExitHandler

// b. PR#5444
#define     HSDK_E_UNABLE_CREATE_FORM          _T("HSDK_E_UNABLE_CREATE_FORM")
#define     HSDK_E_UNABLE_RETRIEVE_FORM        _T("HSDK_E_UNABLE_RETRIEVE_FORM")
// e. PR#5444

// PR#4664, b.Refactoring Additions and Changes
#define		HSDK_E_NO_MOVEITEM_CONTEXT         _T("HSDK_E_NO_MOVEITEM_CONTEXT")
#define		HSDK_E_NO_MOVEPATH_CONTEXT         _T("HSDK_E_NO_MOVEPATH_CONTEXT")
#define		HSDK_E_NO_REMOVEPATH_CONTEXT       _T("HSDK_E_NO_REMOVEPATH_CONTEXT")
#define		HSDK_E_NO_RENAMEPATH_CONTEXT       _T("HSDK_E_NO_RENAMEPATH_CONTEXT")
#define		HSDK_E_INVALID_TARGETPATH          _T("HSDK_E_INVALID_TARGETPATH")
#define		HSDK_E_INVALID_SOURCEPATH          _T("HSDK_E_INVALID_SOURCEPATH")
#define		HSDK_E_NO_DELETEPACKAGE_CONTEXT    _T("HSDK_E_NO_DELETEPACKAGE_CONTEXT")
#define		HSDK_E_INVALID_CALLBACK_RENITM	   _T("HSDK_E_INVALID_CALLBACK_RENITM")
#define		HSDK_E_INVALID_CALLBACK_MOVITM	   _T("HSDK_E_INVALID_CALLBACK_MOVITM")
// PR#4664, e.Refactoring Additions and Changes

// PR# 5740 - start for MovePackage process Target Project and State missing err msgs
#define HSDK_E_NO_TARGET_PROJECT		_T("HSDK_E_NO_TARGET_PROJECT")
#define HSDK_E_NO_TARGET_STATE			_T("HSDK_E_NO_TARGET_STATE")
// PR# 5740 - end

#endif

