//============================================================================
// Name        : IntentRecognizer.cpp
// Author      : 
// Version     :
// Description : This is to find user intent
//============================================================================
#include"../include/IntentRecognizer.h"

//============================================================================
// Method Name : IntentRecognizer
// Description : constructor
//============================================================================
IntentRecognizer::IntentRecognizer()
{
	userdata = "";
	userDataParser = new CUserDataParser();
	ask = CUserDataParser::noAsk;
    weather = CUserDataParser::noweatherinfo;
    city = CUserDataParser::nocityinfo;
    factFound = CUserDataParser::nofactinfo;
}
//============================================================================
// Method Name : ~IntentRecognizer
// Description : destructor
//============================================================================
IntentRecognizer::~IntentRecognizer()
{
	delete userDataParser;
}

//============================================================================
// Method Name : getUserData
// Description : To read user request/commands
//============================================================================
void IntentRecognizer::getUserData()
{
	std::cout << "Please type what is in your mind or (type cancel to exit)" << std::endl;
	getline(std::cin, userdata);
}

//============================================================================
// Method Name : setUserData
// Description : To set user data
//============================================================================
void IntentRecognizer::setUserData(std::string data)
{
	userdata = data;
}

//============================================================================
// Method Name : addIntent
// Description : To add new user intent into map
//============================================================================
void IntentRecognizer::addIntent(std::string key, std::string val)
{
	m.insert(std::pair<std::string, std::string>(key, val));
}

//============================================================================
// Method Name : findIntent
// Description : To find the intent using data parser class
//============================================================================
std::string IntentRecognizer::findIntent()
{
    std::string word;
    std::vector<std::string> StrArray;
	std::string Intent = "";
    //find in Map
	if(m.find(userdata)!=m.end())
	{      
		Intent = m[userdata];
		std::cout << "Intent Found In Map" << std::endl;	  
	}
	else if(userdata == "cancel") // to handle cancel command
	{
		Intent = "cancel";
	}
	else // If exact mapping not found do string parser
	{		
		std::stringstream parseStr(userdata);
	    while (parseStr >> word) // parse all data and push into vector of string
	    {	        
	    	StrArray.push_back(word);
	    }
		//Parse StrArray for user command like set or get
	    userDataParser = new CUserCommand();
	    userDataParser->parseUserData(StrArray);
	    ask = userDataParser->getUserCommand();
	    delete userDataParser;
		//Parse StrArray for weather related info
	    userDataParser = new CWeatherInfo();
		userDataParser->parseUserData(StrArray);
		weather = userDataParser->getWeatherInfo();
		delete userDataParser;
		//Parse StrArray for city related info
		userDataParser = new CCityInfo();
		userDataParser->parseUserData(StrArray);
		city = userDataParser->getCityInfo();
		delete userDataParser;
		//Parse StrArray for fact related info
		userDataParser = new CFactInfo();
		userDataParser->parseUserData(StrArray);
		factFound = userDataParser->getFactInfo();
		delete userDataParser;
		//check for user command and weather related data
        if((ask == CUserDataParser::get) && (weather == CUserDataParser::weatherinfo))
        {
			if(city == CUserDataParser::cityinfo) // check for city info
			{				
				Intent = m["What is the weather like in Paris today?"];
			}
			else
			{			
				Intent = m["What is the weather like today?"];
			}
		}
		else if(factFound == CUserDataParser::factinfo)// check for fact info
		{			
			Intent = m["Tell me an interesting fact"];
		}        
        else
        {            
			Intent = "No Intent Found";
        }
	}
	return Intent;
}
