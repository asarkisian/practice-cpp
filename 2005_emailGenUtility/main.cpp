/////////////////////////////////////////////////////
// Filename: <main.cpp>

/**************************************************************
******************* PROGRAM INFORMATION ***********************  
---------------------------------------------------------------
* Author   :		Sarkisian, Armond
* Company  :        Symantec Corporation
* Dept     :        Security Response (AntiVirus Certification)
* Time     :        11:30 (PST)
* Date     :        10, February 2005
* Software :        Publishing LU/LUP/IU/HH Email Generator
* Version  :		1.0
* Revision :        0.14
**************************************************************/

/**************************************************************
********************** REVISION HISTORY ***********************  
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  - Started emailGen v1.0 to generate LU/LU2/IU 
                posting emails
              - Gor assisted by informing me how to extract 
			    the DIS Seq # from Virscan1.dat
Version:      1.0
Revision:     0.00
Date / Time:  02/10/2005 : 11:30 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Completed initial draft of emailGen
Version:      1.0
Revision:     0.01
Date / Time:  03/26/2005 : 08:59 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Add feature to check DIS Sequence # is indeed 
              unique and also formatted log file ( tabbed 
			  entries and added colors )
Version:      1.0
Revision:     0.02
Date / Time:  04/11/2005 : 11:05 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Changed LU2 entries to LU Plus (LUP) entries after 
              SRM's announced that LU2 has been sunsetted
Version:      1.0
Revision:     0.03
Date / Time:  04/18/2005 : 10:45 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Added the TRZ File name field for the IU log file
Version:      1.0
Revision:     0.04
Date / Time:  04/27/2005 : 14:26 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Changed the color output for custom comments in 
              the log
Version:      1.0
Revision:     0.05
Date / Time:  04/28/2005 : 13:34 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  - Changed emailGen so it cannot accept multiple 
                same arguments
              - Changed the CC field in the log file to be bold
			  - Added Handheld (HH) publishing capability with 
			    HH template
			  - Enhanced all publihing templates
			  - Optimized source code
Version:      1.0
Revision:     0.06
Date / Time:  05/04/2005 : 11:21 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  - Enhanced emailGen interface and made it nicer
              - Replaced cerr object with (Win32) MessageBox 
			    function
Version:      1.0
Revision:     0.07 
Date / Time:  05/11/2005 : 11:20 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond          
Description:  Due to the whatsnew.txt file changing keywords,
              I had to go in and replace the keyword:
			  FILE_SEARCH_STRING and change 'virus' to 'risk'
Version:      1.0
Revision:     0.08
Date / Time:  08/26/2005 : 14:43 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  For the next 10 days, we will need to add the TRZ
              package names Build ??????-pkg3.trz and
			  Build ??????-pkg3.trz to the output report. This
			  will be until the TRZ gets sunsetted. Had to
			  undue revision 0.08 since the new whatsnew.txt file
			  has not yet been implemented. Will change once TRZ
			  gets sunsetted in rev 0.10.
Version:      1.0
Revision:     0.09
Date / Time:  09/28/2005 : 14:46 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Added "SAV 10 and NAV2K6 Definitions ( LU ) Release"
              for the default LU purpose message. Now that we will
			  be publishing LiveUpdate everyday, we will need to
			  differentiate SAV 10, NAV2K6 posting and Full posting.
			  Now, there will be an additional option you must choose
			  when selecting the -lu switch. You will need to specify
			  whether this is a FULL LU post or not. Based on that, it
			  will generate the appropriate comment.
Version:      1.0
Revision:     0.10
Date / Time:  09/30/2005 : 12:57 (PST) 
---------------------------------------------------------------
Full Name:    Sarkisian, Armond    
Description:  Added the -All switch to allow publishing to all
              including Intelligent Updaters, LiveUpdate,
			  and LiveUpdate Plus. The only report it will NOT
			  generate will be Handheld posting. Also fixed problem
			  associated with the -cc switch. It seemed that if
			  the user entered only the -cc switch, it would accept
			  it. I changed it to result in Error 100 ( not enough
			  arguments ).
Version:      1.0
Revision:     0.11
Date / Time:  09/30/2005 : 14:11 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond    
Description:  Added the email subject into the email generated by
              emailGen. This is so you don't reference previous
			  email submissions. You can directly just copy and
			  paste the subject onto the header with ease. Also,
			  added color coding to the report output.
Version:      1.0
Revision:     0.12
Date / Time:  10/04/2005 : 16:47 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond    
Description:  Reverted back to 0.08 revision due to the whatsnew.txt
              file changing tomorrow ( Oct 6th ).
Version:      1.0
Revision:     0.13
Date / Time:  10/05/2005 : 13:39 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Commented out the implementation of rev 0.09 due to the
              TRX and TRZ being sunsetted. Also, removed the entries 
			  from the iu.htm template file.
Version:      1.0
Revision:     0.14
Date / Time:  10/10/2005 : 15:04 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Slightly modified the IU template and took out the
              FILE INFECTOR section as the new whatsnew.txt file
			  omitted that information. Revised the template
			  accordingly.
Version:      1.0
Revision:     0.14
Date / Time:  12/01/2005 : 15:15 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Increased the NAVCE version from 7 to 8
Version:      1.0
Revision:     0.14
Date / Time:  01/09/2006 : 18:17 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Migrated over to VS 2005 and had a problem with
              getDBCS_ID() function call. Apparently, it was
			  calling this function twice and VS 2003.NET did
			  not detect it nor did it give me an error. Problem
			  is now resolved; also changed the name of the TRZ
			  file from 041006j.trz to 041006a-pkg[1-5].trz. 
			  Took out the 'j' TRZ letter and replaced it with 
			  the DBCS letter and also added 4 additional TRZ
			  names which are the packages 1 - 5.
Version:      1.0
Revision:     0.15
Date / Time:  04/10/2006 : 14:25 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Modified the HH template to also include symbian9.trz
Version:      1.0
Revision:     0.15
Date / Time:  05/08/2006 : 17:16 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Adding capability for emailGen to access the P4 server
              and update the ph.txt file with the latest timestamp
			  (this feature is not yet complete)
Version:      1.0
Revision:     0.16
Date / Time:  05/24/2006 : 07:35 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Updated the packages to add NAV 2007 (package 6) to
              both LiveUpdate and LiveUpdate Plus reports
Version:	  1.0
Revision:     0.16
Date / Time:  08/28/2006 : 11:33 (PST)
---------------------------------------------------------------
Full Name:    
Description:  
Version:	  
Revision:     
Date / Time:  
---------------------------------------------------------------
Full Name:    
Description:  
Version:	  
Revision:     
Date / Time:  
-------------------------------------------------------------*/

/////////////////////////////////////////////////////
#include "messages.h"
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#include <iostream>
#include <stdexcept>
#include <windows.h>
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
using std::endl;
using std::exception;
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void doMain(int argc, char** argv);
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	try
	{
		// Send arguments ( command-line ) to doMain()
		doMain(argc, argv);
	}
	catch(const exception& e)
	{
		// Display error via throw command
		MessageBox(NULL, 
			e.what(), 
			"An error was encountered!", 
			MB_OK | MB_ICONHAND);
	}
	catch(...)
	{
		// Display non-standard C++ error(s)
		MessageBox(NULL, 
			UNKNOWN_ERROR, 
			"Please contact the system administrator!", 
			MB_OK | MB_ICONHAND);
	}

	// Return successful back to the OS
	return(EXIT_SUCCESS);
}
/////////////////////////////////////////////////////