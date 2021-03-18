//----------------------------------------------------+-------------------------------------------------
// FILENAME:           hsdksample.cpp
//
// DESCRIPTION:        Sample Program for HSDK module.
//
// NOTES:  
//      1) Environment, State, and Process names are case sensitive.
//      2) REQUIRED INITIAL CONDITIONS:
//          This program is written based on a testing scenario which has a Project named
//          "SDKSampleProject".  It has 2 states: "state-1" and "state-2". 
//          Both states have a repository which has a viewpath "\sdkrep".  
//          The "state-1" has processes named: 
//              "Approve"			: Approve process - with skduser to approve. or the user being used to login
//              "Promote"			: Promote process					
//              "Checkin"			: CheckIn process
//              "Checkout"			: CheckOut process
//              "Concurrent Merge"	: ConcurrentMerge processs
//              "Create Package"	: CreatePackage process
//              "Delete Package"	: DeletePackage process
//              "Delete Versions"   : Delete versions process
//              "Remove Item"       : RemoveItem process
//              "Take Snapshot"     : TakeSnapshotView process
//              "Move Item"			: MoveItem process
//              "Move Path"			: MovePath process
//              "Remove Path"       : RemovePath process
//              "Rename Path"       : RenamePath process
//
//          The "state-2" has processes named: 
//              "Demote"            : Demote package process
//
//          The following client directory exists:
//              PC CLIENT_DIR	 	"c:\\temp\\hsdkdir\\"
//              UNIX CLIENT_DIR	 	"."
//
//          The Project has a user named 'sdkuser' with password 'sdkpass'. 
//           
//
// AUTHOR:             Michael Scott
//
// REVISION HISTORY:
//           04-26-01   MAS     File Creation
// PR3450    11-10-04   LS      added ifdef to include <iostream.h> if using gnu compiler
// PR4026    02-01-05   JS      SAMPLE HSDK-MSG IN O/P AND LOG
// PR4664    01-10-07 faudo01   Add changes for refactoring classes and methods
// PR7574    02-13-07 chaga04   HSDK SAMPLE PROGRAM PROBLEMS
//
// Copyright (c) 2001-2007 Computer Associates inc. All rights reserved. 
//
//----------------------------------------------------+-------------------------------------------------

//  TYPEDEF STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  DEFINE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------


//  INCLUDE STATEMENTS:
//------------------------------------------------------+-----------------------------------------------
#include <hsdk.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1300)//PR#4935
# include <fstream>
  using namespace std;
#else
# include <fstream.h>
#endif

#include <time.h>
#if defined (WIN32)
#include <io.h>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include <sys/stat.h>

#if defined(__GNUC__)
#include <iostream.h>
#endif

//  GLOBAL CONTEXT VARIABLES:
//------------------------------------------------------+-----------------------------------------------
CaString gszProjectName = _T("SDKSampleProject");
CaString gszStateName1 = _T("state-1");
CaString gszStateName2 = _T("state-2");
CaString gszStateSnapshot = _T("viewsnapshot-0");

CaString gszCheckoutName = _T("Checkout");
CaString gszCheckinName = _T("Checkin");
CaString gszPromoteName = _T("Promote");
CaString gszApproveName = _T("Approve");
CaString gszDemoteName = _T("Demote");
CaString gszCreatePackageName = _T("Create Package");
CaString gszDeleteVersionName = _T("Delete Versions");
CaString gszRemoveItemName = _T("Remove Item");
CaString gszConcurrentMergeName = _T("Concurrent Merge");
CaString gszTakeSnapshotName = _T("Take Snapshot");

//PR#4664, b.Add new process names for new R12 processes
CaString gszDeletePackageName = _T("Delete Package");
CaString gszMoveItemName = _T("Move Item");
CaString gszMovePathName = _T("Move Path");
CaString gszRenamePathName = _T("Rename Path");
CaString gszRemovePathName = _T("Remove Path");

CaString gszPackageNameRef = _T("Refactoring");
CaString gszFileNameRef = _T("HSDKRefTestFile.txt");
CaString gszMoveItemPathName = _T("MoveItem");
CaString gszMoveItemPath = _T("\\sdkrep\\MoveItem");
CaString gszMovePathPathName = _T("MovePath");
CaString gszMovePathPath = _T("\\sdkrep\\MovePath");
CaString gszMovePathMoveItemPath = _T("\\sdkrep\\MovePath\\MoveItem");
CaString gszRenamePathPathName = _T("RenamePath");
CaString gszMovePathRenamePathPath = _T("\\sdkrep\\MovePath\\RenamePath");
//PR#4664, e.Add new process names for new R12 processes

CaString gszViewPath = _T("\\sdkrep");
CaString gszFileName = _T("HSDKTestFile.txt");
CaString gszPackageName = _T("pkg1");
CaString gszNewPackageName = _T("Non-Refactoring");
CaString gszSnapshotViewName = _T("Snapshot of state-1");
CaString szUserName = _T("");
CaString szPassword = _T("");

#if defined(WIN32)
CaString gszClientPath = _T("c:\\temp\\hsdkdir"); // Client path and delimiter are platform specific
CaString gszDelimiter = _T("\\");
#else 
CaString gszClientPath = _T("."); // Client path and delimiter are platform specific
CaString gszDelimiter = _T("/");
#endif


CaString CreateTemporaryName( LPCTSTR szprefixname )
{
	time_t ltime;
    TCHAR szTestObjName[129];
	time( &ltime ) ;
	_stprintf( szTestObjName, _T("%s%s%d"), szprefixname, _T("-") ,ltime  ); 

    return CaString(szTestObjName);
}


