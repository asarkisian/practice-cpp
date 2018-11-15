/////////////////////////////////////////////////////
// Filename: <options.h>

/////////////////////////////////////////////////////
#ifndef __OPTIONS_H__
#define __OPTIONS_H__
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// Publishing constants
#define LU					"LiveUpdate"
#define LUP					"LiveUpdatePlus"
#define IU					"IntelligentUpdater"
#define HH					"Handheld"

// Test controls
#define TEST_OUTPUT			false

// Command line argument controls
#define DEFAULT_ARGUMENT	1
#define MIN_ARGUMENT		2
#define MAX_ARGUMENT		7

// Incoming paths
#define LU_TEMPLATE_FILE	"lu.htm"
#define LUP_TEMPLATE_FILE	"lup.htm"
#define IU_TEMPLATE_FILE	"iu.htm"
#define HH_TEMPLATE_FILE	"hh.htm"

// Outgoing path
#define RESULT_FILE			"emailGen.htm"

// Test path
#define TEST_ALL_FILE		"pub_test.htm"

// Definition path required files
#define DOT					'.'
#define BACK_SLASH			'\\'
#define DEF_FILE			"virscan1.dat"
#define UPDATES_FILE		"whatsnew.txt"

// SDGS server path
#define SDGS_PATH			"\\\\sdgs\\builds\\"

// Command line switches
#define CC_SWITCH			"-cc"
#define ALL_SWITCH			"-all"

#define LU_SWITCH			"-lu"
#define LUP_SWITCH			"-lup"
#define IU_SWITCH			"-iu"

#define HH_SWITCH			"-hh"

// Editor controls
#define EDITOR				"\\program files\\internet explorer\\iexplore.exe"
#define SHOW_EDITOR			SW_SHOWMAXIMIZED

// File extensions
//#define TRX_EXTENSION		".trx" discontinued as of 10/11/2005 (rev 0.14)
#define TRZ_EXTENSION		".trz"

// Search strings (this must match the template EXACTLY or else proper output will NOT occur!)
#define FILE_WHITE_SPACE	" "
                             
#define FILE_SEARCH_STRING	"New risk definitions (sorted by Date added):" // 'risk' replaced 'virus'
#define FILE_PROD_VER		"Product Version:</b>"
#define FILE_TRZ_FILE		"TRZ File Name:</b>"
#define FILE_BUILD_NUM		"Build Number:</b>"
#define FILE_NAVCE_VER		"NAVCE Version:</b>"
#define FILE_PURPOSE		"Detailed Purpose of Release:</b>"
#define FILE_DIS_SEQ		"DIS Sequence #:</b>"
#define FILE_NEW_DETECT		"NEW DETECTIONS:"
#define FILE_NEW_DET_LINES	"----------"
// Commented out due to the TRX being sunsetted ( added 10/10/2005, rev 0.14 )
//#define FILE_TRX_FILE		"TRX File Name:</b>"
//#define FILE_TRZ_FILE1	"TRZ File Name 1:</b>"
//#define FILE_TRZ_FILE3	"TRZ File Name 3:</b>"

#define TRZ_PACKAGE_1		"-pkg1"
#define TRZ_PACKAGE_2		"-pkg2"
#define TRZ_PACKAGE_3		"-pkg3"
#define TRZ_PACKAGE_4		"-pkg4"
#define TRZ_PACKAGE_5		"-pkg5"
#define TRZ_PACKAGE_6		"-pkg6" //added 08/28/2006 for NAV 20076

// Search strings for Handhelds
#define FILE_PROD_VER_SAP	"Product ver for Palm (SAH):</b>"
#define FILE_PROD_VER_PPC	"Product ver for PocketPC:</b>"
#define FILE_PROD_VER_SAH	"Product ver for Palm (SAP):</b>"

// Console commands
#define CLEAR_SCREEN		"cls"
#define PAUSE_SCREEN		"pause"

// HTML Tags
#define HTML_LINE_BREAK		"<br>"
#define HTML_HORIZ_RULE		"<hr>"

// Output Field Options
#define	PPC_PRODUCT_VERSION	"000"
// #define TRZ_LETTER			'j' // discontinued as of 0.15 revision due to file name changes

// Sleep Option
#define SLEEP_TIME			17
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////