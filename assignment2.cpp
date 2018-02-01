/*********************************************************************
** Program Filename: assignment2.cpp
** Author: Alexander Nead-Work
** Date: 01/18/2018
** Description: Solution file for CS161 Assignment 2
** Input: Various chars to determine which path to take
** Output: A story
*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;


/*********************************************************************
** Function: getValidInput
** Description: Gets a valid input from the user
** Parameters: question=prompt to user, validInputs[]=valid chars that can be received
** Pre-Conditions: None
** Post-Conditions: Returns the user's input
*********************************************************************/
char getValidInput(string question, char validInputs[]) {
	char input = 'b';

	while (true) {
		cout << question;
		cin >> input;

		for (unsigned int i = 0; i < sizeof(validInputs); i++) {
			if (input == validInputs[i]) {
				return input;
			}
		}

		cout << "Invalid input received. Please answer again." << endl;
	}
}


/*********************************************************************
** Function: intro
** Description: Sets the stage for the story
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Returns a bool for if the user wishes to continue
*********************************************************************/
bool intro() {
	cout << "Welcome to the Hackertron 9001, where you must combine your technical prowess and your spy-ness expertise." << endl;
	cout << "Your mission, should you choose to accept it, will be to destory Dr. Doom's base in Antarctica" << endl;

	char validInputs[2] = {'1', '2'};
	char input = getValidInput("Do you accept this mission (press '1' for yes, '2' for no)? ", validInputs);

	switch (input) {
	case '1':
		return true;
	case '2':
		return false;
	}

	return false;
}


/*********************************************************************
** Function: getTransportation
** Description: Gets a valid input from the user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Returns a string for the vehicle the user wishes to use
*********************************************************************/
string getTransportation() {
	cout << "Your first task on this mission is simple. Choosing a mode of transportation." << endl;

	char validInputs[4] = {'1', '2', '3', '4'};
	char input = getValidInput("Will you take the Porsche, a helicopter, a F-52, or an old dinghy from the storeroom \n(press '1' for Porsche, '2' for helicopter, '3' for F-52, or '4' for dinghy)? ", validInputs);

	switch (input) {
	case '1':
		return "Porsche";
	case '2':
		return "helicopter";
	case '3':
		return "F-52";
	case '4':
		return "old dinghy";
	}

	return "Fiat";
}


/*********************************************************************
** Function: getFirstAction
** Description: Gets a valid input from the user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Returns a bool for if the user wishes to continue
*********************************************************************/
char getFirstAction(string vehicle) {
	cout << "You and your trusty " << vehicle << " have made it safely to Antarctica. What do you do now?" << endl;

	char validInputs[2] = {'1', '2'};
	return getValidInput("Press '1' to hack the mainframe, or press '2' to blow that sucker sky high: ", validInputs);
}


/*********************************************************************
** Function: getSecondAction
** Description: Gets a valid input from the user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Returns a bool for if the user wishes to continue
*********************************************************************/
string getSecondAction() {
	char validInputs[3] = {'1', '2', '3'};
	char input = getValidInput("It's time to use the SDI bus to inject I2C streams into the firewall. Do you use a flash drive (1), a laptop (2), or a brick...I mean Nokia (3)? ", validInputs);

	switch (input) {
	case '1':
		return "flash drive";
	case '2':
		return "laptop";
	case '3':
		return "Nokia";
	}

	return "Thermonuclear explosion";
}


int main() {
	bool accepted = intro();
	cout << endl;

	if (accepted) {
		cout << "Good choice, Agent 42" << endl;

		string vehicle = getTransportation();
		cout << endl;
		if (vehicle == "Porsche" || vehicle == "Fiat") { //shouldn't be possible to get Fiat but meh
			cout << "You fool! How do you drive a Porsche...to ANTARCTICA!? You aren't the spy I once knew... Go home. We are done here." << endl;
			return 0;
		}
		if (vehicle == "old dinghy") {
			srand(time(NULL));
			int coinFlip = rand() % 2;
			if (coinFlip == 0) {
				cout << "Unfortunately, your dinghy has sprung a leak and is going to sink. RIP." << endl;
				return 0;
			}
		}
		char a1 = getFirstAction(vehicle);
		cout << endl;
		string a2;
		string exp;
		switch (a1) {
		case '1':
			cout << "Good choice. I appreciate your dedication to remaining undetected." << endl;
			a2 = getSecondAction();
			cout << endl;
			cout << "You use your trusty " << a2 << " to take out their cyberdefenses." << endl;
			cout << "Are you ready to hack the mainframe? Get your fingers rrrrrrready!!!!!!!!!!!" << endl;
			cout << "ENTER YOUR EXPLOIT: ";
			cin >> exp;
			cout << endl;
			cout << "Your exploit was successful, and the base has been destroyed! Good work agent 42." << endl;
			return 0;
		case '2':
			char validInputs[2] = {'1', '2'};
			char confirm = getValidInput("Interesting choice, but still effective. Are you sure (enter 1 for yes, 2 for no)? ", validInputs);
			cout << endl;
			if (confirm == '1') {
				cout << "You have successfully destroyed the Antarctican base. Mission completed." << endl;
				return 0;
			} else {
				cout << "A good spy must never waver on their choices. You must own up to them. You're done here." << endl;
				return 0;
			}
		}
	} else {
		cout << "What a shame... Toodeloo!" << endl;
		return 0;
	}
}