//------------------------------------------------------+-----------------------------------------------
// FUNCTION NAME:   TestExceptionHandler
//
//
// DESCRIPTION:     Test basic CaException operation
//
// PARAMETERS:         
//                  CaHarvest &h - A referent to the Harvest object currently logged into.
//
// SIDE EFFECTS:    None.
//
// NOTES:              
//      1) This test outputs various error messages to the log file. It is supposed to do so.
//         The results must be verified visually.
//
// RETURN VALUES:   true if success, false if fails
//
//------------------------------------------------------+-----------------------------------------------
bool TestExceptionHandler(CaHarvest &h)
{
    ostream &o = h.GetLog();
    HINT32 iResult = HSDKBAD;
    bool bResult = false;
    CaException gEx(false, _T("Default Exception Handler"));
    gEx.SetReturnCode(iResult);

    o << endl << CaString(_T("--- Begin TestExceptionHandler ---")) << endl;

    try
    {
        CaException ex(HSDK_E_NO_VERSION_LIST);
        ex.SetReturnCode(iResult);
        throw ex;


    } // end try
    catch(CaException ex)
    {
        iResult = HSDKOK;
        ex.LogMessage();
        ex.SetReturnCode(iResult);
        gEx = ex;

    } // end catch

    try
    {
        if(gEx.GetReturnCode() != HSDKOK)
            throw false;

        CaString szExWKey = _T("E0309001a: ERROR: Could not retrieve Version list.");
        CaException exWKey(true, HSDK_E_NO_VERSION_LIST);
        exWKey.LogMessage();
        CaString szResult = exWKey.GetMessage();
        if(szResult != szExWKey)
        {
            throw false;
        }

        CaString szExWOKey = _T("Exception Without Key");
        CaException exWOKey(false, (LPCTSTR)szExWOKey);
        exWOKey.LogMessage();
        szResult = exWOKey.GetMessage();
        if(szResult != szExWOKey)
        {
            throw false;
        }

        CaException exWInvKey(true, _T("Exception With Bad Key"));
        exWInvKey.LogMessage();

    }
    catch(bool)
    {
        o << CaString(_T("***A test condition failed during TestExceptionHandler.***")) << endl;
        iResult = HSDKBAD;
    } // end catch

    catch(...)
    {
        o << CaString(_T("***An unexpected error occured during TestExceptionHandler.***")) << endl;
        iResult = HSDKBAD;
    } // end catch

    o << endl << CaString(_T("--- End TestExceptionHandler ---")) << endl;
    bResult = iResult ? false : true;
    return bResult;

} // TestExceptionHandler


