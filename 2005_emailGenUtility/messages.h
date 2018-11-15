/////////////////////////////////////////////////////
// Filename: <messages.h>

/////////////////////////////////////////////////////
#ifndef __MESSAGES_H__
#define __MESSAGES_H__
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#define ERROR_100		"Error 100: Not enough arguments, please try again!"
#define ERROR_101		"Error 101: Too many arguments, please try again!"
#define ERROR_102		"Error 102: Invalid option, please try again!"
#define ERROR_103		"Error 103: Definition Path does not exist!"
#define ERROR_104		"Error 104: Write protection error, cannot write to file!"
#define ERROR_105		"Error 105: LU Template does not exist, please create one!"
#define ERROR_106		"Error 106: LU Plus Template does not exist, please create one!"
#define ERROR_107		"Error 107: IU Template does not exist, please create one!"
#define ERROR_108		"Error 108: Cannot specify the same option multiple times!"
#define ERROR_109		"Error 109: Switches (-cc) are not in order, please try again!"
#define ERROR_110		"Error 110: Invalid DBCS ID, please try again!"
#define ERROR_111		"Error 111: Definition file does not exist under the given path!"
#define ERROR_112		"Error 112: Error reading from definition file!"
#define ERROR_113		"Error 113: Definition file is corrupt!"
#define ERROR_114		"Error 114: Cannot write to log file!"
#define ERROR_115		"Error 115: Updates file does not exist in definitions directory!"
#define ERROR_116		"Error 116: Error reading from updates file!"
#define ERROR_117		"Error 117: DIS Sequence number is not unique!"
#define ERROR_118		"Error 118: HH Template does not exist, please create one!"

#define UNKNOWN_ERROR	"Unknown internal error!"

#define WARNING_100		"Warning 100: No new detections added, please verify manually!"

#define EMAILGEN_START	"/-\\/-\\/-\\( Starting emailGen )/-\\/-\\/-\\"
#define EMAILGEN_END	"/-\\/-\\( Ended emailGen successfully )/-\\/-\\"

#define TITLE_COPYRIGHT	"Symantec Security Response : emailGen v1.0 r0.16 Copyright 2005"
#define TITLE_LINE		"_______________________________________________________________"

#define PROGRAM_AUTHOR	"By: Armond Sarkisian"

#define USAGE_INFO		"Usage: emailGen \"defFolder\" { [-CC] [-ALL] | [-LU] [-LUP] [-IU] | [-HH] }"\
	"\n\nNote: The -ALL switch will not publish Handheld definitions"

#define GEN_IU_EMAIL	"-[Generating IU  Report]-"
#define GEN_LU_EMAIL	"-[Generating LU  Report]-"
#define GEN_LUP_EMAIL	"-[Generating LU Plus Report]-"

// not included in the -all switch ( added 09/30/2005 )
#define GEN_HH_EMAIL	"-[Generating HH Report]-"

#define SCREEN_REPORT	"-[Log Report]-"
#define	NEW_DETECT_LIST	"-[New Detections List]-"

#define ENTER_CC_COMM	"Enter DBCS Comment: "
#define ENTER_DBCS_ID	"Enter Build Letter: "

#define ENTER_PALM_SEQ	"Please enter the Palm (SAH) sequence #: "

#define IS_FULL_POST	"Post FULL LiveUpdate? (Y)es, (N)o? "

#define LU_RESULTS		"<font face=\"Courier New\" color=\"Orange\" size=\"+.5\"><b>LiveUpdate Results [</font></b><font color=\"Blue\" face=\"Courier New\" size=\"+.5\"> LiveUpdate - Build # "
#define LUP_RESULTS		"<font face=\"Courier New\" color=\"Orange\" size=\"+.5\"><b>LiveUpdate Plus Results [</font></b><font color=\"Blue\" face=\"Courier New\" size=\"+.5\"> LiveUpdate Plus - Build # "
#define IU_RESULTS		"<font face=\"Courier New\" color=\"Orange\" size=\"+.5\"><b>Intelligent Updater Result [</font></b><font color=\"Blue\" face=\"Courier New\" size=\"+.5\"> Intelligent Updaters - Build # "
#define HH_RESULTS		"<font face=\"Courier New\" color=\"Orange\" size=\"+.5\"><b>Handheld Results [</font></b><font color=\"Blue\" face=\"Courier New\" size=\"+.5\"> LiveUpdate HH - Build # "
#define NO_RESULTS		"[ ]"
#define RESULTS_ENDING	"</font><font face=\"Courier New\" color=\"Orange\" size=\"+.5\"><b> ]</b></font>"

#define DBCS_ID_ENTRY	"DBCS ID         : "
#define PROD_VER_ENTRY	"Product Version : "
//#define TRX_FILE_ENTRY	"TRX File Name   : " discontinued as of 10/11/2005 (rev 0.14)
#define TRZ_FILE_ENTRY	"TRZ File Name   : "
#define NAVCE_ENTRY		"NAVCE Version   : "
#define DIS_SEQ_ENTRY	"DIS Sequence    : "

#define DEFAULT_LU_MSG	"SAV 10 and NAV 2006 Definitions ( LU ) Release" // added 09/30/2005
#define DEFAULT_LU_MSG2	"Weekly Full LiveUpdate ( LU ) Release"

#define DEFAULT_LUP_MSG	"Daily LiveUpdate ( LU Plus ) Release"
#define DEFAULT_IU_MSG	"Daily Intelligent Updater ( IU ) Release"
#define DEFAULT_HH_MSG	"Monthly Handheld ( HH ) Release"
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////