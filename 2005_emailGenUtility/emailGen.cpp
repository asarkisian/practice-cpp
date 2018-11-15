/////////////////////////////////////////////////////
// Filename: <emailGen.cpp>

/////////////////////////////////////////////////////
#include "emailGen.h"
#include "messages.h"
#include "options.h"
#include "typedefs.h"
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::flush;
using std::fstream;
using std::getline;
using std::ios;
using std::string;
using std::ws;
using std::vector;
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
emailGen::emailGen()
:my_defPath(" "),
 my_updatesFilePath(" "),
 my_resultPath(" "),
 my_customComment(""),
 my_LU_Email(new vector<field_t*>),
 my_LUP_Email(new vector<field_t*>),
 my_IU_Email(new vector<field_t*>),
 my_New_DetectionsList(new vector<field_t*>),
 my_HH_Email(new vector<field_t*>),
 my_DBCSID_Letter(" "),
 my_DBCSID(" "),
 //my_trxName(" "), discontinued as of 10/11/2005 (rev 0.14)
 my_trzName(" "),
 my_trzName_LU(" "),
 my_trzName_LUP(" "),
 //my_trzName_IU_LOG(" "), discontinued as of 10/11/2005 (rev 0.14)
 my_NAVCE_Version(" "),
 my_DIS_Sequence(" "),
 my_productVersion(" "),
 my_productVersion_SAP(" "),
 my_productVersion_PPC(" "),
 my_productVersion_SAH(" "),
 my_sequence(0),
 my_version(" "),
 my_day(" "),
 my_month(" "),
 my_year(" "),		// (e.g., 05)
 my_full_year(" "),	// (e.g., 2005)
 my_isLU_Post(false),
 my_isFullLU_Post(false), // true only on Wednesdays and other full posts( added 09/30/2005 )
 my_isLUP_Post(false),
 my_isIU_Post(false),
 my_isHH_Post(false),
 my_isCustomMessage(false)
{
}	
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
emailGen::~emailGen()
{
	// Releasing LU within the vector (only if vector is not empty)
	if(!my_LU_Email->empty())
		for(uint_t i = 0; i < my_LU_Email->size(); ++i)
			delete my_LU_Email->at(i);

	// Releasing LUP within the vector (only if vector is not empty)
	if(!my_LUP_Email->empty())
		for(uint_t i = 0; i < my_LUP_Email->size(); ++i)
			delete my_LUP_Email->at(i);

	// Releasing IU within the vector (only if vector is not empty)
	if(!my_IU_Email->empty())
		for(uint_t i = 0; i < my_IU_Email->size(); ++i)
			delete my_IU_Email->at(i);

	// Releasing my_New_DetectionsList within the vector (only if vector is not empty)
	if(!my_New_DetectionsList->empty())
		for(uint_t i = 0; i < my_New_DetectionsList->size(); ++i)
			delete my_New_DetectionsList->at(i);

	// Releasing IU within the vector (only if vector is not empty)
	if(!my_HH_Email->empty())
		for(uint_t i = 0; i < my_HH_Email->size(); ++i)
			delete my_HH_Email->at(i);

	// Releasing vectors from the heap
	delete my_LU_Email;
	delete my_LUP_Email;
	delete my_IU_Email;
	delete my_New_DetectionsList;
	delete my_HH_Email;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::generateLU_Email()
{
	if(!my_LU_Email->empty())
	{
		// Cannot specify the same option multiple times!
		this->displayHelp();
		throw domain_error(ERROR_108);
	}

	cout << GEN_LU_EMAIL << endl;

	field_t someField = (" ");

	fstream fin;
	fin.open(LU_TEMPLATE_FILE, ios::in);
	if(!fin)
	{
		// Publishing template does not exist to input from
		this->displayHelp();
		throw domain_error(ERROR_105);
	}

	// Inputting template into vector
	while(!fin.eof())
	{
		fin >> ws; 
		getline(fin, someField);
		
		my_LU_Email->push_back(new field_t(someField));
	}
	fin.close();
	
	/////////////////////////////////////////////////////
	// Inserting LU data into vector
	/* 
	Items to insert (in order): (2 examples of each and their line numbers in the file)
	NOTE: Line number starts with 0 and not 1!!!
	 - Product Version: <Line 07> (e.g., 20050318.008, 20050319.009)
	 - TRZ File Name:   <Line 09> (e.g., 031805j.trz, 031905j.trz)
	 - Build Number:    <Line 11> (e.g., 031805a, 031905b)
	 - NAVCE Version:   <Line 12> (e.g., 70318h, but we're only inserting (0318h))
	 - Purpose:         <Line 14> (e.g., Weekly LiveUpdate Release, Emergency for W32.Sober.L@mm)
	 - DIS Sequence #:  <Line 16> (e.g., 42265, 42276)
	*/
	for(uint_t i = 0; i < my_LU_Email->size(); ++i)
	{
		// Find the search string for each line

		string::size_type pos = my_LU_Email->at(i)->find(FILE_PROD_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LU_Email->at(i)->append(my_productVersion);
		}

		pos = my_LU_Email->at(i)->find(FILE_TRZ_FILE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LU_Email->at(i)->append(my_trzName_LU);
		}

		pos = my_LU_Email->at(i)->find(FILE_BUILD_NUM, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LU_Email->at(i)->append(my_DBCSID);
		}

		pos = my_LU_Email->at(i)->find(FILE_NAVCE_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LU_Email->at(i)->append(my_NAVCE_Version);
		}

		// If there is no emergency, it will default to DEFAULT_LU_MSG1 or MSG2 depending
		// on if it is a Wednesday or not
		if(!isCustomMessage())
		{
			if( this->is_FullLU_Post( ) )
			{
				// Display the original "Weekly Publishing" for LiveUpdate
				my_customComment = (DEFAULT_LU_MSG2);
			}
			else
			{
				// Display published for NAV2K6 and SAV 10 ONLY
				my_customComment = (DEFAULT_LU_MSG);
			}
		}

		pos = my_LU_Email->at(i)->find(FILE_PURPOSE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found

			my_LU_Email->at(i)->append(FILE_WHITE_SPACE);
			if(!isCustomMessage())
			{
				my_LU_Email->at(i)->append(my_customComment);
			}
			else
			{
				string my_tempComment = "<font color=\"Red\"><strong>";
				my_tempComment += my_customComment;
				my_tempComment += "</strong></font>";
				my_customComment = my_tempComment;
				my_LU_Email->at(i)->append(my_customComment);
			}
		}

		pos = my_LU_Email->at(i)->find(FILE_DIS_SEQ, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LU_Email->at(i)->append(my_DIS_Sequence);
		}
	}
	/////////////////////////////////////////////////////

	if(TEST_OUTPUT)
		this->test_outputLog(LU);
	else
		this->outputLog(LU);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::generateLUP_Email()
{
	if(!my_LUP_Email->empty())
	{
		// Cannot specify the same option multiple times!
		this->displayHelp();
		throw domain_error(ERROR_108);
	}

	cout << GEN_LUP_EMAIL << endl;

	field_t someField = (" ");

	fstream fin;
	fin.open(LUP_TEMPLATE_FILE, ios::in);
	if(!fin)
	{
		// Publishing template does not exist to input from
		this->displayHelp();
		throw domain_error(ERROR_105);
	}

	// Inputting template into vector
	while(!fin.eof())
	{
		fin >> ws; 
		getline(fin, someField);
		
		my_LUP_Email->push_back(new field_t(someField));
	}
	fin.close();
	
	/////////////////////////////////////////////////////
	// Inserting LUP data into vector
	/* 
	Items to insert (in order): (2 examples of each and their line numbers in the file)
	NOTE: Line number starts with 0 and not 1!!!
	 - Product Version: <Line 07> (e.g., 20050318.008, 20050319.009)
	 - TRZ File Name:   <Line 09> (e.g., 031805j.trz, 031905j.trz)
	 - Build Number:    <Line 11> (e.g., 031805a, 031905b)
	 - NAVCE Version:   <Line 12> (e.g., 70318h, but we're only inserting (0318h))
	 - Purpose:         <Line 14> (e.g., Daily LiveUpdate Plus Release, Emergency for W32.Sober.L@mm)
	 - DIS Sequence #:  <Line 16> (e.g., 42265, 42276)
	*/
	for(uint_t i = 0; i < my_LUP_Email->size(); ++i)
	{
		// Find the search string for each line

		string::size_type pos = my_LUP_Email->at(i)->find(FILE_PROD_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LUP_Email->at(i)->append(my_productVersion);
		}

		pos = my_LUP_Email->at(i)->find(FILE_TRZ_FILE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LUP_Email->at(i)->append(my_trzName_LUP);
		}

		pos = my_LUP_Email->at(i)->find(FILE_BUILD_NUM, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LUP_Email->at(i)->append(my_DBCSID);
		}

		pos = my_LUP_Email->at(i)->find(FILE_NAVCE_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(my_NAVCE_Version);
		}

		// If there is no emergency, it will default to DEFAULT_LUP_MESSAGE
		if(!isCustomMessage())
		{
			my_customComment = (DEFAULT_LUP_MSG);
		}

		pos = my_LUP_Email->at(i)->find(FILE_PURPOSE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(FILE_WHITE_SPACE);
			if(!isCustomMessage())
			{
				my_LUP_Email->at(i)->append(my_customComment);
			}
			else
			{
				string my_tempComment = "<font color=\"Red\"><strong>";
				my_tempComment += my_customComment;
				my_tempComment += "</strong></font>";
				my_customComment = my_tempComment;
				my_LUP_Email->at(i)->append(my_customComment);
			}
		}

		pos = my_LUP_Email->at(i)->find(FILE_DIS_SEQ, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_LUP_Email->at(i)->append(FILE_WHITE_SPACE);
			my_LUP_Email->at(i)->append(my_DIS_Sequence);
		}
	}
	/////////////////////////////////////////////////////

	if(TEST_OUTPUT)
		this->test_outputLog(LUP);
	else
		this->outputLog(LUP);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::generateIU_Email()
{
	if(!my_IU_Email->empty())
	{
		// Cannot specify the same option multiple times!
		this->displayHelp();
		throw domain_error(ERROR_108);
	}

	cout << GEN_IU_EMAIL << endl;

	field_t someField = (" ");
	result_t is_displayedNewDetections = (false);

	fstream fin;
	fin.open(IU_TEMPLATE_FILE, ios::in);
	if(!fin)
	{
		// Template does not exist for inputting
		this->displayHelp();
		throw domain_error(ERROR_107);
	}

	// Inputting template into vector
	while(!fin.eof())
	{
		fin >> ws; 
		getline(fin, someField);
		
		my_IU_Email->push_back(new field_t(someField));
	}
	fin.close();

	/////////////////////////////////////////////////////
	// Inserting IU data into vector
	/* 
	Items to insert (in order): (2 examples of each and their line numbers in the file)
	NOTE: Line number starts with 0 and not 1!!!
	 - Product Version: <Line 07> (e.g., 20050318.008, 20050319.009)
	 - Build Number:    <Line 12> (e.g., 031805a, 031905b)
	 - NAVCE Version:   <Line 13> (e.g., 70318h, but we're only inserting (0318h))
	 - Purpose:         <Line 15> (e.g., Daily Intelligent Updater Release, Emergency for W32.Sober.L@mm)
	 - DIS Sequence #:  <Line 17> (e.g., 42265, 42276)
	 - New Detections:	<Line 19> (e.g.,         W32.Kelvir.I              File infector            03/18/05)
	*/
	for(uint_t i = 0; i < my_IU_Email->size(); ++i)
	{
		// Find the search string for each line

		string::size_type pos = my_IU_Email->at(i)->find(FILE_PROD_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(my_productVersion);
		}

/*
NOTE: This portion does not need to be output to any log file anymore
due to the TRZ being sunsetted so I went ahead and commented out the
following lines. If you have any questions, please e-mail
bb_sarkar@yahoo.com. ( added 10/10/2005, rev 0.14 )

        pos = my_IU_Email->at(i)->find(FILE_TRX_FILE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(my_trxName);
		}

		pos = my_IU_Email->at(i)->find(FILE_TRZ_FILE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			//my_IU_Email->at(i)->append(my_trzName_IU_LOG); discontinued as of 10/11/2005 (rev 0.14)
		}

/////////////////////////////////////////////////////////
// Start: Temporary until TRZ/TRX sunset

		pos = my_IU_Email->at(i)->find(FILE_TRZ_FILE1, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			// Build 092805a-pkg1.trz

			field_t trz_Package1 = ( my_DBCSID );
			trz_Package1 += "-pkg1.trz";

			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(trz_Package1);
		}

		pos = my_IU_Email->at(i)->find(FILE_TRZ_FILE3, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			// Build 092805a-pkg3.trz

			field_t trz_Package3 = ( my_DBCSID );
			trz_Package3 += "-pkg3.trz";

			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(trz_Package3);
		}
*/
/////////////////////////////////////////////////////////
// End: Temporary until TRZ sunset

		pos = my_IU_Email->at(i)->find(FILE_BUILD_NUM, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(my_DBCSID);
		}

		pos = my_IU_Email->at(i)->find(FILE_NAVCE_VER, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(my_NAVCE_Version);
		}

		// If there is no emergency, it will default to DEFAULT_IU_MESSAGE
		if(!isCustomMessage())
		{
			my_customComment = (DEFAULT_IU_MSG);
		}

		pos = my_IU_Email->at(i)->find(FILE_PURPOSE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			if(!isCustomMessage())
			{
				my_IU_Email->at(i)->append(my_customComment);
			}
			else
			{
				string my_tempComment = "<font color=\"Red\"><strong>";
				my_tempComment += my_customComment;
				my_tempComment += "</strong></font>";
				my_customComment = my_tempComment;
				my_IU_Email->at(i)->append(my_customComment);
			}
		}

		pos = my_IU_Email->at(i)->find(FILE_DIS_SEQ, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			
			my_IU_Email->at(i)->append(FILE_WHITE_SPACE);
			my_IU_Email->at(i)->append(my_DIS_Sequence);
			my_IU_Email->at(i)->append("\n");
		}

		// Do not display the new detections multiple times since it is its own vector
		if(!is_displayedNewDetections)
		{
			pos = my_IU_Email->at(i)->find(FILE_NEW_DETECT, 0);
			if(pos == string::npos)
			{
				// Search string not found
			}
			else
			{
				my_IU_Email->at(i)->append("\n");
			}

			pos = my_IU_Email->at(i)->find(FILE_NEW_DET_LINES, 0);
			if(pos == string::npos)
			{
				// Search string not found
			}
			else
			{
				// To state that the new detections have already been displayed
				is_displayedNewDetections = (true);

				// Search string found
				for(uint_t p = 0; p < my_New_DetectionsList->size(); ++p)
				{
					if(p == 0)
					{
						my_IU_Email->at(i)->append("<br>");
					}

					my_IU_Email->at(i)->append(*my_New_DetectionsList->at(p));
					my_IU_Email->at(i)->append("<br>");
				} // end of for-loop
			} // end of if-else
		} // end of if-else
	} // end of for-loop

	// Erase the last element due to ----- line problems
	my_IU_Email->erase(my_IU_Email->end()-1);
	/////////////////////////////////////////////////////

	if(TEST_OUTPUT)
		this->test_outputLog(IU);
	else
		this->outputLog(IU);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::generateHH_Email()
{
	if(!my_HH_Email->empty())
	{
		// Cannot specify the same option multiple times!
		this->displayHelp();
		throw domain_error(ERROR_108);
	}

	cout << GEN_HH_EMAIL << endl;

	field_t someField = (" ");

	fstream fin;
	fin.open(HH_TEMPLATE_FILE, ios::in);
	if(!fin)
	{
		// Publishing template does not exist to input from
		this->displayHelp();
		throw domain_error(ERROR_105);
	}

	// Inputting template into vector
	while(!fin.eof())
	{
		fin >> ws; 
		getline(fin, someField);
		
		my_HH_Email->push_back(new field_t(someField));
	}
	fin.close();
	
	/////////////////////////////////////////////////////
	// Inserting HH data into vector
	/* 
	Items to insert (in order): (2 examples of each and their line numbers in the file)
	NOTE: Line number starts with 0 and not 1!!!
	 - Product Ver for SAP:      <Line 6>  (e.g., 20050404.010) <-- has a product version #
	 - Product Ver for PocketPC: <Line 7>  (e.g., 20050404.000) <-- always three zeros
	 - Product Ver for SAH:      <Line 8>  (e.g., 20050404) <-- doesn't have a version
	 - Build Number:             <Line 11> (e.g., 050305H, 060205H)
	 - Purpose:                  <Line 12> (e.g., Monthly Handheld Release, Emergency for SymbOS.Hobbes.A)
	*/
	for(uint_t i = 0; i < my_HH_Email->size(); ++i)
	{
		// Find the search string for each line

		string::size_type pos = my_HH_Email->at(i)->find(FILE_PROD_VER_SAP, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_HH_Email->at(i)->append(FILE_WHITE_SPACE);
			my_HH_Email->at(i)->append(my_productVersion_SAH);
		}

		pos = my_HH_Email->at(i)->find(FILE_PROD_VER_PPC, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_HH_Email->at(i)->append(FILE_WHITE_SPACE);
			my_HH_Email->at(i)->append(my_productVersion_PPC);
		}

		pos = my_HH_Email->at(i)->find(FILE_PROD_VER_SAH, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_HH_Email->at(i)->append(FILE_WHITE_SPACE);
			my_HH_Email->at(i)->append(my_productVersion_SAP);
		}

		pos = my_HH_Email->at(i)->find(FILE_BUILD_NUM, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_HH_Email->at(i)->append(FILE_WHITE_SPACE);
			my_HH_Email->at(i)->append(my_DBCSID);
		}

		// If there is no emergency, it will default to DEFAULT_LU_MESSAGE
		if(!isCustomMessage())
		{
			my_customComment = (DEFAULT_HH_MSG);
		}

		pos = my_HH_Email->at(i)->find(FILE_PURPOSE, 0);
		if(pos == string::npos)
		{
			// Search string not found
		}
		else
		{
			// Search string found
			

			my_HH_Email->at(i)->append(FILE_WHITE_SPACE);
			if(!isCustomMessage())
			{
				my_HH_Email->at(i)->append(my_customComment);
			}
			else
			{
				string my_tempComment = "<font color=\"Red\"><strong>";
				my_tempComment += my_customComment;
				my_tempComment += "</strong></font>";
				my_customComment = my_tempComment;
				my_HH_Email->at(i)->append(my_customComment);
			} // end of if-else
		} // end of if-else
	} // end of for-loop
	/////////////////////////////////////////////////////

	if(TEST_OUTPUT)
		this->test_outputLog(HH);
	else
		this->outputLog(HH);

}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getDef_Path(path_t defPath)
{
	my_defPath = (defPath);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getCustomComment()
{
	cout << '\n' << ENTER_CC_COMM 
		<< "____________________________"
		<< "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
		<< "\b\b\b\b\b\b\b\b";
	cin >> ws; 
	getline(cin, my_customComment);

	endl(cout);

	my_isCustomMessage = (true);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getDBCS_ID_Letter()
{
	cout << '\n' << ENTER_DBCS_ID
		<< "_"
		<< "\b";
	cin >> ws;
	getline(cin, my_DBCSID_Letter);

	// converting all characters to lowercase
	for(uint_t i = 0; i < my_DBCSID_Letter.size(); ++i)
		my_DBCSID_Letter.at(i) = tolower(my_DBCSID_Letter.at(i));

	// Checks to ensure the DBCS ID is valid
	// (must contain at least one character)
	if(!isDBCS_Letter_Valid())
	{
		// DBCS ID is invalid, does not contain a character
		this->displayHelp();
		throw domain_error(ERROR_110);
	}

	// Was apparently calling this function twice which was resulting in an error
	// NOT DETECTED IN VS 2003.NET
	//this->getDBCS_ID(); // removed rev 0.15 due to problems
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getDBCS_ID()
{
	// Create the DBCS_ID (e.g., 030507a, 060305b)
	my_DBCSID = my_month;
	my_DBCSID += my_day;

	// Prior to changing the format to 2005 to 05, we need
	// to keep a copy of 2005 in a global variable
	my_full_year = (my_year);
	
	// Change the format of the year from 2005 to 05
	my_year.erase(my_year.begin(), my_year.begin()+2);

	my_DBCSID += my_year;
	my_DBCSID += my_DBCSID_Letter;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getProduct_Version()
{
	uchar_t buffer[12];
	uint_t version, day, month;
	year_t year;
	field_t ver_zero_string, day_zero_string, month_zero_string;	
	char my_ver_char[4], my_day_char[3], my_month_char[3], my_year_char[5];

	file_t defFile = (my_defPath);

	defFile += BACK_SLASH;
	defFile += strlwr(DEF_FILE);

	fstream fin;
	fin.open(defFile.c_str(), ios::binary | ios::in);
	if(!fin)
	{
		// Definition file does not exist under the given path
		this->displayHelp();
		throw domain_error(ERROR_111);
	}

    fin.read((char*) buffer, sizeof(buffer));
	if(!fin)
	{
		// Error reading from definition file!
		this->displayHelp();
		throw domain_error(ERROR_112);
	}

	if(buffer[0] != 'S' || buffer[1] != 'Y'
	|| buffer[2] != 'M' || buffer[3] != 'C')
	{
		// Definition file is corrupt!
		this->displayHelp();
		throw domain_error(ERROR_113);
	}

	/////////////////////////////////////////////////////
	// Retrieve info from buffer and convert to int for display
	month	= static_cast<uint_t>(buffer[8]);
	day		= static_cast<uint_t>(buffer[9]);
	version	= static_cast<uint_t>(buffer[4]);
	year	= buffer[10];
	year	= year + 1900;
	/////////////////////////////////////////////////////

	// Make sure there is a zero when there is only one digit
	// For example, month of March should not be 3, but should be 03
	if(version < 10)
	{
		// Add two zeros
		ver_zero_string = ("00");
	}
	else if(version < 100)
	{
		// Add one zero
		ver_zero_string = ("0");
	}
	else
	{
		// Leave it blank
		ver_zero_string = ("");
	}
	
	if(month < 10)
	{
		// Add one zero
		month_zero_string = ("0");
	}
	else
	{
		// Leave it blank
		month_zero_string = ("");
	}

	if(day < 10)
	{
		// Add one zero
		day_zero_string = ("0");
	}
	else
	{
		// Leave it blank
		day_zero_string = ("");
	}

	// Convert integer to character pointer (char*)
	_itoa(year,		my_year_char,	10);
	_itoa(month,	my_month_char,	10);
	_itoa(day,		my_day_char,	10);
	_itoa(version,	my_ver_char,	10);

	// Creating a global copy of the product_version variables
	// Also, converting from character pointer (char*) to field_t
	my_year		= (my_year_char);
	my_month	= (my_month_char);
	my_day		= (my_day_char);
	my_version	= (my_ver_char);

	// Append the zero's (if applicable) to the appropriate field_t's
	my_month	= month_zero_string + my_month;
	my_day		= day_zero_string	+ my_day;
	my_version	= ver_zero_string	+ my_version;

	// Sum all the global field_t's up into one field_t to create the prod_version
	my_productVersion	= (my_year);
	my_productVersion	+= my_month;
	my_productVersion	+= my_day;

	// Create the Product Version for Palm (SAH)
	my_productVersion_SAP = my_productVersion;

	my_productVersion += DOT;

	// Create the Product Version for Palm (SAP) and PocketPC (PPC) devices
	my_productVersion_SAH	= my_productVersion; // prepare the SAH sequence #
	my_productVersion_PPC	= my_productVersion;
	my_productVersion_PPC	+= PPC_PRODUCT_VERSION;

	my_productVersion += my_version;

	fin.close();

	// Call the NAVCE_Version function to create the NAVCE_Version
	// Send in the integer version of the: (month, day, and version)
	this->getNAVCE_Version(month, day, version);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getDIS_Sequence()
{
	char my_seq_char[6];

	file_t defFile = (my_defPath);

	defFile += BACK_SLASH;
	defFile += strlwr(DEF_FILE);

	fstream fin;
	fin.open(defFile.c_str(), ios::binary | ios::in);
	if(!fin)
	{
		// Definition file does not exist under the given path
		this->displayHelp();
		throw domain_error(ERROR_111);
	}

	fin.seekg(-8, ios::end);
	fin.read((char*)&my_sequence, 4);
	if(!fin)
	{
		// Definition file is corrupt!
		this->displayHelp();
		throw domain_error(ERROR_113);
	}

	// Convert sequence_t to character pointer (char*)
	_itoa(my_sequence, my_seq_char, 10);

	// Convert character pointer (char*) to string
	my_DIS_Sequence = (my_seq_char);

	fin.close();
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getNAVCE_Version(uint_t month, uint_t day, uint_t version)
{
	/* 
	Create the NAVCE_Version (e.g., 0311i, 0615af)
	It is actually 70311i, but the 7 is inputted
	from the template since it changes yearly.
	*/
	field_t my_letter = (" ");

	if(version == 1)		my_letter = "a";
	else if(version == 2)	my_letter = "b";
	else if(version == 3)	my_letter = "c";
	else if(version == 4)	my_letter = "d";
	else if(version == 5)	my_letter = "e";
	else if(version == 6)	my_letter = "f";
	else if(version == 7)	my_letter = "g";
	else if(version == 8)	my_letter = "h";
	else if(version == 9)	my_letter = "i";
	else if(version == 10)	my_letter = "j";
	else if(version == 11)	my_letter = "k";
	else if(version == 12)	my_letter = "l";
	else if(version == 13)	my_letter = "m";
	else if(version == 14)	my_letter = "n";
	else if(version == 15)	my_letter = "o";
	else if(version == 16)	my_letter = "p";
	else if(version == 17)	my_letter = "q";
	else if(version == 18)	my_letter = "r";
	else if(version == 19)	my_letter = "s";
	else if(version == 20)	my_letter = "t";
	else if(version == 21)	my_letter = "u";
	else if(version == 22)	my_letter = "v";
	else if(version == 23)	my_letter = "w";
	else if(version == 24)	my_letter = "x";
	else if(version == 25)	my_letter = "y";
	else if(version == 26)	my_letter = "z";
	else if(version == 27)	my_letter = "aa";
	else if(version == 28)	my_letter = "ab";
	else if(version == 29)	my_letter = "ac";
	else if(version == 30)	my_letter = "ad";
	else if(version == 31)	my_letter = "ae";
	else if(version == 32)	my_letter = "af";
	else if(version == 33)	my_letter = "ag";
	else if(version == 34)	my_letter = "ah";
	else if(version == 35)	my_letter = "ai";
	else if(version == 36)	my_letter = "aj";
	else if(version == 37)	my_letter = "ak";
	else if(version == 38)	my_letter = "al";
	else if(version == 39)	my_letter = "am";
	else if(version == 40)	my_letter = "an";
	else if(version == 41)	my_letter = "ao";
	else if(version == 42)	my_letter = "ap";
	else if(version == 43)	my_letter = "aq";
	else if(version == 44)	my_letter = "ar";
	else if(version == 45)	my_letter = "as";
	else if(version == 46)	my_letter = "at";
	else if(version == 47)	my_letter = "au";
	else if(version == 48)	my_letter = "av";
	else if(version == 49)	my_letter = "aw";
	else if(version == 50)	my_letter = "ax";
	else if(version == 51)	my_letter = "ay";
	else if(version == 52)	my_letter = "az";
	else if(version == 53)	my_letter = "ba";
	else if(version == 54)	my_letter = "bb";
	else if(version == 55)	my_letter = "bc";
	else if(version == 56)	my_letter = "bd";
	else if(version == 57)	my_letter = "be";
	else if(version == 58)	my_letter = "bf";
	else if(version == 59)	my_letter = "bg";
	else if(version == 60)	my_letter = "bh";
	else if(version == 61)	my_letter = "bi";
	else if(version == 62)	my_letter = "bj";
	else if(version == 63)	my_letter = "bk";
	else if(version == 64)	my_letter = "bl";
	else if(version == 65)	my_letter = "bm";
	else if(version == 66)	my_letter = "bn";
	else if(version == 67)	my_letter = "bo";
	else if(version == 68)	my_letter = "bp";
	else if(version == 69)	my_letter = "bq";
	else if(version == 70)	my_letter = "br";
	else if(version == 71)	my_letter = "bs";
	else if(version == 72)	my_letter = "bt";
	else if(version == 73)	my_letter = "bu";
	else if(version == 74)	my_letter = "bv";
	else if(version == 75)	my_letter = "bw";
	else if(version == 76)	my_letter = "bx";
	else if(version == 77)	my_letter = "by";
	else if(version == 78)	my_letter = "bz";
	else if(version == 79)	my_letter = "ca";
	else if(version == 80)	my_letter = "cb";
	else if(version == 81)	my_letter = "cc";
	else if(version == 82)	my_letter = "cd";
	else if(version == 83)	my_letter = "ce";
	else if(version == 84)	my_letter = "cf";
	else if(version == 85)	my_letter = "cg";
	else if(version == 86)	my_letter = "ch";
	else if(version == 87)	my_letter = "ci";
	else if(version == 88)	my_letter = "cj";
	else if(version == 89)	my_letter = "ck";
	else if(version == 90)	my_letter = "cl";
	else if(version == 91)	my_letter = "cm";
	else if(version == 92)	my_letter = "cn";
	else if(version == 93)	my_letter = "co";
	else if(version == 94)	my_letter = "cp";
	else if(version == 95)	my_letter = "cq";
	else if(version == 96)	my_letter = "cr";
	else if(version == 97)	my_letter = "cs";
	else if(version == 98)	my_letter = "ct";
	else if(version == 99)	my_letter = "cu";

	//0311i MonthDayLetter (which was converted by the version)
	my_NAVCE_Version = (my_month);
	my_NAVCE_Version += my_day;
	my_NAVCE_Version += my_letter;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::getNew_Detections()
{
	result_t isDateFound = (true);

	// Date format in the file (e.g., 03/17/05, 11/20/05)
	field_t todaysDate = (my_month);
	todaysDate += '/';
	todaysDate += my_day;
	todaysDate += '/';
	todaysDate += my_year;

	field_t someLine	= (" ");
	file_t updatesFile	= (my_defPath);

	updatesFile += BACK_SLASH;
	updatesFile += UPDATES_FILE;

	fstream fin;
	fin.open(updatesFile.c_str(), ios::in);
	if(!fin)
	{
		// Updates file does not exist in definitions directory!
		this->displayHelp();
		throw domain_error(ERROR_115);
	}

	/* 
	Retrieve the latest detections (sorted by date)
	from the updates file in hawking folder.
	*/
	while(!fin.eof())
	{
		fin >> ws;
		getline(fin, someLine);

		// search for the string: "New virus definitions (sorted by Date added):"
		if(someLine == FILE_SEARCH_STRING)
		{
			// Found the string (now, need to go down 2 lines to check for new detections)
			fin >> ws; getline(fin, someLine); // Line 1
			fin >> ws; getline(fin, someLine); // Line 2

			// Ready to start checking for dates (must be compared to todays date)
			while(isDateFound)
			{
				fin >> ws; getline(fin, someLine);

				// Check the contents of the line for the date (59 char to the date)
				for(uint_t i = 0; i < someLine.size(); ++i)
				{
					// Comparing <todaysDate> variable to the date in the file
					string::size_type pos = someLine.find(todaysDate, 0);
					if(pos == string::npos) 
					{
						// Search string not found
						isDateFound = (false);
					}
					else
					{
						// Search string found
						my_New_DetectionsList->push_back(new field_t(someLine));
						break;
					} // end of if-else
				} // end of for-loop
			} // end of while-loop
		} // end of if
	} // end of while-loop
	
	fin.close();
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
field_t emailGen::getPalm_SAHVersion()
{
	// Get the Palm ( SAH ) sequence version # by prompting the user
	field_t sequenceNumber;
	
	// Prompt the user to enter the Palm ( SAH ) sequence #
	cout << '\n' << ENTER_PALM_SEQ;
	cin >> sequenceNumber;

	endl(cout);

	return(sequenceNumber);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
/* discontinued as of 10/11/2005 (rev 0.14)
void emailGen::createTRX_Filename()
{
	// Copy everything execept for the letter
	for(uint_t i = 0; i < (my_DBCSID.size()-1); ++i)
		my_trxName += my_DBCSID.at(i);

	// Appending file extension
	my_trxName += strlwr(TRX_EXTENSION);

	// Left 1 space in the beginning [0] so must erase it
	my_trxName.erase(my_trxName.begin());
}
*/
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::createTRZ_Filename()
{
	// Copy everything execept for the letter
	for(uint_t i = 0; i < (my_DBCSID.size()-1); ++i)
		my_trzName += my_DBCSID.at(i);

	// Remove all characters from the TRZ file name
	for(uint_t i = 0; i < my_trzName.size(); ++i)
	{
		if(isalpha(my_trzName.at(i)))
		{
			my_trzName.erase(i);
		}
	}

	//my_trzName_IU_LOG = my_trzName; discontinued as of 10/11/2005 (rev 0.14)

	// trz file name suffix (0.15 changed to DBCSID_Letter due to file name changes)
	my_trzName += DBCSID_Letter();//TRZ_LETTER; // no more TRZ_LETTER as of 0.15 revision due to TRZ name changes

	// Appending file extension
	//my_trzName_IU_LOG += strlwr(TRZ_EXTENSION); discontinued as of 10/11/2005 (rev 0.14)
	//my_trzName += strlwr(TRZ_EXTENSION);

	// Left 1 space in the beginning [0] so must erase it
	//my_trzName_IU_LOG.erase(my_trzName_IU_LOG.begin()); discontinued as of 10/11/2005 (rev 0.14)
	my_trzName.erase(my_trzName.begin());

	//************** Revision 0.15 changed TRZ file name **************
    /* 
	Added revision 0.15 where the TRZ file names changed to:
	(i.e., 04102006a-pkg1.trz, 04102006a-pkg2.trz, 04102006a-pkg3.trz,
	       04102006a-pkg4.trz, 04102006a-pkg5.trz)

	Packages 1 - 5 get published for LiveUpdate Plus (LUP)
	Packages 2 - 5 get published for LiveUpdate (LU)
	*/

	// LUP
	my_trzName_LUP = my_trzName + TRZ_PACKAGE_1 + strlwr(TRZ_EXTENSION);
    my_trzName_LUP += ", ";
	my_trzName_LUP += my_trzName + TRZ_PACKAGE_2 + strlwr(TRZ_EXTENSION);
    my_trzName_LUP += ", ";
	my_trzName_LUP += my_trzName + TRZ_PACKAGE_3 + strlwr(TRZ_EXTENSION);
    my_trzName_LUP += ", ";
	my_trzName_LUP += my_trzName + TRZ_PACKAGE_4 + strlwr(TRZ_EXTENSION);
    my_trzName_LUP += ", ";
	my_trzName_LUP += my_trzName + TRZ_PACKAGE_5 + strlwr(TRZ_EXTENSION);
    my_trzName_LUP += ", ";
	my_trzName_LUP += my_trzName + TRZ_PACKAGE_6 + strlwr(TRZ_EXTENSION);

	// LU
	my_trzName_LU = my_trzName + TRZ_PACKAGE_2 + strlwr(TRZ_EXTENSION);
    my_trzName_LU += ", ";
	my_trzName_LU += my_trzName + TRZ_PACKAGE_3 + strlwr(TRZ_EXTENSION);
    my_trzName_LU += ", ";
	my_trzName_LU += my_trzName + TRZ_PACKAGE_4 + strlwr(TRZ_EXTENSION);
    my_trzName_LU += ", ";
	my_trzName_LU += my_trzName + TRZ_PACKAGE_5 + strlwr(TRZ_EXTENSION);
    my_trzName_LU += ", ";
	my_trzName_LU += my_trzName + TRZ_PACKAGE_6 + strlwr(TRZ_EXTENSION);

	//*****************************************************************

}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::select_LU_Post(result_t isPost)
{
	my_isLU_Post = (isPost);

	if( !isCustomMessage() )
	{
		char choice = ( ' ' );

		// Force the user to enter either 'N' or 'Y'
		while( choice != 'N' && choice != 'Y' )
		{
			cout << '\n' << IS_FULL_POST;
			cin >> choice;

			choice = toupper(choice);

			if( choice == 'Y' )
			{
				my_isFullLU_Post = ( true );
			}
			else
			{
				my_isFullLU_Post = ( false );
			} // end of if
		} // end of while-loop
	} // end of if
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::select_LUP_Post(result_t isPost)
{
	my_isLUP_Post = (isPost);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::select_IU_Post(result_t isPost)
{
	my_isIU_Post = (isPost);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::select_HH_Post(result_t isPost)
{
	my_isHH_Post = (isPost);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::resetResultFile()
{
	fstream fout;
	fout.open(RESULT_FILE, ios::out);
	fout.close();
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::modify_PalmSAH_Version(field_t seqNumber)
{
	my_productVersion_SAH += (seqNumber);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::updatePH( )
{
	// This section of the code will allow the client code to access
	// the p4 server and update the ph.txt file

	// Communication method will be command-line rather than the API
	
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::displayTitle() const
{
	system(CLEAR_SCREEN);

	endl(cout);
	cout << TITLE_COPYRIGHT << "\n\n" 
		 << PROGRAM_AUTHOR	<< '\n' << TITLE_LINE << "\n\n" << endl;
	
	for(uint_t i = 0; i < strlen(EMAILGEN_START); ++i)
	{
		cout << EMAILGEN_START[i];
		
		Sleep(SLEEP_TIME);
	}

	cout << "\n\n" << flush;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::displayHelp() const
{
	cout << '\n' << USAGE_INFO << '\n' << endl;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
string emailGen::defPath() const
{
	return(my_defPath);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
std::string emailGen::customComment() const
{
	return(my_customComment);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::displayLog_File() const
{	
	//string my_log = (strlwr(EDITOR));

	// Now you have the windows folder in szFolderName
	char szFolderName[MAX_PATH];
	GetWindowsDirectory(szFolderName, MAX_PATH);

	// Create the editor path
	string my_log = ("");
	my_log += szFolderName[0];
	my_log += szFolderName[1];
	my_log += strlwr(EDITOR);
	my_log += ' ';

	// Display the test log output (only in test mode)
	if(TEST_OUTPUT)
	{
		char full_logPath[100];

		// Convert relative log path to absolute for ie to open
		_fullpath(full_logPath, TEST_ALL_FILE, _MAX_PATH );

		// Append absolute path
		my_log += full_logPath;

		// Executes the EDITOR and displays the test log file for the current run
		WinExec(my_log.c_str(), SHOW_EDITOR);
	}
	else
	{
		char full_logPath[100];

		// Convert relative log path to absolute for ie to open
		_fullpath(full_logPath, RESULT_FILE, _MAX_PATH );

		// Append absolute path
		my_log += full_logPath;

		// Executes the EDITOR and displays the log file for the current run
		WinExec(my_log.c_str(), SHOW_EDITOR);
	}
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::displayLog_Screen() const
{
	// Display the report onto the monitor ( screen )
	cout << '\n' << SCREEN_REPORT					<< '\n'
		 << DBCS_ID_ENTRY	<< my_DBCSID			<< '\n' 
		 << PROD_VER_ENTRY	<< my_productVersion	<< '\n'
		 << NAVCE_ENTRY		<< my_NAVCE_Version		<< '\n' 
	    //<< TRX_FILE_ENTRY	<< my_trxName			<< '\n' discontinued as of 10/11/2005 (rev 0.14)
		 << TRZ_FILE_ENTRY	<< my_trzName_LUP		<< '\n'
		 << DIS_SEQ_ENTRY	<< my_DIS_Sequence		<< '\n' 
		 << '\n'
		 << NEW_DETECT_LIST	<< endl;
	
	// If the DetectionList ( vector ) is not empty
	if(!my_New_DetectionsList->empty())
	{
		for(uint_t i = 0; i < my_New_DetectionsList->size(); ++i)
			cout << *my_New_DetectionsList->at(i) << endl;
	}
	else
	{
		// No new detections added, please verify manually!
		cout << WARNING_100 << endl;
	}
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::outputLog(pubType_t type) const
{
	const vector<field_t*>* pub_data;

	my_resultPath = (RESULT_FILE);

	/////////////////////////////////////////////////
	//**************** Live output ****************//
	fstream fout;
	fout.open(my_resultPath.c_str(), ios::out | ios::app);
	if(!fout)
	{ 
		// File cannot be written to
		this->displayHelp();
		throw domain_error(ERROR_104);
	}

	// Determine whether it is an LU, LUP, IU, or HH test
	type == LU	?	pub_data = (my_LU_Email),  fout << LU_RESULTS << DBCSID( ) << RESULTS_ENDING << endl :
	type == LUP ?	pub_data = (my_LUP_Email), fout << LUP_RESULTS << DBCSID( ) << RESULTS_ENDING << endl:
	type == IU	?	pub_data = (my_IU_Email),  fout << IU_RESULTS << DBCSID( ) << RESULTS_ENDING << endl :
	type == HH	?	pub_data = (my_HH_Email),  fout << HH_RESULTS << DBCSID( ) << RESULTS_ENDING << endl :
											   fout << NO_RESULTS << DBCSID( ) << RESULTS_ENDING << endl ;
											   
	fout << HTML_HORIZ_RULE << '\n' << endl;
	for(uint_t i = 0; i < pub_data->size(); ++i)
	{
		fout << *pub_data->at(i) << endl;
		if(!fout)
		{
			// Cannot write to log file!
			this->displayHelp();
			throw domain_error(ERROR_114);
		}
	}

	fout << '\n' << endl;
	fout.close();
	/////////////////////////////////////////////////
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::test_outputLog(pubType_t type) const
{
	const vector<field_t*>* my_test;

	/////////////////////////////////////////////////
	//*************** Testing output **************//
	fstream fout;
	fout.open(TEST_ALL_FILE, ios::out | ios::app);
	if(!fout)
	{
		// File cannot be written to
		this->displayHelp();
		throw domain_error(ERROR_104);
	}

	// Determine whether it is an LU, LUP, IU or HH test
	type == LU	?	my_test = (my_LU_Email),  fout << LU_RESULTS << endl :
	type == LUP ?	my_test = (my_LUP_Email), fout << LUP_RESULTS << endl:
	type == IU	?	my_test = (my_IU_Email),  fout << IU_RESULTS << endl :
	type == HH	?	my_test = (my_HH_Email),  fout << HH_RESULTS << endl :
											  fout << NO_RESULTS << endl ;

	fout << HTML_HORIZ_RULE << '\n' << endl;
	for(uint_t i = 0; i < my_test->size(); ++i)
	{
		fout << *my_test->at(i) << endl;
		if(!fout)
		{
			// Cannot write to log file!
			this->displayHelp();
			throw domain_error(ERROR_114);
		}
	}

	fout << '\n' << endl;
	fout.close();
	/////////////////////////////////////////////////
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isDBCS_Letter_Valid() const
{
	result_t characterResult = (false);

	// Test: Check to ensure there is atleast one character
	for(uint_t i = 0; i < my_DBCSID_Letter.size(); ++i)
	{
		if(isalpha(my_DBCSID_Letter.at(i)))
			characterResult = (true);
	}

	return(characterResult);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::verifyDef_Path() const
{
	file_t defFile = (my_defPath);

	defFile += BACK_SLASH;
	defFile += strlwr(DEF_FILE);
	
	/////////////////////////////////////////////////
	// Ensure the definition file exists on the HD
	fstream fin;
	fin.open(defFile.c_str(), ios::binary | ios::in);
	if(!fin)
	{
		// Definition file does not exist under the given path
		this->displayHelp();
		throw domain_error(ERROR_111);
	}

	fin.close();
	/////////////////////////////////////////////////
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
field_t emailGen::version() const
{
	return(my_version);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
field_t emailGen::day() const 
{
	return(my_day);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
field_t emailGen::month() const
{
	return(my_month);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
field_t emailGen::year() const
{
	return(my_year);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
sequence_t emailGen::sequence() const
{
	return(my_sequence);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
id_t emailGen::DBCSID_Letter() const
{
	return(my_DBCSID_Letter);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
id_t emailGen::DBCSID() const
{
	return(my_DBCSID);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isLU_Post() const
{
	return(my_isLU_Post);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::is_FullLU_Post() const
{
	return( my_isFullLU_Post );
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isLUP_Post() const
{
	return(my_isLUP_Post);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isIU_Post() const
{
	return(my_isIU_Post);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isHH_Post() const
{
	return(my_isHH_Post);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
result_t emailGen::isCustomMessage() const
{
	return(my_isCustomMessage);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void emailGen::isDISSequence_Unique() const
{
	// Ensure the DIS Sequence number is indeed unique

	// Creating data structure for FindFirstFile function
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	// Appending the DIS Sequence number to the SDGS Path
	field_t DIS_Seq_Path = (SDGS_PATH);
	DIS_Seq_Path += my_DIS_Sequence;

	/////////////////////////////////////////////////
	// Testing DIS Sequence number ( making it unique )
	//DIS_Seq_Path = (SDGS_PATH);
	//DIS_Seq_Path += "42663"; // this # was unique on 04/11/05
	/////////////////////////////////////////////////
		
	hFind = FindFirstFile(DIS_Seq_Path.c_str(), &FindFileData);
	if(hFind != INVALID_HANDLE_VALUE) 
	{
		// DIS Sequence number is not unique!
		this->displayHelp();
		throw domain_error(ERROR_117);
	}

	// Closing the file handle
	FindClose(hFind);
}
/////////////////////////////////////////////////////