//------------------------------------------------------+-----------------------------------------------
// FUNCTION NAME:   HSDKSampleOperation
//
//
// DESCRIPTION:     Test basic HSDK operation
//
// PARAMETERS:         
//                  CaHarvest &h - A referent to the Harvest object currently logged into.
//
// SIDE EFFECTS:    Current Context is set by last operation run.
//
// NOTES:              
//      1) This test depends on an SDKSampleProject existing as per the instructions in the
//         header portion of this file.
//      2) The order of operations allows this test to be run multiple times.
//      3) If this test fails all versions of the test file must be removed prior to another run.
//
// TEST SCENARIO:
//      - Get Log stream and Current Context from Harvest object.
//      - Set Current Context to the SDKSampleProject, state-1, View Path, Client Path, 
//          and each process in state-1.
//      - Create a Package to use.
//      - Create a test file in the Client Path directory. If file exists set to read/write.
//      - Checkin the file.
//      - Checkout the file for concurrent update.
//      - Edit the file prior to checkin.
//      - Checkin the updated file.
//      - Perform a Concurrent Merge on the package.
//      - Perform a Remove Item on the checked in Item.
//      - Verify that Item's Version Tree is correct in Package.
//      - Delete all version of the Item, from version 0 through the 'D' version.
//      - Approve the Package.
//      - Promote the Package to state-2.
//      - Set Current Context to state-2 with Demote Process.
//      - Demote the Package to state-1.
//
// RETURN VALUES:   true if success, false if fails
//
//------------------------------------------------------+-----------------------------------------------
bool HSDKSampleOperation(CaHarvest &h)
{
    ostream &o = h.GetLog();
    HINT32 iResult = HSDKOK;
    bool bResult = false;
    CaString szFullFilePath = _T("");

    o << endl << CaString(_T("--- Begin HSDKSampleOperation ---")) << endl;

    try
    {
	int i,j;
        //  Establish Context:
        //----------------------------------------------+-----------------------------------------------
        CaContext& rContext = h.GetContext();           // Retrieve context from Harvest object
        if(!rContext)
            throw CaException(false, _T("Error: Could not get context."));

        CaContainer bag = h.GetProjectList();           // Verify Project name is in list and set it.

        CaDataArray a = bag.FindData(CA_ATTRKEY_NAME, (LPCTSTR)gszProjectName);
        if(a.GetSize() == 0)
            throw CaException(false, _T("Error: Project not found."));
        HAROBJID iObjid = (HINT32)bag.Props(CA_ATTRKEY_OBJID,a[0]);
        if(!rContext.SetProject(iObjid))
            throw CaException(false, _T("Error: Could not set context project."));

        CaString szProjectName = rContext.GetProjectName();
        if(szProjectName != gszProjectName)
            throw CaException(false, _T("Error: Could Not Set Project."));

        CaContainer cTemp = (CaContainer) rContext.GetStateList();
		bag = cTemp;
        //bag = rContext.GetStateList();                  // Verify State name is in list and set it.

        a = bag.FindData(CA_ATTRKEY_NAME, (LPCTSTR)gszStateName1);
        if(a.GetSize() == 0)
            throw CaException(false, _T("Error: State not found."));
        iObjid = (HINT32)bag.Props(CA_ATTRKEY_OBJID,a[0]);
        if(!rContext.SetState(iObjid))
            throw CaException(false, _T("Error: Could not set context State."));

        CaString szStateName = rContext.GetStateName();
        if(szStateName != gszStateName1)
            throw CaException(false, _T("Error: Could Not Set State."));

        rContext.SetViewPath(gszViewPath);              // Set View Path

        CaContainer cTemp2 = (CaContainer) rContext.GetProcessList();
        bag = cTemp2;
        //bag = rContext.GetProcessList();                // Verify Create Package process in list and set it.

        a = bag.FindData(CA_ATTRKEY_NAME, (LPCTSTR)gszCreatePackageName);
        if(a.GetSize() == 0)
            throw CaException(false, _T("Error: CreatePackage process not found."));
        iObjid = (HINT32)bag.Props(CA_ATTRKEY_OBJID,a[0]);
        if(!rContext.SetCreatePackage(iObjid))
            throw CaException(false, _T("Error: Could not set context CreatePackage Process."));

        CaString szCreatePackageName = rContext.GetCreatePackageName();
        if(szCreatePackageName != gszCreatePackageName)
            throw CaException(false, _T("Error: Could Not Set CreatePackage."));

        if(!rContext.SetCheckout(gszCheckoutName))      // Set Checkout process
            throw CaException(false, _T("Error: Could not set context Checkout Process."));
        CaString szCheckoutName = rContext.GetCheckoutName();
        if(szCheckoutName != gszCheckoutName)
            throw CaException(false, _T("Error: Could Not Set Checkout."));

        if(!rContext.SetCheckin(gszCheckinName))        // Set Checkin process
            throw CaString(_T("Error: Could not set context Checkin Process."));
        CaString szCheckinName = rContext.GetCheckinName();
        if(szCheckinName != gszCheckinName)
            throw CaException(false, _T("Error: Could Not Set Checkin."));

        if(!rContext.SetApprove(gszApproveName))        // Set Approve process
            throw CaString(_T("Error: Could not set context Approve Process."));
        CaString szApproveName = rContext.GetApproveName();
        if(szApproveName != gszApproveName)
            throw CaException(false, _T("Error: Could Not Set Approve."));

        if(!rContext.SetPromote(gszPromoteName))        // Set Promote process
            throw CaString(_T("Error: Could not set context Promote Process."));
        CaString szPromoteName = rContext.GetPromoteName();
        if(szPromoteName != gszPromoteName)
            throw CaException(false, _T("Error: Could Not Set Promote."));

        if(!rContext.SetDeleteVersion(gszDeleteVersionName)) // Set DeleteVersion process
            throw CaString(_T("Error: Could not set context DeleteVersion Process."));
        CaString szDeleteVersionName = rContext.GetDeleteVersionName();
        if(szDeleteVersionName != gszDeleteVersionName)
            throw CaException(false, _T("Error: Could Not Set DeleteVersion."));

        if(!rContext.SetRemoveItem(gszRemoveItemName))  // Set RemoveItem process
            throw CaString(_T("Error: Could not set context RemoveItem Process."));
        CaString szRemoveItemName = rContext.GetRemoveItemName();
        if(szRemoveItemName != gszRemoveItemName)
            throw CaException(false, _T("Error: Could Not Set RemoveItem."));

        if(!rContext.SetConcurrentMerge(gszConcurrentMergeName)) // Set ConcurrentMerge process
            throw CaString(_T("Error: Could not set context ConcurrentMerge Process."));
        CaString szConcurrentMergeName = rContext.GetConcurrentMergeName();
        if(szConcurrentMergeName != gszConcurrentMergeName)
            throw CaException(false, _T("Error: Could Not Set ConcurrentMerge."));

	    if(!rContext.SetTakeSnapshot(gszTakeSnapshotName)) // Set TakeSnapshot process
            throw CaString(_T("Error: Could not set context TakeSnapshot Process."));
        CaString szTakeSnapshotName = rContext.GetTakeSnapshotName();
        if(szTakeSnapshotName != gszTakeSnapshotName)
            throw CaException(false, _T("Error: Could Not Set TakeSnapshot."));

//PR#4664, b.Establish context for new R12 processes
        if(!rContext.SetMoveItem(gszMoveItemName))  // Set MoveItem process
            throw CaString(_T("Error: Could not set context MoveItem Process."));
        CaString szMoveItemName = rContext.GetMoveItemName();
        if(szMoveItemName != gszMoveItemName)
            throw CaException(false, _T("Error: Could Not Set MoveItem."));

        if(!rContext.SetMovePath(gszMovePathName))  // Set MovePath process
            throw CaString(_T("Error: Could not set context MovePath Process."));
        CaString szMovePathName = rContext.GetMovePathName();
        if(szMovePathName != gszMovePathName)
            throw CaException(false, _T("Error: Could Not Set MovePath."));

        if(!rContext.SetRemovePath(gszRemovePathName))  // Set RemovePath process
            throw CaString(_T("Error: Could not set context RemovePath Process."));
        CaString szRemovePathName = rContext.GetRemovePathName();
        if(szRemovePathName != gszRemovePathName)
            throw CaException(false, _T("Error: Could Not Set RemovePath."));

        if(!rContext.SetRenamePath(gszRenamePathName))  // Set RenamePath process
            throw CaString(_T("Error: Could not set context RenamePath Process."));
        CaString szRenamePathName = rContext.GetRenamePathName();
        if(szRenamePathName != gszRenamePathName)
            throw CaException(false, _T("Error: Could Not Set RenamePath."));

        if(!rContext.SetDeletePackage(gszDeletePackageName)) // Set DeletePackage process
            throw CaString(_T("Error: Could not set context DeletePackage Process."));
        CaString szDeletePackageName = rContext.GetDeletePackageName();
        if(szDeletePackageName != gszDeletePackageName)
            throw CaException(false, _T("Error: Could Not Set DeletePackage."));
//PR#4664, e.Establish context for new R12 processes
        
		o << CaString(_T("Established basic Harvest Context.")) << endl;

//PR#4664, b.Refactoring and Delete Package tests
        //  Create a package:
        //----------------------------------------------+-----------------------------------------------
        CaCreatePackage &rCreatePackageRef = rContext.GetCreatePackage();

        rCreatePackageRef.SetPackageName(gszPackageNameRef); // Set Process options
        rCreatePackageRef.SetAssignedUserName(szUserName); // Set Process options
        rCreatePackageRef.SetPriority(1);
        rCreatePackageRef.SetDescription(_T("A Description"));
        if(rCreatePackageRef.Execute())
            throw CaException(false, _T("Error: CreatePackage Failed."));

        o << CaString(_T("Created Package: ")) << gszPackageNameRef << endl;

        if (!rContext.SetPackage(gszPackageNameRef))        // Set new package to context
            throw CaException(false, _T("Error: Could not set package context."));

        //  Create a File to checkin and manipulate:
        //----------------------------------------------+-----------------------------------------------
        szFullFilePath = gszClientPath;
        szFullFilePath += gszDelimiter;
        szFullFilePath += gszFileNameRef;
        chmod((char*)szFullFilePath, S_IWRITE);
        ofstream oTestFileRef((char*)szFullFilePath, ios::out | ios::trunc); // File to checkin and manipulate
        oTestFileRef << "This is a test file for refactoring: " << (char*)szFullFilePath << endl;
        oTestFileRef.close();

        //  Checkin the file:
        //----------------------------------------------+-----------------------------------------------
        CaCheckin &rCheckinRef = rContext.GetCheckin();

        CaStringList FileListRef;                       // Setup file list for checkin
        FileListRef.Add(gszFileNameRef);

        rCheckinRef.SetFileList(FileListRef);                 // Set Checkin options
        rCheckinRef.SetCheckinMode(HAR_UPDATE_AND_RELEASE);
        rCheckinRef.SetClientDir(gszClientPath);
        rCheckinRef.SetPathOption(CI_OPTION_ALL_FILE_TO_SAME_PATH);
        rCheckinRef.SetItemOption(CI_FILTER_NEW_OR_EXISTING_ITEMS);

        if(rCheckinRef.Execute())
            throw CaException(false, _T("Error: Checkin Failed."));

        o << CaString(_T("Checked in file: ")) << gszFileNameRef << endl;

		//  Move Item:
        //----------------------------------------------+-----------------------------------------------
		CaMoveItem &rMoveItem = rContext.GetMoveItem();

		if (rCheckinRef.CreateItemPath(gszMoveItemPathName, gszViewPath))
            throw CaException(false, _T("Error: CreateItemPath Failed."));

		rMoveItem.SetItemName(gszFileNameRef);
		rMoveItem.SetItemPath(gszViewPath);
		rMoveItem.SetTargetItemPath(gszMoveItemPath);
        rMoveItem.SetDescription(_T("Moving an item"));

        if (rMoveItem.Execute())
            throw CaException(false, _T("Error: MoveItem Failed."));

		//  Move Path:
        //----------------------------------------------+-----------------------------------------------
		CaMovePath &rMovePath = rContext.GetMovePath();

		if (rCheckinRef.CreateItemPath(gszMovePathPathName, gszViewPath))
            throw CaException(false, _T("Error: CreateItemPath Failed."));

		rMovePath.SetItemPath(gszMoveItemPath);
		rMovePath.SetTargetItemPath(gszMovePathPath);
        rMovePath.SetDescription(_T("Moving a path"));

        if (rMovePath.Execute())
            throw CaException(false, _T("Error: MovePath Failed."));

		//  Rename Path:
        //----------------------------------------------+-----------------------------------------------
		CaRenamePath &rRenamePath = rContext.GetRenamePath();

		rRenamePath.SetItemPath(gszMovePathMoveItemPath);
		rRenamePath.SetNewItemPathName(gszRenamePathPathName);
        rRenamePath.SetDescription(_T("Renaming a path"));

        if (rRenamePath.Execute())
            throw CaException(false, _T("Error: RenamePath Failed."));

		//  Remove Path:
        //----------------------------------------------+-----------------------------------------------
		CaRemovePath &rRemovePath = rContext.GetRemovePath();

		rRemovePath.SetItemPath(gszMovePathRenamePathPath);
        rRemovePath.SetDescription(_T("Removing a path"));

        if (rRemovePath.Execute())
            throw CaException(false, _T("Error: RemovePath Failed."));

        //  Verify Versions in Package:
        //----------------------------------------------+-----------------------------------------------
        CaVersionChooser& rVersionChooserRef = rContext.GetVersionChooser();

		rVersionChooserRef.Clear();
        rVersionChooserRef.SetPackageObjId(rContext.GetPackageId());
        rVersionChooserRef.SetRecursive(true);
        rVersionChooserRef.SetVersionStatusOption(VERSION_FILTER_ALL_TAG);
        rVersionChooserRef.SetVersionOption(VERSION_FILTER_ALL_IN_VIEW);
        rVersionChooserRef.SetParentPath(gszViewPath);
        rVersionChooserRef.Execute();
        CaContainer cTempRef = (CaContainer)rVersionChooserRef.GetVersionList();
        bag = cTempRef;
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Versions in Package."));
        }

		//  Display the Refactoring version information
        //----------------------------------------------+-----------------------------------------------
		rVersionChooserRef.Clear();

		o << _T("Resultant Refactoring Package Version Information:") << endl;
        int iRefVerCount = (HINT32)bag.GetKeyElementCount(CA_ATTRKEY_MAPPED_VERSION_NAME);
        for (i=0, j=0; i < iRefVerCount; i++)
        {
			CaString szVersionName   = (LPCTSTR)bag.Props(CA_ATTRKEY_NAME, i);
			CaString szPathName      = (LPCTSTR)bag.Props(CA_ATTRKEY_FULL_PATH_NAME, i);
            CaString szMappedVersion = (LPCTSTR)bag.Props(CA_ATTRKEY_MAPPED_VERSION_NAME, i);
            CaString szVersionStatus = (LPCTSTR)bag.Props(CA_ATTRKEY_VERSION_STATUS, i);
            HINT32 iItemId           = (HINT32)bag.Props(CA_ATTRKEY_ITEMID, i);
            HINT32 iVersId           = (HINT32)bag.Props(CA_ATTRKEY_OBJID, i);
            HINT32 iParentVersId     = (HINT32)bag.Props(CA_ATTRKEY_PARENT_VERSIONID, i);

			o << _T("   ") << szPathName << _T("/") << szVersionName << _T(":") << szMappedVersion << _T("[") << szVersionStatus << _T("]") << 
				_T(" Item:")<<iItemId << _T(" Vers:")<<iVersId << _T(" ParVers:")<<iParentVersId <<  endl;

			if (_tcscmp((LPCTSTR)szVersionName, (LPCTSTR)gszRenamePathPathName)==0  &&
				_tcscmp((LPCTSTR)szPathName,    (LPCTSTR)gszMovePathPath)==0)
			{
		        rVersionChooserRef.SetVersionObjId((HINT32)bag.Props(CA_ATTRKEY_OBJID,i), j++);				
			}
        }

		//  Delete RenamePath Path Versions
        //----------------------------------------------+-----------------------------------------------
        rVersionChooserRef.SetPackageObjId(rContext.GetPackageId());
//        rVersionChooserRef.SetItemName(gszRenamePathPathName);
        rVersionChooserRef.SetRecursive(false);
//        rVersionChooserRef.SetParentPath(gszMovePathPath);
        rVersionChooserRef.SetVersionStatusOption(VERSION_FILTER_ALL_TAG);
        rVersionChooserRef.SetVersionOption(VERSION_FILTER_ALL_IN_VIEW);
        rVersionChooserRef.Execute();
        cTempRef = (CaContainer)rVersionChooserRef.GetVersionList();
        bag = cTempRef;
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No RenamePath Versions in Package."));
        }

        //----------------------------------------------+-----------------------------------------------
		o << _T("Filtered Refactoring Package Versions to Delete:") << endl;
        iRefVerCount = (HINT32)bag.GetKeyElementCount(CA_ATTRKEY_MAPPED_VERSION_NAME);
        for (i=0; i < iRefVerCount; i++)
        {
			CaString szVersionName   = (LPCTSTR)bag.Props(CA_ATTRKEY_NAME, i);
			CaString szPathName      = (LPCTSTR)bag.Props(CA_ATTRKEY_FULL_PATH_NAME, i);
            CaString szMappedVersion = (LPCTSTR)bag.Props(CA_ATTRKEY_MAPPED_VERSION_NAME, i);
            CaString szVersionStatus = (LPCTSTR)bag.Props(CA_ATTRKEY_VERSION_STATUS, i);
            HINT32 iItemId           = (HINT32)bag.Props(CA_ATTRKEY_ITEMID, i);
            HINT32 iVersId           = (HINT32)bag.Props(CA_ATTRKEY_OBJID, i);
            HINT32 iParentVersId     = (HINT32)bag.Props(CA_ATTRKEY_PARENT_VERSIONID, i);

			o << _T("   ") << szPathName << _T("/") << szVersionName << _T(":") << szMappedVersion << _T("[") << szVersionStatus << _T("]") << 
				_T(" Item:")<<iItemId << _T(" Vers:")<<iVersId << _T(" ParVers:")<<iParentVersId <<  endl;
        }
        
        CaDeleteVersion &rDeleteVersionRef = rContext.GetDeleteVersion();
        if (rDeleteVersionRef.Execute())    
            throw CaException(false, _T("Error: DeleteVersion Failed."));

        o << CaString(_T("Deleted All Versions of RenamePath in Refactoring package: ")) << endl;

		//  Delete other versions in the Refactoring package
        //----------------------------------------------+-----------------------------------------------
		rVersionChooserRef.Clear();
        rVersionChooserRef.SetPackageObjId(rContext.GetPackageId());
        //rVersionChooserRef.SetItemName(gszFileNameRef);
        rVersionChooserRef.SetRecursive(true);
        rVersionChooserRef.SetVersionStatusOption(VERSION_FILTER_ALL_TAG);
        rVersionChooserRef.SetVersionOption(VERSION_FILTER_ALL_IN_VIEW);
        rVersionChooserRef.SetParentPath(gszViewPath);
        rVersionChooserRef.Execute();
        cTempRef = (CaContainer)rVersionChooserRef.GetVersionList();
        bag = cTempRef;
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Versions in Package."));
        }
        
        if(rDeleteVersionRef.Execute())    
            throw CaException(false, _T("Error: DeleteVersion Failed."));

        o << CaString(_T("Deleted All Versions in Refactoring package: ")) << endl;

        //  Delete Package:
        //----------------------------------------------+-----------------------------------------------
		CaDeletePackage &rDeletePackage = rContext.GetDeletePackage();

        if (rDeletePackage.Execute(gszPackageNameRef))
            throw CaException(false, _T("Error: DeletePackage Failed."));
