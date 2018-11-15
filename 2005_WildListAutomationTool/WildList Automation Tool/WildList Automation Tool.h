// WildList Automation Tool.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "BrowseCtrl.h"
#include "resource.h"		// main symbols

#include "shlobj.h"
#include <string>

// CWildListAutomationToolApp:
// See WildList Automation Tool.cpp for the implementation of this class
//

class CWildListAutomationToolApp : public CWinApp
{
public:
	CWildListAutomationToolApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWildListAutomationToolApp theApp;