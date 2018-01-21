#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

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

bool intro() {
	cout << "Welcome to the Hackertron 9001, where you must combine your technical prowess and your spy-ness expertise." << endl;
	cout << "Your mission, should you choose to accept it, will be to destory Dr. Doom's base in Antarctica" << endl;

	char validInputs[2] = {'y', 'n'};
	char input = getValidInput("Do you accept this mission (press 'y' for yes, 'n' for no)? ", validInputs);

	switch (input) {
	case 'y':
		return true;
	case 'n':
		return false;
	}

	return false;
}

string getTransportation() {
	cout << "Your first task on this mission is simple. Choosing a mode of transportation." << endl;

	char validInputs[4] = {'p', 'h', 'f', 'd'};
	char input = getValidInput("Will you take the Porsche, a helicopter, a F-52, or an old dinghy from the storeroom \n(press 'p' for Porsche, 'h' for helicopter, 'f' for F-52, or 'd' for dinghy)? ", validInputs);

	switch (input) {
	case 'p':
		return "Porsche";
	case 'h':
		return "helicopter";
	case 'f':
		return "F-52";
	case 'd':
		return "old dinghy";
	}

	return "Fiat";
}

char getFirstAction(string vehicle) {
	cout << "You and your trusty " << vehicle << " have made it safely to Antarctica. What do you do now?" << endl;

	char validInputs[2] = {'h', 'b'};
	return getValidInput("Press 'h' to hack the mainframe, or press 'b' to blow that sucker sky high: ", validInputs);
}

string getSecondAction() {
	char validInputs[3] = {'f', 'l', 'b'};
	char input = getValidInput("It's time to use the SDI bus to inject I2C streams into the firewall. Do you use a (f)lash drive, a (l)aptop, or a (b)rick...I mean Nokia? ", validInputs);

	switch (input) {
	case 'f':
		return "flash drive";
	case 'l':
		return "laptop";
	case 'b':
		return "Nokia";
	}

	return "Thermonuclear explosion";
}

int main() {
	bool accepted = intro();

	if (accepted) {
		cout << "Good choice, Agent 42" << endl;

		string vehicle = getTransportation();
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
		string a2;
		string exp;
		switch (a1) {
		case 'h':
			cout << "Good choice. I appreciate your dedication to remaining undetected." << endl;
			a2 = getSecondAction();
			cout << "You use your trusty " << a2 << " to take out their cyberdefenses.\n" << endl;
			cout << "Are you ready to hack the mainframe? Get your fingers rrrrrrready!!!!!!!!!!!" << endl;
			cout << "ENTER YOUR EXPLOIT: ";
			cin >> exp;
			cout << "Your exploit was successful, and the base has been destroyed! Good work agent 42." << endl;
			return 0;
		case 'b':
			char validInputs[2] = {'y', 'n'};
			char confirm = getValidInput("Interesting choice, but still effective. Are you sure (enter y or n)?", validInputs);
			if (confirm == 'y') {
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