#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int Arrowindex = 0;
bool menu = true;
bool classMenu = false;

string name;

//actual game shit from here on
//classes the player can choose from
int Warrior[4] = {100, 10, 3, 15};
int Wizard[4] = {80, 3, 16, 32};
int Rogue[4];

//level experience and shit
int ChEXP = 0;
int ChLVL = 0;

void interaction(const string MenuOptions[], int size);
void display(const string MenuOptions[], int size);
void MenuDisplay(string SelectedOption);
void NameDisplay(string SelectedOption);
void transitionToGame();
void transitionToContinue();
void transitionToOptions();
void transitionToExit();
void gameStartCheck();
void gameStart();
void gameIntro();
int randomNumberGenerator(int limit);

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
	if(menu == false)
	cout<<"\n\n\nHP: Represents your total health points.\nSTR: Determines the amount of physical damage your deal.\nMG: Determines the amount of magic damage you deal. \nAGI: Determines the odds of you getting hit by enemy attacks."<<endl;
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
    if(menu == true){
    	cout<<"Welcome to <PLACEHOLDER>."<<endl;
	}
    else
    cout<<"Choose your Class:"<<endl;
    for (int i = 0; i < size; i++) {
        if (i == Arrowindex) {
        	if(menu == true)
            cout << highlight << Options[i] << endl;
            if(classMenu == true && menu == false) {
            	if(Options[i] == "Knight") {
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
    string MenuOptions[] = { "Start Game", "Continue", "Options", "Exit" };
    int size = sizeof(MenuOptions) / sizeof(MenuOptions[0]);
    display(MenuOptions, size);
}


void transitionToGame() {
	menu = false;
	classMenu = true;
	const string ClassOptions[] = { "Knight", "Wizard", "Rogue"};
	int size = sizeof(ClassOptions)/sizeof(ClassOptions[0]);
	cout<<"Choose your class: "<<endl;
	display(ClassOptions, size);
}


void MenuDisplay(string SelectedOption) {
	if(SelectedOption == "Start Game")
            transitionToGame();
        else if(SelectedOption == "Continue")
        	transitionToContinue();
        else if(SelectedOption == "Options")
            transitionToOptions();
        else if(SelectedOption == "Exit")
            transitionToExit();
}


void NameDisplay(string SelectedOption) {
	cout<<"\nEnter Your Name: ";
	getline(cin, name);
	cout<<"Your "<<SelectedOption<<" has been named: "<< name <<"."<<endl;
	cout<<"Press the SPACEBAR to Start the Game:"<<endl;
	gameStartCheck();
}

void gameStartCheck() {
	if(getch() == SPACEBAR)
	gameStart();
	else{
		cout<<"Oops... Try Again."<<endl;
		gameStartCheck();
	}
		
}

void gameStart() {
	gameIntro();
}

void gameIntro() {
	
	system("cls");
	int introSceneNumber = randomNumberGenerator(5);
	
	if(introSceneNumber == 1){
		cout<<"The first thing you notice is the smell: damp earth, rotting wood, and the faint metallic tang of blood. As your eyes adjust to the gloom,"<<endl;
		cout<<"you realize you're in a dungeon-a vast network of stone corridors that twist and coil like a serpent. Chains hang form the walls,"<<endl;
		cout<<"their clinking whispers carried on a faint, icy draft. You search your thoughts for answers, for a memory-any memory-but there is nothing.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"Who are you? How did you get here? All you know is the weight of the silence and the sense that you are being watched.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"The distant roar of something massive shakes the ground beneath you. Goblin chatter echoes through the halls, and stone gargoyles glare down from crumbling arches"<<endl;
		cout<<"as if daring you to take another step. Somewhere far above, a faint silver of light offers hope. But between you and freedom lies a gauntlet of horrors:"<<endl;
		cout<<"bandits thirsty for blood, a hydra lurking in the shadows, a dragon's infernal roar.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"And at the end of it all, a presence stirs. A darkness that waits for you."<<endl;
	}
	
	 else if(introSceneNumber == 2) {
		cout<<"You awaken in darkness. The air is damp, the stone beneath you cold and unforgiving. Shadows dance across the jagged walls, their flickering shapes cast by distant"<<endl;
		cout<<"torches that seem too faint to reach you. Your head pounds, and your mind is an empty void-no name, no past, no purpose. Only questions echo within your thoughts,"<<endl;
		cout<<"as hollow as the vast, oppressive silence surrounds you.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"In the distance, you hear it: the faint clatter of steel, the guttural growl of unseen beasts. Something stirs within the dark-something ancient, hungry, and watchful."<<endl;
		cout<<"This place is no sanctuary. It is a prison, a labyrinth of malice and death. If you wish to survive, you must move, fight, and carve your path out of this forsaken tomb.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"But deep within, a voice lingers, mocking and cold: You will never leave."<<endl;
	}
	
	 else if(introSceneNumber == 3) {
		cout<<"You awaken to the sound of dripping water, each drop like a hammar to you skull. Your body aches as though you've been battered for days, but no wounds mark your skin."<<endl;
		cout<<"You try to remember how you got here, but your mind is a fog-thick and impenetrable.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"The dungeon around you seems alive, its walls lined with grotesque carvings of fanged beasts and winged devils. The air is thick with a heavy tension, each breath a struggle"<<endl;
		cout<<"against the oppressive weight of the unknown. In the distance, faint sounds ripple through the stillness-footsteps, snarls, the scrape of steel against stone.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"Instinct whisper that this is no ordinary dungeon. This is a crucible, designed to test and destroy. Goblins skulk in the shadows, gargoyles watch with lifeless eyes,"<<endl;
		cout<<"and deeper still, beasts of legend wait, coiled in throne of darkness, where a vampire lord reigns, his laughter echoing through the void.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"You have no choice. The only path is forward, through fire and blood, through terror and death. Will you escape this nightmare, or will the dungeon claim you as its own?"<<endl;
	}
	
	 else if(introSceneNumber == 4) {
		cout<<"You open your eyes to suffocating darkness, the faint glow of a distant torch barely illuminating the oppressive stone walls that surround you."<<endl;
		cout<<"The air is thick with damp and decay, each breath filling your lungs with the stench of rot. Chains dangle from the walls, rusted but still strong,"<<endl;
		cout<<"whispering of those who came before you and never left.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"Your head is empty, save for the throbbing ache that clouds your thoughts. Who you were, why you are here-these questions are lost to the void of your"<<endl;
		cout<<"shattered memory. All you know is the chill that creeps up your spine and the sound of something stirring in the distance.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"This place is alive with malevolence. Goblins scurry in the shadows, their wicked grins barely visible in the faint light. Stone gargoyles perch overhead,"<<endl;
		cout<<"their lifeless eyes following your every move. As you rise, the faint echo of a beast's roar rumbles through the halls, promising pain and fire.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"At the dungeons's heart, a darkness waits, ancient and cruel. Its voice scrates at the edges of your mind, mocking your resolve. It knows"<<endl;
		cout<<"you will come, and it hungers for your failure."<<endl;
	}
	
	else if(introSceneNumber == 5) {
		cout<<"When you awaken, the first sensation is the chill-sharp and relentless, it seeps into your bones. The ground beneath you is slick with moisture, the walls"<<endl;
		cout<<"around you carved from unyielding stone, etched with runes that pulse faintly in the dark. You are alone, yet you feel eyes upon you, hidden in the shadows.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"The questions come quickly, but answers do not follow. Your name, your purpose, your past-everything is gone, leaving only an emptiness as cold as the dungeon itself."<<endl;
		cout<<"In its place, a single certainty arises: this place is a crucible, and you are next to be tested.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"The silence is broken by guttural snarls and cruel laughter, the unmistakable sound of goblins plotting in the darkness. Further down the labyrinth,"<<endl;
		cout<<"the stone trembles under the weight of something immense, a beast whose hunger echoes in every corner. And deeper still, beyond the halls of bandits and petrifying"<<endl;
		cout<<"gaze of gargoyles, lies a throne of ruin where a lord of night waits to drink your life away.";
		getch();
		cout<<""<<endl<<endl;
		cout<<"Your only weapon is your will. The dungeon is merciless, but you are here for a reason. Perhaps, by escaping this nightmare,"<<endl;
		cout<<"you will discover the truth of who you are-or perish in the attempt."<<endl;
	}
}

int randomNumberGenerator(int limit) {
	int min = 1;
	int max = limit;
	srand(time(NULL));
	int random_number = rand() % (max - min +1) + min;
	return random_number;
}
