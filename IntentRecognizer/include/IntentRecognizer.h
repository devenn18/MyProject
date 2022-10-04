//============================================================================
// Name        : IntentRecognizer.h
// Author      : Devendra
// Version     :
// Description : Intent Recognizer Class mainly repsonsible to find the intent
//============================================================================
#if !defined(EA_21FB73B5_D57D_45c4_99CC_C62A5EE1946D__INCLUDED_)
#define EA_21FB73B5_D57D_45c4_99CC_C62A5EE1946D__INCLUDED_

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include "UserDataParser.h"

class IntentRecognizer
{
private:
	std::string userdata;
	std::map<std::string, std::string> m;
	CUserDataParser *userDataParser;
	int ask;
    int weather;
    int city;
    int factFound;
public:
	IntentRecognizer();
	~IntentRecognizer();
	void getUserData();
	void setUserData(std::string data);
	void addIntent(std::string key, std::string val);
	std::string findIntent();
};

#endif // !defined(EA_21FB73B5_D57D_45c4_99CC_C62A5EE1946D__INCLUDED_)
