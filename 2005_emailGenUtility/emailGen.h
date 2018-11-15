/////////////////////////////////////////////////////
// Filename: <emailGen.h>

/////////////////////////////////////////////////////
#ifndef __EMAILGEN_H__
#define __EMAILGEN_H__
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#include "messages.h"
#include "typedefs.h"
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#include <string>
#include <vector>
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
class emailGen
{
public:

	//**********************************************
	// Constructors / Destructors
	emailGen();
	~emailGen();
	
	//**********************************************
	// Modifiers
	void generateLU_Email();
	void generateLUP_Email();
	void generateIU_Email();
	void generateHH_Email();

	void getDef_Path(std::string defPath);
	void getCustomComment();
	void getDBCS_ID_Letter();
	void getDBCS_ID();
	void getProduct_Version();
	void getDIS_Sequence();
	void getNAVCE_Version(uint_t month, uint_t day, uint_t version);
	void getNew_Detections();

	field_t getPalm_SAHVersion(); // Prompts the user to enter the SAH sequence # 

	//void createTRX_Filename(); discontinued as of 10/11/2005 (rev 0.14)
	void createTRZ_Filename();
	
	void select_LU_Post(result_t isPost);

	void select_LUP_Post(result_t isPost);
	void select_IU_Post(result_t isPost);
	void select_HH_Post(result_t isPost);

	void resetResultFile();

	void modify_PalmSAH_Version(field_t seqNumber);

	void updatePH( );

	//**********************************************
	// Accessors
	void displayTitle() const;
	void displayHelp() const;
	
	path_t defPath() const;
	
	std::string customComment() const;
	
	void displayLog_File() const;   // display on editor
	void displayLog_Screen() const; // display on screen

	void outputLog(pubType_t type) const;
	void test_outputLog(pubType_t type) const;
	
	result_t isDBCS_Letter_Valid() const;

	void verifyDef_Path() const;

	field_t version() const;
	field_t day() const; 
	field_t month() const;
	field_t year() const;

	sequence_t sequence() const;

	id_t DBCSID_Letter() const;
	id_t DBCSID() const;

	result_t isLU_Post() const;
	result_t is_FullLU_Post() const;

	result_t isLUP_Post() const;
	result_t isIU_Post() const;
	result_t isHH_Post() const;

	result_t isCustomMessage() const;

	void isDISSequence_Unique() const;

private:

	//**********************************************
	// Private Attributes
	mutable path_t my_defPath;
	mutable path_t my_updatesFilePath;
	mutable path_t my_resultPath;

	std::string my_customComment;

	std::vector<field_t*>* my_LU_Email;
	std::vector<field_t*>* my_LUP_Email;
	std::vector<field_t*>* my_IU_Email;
	std::vector<field_t*>* my_New_DetectionsList;
	std::vector<field_t*>* my_HH_Email;
	
	id_t my_DBCSID_Letter;
	id_t my_DBCSID;

	//field_t my_trxName; discontinued as of 10/11/2005 (rev 0.14)
	field_t my_trzName;

	field_t my_trzName_LU;  // added rev 0.15 due to TRZ file name changes
	field_t my_trzName_LUP; // added rev 0.15 due to TRZ file name changes

	//field_t my_trzName_IU_LOG; // for the IU log file, discontinued as of 10/11/2005 (rev 0.14)
	field_t my_NAVCE_Version;
	field_t my_DIS_Sequence;

	field_t my_productVersion;

	field_t my_productVersion_SAP; // old palm ( SAP )
	field_t my_productVersion_PPC; // pocketpc WinCE ( SAH )
	field_t my_productVersion_SAH; // newer palm ( SAH )

	sequence_t my_sequence;

	field_t my_version;
	field_t my_day;
	field_t my_month;
	field_t my_year;		// i.e., 05
	field_t my_full_year;	// i.e., 2005

	result_t my_isLU_Post;
	result_t my_isFullLU_Post;
	result_t my_isLUP_Post;
	result_t my_isIU_Post;
	result_t my_isHH_Post;

	result_t my_isCustomMessage; // rollback, engine, emergency, etc.
};
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////