#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int Arrowindex = 0;

void interaction(const string MenuOptions[], int size, const string highlight);
void display(const string MenuOptions[], int size, const string highlight);

void transitionToGame() {
    system("cls");
    cout << "You chose to start the game.";
}

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

void interaction(const string MenuOptions[], int size, const string highlight) {
    int input = _getch();
    const string SelectedOption = MenuOptions[Arrowindex];
    if(input == SPACEBAR){
        if(SelectedOption == "START GAME")
            transitionToGame();
        else if(SelectedOption == "CONTINUE")
        	transitionToContinue();
        else if(SelectedOption == "OPTIONS")
            transitionToOptions();
        else if(SelectedOption == "EXIT")
            transitionToExit();
    }
    else if (input == W && Arrowindex > 0){
        Arrowindex--;
        display(MenuOptions, size, highlight);
    }
    else if (input == S && Arrowindex < size - 1){
        Arrowindex++;
        display(MenuOptions, size, highlight);
    }
    else
        display(MenuOptions, size, highlight);
}

void display(const string MenuOptions[], int size, const string highlight) {
    system("cls");
    for(int i=1; i<=45; i++)
        cout<<" ";
    cout << "WELCOME TO DnD ADVENTURE!" << endl;
    cout << "An immersive dungeons and dragons role-playing game made by Shahab Burhan, Suhaib Asim, and Ayan Gandu.\n\n\n" << endl;
    
    for (int i = 0; i < size; i++) {
        if (i == Arrowindex) {
            cout << highlight << MenuOptions[i] << endl;
        } else {
            cout << "    " << MenuOptions[i] << endl;
        }
    }
    interaction(MenuOptions, size, highlight);
}

int main() {
    string MenuOptions[] = { "START GAME", "CONTINUE", "OPTIONS", "EXIT" };
    const string highlight = " -> ";
    int size = sizeof(MenuOptions) / sizeof(MenuOptions[0]);
    display(MenuOptions, size, highlight);
    return 0;
}
