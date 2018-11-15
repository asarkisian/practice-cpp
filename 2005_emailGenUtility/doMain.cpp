/////////////////////////////////////////////////////
// Filename: <doMain.cpp>

/////////////////////////////////////////////////////
#include "emailGen.h"
#include "options.h"
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#include <iostream>
#include <windows.h>
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
using std::cout;
using std::domain_error;
using std::endl;
using std::flush;
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void doMain(int argc, char** argv)
{
	// Allocate new memory for the emailGen object
	emailGen* g = (new emailGen());

	// Display title at top of program emailGen
	g->displayTitle();

	if((argc == DEFAULT_ARGUMENT) 
	|| (argc == MIN_ARGUMENT))
	{
		// Not enough arguments
		g->displayHelp();
		throw domain_error(ERROR_100);
	}
	else if(argc > MAX_ARGUMENT)
	{
		// Too many arguments
		g->displayHelp();
		throw domain_error(ERROR_101);
	}
	else
	{
		// Reset the result file (prevent from appending)
		g->resetResultFile();

		// Prompt the user for the DBCS_ID_Letter
		g->getDBCS_ID_Letter();

		// Retrieve the 1st argument which is the def path
		g->getDef_Path(strlwr(argv[1]));

		// Verify the definition file exists under the given path
		g->verifyDef_Path();

		// Get the product version from the definition file
		// This is where the version, day, month and year get originally created
		// The NAVCE_Version is also called from within this function
		g->getProduct_Version(); // <--- g->getNAVE_Version();

		// Get the entire DBCS_ID based off the DBCS_ID_Letter and Product Version
		g->getDBCS_ID();

		// Create the TRX filename based off the DBCS_ID
		// g->createTRX_Filename(); discontinued as of 10/11/2005 (rev 0.14)

		// Create the TRZ filename based off the DBCS_ID (only for LU or LUP mode)
		g->createTRZ_Filename();

		// Get the DIS sequence number from the definition file
		g->getDIS_Sequence();

		// Ensure the DIS sequence number is indeed unique
		g->isDISSequence_Unique();

		// Get the new detections list from the definitions path
		g->getNew_Detections();

		for(int i = MIN_ARGUMENT; i < argc; ++i)
		{
			// Compare switches (command-line)
			if(!strcmp(strlwr(argv[i]), strlwr(CC_SWITCH)))
			{
				if(i > MIN_ARGUMENT)
				{
					g->displayHelp();
					throw domain_error(ERROR_109);
				}
				else
				{
					// Prompt the user to enter a custom comment ( CC )
					g->getCustomComment();
				}
			}
			else if(!strcmp(strlwr(argv[i]), ALL_SWITCH))
			{
				// The user selected the -all switch

				// NOTE: The -all switch does not work with the handheld module

				if(!g->isLU_Post() && !g->isLUP_Post() && !g->isIU_Post() )
				{
					g->select_LUP_Post(true);
					g->select_LU_Post(true);
					g->select_IU_Post(true);

					// Generating all email notification reports
					g->generateLUP_Email();
					g->generateLU_Email();
					g->generateIU_Email();
				}
				else
				{
					// Cannot specify the same option multiple times!
					g->displayHelp();
					throw domain_error(ERROR_108);
				}
			}		
			else if(!strcmp(strlwr(argv[i]), LU_SWITCH))
			{
				if(!g->isLU_Post())
				{
					g->select_LU_Post(true);

					// Generating LiveUpdate email notification report
					g->generateLU_Email();
				}
				else
				{
					// Cannot specify the same option multiple times!
					g->displayHelp();
					throw domain_error(ERROR_108);
				}
			}		
			else if(!strcmp(strlwr(argv[i]), strlwr(LUP_SWITCH)))
			{
				if(!g->isLUP_Post())
				{
					g->select_LUP_Post(true);

					// Generating LiveUpdate Plus email notification report
					g->generateLUP_Email();
				}
				else
				{
					// Cannot specify the same option multiple times!
					g->displayHelp();
					throw domain_error(ERROR_108);
				}
			}
			else if(!strcmp(strlwr(argv[i]), strlwr(IU_SWITCH)))
			{
				if(!g->isIU_Post())
				{
					g->select_IU_Post(true);

					// Generating Intelligent Updater email notification report
					g->generateIU_Email();
				}
				else
				{
					// Cannot specify the same option multiple times!
					g->displayHelp();
					throw domain_error(ERROR_108);
				}
			}
			else if(!strcmp(strlwr(argv[i]), strlwr(HH_SWITCH)))
			{
				if(!g->isHH_Post())
				{
					g->select_HH_Post(true);

					// Append the sequence # to the productVersion_SAH
					g->modify_PalmSAH_Version(g->getPalm_SAHVersion());

					// Generating Intelligent Updater email notification report
					g->generateHH_Email();
				}
				else
				{
					// Cannot specify the same option multiple times!
					g->displayHelp();
					throw domain_error(ERROR_108);
				}
			}
			else
			{
				// Invalid command line option
				g->displayHelp();
				throw domain_error(ERROR_102);
			} // end of else
		} // end of for-loop
	} // end of if-else

	// If they only chose -cc, they will receive an error message (added 09/30/2005 )
	if( !g->isHH_Post() && !g->isIU_Post() && !g->isLU_Post() && !g->isLUP_Post() )
	{
		g->displayHelp();
		throw domain_error(ERROR_100);
	} // end of if

	// Generate screen report
	g->displayLog_Screen();

	// emailGen successfully completed
	cout << "\n\n\n" << flush;
	for(uint_t i = 0; i < strlen(EMAILGEN_END); ++i)
	{
		cout << EMAILGEN_END[i];
		Sleep(SLEEP_TIME);
	}

	endl(cout);

	// Generate file report
	g->displayLog_File();

	// Release emailGen object
	delete g;

	// return back to main() function
	return;
}
/////////////////////////////////////////////////////