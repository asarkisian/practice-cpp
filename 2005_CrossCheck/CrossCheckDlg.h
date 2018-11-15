// CrossCheckDlg.h : header file
//

#if !defined(AFX_CROSSCHECKDLG_H__5345553A_3EF5_469F_A70B_5F09B26E38CF__INCLUDED_)
#define AFX_CROSSCHECKDLG_H__5345553A_3EF5_469F_A70B_5F09B26E38CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCrossCheckDlg dialog

class CCrossCheckDlg : public CDialog
{
// Construction
public:
	CCrossCheckDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCrossCheckDlg)
	enum { IDD = IDD_CROSSCHECK_DIALOG };
	CProgressCtrl	m_progress_bar;
	BOOL	m_scan_all;
	BOOL	m_scan_files;
	BOOL	m_scan_registry;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrossCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCrossCheckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnCheckScanAll();
	afx_msg void OnCheckScanFiles();
	afx_msg void OnCheckScanRegistry();
	afx_msg void OnScanNow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CROSSCHECKDLG_H__5345553A_3EF5_469F_A70B_5F09B26E38CF__INCLUDED_)
