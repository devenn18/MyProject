//============================================================================
// Name        : UserDataParser.cpp
// Author      : 
// Version     :
// Description : This is supportive class to parse user data
//============================================================================
#include"../include/UserDataParser.h"

//============================================================================
// Method Name : CUserDataParser::findStr
// Description : To find string in given vector
//============================================================================
int CUserDataParser::findStr(std::vector<std::string> vec, std::string searchWord)
{
    int found = 0;
	if ( std::find(vec.begin(), vec.end(), searchWord) != vec.end() )
	{
	   found = 1;
	}
	return found;
}
//below all are interfaces (virtual functions)
void CUserDataParser::parseUserData(std::vector<std::string> userData){}
int CUserDataParser::getUserCommand(){}
int CUserDataParser::getWeatherInfo(){}
int CUserDataParser::getCityInfo(){}
int CUserDataParser::getFactInfo(){}
//end


//Start CUserCommand
//============================================================================
// Method Name : CUserCommand::CUserCommand
// Description : constructor
//============================================================================
CUserCommand::CUserCommand()
{
	userReq = noAsk;
}
//============================================================================
// Method Name : CUserDataParser::findStr
// Description : To parse user request/command data like set, get, open, close
//============================================================================
void CUserCommand::parseUserData(std::vector<std::string> userData)
{
	if(findStr(userData, "what") || findStr(userData, "whats") || findStr(userData, "What") || findStr(userData, "Whats")
		|| findStr(userData, "How") || findStr(userData, "how") || findStr(userData, "Hows") || findStr(userData, "hows") 
			|| findStr(userData, "Get") ||findStr(userData, "get") || findStr(userData, "Tell") ||findStr(userData, "tell"))
	{
		userReq = get;
	}
	else if(findStr(userData, "Set") ||findStr(userData, "set"))
	{
		userReq = set;
	}
	else if(findStr(userData, "open") ||findStr(userData, "Open"))
	{
		userReq = open;
	}
	else if(findStr(userData, "close") ||findStr(userData, "Close"))
	{
		userReq = close;
	}
	else
	{
		userReq = noAsk;
	}
}
//============================================================================
// Method Name : CUserCommand::getUserCommand
// Description : To get user command/request data from user
//============================================================================
int CUserCommand::getUserCommand()
{
	return userReq;
}
// end CUserCommand
//start CWeatherInfo
//============================================================================
// Method Name : CWeatherInfo::parseUserData
// Description : To parse weather related user data
//============================================================================
void CWeatherInfo::parseUserData(std::vector<std::string> userData)
{
    if(findStr(userData, "weather") ||findStr(userData, "temperature") || findStr(userData, "climate")
    		||findStr(userData, "Weather") || findStr(userData, "Temperature") ||findStr(userData, "Climate"))
    {
    	userweatherReq = weatherinfo;
    }
    else
    {
    	userweatherReq = noweatherinfo;
    }
}
//============================================================================
// Method Name : CWeatherInfo::getWeatherInfo
// Description : To get weather related info in user data
//============================================================================
int CWeatherInfo::getWeatherInfo()
{
	return userweatherReq;
}

//============================================================================
// Method Name : CCityInfo::parseUserData
// Description : To parse city related data
//============================================================================
void CCityInfo::parseUserData(std::vector<std::string> userData)
{
    if(findStr(userData, "in") || findStr(userData, "In"))
    {
    	usercityReq = cityinfo;
    }
    else
    {
    	usercityReq = nocityinfo;
    }
}
//============================================================================
// Method Name : CCityInfo::getCityInfo
// Description : To get city related info in user data
//============================================================================
int CCityInfo::getCityInfo()
{
	return usercityReq;
}
//end CWeatherInfo

//start CFactInfo
//============================================================================
// Method Name : CFactInfo::parseUserData
// Description : To parse fact related data
//============================================================================
void CFactInfo::parseUserData(std::vector<std::string> userData)
{
    if(findStr(userData, "Fact") || findStr(userData, "fact"))
    {
    	userFactReq = factinfo;
    }
    else
    {
    	userFactReq = nofactinfo;
    }
}
//============================================================================
// Method Name : CFactInfo::getFactInfo
// Description : To get fact related info in user data
//============================================================================
int CFactInfo::getFactInfo()
{
	return userFactReq;
}
//end CFactInfo
