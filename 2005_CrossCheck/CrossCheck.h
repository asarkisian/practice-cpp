// CrossCheck.h : main header file for the CROSSCHECK application
//

#if !defined(AFX_CROSSCHECK_H__B63233F6_D987_47BD_8D0F_56D32386D5C7__INCLUDED_)
#define AFX_CROSSCHECK_H__B63233F6_D987_47BD_8D0F_56D32386D5C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCrossCheckApp:
// See CrossCheck.cpp for the implementation of this class
//

class CCrossCheckApp : public CWinApp
{
public:
	CCrossCheckApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrossCheckApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCrossCheckApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CROSSCHECK_H__B63233F6_D987_47BD_8D0F_56D32386D5C7__INCLUDED_)