//PR#4664, e.Refactoring and Delete Package tests

        //  Create a Package to use:
        //----------------------------------------------+-----------------------------------------------
        CaCreatePackage &rCreatePackage = rContext.GetCreatePackage();

        rCreatePackage.SetAssignedUserName(szUserName); // Set Process options
        rCreatePackage.SetPriority(1);
        rCreatePackage.SetDescription(_T("A Description"));
        rCreatePackage.SetPackageName(gszNewPackageName); 
        if(rCreatePackage.Execute())
            throw CaException(false, _T("Error: CreatePackage Failed."));

        gszPackageName = rCreatePackage.GetPackageName();   // Get name of new package
        o << CaString(_T("Created Package: ")) << gszPackageName << endl;

        if(!rContext.SetPackage(gszPackageName))        // Set new package to context
            throw CaException(false, _T("Error: Could not set package context."));

        //  Create a File to checkin and manipulate:
        //----------------------------------------------+-----------------------------------------------
        szFullFilePath= gszClientPath;
        szFullFilePath += gszDelimiter;
        szFullFilePath += gszFileName;
        chmod((char*)szFullFilePath, S_IWRITE);
        ofstream oTestFile((char*)szFullFilePath, ios::out | ios::trunc); // File to checkin and manipulate
        oTestFile << "This is a test file: " << (char*)szFullFilePath << endl;
        oTestFile.close();

        //  Checkin the file:
        //----------------------------------------------+-----------------------------------------------
        CaCheckin &rCheckin = rContext.GetCheckin();

        CaStringList FileList;                          // Setup file list for checkin
        FileList.Add(gszFileName);

        rCheckin.SetFileList(FileList);                 // Set Checkin options
        rCheckin.SetCheckinMode(HAR_UPDATE_AND_RELEASE);
        rCheckin.SetClientDir(gszClientPath);
        rCheckin.SetPathOption(CI_OPTION_ALL_FILE_TO_SAME_PATH);
        rCheckin.SetItemOption(CI_FILTER_NEW_OR_EXISTING_ITEMS);

        if(rCheckin.Execute())
            throw CaException(false, _T("Error: Checkin Failed."));

        o << CaString(_T("Checked in file: ")) << gszFileName << endl;


        //  Checkout the file for concurrent update:
        //----------------------------------------------+-----------------------------------------------
        CaCheckout &rCheckout = rContext.GetCheckout();

        CaVersionChooser& rVersionChooser = rContext.GetVersionChooser();
		rVersionChooser.Clear();
        rVersionChooser.SetItemName(gszFileName);
        rVersionChooser.SetRecursive(true);
        rVersionChooser.SetVersionStatusOption(VERSION_FILTER_ALL_TAG);
        rVersionChooser.SetBranchOption(BRANCH_FILTER_TRUNK_AND_BRANCH);
        rVersionChooser.SetVersionOption(VERSION_FILTER_LATEST_IN_VIEW);
        rVersionChooser.Execute();

        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Versions to Checkout."));
        }
        else
        {
            rCheckout.SetCheckoutMode(CO_MODE_CONCURRENT);
            rCheckout.SetClientDir(gszClientPath);
            rCheckout.SetPathOption(CO_OPTION_ALL_ITEM_TO_SAME_DIRECTORY);
            rCheckout.SetReplaceFile(true);

            if(rCheckout.Execute())
                throw CaException(false, _T("Error: Checkout Failed."));
        }

        o << CaString(_T("Checked out file for concurrent update: ")) << gszFileName << endl;


        //  Update File to checkin:
        //----------------------------------------------+-----------------------------------------------
        oTestFile.open((char*)szFullFilePath, ios::app);
        oTestFile << "This has been appended to the file." << endl;
        oTestFile.close();


        //  Checkin the file by version:
        //----------------------------------------------+-----------------------------------------------
        rVersionChooser.Clear();
        rVersionChooser.SetItemName(gszFileName);
        rVersionChooser.SetRecursive(true);
        rVersionChooser.SetVersionStatusOption(VERSION_FILTER_RESERVED_VERSION);
        rVersionChooser.SetVersionOption(VERSION_FILTER_LATEST_IN_VIEW);
        rVersionChooser.SetParentPath(gszViewPath);
        rVersionChooser.Execute();
        CaContainer cTemp4 = (CaContainer)  rVersionChooser.GetVersionList();
        bag = cTemp4;
        //bag = rVersionChooser.GetVersionList();
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Versions to Checkout."));
        }

        rCheckin.SetCheckinMode(HAR_UPDATE_AND_RELEASE);
        rCheckin.SetClientDir(gszClientPath);
        rCheckin.SetPathOption(CI_OPTION_ALL_FILE_TO_SAME_PATH);
        rCheckin.SetItemOption(CI_FILTER_NEW_OR_EXISTING_ITEMS);

        if(rCheckin.Execute(false))
            throw CaException(false, _T("Error: Checkin Failed."));

        o << CaString(_T("Checked in file by version: ")) << gszFileName << endl;


        //  Perform Concurrent Merge on Package:
        //----------------------------------------------+-----------------------------------------------
        CaConcurrentMerge &rConcurrentMerge = rContext.GetConcurrentMerge();
        rConcurrentMerge.SetVersionDescription(_T("A Concurrent Merge Description"));
        rConcurrentMerge.SetMergeRule(MERGE_RULE_CONFLICT_TAG);

        if(rConcurrentMerge.Execute())
            throw CaException(false, _T("Error: ConcurrentMerge Failed."));

        o << CaString(_T("Performed Concurrent Merge on Package: ")) << gszPackageName << endl;

		// Take a snapshot of state-0
		//----------------------------------------------+-----------------------------------------------
        
		CaTakeSnapshot &rTakeSnapshot = rContext.GetTakeSnapshot();
		CaString snapshotbyname = CreateTemporaryName( _T("TestSnapshotByName") ) ;
		
		// Take snapshot with current contents of state
        if( rTakeSnapshot.Execute( (LPCTSTR)snapshotbyname ) )
	        throw CaException( false, _T("Error: Snapshot by name Failed.") );

		o << CaString(_T("Performed Take Snapshot Process on State-1")) << snapshotbyname << endl << endl;

        //  Remove Item:
        //----------------------------------------------+-----------------------------------------------
        CaRemoveItem &rRemoveItem = rContext.GetRemoveItem();
        rRemoveItem.SetDescription(_T("A Remove Item Description"));
        rRemoveItem.SetItemName(gszFileName);
        rRemoveItem.SetItemPath(gszViewPath);
        rRemoveItem.SetRecursive(true);
        if(rRemoveItem.Execute())
            throw CaException(false, _T("Error: RemoveItem Failed."));

        o << CaString(_T("Performed Remove Item on: ")) << gszFileName << endl;


        //  Verify Versions in Package:
        //----------------------------------------------+-----------------------------------------------
        rVersionChooser.Clear();
        rVersionChooser.SetPackageObjId(rContext.GetPackageId());
        rVersionChooser.SetItemName(gszFileName);
        rVersionChooser.SetRecursive(true);
        rVersionChooser.SetVersionStatusOption(VERSION_FILTER_ALL_TAG);
        rVersionChooser.SetVersionOption(VERSION_FILTER_ALL_IN_VIEW);
        rVersionChooser.SetParentPath(gszViewPath);
        rVersionChooser.Execute();
        CaContainer cTemp5 = (CaContainer)  rVersionChooser.GetVersionList();
        bag = cTemp5;
        //bag = rVersionChooser.GetVersionList();
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Versions in Package."));
        }

        CaStringList szMappedVersions;
        szMappedVersions.Add(_T("0"));
        szMappedVersions.Add(_T("0.1.1"));
        szMappedVersions.Add(_T("1"));
        szMappedVersions.Add(_T("2"));
        int iVerCount = (HINT32)bag.GetKeyElementCount(CA_ATTRKEY_MAPPED_VERSION_NAME);
        for(i=0; i < iVerCount; i++)
        {
            CaString szMappedVersion = (LPCTSTR)bag.Props(CA_ATTRKEY_MAPPED_VERSION_NAME, i);
            if(szMappedVersion != szMappedVersions[i])
            {
                o << bag;
                throw CaException(false, _T("Error: Package Version Tree incorrect."));
            }
        }
        if((HINT32)bag.Props(CA_ATTRKEY_MERGED_VERSIONID, 2) == 0) // Version 2 should be merged
                throw CaException(false, _T("Error: Package Version Tree incorrect."));

        if(CaString(_T("D")) != (LPCTSTR)bag.Props(CA_ATTRKEY_VERSION_STATUS, 3)) // Version 3 is removed.
                throw CaException(false, _T("Error: Package Version Tree incorrect."));

        
        //  Delete All Versions of file:
        //----------------------------------------------+-----------------------------------------------
        CaDeleteVersion &rDeleteVersion = rContext.GetDeleteVersion();
        if(rDeleteVersion.Execute())    
            throw CaException(false, _T("Error: DeleteVersion Failed."));

        o << CaString(_T("Deleted All Versions of: ")) << gszFileName << endl;


        //  Approve Package:
        //----------------------------------------------+-----------------------------------------------
        CaApprove &rApprove = rContext.GetApprove();

        CaPackageChooser &rPackageChooser = rContext.GetPackageChooser(); // Set up package chooser
        rPackageChooser.Clear();
        rPackageChooser.SetPackageName(rContext.GetPackageName());
        rPackageChooser.Execute();
        CaContainer cTemp6 = (CaContainer) rPackageChooser.GetPackageList(); 
        bag = cTemp6;
        //bag = rPackageChooser.GetPackageList();
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Packages to Approve."));
        }
        else
        {
            rApprove.SetDescription(_T("This is an approval description"));
            rApprove.SetApprove(true);
            if(rApprove.Execute())
                throw CaException(false, _T("Error: Approve Failed."));
        }

        o << CaString(_T("Approved Package: ")) << gszPackageName << endl;


        //  Promote Package:
        //----------------------------------------------+-----------------------------------------------
        CaPromote &rPromote = rContext.GetPromote();
        if(rPromote.Execute())
            throw CaException(false, _T("Error: Promote Failed."));

        o << CaString(_T("Promoted package: ")) << gszPackageName << endl;


        //  Establish context to Demote Package:
        //----------------------------------------------+-----------------------------------------------
        if(!rContext.SetState(gszStateName2))
            throw CaException(false, _T("Error: Could not set context State."));

        if(!rContext.SetDemote(gszDemoteName))
            throw CaException(false, _T("Error: Could not set context Demote Process."));

        o << CaString(_T("Set context for Demote Package: ")) << gszPackageName << endl;


        //  Demote Package:
        //----------------------------------------------+-----------------------------------------------
        CaDemote &rDemote = rContext.GetDemote();
        rPackageChooser.Clear();
        rPackageChooser.SetPackageName(gszPackageName);
        rPackageChooser.Execute();
        CaContainer cTemp7 = (CaContainer) rPackageChooser.GetPackageList(); 
        bag = cTemp7;
        //bag = rPackageChooser.GetPackageList();
        if(bag.IsEmpty())
        {
            throw CaException(false, _T("Error: No Packages to Demote."));
        }
        else
        {
            if(rDemote.Execute())
                throw CaException(false, _T("Error: Demote Failed."));
        }

        o << CaString(_T("Demoted package: ")) << gszPackageName << endl;


    } // end try
    catch(CaException ex)
    {
        iResult = HSDKBAD;
        ex.LogMessage();
        ex.SetReturnCode(iResult);
    } // end catch

    catch(...)
    {
        o << CaString(_T("An unexpected error occured during HSDKSampleOperation.")) << endl;
        iResult = HSDKBAD;
    } // end catch

    o << endl << CaString(_T("--- End HSDKSampleOperation ---")) << endl;
    bResult = iResult ? false : true;
    return bResult;

} // HSDKSampleOperation


