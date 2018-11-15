// WildList Automation ToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WildList Automation Tool.h"
#include "WildList Automation ToolDlg.h"

#include <string>

using std::string;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

bool GetFolder(std::string& folderpath, 
               const char* szCaption = NULL, 
               HWND hOwner = NULL)
{
   bool retVal = false;

   // The BROWSEINFO struct tells the shell 
   // how it should display the dialog.
   BROWSEINFO bi;
   memset(&bi, 0, sizeof(bi));

   bi.ulFlags   = BIF_USENEWUI;
   bi.hwndOwner = hOwner;
   bi.lpszTitle = szCaption;

   // must call this if using BIF_USENEWUI
   ::OleInitialize(NULL);

   // Show the dialog and get the itemIDList for the 
   // selected folder.
   LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

   if(pIDL != NULL)
   {
      // Create a buffer to store the path, then 
      // get the path.
      char buffer[_MAX_PATH] = {'\0'};
      if(::SHGetPathFromIDList(pIDL, buffer) != 0)
      {
         // Set the string value.
         folderpath = buffer;
         retVal = true;
      }

      // free the item id list
      CoTaskMemFree(pIDL);
   }

   ::OleUninitialize();

   return retVal;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWildListAutomationToolDlg dialog




CWildListAutomationToolDlg::CWildListAutomationToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWildListAutomationToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWildListAutomationToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON1, m_wndCtrl1);
	DDX_Control(pDX, IDC_BUTTON2, m_wndCtrl2);

	DDX_Control( pDX, IDC_EDIT1, m_edit1 );
	DDX_Control( pDX, IDC_EDIT2, m_edit2 );

	DDX_Control( pDX, IDC_PROGRESS1, m_Progress );
}

BEGIN_MESSAGE_MAP(CWildListAutomationToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CWildListAutomationToolDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CWildListAutomationToolDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CWildListAutomationToolDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CWildListAutomationToolDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CWildListAutomationToolDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CWildListAutomationToolDlg message handlers

BOOL CWildListAutomationToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWildListAutomationToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWildListAutomationToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWildListAutomationToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWildListAutomationToolDlg::OnBnClickedCancel()
{
	int nResult = ( MessageBox( "Exit Report Generator?", "End Program", MB_YESNO | MB_ICONQUESTION ) );
	
	if( nResult == IDYES )
		PostQuitMessage( EXIT_SUCCESS );
}

void CWildListAutomationToolDlg::OnBnClickedOk()
{
	Report my_report = Report( );
	CString frequencyFile, newFile, scannerPath, samplesPath;
	POSITION pos = ( 0 );
	m_Progress.SetRange( 0, 100 );
	m_Progress.SetPos( 0 );
	m_Progress.SetStep( 5 );

//////////////////////////////////////////////////////
// Phase # 1: Validation functions

	// validate # 1
	pos = m_wndCtrl1.GetStartPosition();
	while (pos != NULL) { frequencyFile += m_wndCtrl1.GetNextPathName(pos) + _T("\n"); }
	if( frequencyFile == "" )
	{
		MessageBox( "Error 103: No frequency report found!" );
		m_Progress.SetPos( 0 );
		return;
	}
	std::string freq = static_cast<LPCTSTR>( frequencyFile );
	my_report.my_freqFile = ( freq );
	m_Progress.StepIt( );

	// validate # 2
	pos = m_wndCtrl2.GetStartPosition();
	while (pos != NULL) { newFile += m_wndCtrl2.GetNextPathName(pos) + _T("\n"); }
	if( newFile == "" )
	{
		MessageBox( "Error 104: No new detections list found!" );
		m_Progress.SetPos( 0 );
		return;
	}
	std::string nf = static_cast<LPCTSTR>( newFile );
	my_report.my_newFile = ( nf );
	m_Progress.StepIt( );

	// validate input # 3
	m_edit1.GetWindowTextA( scannerPath );
	if( scannerPath == "" )
	{
		MessageBox( "Error 105: Definition folder not specified!" );
		m_Progress.SetPos( 0 );
		return;
	}
	m_Progress.StepIt( );

	// validate input # 4
	m_edit2.GetWindowTextA( samplesPath );
	if( samplesPath == "" )
	{
		MessageBox( "Error 106: Samples folder not specified!" );
		m_Progress.SetPos( 0 );
		return;
	}
	m_Progress.StepIt( );

//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Phase # 2: Validate Scanner

	CString szFile, szPath( scannerPath );
	DWORD dwAttr;

	// checking for command-line scanner
	szFile = ("/navc32.exe");
	dwAttr = GetFileAttributes( szPath + szFile );
	if(dwAttr == 0xffffffff)
	{
		DWORD dwError = GetLastError();
		if(dwError == ERROR_FILE_NOT_FOUND)
		{
			MessageBox( "Command-Line scanner does not exist in specified folder!" );
			m_Progress.SetPos( 0 );
			return;
		}
		else if(dwError == ERROR_ACCESS_DENIED)
		{
			MessageBox( "Access denied to command-line scanner!" );
			m_Progress.SetPos( 0 );
			return;
		}
		else
		{
			MessageBox( "Unknown Error while trying to access the command-line scanner" );
			m_Progress.SetPos( 0 );
			return;
		}
	}
	m_Progress.StepIt( );

//////////////////////////////////////////////////////
// Phase # 3: Scan samples
	
	// get the path
	string my_command = scannerPath;

	// get the scanner
	my_command += "/navc32.exe ";

	// get the samples directory
	my_command += samplesPath;

	// use the appropriate switches
	my_command += " /S /verbose /log:scan_report.txt";

	WinExec( my_command.c_str( ), SW_SHOWNORMAL ); // SW_SHOWNORMAL, SW_HIDE, SW_MINIMIZE

	m_Progress.StepIt( );
	m_Progress.SetStep( 15 );

	// retrieve, match, sort threats and generate report
	if( my_report.retrieveThreatFreq( ) )
	{
		m_Progress.StepIt( );

		if( my_report.matchNewFile( ) )
		{
			my_report.sortThreats( );
			m_Progress.StepIt( );

			my_report.generateReport( );
			m_Progress.StepIt( );
		}
		else
		{
			m_Progress.SetPos( 0 );
		}
	}
	else
	{
		m_Progress.SetPos( 0 );
	}

	m_Progress.SetPos( 100 );
}
void CWildListAutomationToolDlg::OnBnClickedButton4()
{
	std::string szPath("");

	// get the entire folder
	if (GetFolder(szPath, "Select a folder.") == true)  { m_edit2.SetWindowText(szPath.c_str()); }
}

void CWildListAutomationToolDlg::OnBnClickedButton3()
{
	std::string szPath("");

	// get the entire folder
	if (GetFolder(szPath, "Select a folder.") == true)  { m_edit1.SetWindowText(szPath.c_str()); }
}
void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	PostQuitMessage( 0 );
}

void CWildListAutomationToolDlg::OnBnClickedButton5()
{
    CDialog theDialog( IDD_ABOUTBOX );

	// call the about form
    theDialog.DoModal();
}
