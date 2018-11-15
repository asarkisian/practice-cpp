#include <fstream>
#include <string>
#include "halloffame.h"
#include "encryptFile.h"

void __fastcall hallOfFame::importDisk()const{

 ifstream fin;
 fin.open(FILE_NAME, ios::in);	//Opens file mode in input mode

	//Going to import the top scores names and scores to these temporary files
	std::string tempPlayaOneName;
	std::string tempPlayaTwoName;
	std::string tempPlayaThreeName;
	std::string tempPlayaFourName;
	std::string tempPlayaFiveName;
	std::string tempPlayaSixName;
	std::string tempPlayaSevenName;
	std::string tempPlayaEightName;
	std::string tempPlayaNineName;
	std::string tempPlayaTenName;

	std::string tempPlayaOneScore;
	std::string tempPlayaTwoScore;
	std::string tempPlayaThreeScore;
	std::string tempPlayaFourScore;
	std::string tempPlayaFiveScore;
	std::string tempPlayaSixScore;
	std::string tempPlayaSevenScore;
	std::string tempPlayaEightScore;
	std::string tempPlayaNineScore;
	std::string tempPlayaTenScore;

  				//Retrieve game data (gamelog.dat)
					getline(fin, tempPlayaOneName, '\n');
					getline(fin, tempPlayaTwoName, '\n');
					getline(fin, tempPlayaThreeName, '\n');
					getline(fin, tempPlayaFourName, '\n');
					getline(fin, tempPlayaFiveName, '\n');
					getline(fin, tempPlayaSixName, '\n');
					getline(fin, tempPlayaSevenName, '\n');
					getline(fin, tempPlayaEightName, '\n');
					getline(fin, tempPlayaNineName, '\n');
					getline(fin, tempPlayaTenName, '\n');

					getline(fin, tempPlayaOneScore, '\n');
					getline(fin, tempPlayaTwoScore, '\n');
					getline(fin, tempPlayaThreeScore, '\n');
					getline(fin, tempPlayaFourScore, '\n');
					getline(fin, tempPlayaFiveScore, '\n');
					getline(fin, tempPlayaSixScore, '\n');
					getline(fin, tempPlayaSevenScore, '\n');
					getline(fin, tempPlayaEightScore, '\n');
					getline(fin, tempPlayaNineScore, '\n');
					getline(fin, tempPlayaTenScore, '\n');


	//Decrypt the players names
	tempPlayaOneName = encryptIt->decryptIt(tempPlayaOneName);
	tempPlayaTwoName = encryptIt->decryptIt(tempPlayaTwoName);
	tempPlayaThreeName = encryptIt->decryptIt(tempPlayaThreeName);
	tempPlayaFourName = encryptIt->decryptIt(tempPlayaFourName);
	tempPlayaFiveName = encryptIt->decryptIt(tempPlayaFiveName);
	tempPlayaSixName = encryptIt->decryptIt(tempPlayaSixName);
	tempPlayaSevenName = encryptIt->decryptIt(tempPlayaSevenName);
	tempPlayaEightName = encryptIt->decryptIt(tempPlayaEightName);
	tempPlayaNineName = encryptIt->decryptIt(tempPlayaNineName);
	tempPlayaTenName = encryptIt->decryptIt(tempPlayaTenName);

	//Decrpyt the players scores
	tempPlayaOneScore = encryptIt->decryptIt(tempPlayaOneScore);
	tempPlayaTwoScore = encryptIt->decryptIt(tempPlayaTwoScore);
	tempPlayaThreeScore = encryptIt->decryptIt(tempPlayaThreeScore);
	tempPlayaFourScore = encryptIt->decryptIt(tempPlayaFourScore);
	tempPlayaFiveScore = encryptIt->decryptIt(tempPlayaFiveScore);
	tempPlayaSixScore = encryptIt->decryptIt(tempPlayaSixScore);
	tempPlayaSevenScore = encryptIt->decryptIt(tempPlayaSevenScore);
	tempPlayaEightScore = encryptIt->decryptIt(tempPlayaEightScore);
	tempPlayaNineScore = encryptIt->decryptIt(tempPlayaNineScore);
	tempPlayaTenScore = encryptIt->decryptIt(tempPlayaTenScore);

	 //Update the main game files
	 theRecords.playerOne[0] = tempPlayaOneName.c_str();
	 theRecords.playerTwo[0] = tempPlayaTwoName.c_str();
	 theRecords.playerThree[0] = tempPlayaThreeName.c_str();
	 theRecords.playerFour[0] = tempPlayaFourName.c_str();
	 theRecords.playerFive[0] = tempPlayaFiveName.c_str();
	 theRecords.playerSix[0] = tempPlayaSixName.c_str();
	 theRecords.playerSeven[0] = tempPlayaSevenName.c_str();
	 theRecords.playerEight[0] = tempPlayaEightName.c_str();
	 theRecords.playerNine[0] = tempPlayaNineName.c_str();
	 theRecords.playerTen[0] = tempPlayaTenName.c_str();

	 theRecords.playerOne[1] = tempPlayaOneScore.c_str();
	 theRecords.playerTwo[1] = tempPlayaTwoScore.c_str();
	 theRecords.playerThree[1] = tempPlayaThreeScore.c_str();
	 theRecords.playerFour[1] = tempPlayaFourScore.c_str();
	 theRecords.playerFive[1] = tempPlayaFiveScore.c_str();
	 theRecords.playerSix[1] = tempPlayaSixScore.c_str();
	 theRecords.playerSeven[1] = tempPlayaSevenScore.c_str();
	 theRecords.playerEight[1] = tempPlayaEightScore.c_str();
	 theRecords.playerNine[1] = tempPlayaNineScore.c_str();
	 theRecords.playerTen[1] = tempPlayaTenScore.c_str();

   fin.close();	//Closes the file stream
}