; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCrossCheckDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CrossCheck.h"

ClassCount=3
Class1=CCrossCheckApp
Class2=CCrossCheckDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CROSSCHECK_DIALOG
Resource4=IDR_MENU1

[CLS:CCrossCheckApp]
Type=0
HeaderFile=CrossCheck.h
ImplementationFile=CrossCheck.cpp
Filter=N

[CLS:CCrossCheckDlg]
Type=0
HeaderFile=CrossCheckDlg.h
ImplementationFile=CrossCheckDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_SCAN_NOW

[CLS:CAboutDlg]
Type=0
HeaderFile=CrossCheckDlg.h
ImplementationFile=CrossCheckDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CROSSCHECK_DIALOG]
Type=1
Class=CCrossCheckDlg
ControlCount=9
Control1=ID_SCAN_NOW,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342181902
Control4=IDC_STATIC,button,1342177287
Control5=IDC_PROGRESS_BAR,msctls_progress32,1350565888
Control6=IDC_CHECK_SCAN_FILES,button,1342242819
Control7=IDC_CHECK_SCAN_REGISTRY,button,1342242819
Control8=IDC_CHECK_SCAN_ALL,button,1342242819
Control9=IDC_BUTTON3,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_FILE_EXIT
Command2=ID_HELP_ABOUT
CommandCount=2

