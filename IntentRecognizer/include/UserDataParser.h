//============================================================================
// Name        : UserDataParser.h
// Author      : 
// Version     :
// Description : This is supportive class to parse user data
//============================================================================

#ifndef USERDATAPARSER_H_
#define USERDATAPARSER_H_

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

//Base class for user data parser
class CUserDataParser
{
private:
	std::vector<std::string> userRequest;
public:
	enum UserAsk { noAsk, get, set, open, close };
	enum WatherInfo { noweatherinfo, weatherinfo };
	enum CityInfo { nocityinfo, cityinfo };
	enum FactInfo { nofactinfo, factinfo };
	int findStr(std::vector<std::string> vec, std::string searchWord);
	virtual void parseUserData(std::vector<std::string> userData);
	virtual int getUserCommand();
	virtual int getWeatherInfo();	
	virtual int getCityInfo();
	virtual int getFactInfo();
};

//Derived class to parse user request/command type - set or get
class CUserCommand:public CUserDataParser
{	
private:
	UserAsk userReq;
	//std::vector<std::string> userComand;
public:
	CUserCommand();
	void parseUserData(std::vector<std::string> userData);
	int getUserCommand();
};

//Derived class to parse weather information
class CWeatherInfo:public CUserDataParser
{
private:
	WatherInfo userweatherReq;
public:
	void parseUserData(std::vector<std::string> userData);
	int getWeatherInfo();
};

//Derived class to parse city information
class CCityInfo:public CUserDataParser
{
private:
	CityInfo usercityReq;
public:
	void parseUserData(std::vector<std::string> userData);
	int getCityInfo();
};

//Derived class to parse fact information
class CFactInfo:public CUserDataParser
{
private:
	FactInfo userFactReq;
public:
	void parseUserData(std::vector<std::string> userData);
	int getFactInfo();
};

#endif /* USERDATAPARSER_H_ */
