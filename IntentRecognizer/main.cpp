//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Description : Intent Recognizer main file
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include"include/IntentRecognizer.h"

int main() {
	
	std::string intent = "";
	IntentRecognizer *IntentRecnizer = new IntentRecognizer();
	//Add the all intent with IntentRecognizer class
	IntentRecnizer->addIntent("What is the weather like today?","Get Weather");
	IntentRecnizer->addIntent("What is the weather like in Paris today?","Get Weather City");
	IntentRecnizer->addIntent("Tell me an interesting fact","Get Fact");
	
	while(true)
	{
		IntentRecnizer->getUserData(); // get data from user
		intent = IntentRecnizer->findIntent(); // find the intent from user data
		std::cout<<"=> Intent: "<<intent<<std::endl;
		if(intent == "cancel") // added for user cancellation
			break;
	}	
	delete IntentRecnizer;
	return 0;
}
