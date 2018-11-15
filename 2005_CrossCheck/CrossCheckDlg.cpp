// CrossCheckDlg.cpp : implementation file
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Defines.h"
#include "Typedefs.h"
#include "Management.h"
#include "CrossCheck.h"
#include "CrossCheckDlg.h"
#include <fstream>

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
using std::endl;
using std::fstream;
using std::getline;
using std::ios;
using std::string;
using std::vector;
using std::ws;
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

/////////////////////////////////////////////////////////////////////////////
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CCrossCheckDlg dialog

/////////////////////////////////////////////////////////////////////////////
CCrossCheckDlg::CCrossCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCrossCheckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCrossCheckDlg)
	m_scan_all = FALSE;
	m_scan_files = FALSE;
	m_scan_registry = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
long CheckFile(CString szFile)
{
	WIN32_FIND_DATA FileInfo;
	HANDLE hFind;

	long fileSize = 0;

	hFind = ::FindFirstFile(szFile, &FileInfo);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		fileSize = -1;
	}
	else
	{
		fileSize = FileInfo.nFileSizeLow;
	}

	FindClose(hFind);

	return(fileSize);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCrossCheckDlg)
	DDX_Control(pDX, IDC_PROGRESS_BAR, m_progress_bar);
	DDX_Check(pDX, IDC_CHECK_SCAN_ALL, m_scan_all);
	DDX_Check(pDX, IDC_CHECK_SCAN_FILES, m_scan_files);
	DDX_Check(pDX, IDC_CHECK_SCAN_REGISTRY, m_scan_registry);
	//}}AFX_DATA_MAP
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CCrossCheckDlg, CDialog)
	//{{AFX_MSG_MAP(CCrossCheckDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_SCAN_ALL, OnCheckScanAll)
	ON_BN_CLICKED(IDC_CHECK_SCAN_FILES, OnCheckScanFiles)
	ON_BN_CLICKED(IDC_CHECK_SCAN_REGISTRY, OnCheckScanRegistry)
	ON_BN_CLICKED(ID_SCAN_NOW, OnScanNow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CCrossCheckDlg message handlers

/////////////////////////////////////////////////////////////////////////////
BOOL CCrossCheckDlg::OnInitDialog()
{
	// onLoad event

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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//GetVersion();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}
/////////////////////////////////////////////////////////////////////////////

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
HCURSOR CCrossCheckDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnCancel() 
{
	if(MessageBox(EXIT_PROGRAM_MSG, EXIT_PROGRAM_TITLE, 
      MB_ICONQUESTION | MB_YESNO) == IDYES)
		CDialog::OnCancel();
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnCheckScanAll() 
{
	CButton* p_scanFiles = (CButton*)GetDlgItem(IDC_CHECK_SCAN_FILES);
	CButton* p_scanRegistry = (CButton*)GetDlgItem(IDC_CHECK_SCAN_REGISTRY);

	if(p_scanFiles->GetCheck())
		p_scanFiles->SetCheck(false);
	if(p_scanRegistry->GetCheck())
		p_scanRegistry->SetCheck(false);

}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnCheckScanFiles() 
{
	CButton* p_scanAll = (CButton*)GetDlgItem(IDC_CHECK_SCAN_ALL);
	CButton* p_scanFiles = (CButton*)GetDlgItem(IDC_CHECK_SCAN_FILES);
	CButton* p_scanRegistry = (CButton*)GetDlgItem(IDC_CHECK_SCAN_REGISTRY);

	if(p_scanAll->GetCheck())
		p_scanAll->SetCheck(false);


	if(p_scanFiles->GetCheck() && p_scanRegistry->GetCheck())
	{
		p_scanFiles->SetCheck(false);
		p_scanRegistry->SetCheck(false);
		p_scanAll->SetCheck(true);
	}
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnCheckScanRegistry() 
{
	CButton* p_scanAll = (CButton*)GetDlgItem(IDC_CHECK_SCAN_ALL);
	CButton* p_scanFiles = (CButton*)GetDlgItem(IDC_CHECK_SCAN_FILES);
	CButton* p_scanRegistry = (CButton*)GetDlgItem(IDC_CHECK_SCAN_REGISTRY);

	if(p_scanAll->GetCheck())
		p_scanAll->SetCheck(false);

	if(p_scanFiles->GetCheck() && p_scanRegistry->GetCheck())
	{
		p_scanFiles->SetCheck(false);
		p_scanRegistry->SetCheck(false);
		p_scanAll->SetCheck(true);
	}
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CCrossCheckDlg::OnScanNow() 
{
	CButton* p_scanAll = (CButton*)GetDlgItem(IDC_CHECK_SCAN_ALL);
	CButton* p_scanFiles = (CButton*)GetDlgItem(IDC_CHECK_SCAN_FILES);
	CButton* p_scanRegistry = (CButton*)GetDlgItem(IDC_CHECK_SCAN_REGISTRY);
	
	string filePath, registryPath, logPath;

//***************************************************************************
// Start - Error checking

	// Make sure a scan option has been chosen in order to start scanning
	if((!p_scanAll->GetCheck()) && (!p_scanFiles->GetCheck()) && (!p_scanRegistry->GetCheck()))
	{
		MessageBox(ERROR_100_MSG, ERROR_100_TITLE, MB_OK | MB_ICONERROR);

		return;
	}

	// Set the data/log files path
	filePath = DATA_DIRECTORY;
	filePath += "\\";
	filePath += CRITICAL_FILE;

	registryPath = DATA_DIRECTORY;
	registryPath += "\\";
	registryPath += CRITICAL_REGISTRY;

	// Gets the date and time
	CTime ct(time(NULL));


	logPath = LOG_DIRECTORY;
	logPath += "\\";
	logPath += ct.Format("%Y%b%d_%H%M%S_");
	logPath += LOG_FILE;

	// Error checking on data files
	if(CheckFile(filePath.c_str()) == FILE_DOES_NOT_EXIST)
	{
		MessageBox(CREATE_DATA_FILE_MSG, CREATE_DATA_FILE_TITLE, MB_OK | MB_ICONINFORMATION);
		
		CreateDirectory(DATA_DIRECTORY, NULL);
		fstream fout;
		fout.open(filePath.c_str(), ios::out);
		fout.close();

		return;
	}
	else if(CheckFile(registryPath.c_str()) == FILE_DOES_NOT_EXIST)
	{
		MessageBox(CREATE_DATA_REGISTRY_MSG, CREATE_DATA_REGISTRY_TITLE, MB_OK | MB_ICONINFORMATION);

		CreateDirectory(DATA_DIRECTORY, NULL);
		fstream fout;
		fout.open(registryPath.c_str(), ios::out);
		fout.close();

		return;
	}
	else if(CheckFile(filePath.c_str()) == FILE_IS_EMPTY)
	{
		MessageBox(ERROR_101_MSG, ERROR_101_TITLE, MB_OK | MB_ICONERROR);

		return;
	}
	else if(CheckFile(registryPath.c_str()) == FILE_IS_EMPTY)
	{
		MessageBox(ERROR_102_MSG, ERROR_102_TITLE, MB_OK | MB_ICONERROR);

		return;
	}

//***************************************************************************
// End - Error checking

	//  Data used to locate a file(s)
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	// Used to store all the file names under
	DataManagement* my_data = new DataManagement();

	fstream fout_log, fin_file, fin_registry;

	fin_file.open(filePath.c_str(), ios::in);
	fin_registry.open(registryPath.c_str(), ios::in);

	// Initializing the progress bar
	m_progress_bar.SetPos(MIN_STEP);

	if(p_scanAll->GetCheck())
	{
		// To index the vectors using the while loop
		uint_t f = 0, r = 0;

		string temp;
		vector<string> tempFiles;
		vector<string> tempRegistries;

		while(!fin_file.eof())
		{
			fin_file >> ws;
			getline(fin_file, temp);
			tempFiles.push_back(string(temp));
			my_data->addFiles(tempFiles.at(f), CRITICAL);

			++f;
		}

		while(!fin_registry.eof())
		{
			fin_registry >> ws;
			getline(fin_registry, temp);
			tempRegistries.push_back(string(temp));
			my_data->addRegistry(tempRegistries.at(r), CRITICAL);

			+r;
		}

//***************************************************************************
// Start - Scanning for file(s)

		m_progress_bar.SetPos(MIN_STEP);
		m_progress_bar.SetStep(STEP_SIZE);

		// Scanning the files
		for(uint_t x = 0; x < f; ++x)
		{
			hFind = FindFirstFile(tempFiles.at(x).c_str(), &FindFileData);

			if(hFind == INVALID_HANDLE_VALUE)
			{
				// Adding the missing file to the vector
				my_data->addFiles(tempFiles.at(x), MISSING);
			}
			else
			{
				// Check md5
				// checkMd5();

				if(FindFileData.nFileSizeLow == 0)
				{
					my_data->addFiles(tempFiles.at(x), CORRUPTED);
				}
			}
		}

//***************************************************************************
// End - Scanning for file(s)

//***************************************************************************
// Start - Scanning for registrie(s)

//***************************************************************************
// End - Scanning for registrie(s)

	}
	else if(p_scanFiles->GetCheck())
	{
		vector<string> tempFiles;
		
		// only scan file(s) here
	}
	else // scanRegistries
	{
		vector<string> tempRegistries;

		// only scan registrie(s) here
	}

//***************************************************************************
// Start - Outputting results to screen

	// Create the log directory
	CreateDirectory(LOG_DIRECTORY, NULL);

	fout_log.open(logPath.c_str(), ios::out);
	if(!fout_log)
	{
		MessageBox(ERROR_103_MSG, ERROR_103_TITLE, MB_OK | MB_ICONERROR);
	}
	else
	{
		fout_log << SOFTWARE_TITLE << ' ' << DATA_REPORT_TITLE << ' ' << string(ct.Format("%A, %B %d, %Y")) << endl;
		fout_log << TIME_TESTED_ON << '[' << string(ct.Format("%H:%M:%S")) << ']' << endl; 
		fout_log << UNDERLINE << '\n' << endl;

		fout_log << DATA_REPORT_OUTPUT << endl;

		fout_log << '\n' << FILE_REPORT << endl;
		fout_log << CRITICAL_FILE_OUTPUT << my_data->criticalFilesSize() << endl;
		fout_log << MISSING_FILE_OUTPUT << my_data->missingFilesSize() << '/' << my_data->criticalFilesSize() << endl;
		fout_log << CORRUPTED_FILE_OUTPUT << my_data->corruptedFilesSize() << '/' << my_data->criticalFilesSize() << endl;

		fout_log << '\n' << REGISTRY_REPORT << endl;
		fout_log << CRITICAL_REGISTRY_OUTPUT << my_data->criticalRegistriesSize() << endl;
		fout_log << MISSING_REGISTRY_OUTPUT << my_data->missingRegistriesSize() << '/' << my_data->criticalRegistriesSize() << endl;
		fout_log << CORRUPTED_REGISTRY_OUTPUT << my_data->corruptedRegistriesSize() << '/' << my_data->criticalRegistriesSize() << endl;

		endl(fout_log);

		fout_log << MISSING_FILES << endl;

		if(my_data->isMissingFilesEmpty())
		{
			fout_log << NO_MISSING_FILES << endl;
		}
		else
		{
			for(uint_t l = 0; l < my_data->missingFilesSize(); ++l)
			{
				fout_log << MISSING_FILE_OUTPUT << my_data->missingFiles(l) << endl;
			}
		}

		fout_log << '\n' << CORRUPTED_FILES << endl;

		if(my_data->isCorruptedFilesEmpty())
		{
			fout_log << NO_CORRUPTED_FILES << endl;
		}
		else
		{
			for(uint_t l = 0; l < my_data->corruptedFilesSize(); ++l)
			{
				fout_log << CORRUPTED_FILE_OUTPUT << my_data->corruptedFiles(l) << endl;
			}
		}

		endl(fout_log);

		fout_log << MISSING_REGISTRIES << endl;

		if(my_data->isMissingRegistriesEmpty())
		{
			fout_log << NO_MISSING_REGISTRIES << endl;
		}
		else
		{
			for(uint_t l = 0; l < my_data->missingRegistriesSize(); ++l)
			{
				fout_log << MISSING_REGISTRY_OUTPUT << my_data->missingRegistries(l) << endl;
			}
		}

		fout_log << '\n' << CORRUPTED_REGISTRIES << endl;

		if(my_data->isCorruptedRegistriesEmpty())
		{
			fout_log << NO_CORRUPTED_REGISTRIES << endl;
		}
		else
		{
			for(uint_t l = 0; l < my_data->corruptedRegistriesSize(); ++l)
			{
				fout_log << CORRUPTED_REGISTRY_OUTPUT << my_data->corruptedRegistries(l) << endl;
			}
		}
	}

//***************************************************************************
// End - Outputting results to screen

	// Complete
	m_progress_bar.SetPos(MAX_STEP);
	
	MessageBox(SCANNING_COMPLETE_MSG, SCANNING_COMPLETE_TITLE, MB_OK | MB_ICONINFORMATION);

	if(MessageBox(VIEW_LOG_FILE_MSG, logPath.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		string executeLog;
					
		executeLog = EDITOR;
		executeLog += ' ';
		executeLog += logPath;

		// Executes the EDITOR and displays the log file for the current run
		WinExec(executeLog.c_str(), SW_SHOWNORMAL);
	}

	// Reset progress bar back to zero
	m_progress_bar.SetPos(MIN_STEP);

	// Close the file handle
	fin_file.close();
	fin_registry.close();

	delete my_data;
}
/////////////////////////////////////////////////////////////////////////////
