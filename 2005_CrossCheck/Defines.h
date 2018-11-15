/////////////////////////////////////////////////////////////////////////////
#pragma once
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
#define SOFTWARE_TITLE					"Symantec CrossCheck"
#define DATA_REPORT_TITLE				"Data Report for"
#define UNDERLINE						"================================================================"

#define EDITOR							"notepad.exe"

#define MIN_STEP						0
#define MAX_STEP						100
#define	STEP_SIZE						1

#define CRITICAL						"Critical"
#define MISSING							"Missing"
#define CORRUPTED						"Corrupted"

#define TEMP_DIRECTORY					"temp"
#define LOG_DIRECTORY					"log"
#define DATA_DIRECTORY					"data"

#define LOG_FILE						"user.log"
#define CRITICAL_FILE					"files.dat"
#define CRITICAL_REGISTRY				"registries.dat"

#define FILE_DOES_NOT_EXIST				-1
#define FILE_IS_EMPTY					0

#define CRITICAL_FILE_OUTPUT			"Total Critical Files: "
#define CRITICAL_REGISTRY_OUTPUT		"Total Critical Registries: "

#define TIME_TESTED_ON					"Testing Time: "

#define MISSING_FILES					"-_-_-_-_-_-_-_-_-_-_-_( Missing Files )_-_-_-_-_-_-_-_-_-_-_-_-"
#define MISSING_REGISTRIES				"-_-_-_-_-_-_-_-_-_-_( Missing Registries )_-_-_-_-_-_-_-_-_-_-_"
#define MISSING_FILE_OUTPUT				"Missing File: "
#define MISSING_REGISTRY_OUTPUT			"Missing Registry: "
#define NO_MISSING_FILES				"<No missing files>"
#define NO_MISSING_REGISTRIES			"<No missing registries>"

#define CORRUPTED_FILES					"-_-_-_-_-_-_-_-_-( Possibly Corrupted Files )-_-_-_-_-_-_-_-_-_"
#define CORRUPTED_REGISTRIES			"-_-_-_-_-_-_-_-( Possibly Corrupted Registries )-_-_-_-_-_-_-_-"

#define CORRUPTED_FILE_OUTPUT			"Corrupted File: "
#define CORRUPTED_REGISTRY_OUTPUT		"Corrupted Registries: "
#define NO_CORRUPTED_FILES				"<No corrupted files>"
#define NO_CORRUPTED_REGISTRIES			"<No corrupted registries>"

#define DATA_REPORT_OUTPUT				"-_-_-_-_-_-_-_-_-_-_-_-( Data Report )-_-_-_-_-_-_-_-_-_-_-_-_"

#define FILE_REPORT						"***File Report***"
#define REGISTRY_REPORT					"***Registry Report***"

// Message Box text
#define EXIT_PROGRAM_MSG				"Are you sure you want to exit?"
#define EXIT_PROGRAM_TITLE				"Exiting"

#define ERROR_100_MSG					"Error 100: You need to specify scan options!"
#define ERROR_100_TITLE					"Error 100"
#define ERROR_101_MSG					"Error 101: Data file does not contain any data, please contact your administrator!"
#define ERROR_101_TITLE					"Error 101"
#define ERROR_102_MSG					"Error 102: Data registry does not contain any data, please contact your administrator!"
#define ERROR_102_TITLE					"Error 102"
#define ERROR_103_MSG					"Error 103: Unable to output results to disk!"
#define ERROR_103_TITLE					"Error 103"

#define CREATE_DATA_FILE_MSG			"Data file does not exist, creating new data file!"
#define CREATE_DATA_FILE_TITLE			"Creating new data file"

#define CREATE_DATA_REGISTRY_MSG		"Data registry does not exist, creating new data registry!"
#define CREATE_DATA_REGISTRY_TITLE		"Creating new data registry"

#define SCANNING_COMPLETE_MSG			"Scanning Complete!"
#define SCANNING_COMPLETE_TITLE			"Scan Complete"

#define VIEW_LOG_FILE_MSG				"Would you like to view the log file?"
/////////////////////////////////////////////////////////////////////////////