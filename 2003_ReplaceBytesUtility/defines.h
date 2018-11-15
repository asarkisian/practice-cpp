///////////////////////////////////////////////////
// Project: ReplaceIt ( RI )
// File:    defines.h
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#ifndef ___DEFINES_H___
#define ___DEFINES_H___
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#define START_OF_FILE	0

#define BYTE_MODE		"-b"
#define WORD_MODE		"-w"

#define SPACE			"SPACE"

#define NO_ARGUMENTS	1
#define MAX_ARGUMENTS	4

#define SOURCE_ARGUMENT	2
#define DEST_ARGUMENT	3
#define MODE_ARGUMENT	4

#define NO_DATA_FILE	""
#define TEMPLATE_FILE	"riTemplate.txt"

#define MODE			"Mode  : "
#define B_MODE			"[Byte-Mode]"
#define W_MODE			"[Word-Mode]"

#define STATUS_START	"Status: [Starting ReplaceIt]"
#define STATUS_LOAD		"Status: [Loading Data]"
#define STATUS_REPLACE	"Status: [Replacing Search Strings]"
#define STATUS_OUTPUT	"Status: [Outputting Results]"
#define STATUS_COMPLETE	"Status: [Ending ReplaceIt"

#define EXCEPTION		"Exception: "
#define MD5				"MD5 = "

#define ERROR_100		"No arguments provided, please try again!"
#define ERROR_101		"Too many arguments, please try again!"
#define ERROR_102		"Unable to open data file!"
#define ERROR_103		"Unable to open template file!"
#define ERROR_104		"Unable to write to destination file!"
#define ERROR_105		"No mode was selected, please try again!"

#define START_PROGRAM	"-/\\/\\/\\/\\/\\/\\ Starting ReplaceIt v2.0 /\\/\\/\\/\\/\\/\\-" 
#define END_PROGRAM		"-\\/\\/\\/\\/\\/\\/\\ Ending ReplaceIt /\\/\\/\\/\\/\\/\\-"

#define COMPANY			"Symantec Seucurity Response ReplaceIt v2.0 r0.00 Copyright 2005"
#define TITLE_LINE		"_______________________________________________________________"

#define AUTHOR			"By Armond Sarkisian"

#define PROGRAM_USAGE	"ri.exe file1.ext [file2.ext] { -b | -w }"
#define USAGE1			"[file1.txt can be both the source and destination]"
#define USAGE2			"[file2.txt can be an alternative destination]"
#define USAGE3			"-b indicates Byte-Mode"
#define USAGE4			"-w indicates Word-Mode"

#define CLEAR_SCREEN	"cls"
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////