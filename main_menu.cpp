#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int Arrowindex = 0;
bool menu = true;

string name;
//classes initial stats
int Warrior[4] = {100, 10, 3, 15};
int Wizard[4] = {80, 3, 16, 32};
int Rogue[4];

void interaction(const string MenuOptions[], int size);
void display(const string MenuOptions[], int size);
void MenuDisplay(string SelectedOption);
void NameDisplay(string SelectedOption);

void transitionToGame();

void transitionToContinue() {
	system("cls");
	cout<<"You chose to continue the game.";
}

void transitionToOptions() {
    system("cls");
    cout << "You chose to go to options.";
}

void transitionToExit() {
    system("cls");
    cout << "Goodbye.";
}

void interaction(const string Options[], int size) {
    int input = _getch();
    const string SelectedOption = Options[Arrowindex];
    if(input == SPACEBAR){
    	if(menu == true)
    	MenuDisplay(SelectedOption);
    	else
    	NameDisplay(SelectedOption);
    }
    else if (input == W && Arrowindex > 0){
        Arrowindex--;
        display(Options, size);
    }
    else if (input == S && Arrowindex < size - 1){
        Arrowindex++;
        display(Options, size);
    }
    else
        display(Options, size);
}

void display(const string Options[], int size) {
	const string highlight = " -> ";
    system("cls");
    if(menu == true)
    cout<<"Welcome to DND."<<endl;
    else
    cout<<"Choose your Class."<<endl;
    for (int i = 0; i < size; i++) {
        if (i == Arrowindex) {
        	if(menu == true)
            cout << highlight << Options[i] << endl;
            else {
            	if(Options[i] == "Warrior") {
            		cout<< highlight << Options[i] << "\t [HP: 100, STR: 10, MG: 3, AGI: 15]"<<endl;
				} else if (Options[i] == "Wizard") {
					cout<< highlight << Options[i] << "\t [HP: 80, STR: 3, MG: 16, AGI: 32]"<<endl;
				} else if (Options[i] == "Rogue") {
					cout<< highlight << Options[i] << "\t Haven't decided yet"<<endl;
				}
			}
            
        } else {
            cout << "    " << Options[i] << endl;
        }
    }
    interaction(Options, size);
}

int main() {
    string MenuOptions[] = { "START GAME", "CONTINUE", "OPTIONS", "EXIT" };
    int size = sizeof(MenuOptions) / sizeof(MenuOptions[0]);
    display(MenuOptions, size);
    return 0;
}


void transitionToGame() {
	menu = false;
	const string ClassOptions[] = { "Warrior", "Wizard", "Rogue" };
	int size = sizeof(ClassOptions)/sizeof(ClassOptions[0]);
	cout<<"Choose your class: "<<endl;
	display(ClassOptions, size);
}

void MenuDisplay(string SelectedOption) {
	if(SelectedOption == "START GAME")
            transitionToGame();
        else if(SelectedOption == "CONTINUE")
        	transitionToContinue();
        else if(SelectedOption == "OPTIONS")
            transitionToOptions();
        else if(SelectedOption == "EXIT")
            transitionToExit();
}

void NameDisplay(string SelectedOption) {
	cout<<"Enter Your Name: ";
	cin>>name;
	cout<<"Your "<<SelectedOption<<" has been named: "<< name;
	cout<<"Goodbye."
}



