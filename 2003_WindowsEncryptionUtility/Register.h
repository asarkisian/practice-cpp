#if !defined REGISTER_H
#define REGISTER_H

#include <fstream>
#include "Main.h"

using namespace std;
extern TfrmMain *frmMain;

class registerSoftware{
	public:
		registerSoftware(): RegisteredSoftware(0) {}

		void inputRegister();
		void outputRegister();
		void registerComplete();
		void registerIncomplete();
		bool validateRegistration()const;

	private:
		bool RegisteredSoftware;
};

#endif 
