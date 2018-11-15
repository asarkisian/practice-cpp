// WildList Automation ToolDlg.h : header file
//

#pragma once



// CWildListAutomationToolDlg dialog
class CWildListAutomationToolDlg : public CDialog
{
// Construction
public:
	CWildListAutomationToolDlg(CWnd* pParent = NULL);	// standard constructor

	CBrowseCtrl m_wndCtrl1, m_wndCtrl2, m_wndCtrl3, m_wndCtrl4 ;
	CEdit m_edit1, m_edit2;

	CProgressCtrl m_Progress;

// Dialog Data
	enum { IDD = IDD_WILDLISTAUTOMATIONTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedButton5();
};