//------------------------------------------------------+-----------------------------------------------
// FUNCTION NAME:   main
//
//
// DESCRIPTION:     Main routine to run HSDK Sample Programs.
//
// PARAMETERS:         
//                  int argc
//                  char** argv
//
// SIDE EFFECTS:    Current Context is set by last operation run.
//
// NOTES:              
//      1) This test depends on an SDKSampleProject existing as per the instructions in the
//         header portion of this file.
//      2) A Broker name must be passed to this program.
//      3) Usage: hsdksample -b brokername [-u username] [-p password]
//
// RETURN VALUES:   zero if success, non-zero if fails
//
//------------------------------------------------------+-----------------------------------------------
int main(int argc,char**argv)
{
  CaString szBrokerName = _T("");
  bool bHaveBrokerName = false;
  bool bHaveUser = false;
  bool bHavePswd = false;
  bool bResult = false;
  int i;

  for(i = 0; i < argc; i++) // Set broker based on -b flag 
  {
    if(strcmp(argv[i], "-b") == 0)
    {
      if(argc <= i)
      {
        cout << CaString(_T("Must give broker name")) << endl;
        exit(1);
      }
      bHaveBrokerName = true;
      szBrokerName = argv[i+1];
    } // end if broker 

	if(strcmp(argv[i], "-u") == 0)  // set users based on -u flag
	{
		bHaveUser = true;
        szUserName = argv[i+1];
    }

    if(strcmp(argv[i], "-p") == 0)  // set password based on -p flag
	{
		bHavePswd = true;
        szPassword = argv[i+1];
    }


  } // end for all args 

  if(!bHaveBrokerName)
  {
	cout << CaString(_T("Must give broker name")) << endl;
	exit(1);
  }

  if(!bHaveUser)
  {
      // user default user harvest and default password 
    // pr# 4026
	cout << CaString(_T("Using default user sdkuser with default password")) << endl;
	//cout << CaString(_T("Using default user harvest with default password")) << endl;
	// end of pr# 4026

    szUserName = _T("sdkuser");
    szPassword = _T("sdkpass"); 
  }
    CaHarvest h;
    ofstream logfile("HSDKSample.log"); //@@@ ostreams must take char*
    h.SetLog(logfile);

    ostream &o = h.GetLog();

    try
    {
/*
        if(h.Login(szBrokerName, szUserName, szPassword))
            throw CaString(_T("Error: Could not attach to broker."));*/ //PR 7574
		// PR 7574 START
		if(h.SetBroker(szBrokerName))
			throw CaString(_T("Error: Could not attach to broker."));
		if(h.Login(szUserName, szPassword))
            throw CaString(_T("Error: Could not login to broker."));
		// PR 7574 END

        o << CaString(_T("Created session")) << endl;

        bResult = TestExceptionHandler(h);
        if(!bResult)
            exit(2);

        bResult = HSDKSampleOperation(h);
        if(!bResult)
            exit(3);

        h.Logout();

        // Login again to verify it works
        if(h.Login(szBrokerName, szUserName, szPassword))
            throw CaString(_T("Error: Could not attach to broker."));
        CaContext& rContext = h.GetContext();           // Retrieve context from Harvest object
        if(!rContext)
            throw CaException(false, _T("Error: Could not get context."));

        if(!rContext.SetProject(gszProjectName))
            throw CaException(false, _T("Error: Could not set context project."));
        h.Logout();

    } // end try

    catch(CaException ex)
    {
        ex.LogMessage();
        exit(1000);
    } // end catch

    catch(CaString szMsg)
    {
        o << szMsg << endl;
        o << CaString(_T("An unexpected error occured during the HSDK Sample Program.")) << endl;

        exit(1001);
    } // end catch

    catch(...)
    {
        o << CaString(_T("An unexpected error occured during the HSDK Sample Program.")) << endl;
        exit(1002);
    } // end catch

  // If it gets this far it has passed. The Event tests' results should still be inspected
    o << CaString(_T("The HSDK Sample Program Completed Successfully.")) << endl;
    return(0);

} // end main
