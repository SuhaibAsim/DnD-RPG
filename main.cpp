#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int arrowIndex = 0;

bool mainMenu;
bool classMenu;
bool combatMenu;
bool weaponMenu;

string name;
string monster;
string cAction;
string playerWeapon;
string logArray[100];
int logIndex = 0;
int logCount = 0;

string playerDetails;
string monsterDetails;

//actual game shit from here on
//classes the player can choose from
//[0]HP [1]STR [2]MG [3]AGI
int Knight[4] = {100, 10, 3, 15};
int Pyromancer[4] = {80, 3, 16, 32};
int Rogue[4];

//[0]HP [1]STR [3]XP
int Goblin[] = {20, 5, 5};
int Gargoyle[] = {35, 8, 15};

//character stats and shit
int playerExp = 0;
int playerLevel = 0;
int playerHp;
int dynamicPlayerHp;
int playerPower;
int playerMagic;
int playerAgility;

//monster stats
int monsterHp;
int monsterPower;
int monsterExp;

int dynamicMonsterHp = 0;
string playerClass;
bool playerAction = true;
bool monsterAction = false;
bool monsterAlive = false;
bool playerAlive = true;

void interaction(string menuOptions[], int size);
void display(string menuOptions[], int size);
void menuChoiceDetermine(string selectedOption);
void weaponWindow();
void nameDisplay(string selectedOption);
void transitionToGame();
void transitionToContinue();
void transitionToOptions();
void transitionToExit();
void gameStartplayereck();
void gameStart();
void gameIntro();
void gameLoop();
void playerStatsDisplay();
void combatDisplay();
void monsterDetermine();
void monsterStatsDetermine();
void monsterStatsDisplay();
void playerTurn();
//void monsterTurn();
void combatLoop();
void gameOver();
//void victory();

void classChoiceDetermine(string);
int randomNumberGenerator(int , int);

void weaponDisplay(string weapon, const string highlight);
void weaponChoiceDetermine(string weapon);
void classDisplay(string class_, const string highlight);

//window functions
void menuWindow();
void classWindow();
void weaponWindow();
void combatWindow();
void windowDetermine();

void topWindowDisplay();
void classWindow();
void descriptionDisplay();

void transitionToContinue() {
	system("cls");
	cout<<"This feature is not yet implemented.";
}

void transitionToOptions() {
    system("cls");
    cout << "You chose to go to options.";
}

void transitionToExit() {
    system("cls");
    cout << "Goodbye.";
}

//void playerTurn() {
//	if(playerAction == true && playerAlive == true) {
//		if (cAction == "Attack") {
//        	playerAction = false;
//        	logArray[logIndex] = "> You attack the monster: " + monster + " [-" + to_string(playerPower) + "]";
//        	dynamicMonsterHP -= playerPower;
//        	if (dynamicMonsterHP <= 0)
////            	victory();
//        	logIndex++;
//    }
//    if (cAction == "Defend") {
//        playerAction = false;
//        dynamicplayerHp -= monsterSTR / 2;
//        logArray[logIndex] = "> You defend against the monster: " + monster;
//        logIndex++;
//    }
//    if (cAction == "Run") {
//        playerAction = false;
//        logArray[logIndex] = "> You attempt to run from the monster: " + monster;
//        logIndex++;
//    }
//}
//}
    
//    cAction = "";
//    monsterAction = true;
//    monsterTurn();
//    return;
//}

//void victory() {
//	monsterAlive = false;
//	cAction = "";
//	cout<<"\n\nYou slayed the "<<monster<<endl;
//	monsterDetermine();
//	monsterStatsDetermine();
//	monsterAlive = true;
//	dynamicMonsterHP = monsterHP;
//	for(int i = 0; i < 100; i++ )
//		logArray[i] = "\0";
//	cout<<"You encounter another monster: "<<monster<<endl;
//	getch();
//	system("cls");
//	const string action[] = {"Attack", "Defend", "Run"};
//	int size = sizeof(action)/sizeof(action[0]);
////	display(action, size);
//}

//void monsterTurn() {
//	if(monsterAction == true && playerAction == false && monsterAlive == true && playerAlive == true){
//		dynamicplayerHp -= monsterSTR;
//		if(dynamicplayerHp <= 0)
//		gameOver();
//		logArray[logIndex] = "> The monster: " + monster + " attacked you. [-" + to_string(monsterSTR) + "]";
//		logIndex++;
//	}
//	monsterAction = false;
//	playerAction = true;
//}
//
//void gameOver() {
//	playerAlive = false;
//	system("cls");
//	cout<<"YOU DIED.";
//	exit(0);
//}

//void combatLoop(){
//	playerTurn();
//}

void combatWindow() {
	combatMenu = true;
	mainMenu = false;
	classMenu = false;
	weaponMenu = false;
	
	if(dynamicMonsterHp <= 0)
		monsterDetermine();
	
	playerDetails = "[Class:" + playerClass + "] [HP:" + to_string(dynamicPlayerHp) + "] [POW:" + to_string(playerPower) + "]";
	monsterDetails = "[Monster:" + monster + "] [HP:" + to_string(dynamicMonsterHp) + "] [POW:" + to_string(monsterPower) + "]";
	
	string action[] = {"Attack", "Defend", "Run"};
	int size = sizeof(action)/sizeof(action[0]);
	system("cls");
	display(action, size);
}

void combatChoiceDetermine(string action) {
	if(action == "Attack") {
		
		dynamicMonsterHp = dynamicMonsterHp - playerPower;
	}
	if(dynamicMonsterHp > 0) {
		//monster turn
		dynamicPlayerHp = dynamicPlayerHp - monsterPower;
		}
	combatWindow();	
}

void introWindow() {
	mainMenu = false;
	classMenu = false;
	weaponMenu = false;
	combatMenu = false;
	system("cls");
	int introSceneNumber = randomNumberGenerator(1 , 5);
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
		cout<<"And at the end of it all, a presence stirs. A darkness that waits for you.";
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
		cout<<"But deep within, a voice lingers, mocking and cold: You will never leave.";
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
		cout<<"You have no choice. The only path is forward, through fire and blood, through terror and death. Will you escape this nightmare, or will the dungeon claim you as its own?";
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
		cout<<"you will come, and it hungers for your failure.";
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
		cout<<"you will discover the truth of who you are-or perish in the attempt.";
	}
	getch();
	cout<<""<<endl<<endl;
	cout<<"As you rise and begin to explore, you come across your first foe..."<<endl;
	getch();
	combatWindow();
}

void weaponChoiceDetermine(string weapon) {
	playerWeapon = weapon;
	introWindow();
}

void windowDetermine(string selectedOption) {
    if(mainMenu == true && classMenu == false && weaponMenu == false && combatMenu == false)
    	menuChoiceDetermine(selectedOption);
   	else if(classMenu == true && mainMenu == false && weaponMenu == false && combatMenu == false)
    	classChoiceDetermine(selectedOption);
	else if(weaponMenu == true && mainMenu == false && classMenu == false && combatMenu == false)
		weaponChoiceDetermine(selectedOption);
	else if(combatMenu == true && mainMenu == false && classMenu == false && weaponMenu == false)
		combatChoiceDetermine(selectedOption);
}

void interaction(string options[], int size) {
	int input = _getch();
    string selectedOption = options[arrowIndex];
    
	if(input == SPACEBAR)
	windowDetermine(selectedOption);
	
    if (input == W && arrowIndex > 0){
        arrowIndex--;
        system("cls");
        display(options, size);
    }
    else if (input == S && arrowIndex < size - 1){
        arrowIndex++;
        system("cls");
        display(options, size);
    }
    else {
    	system("cls");
    	display(options, size);
	}
}

void topWindowDisplay() {
	if(combatMenu == true && mainMenu == false && weaponMenu == false && classMenu == false)
		cout<<"What will you Do: "<<endl;
	else if(mainMenu == true && classMenu == false && weaponMenu == false && combatMenu == false)
    	cout<<"Welcome to <PLACEHOLDER>."<<endl;
    else if(classMenu == true && mainMenu == false && weaponMenu == false && combatMenu == false)
    	cout<<"Choose your Class:"<<endl;
    else if(weaponMenu == true && mainMenu == false && classMenu == false && combatMenu == false)
    	cout<<"Select your Weapon: "<<endl;
}

void display(string options[], int size) {
	
	cout<<playerDetails<<endl<<endl;
	topWindowDisplay();

	const string highlight = " -> ";

    for (int i = 0; i < size; i++) {
        if (i == arrowIndex) {
        	string option = options[i];
            if(classMenu == true && mainMenu == false && weaponMenu == false && combatMenu == false)
            	classDisplay(option, highlight); //exceptional case since i want to display stats aswell
            else if(weaponMenu == true && mainMenu == false && classMenu == false && combatMenu == false)
				weaponDisplay(option, highlight);
           	else 
				cout << highlight << option << endl;  
        }
		else
            cout << "    " << options[i] << endl;
}
//    	logCount = 0;
//    	string temp[3];
//		for (int i = 99; i >= 0 && logCount < 3; i--) {
//    		if (!logArray[i].empty()) {
//    			temp[logCount] = logArray[i];
//				logCount++;
//			}
//		}
//		if (logCount > 0) {
//        	for (int i = logCount - 1; i >= 0; i--)
//            	cout << temp[i] << endl;
//    } else 
//        cout << "No logs available." << endl;
//    }
	cout<<endl<<endl<<monsterDetails<<endl;
	descriptionDisplay();
	interaction(options, size);
}


void descriptionDisplay() {
	if(classMenu == true) {
		cout<<"\nStats Description:"<<endl;
	} else if(weaponMenu == true) {
		cout<<"\nWeapon Stats Description:"<<endl;
	}
}

void weaponDisplay(string weapon, const string highlight) {
	cout<< highlight << weapon;
	
	if(playerClass == "Knight"){
		if(weapon == "Battleaxe")
			cout<< "\t [1d8 + POW]"<<endl;
		else if(weapon == "Longbow")
			cout<< "\t [1d5 + POW]"<<endl;
		else
			cout<< "\t [1d13 + POW]"<<endl;
	}
//	else if(playerClass == "Pyromancer") {
//	}	
}

void classDisplay(string class_, const string highlight) {
	if(class_ == "Knight")
   	cout<< highlight << class_ << "\t [HP: 100, STR: 10, MG: 3, AGI: 15]"<<endl;
	else if (class_ == "Pyromancer") 
	cout<< highlight << class_ << "\t [HP: 80, STR: 3, MG: 16, AGI: 32]"<<endl;
	else if (class_ == "Rogue")
	cout<< highlight << class_ << "\t Haven't decided yet"<<endl;
}

int main() {
	menuWindow();
}

void menuWindow() {
	mainMenu = true;
	classMenu = false;
	weaponMenu = false;
	combatMenu = false;
	string menuOptions[] = { "Start Game", "Continue", "Options", "Exit" };
    int size = sizeof(menuOptions) / sizeof(menuOptions[0]);
    system("cls");
    display(menuOptions, size);
}

void classWindow() {
	classMenu = true;
	mainMenu = false;
	weaponMenu = false;
	combatMenu = false;
	string classOptions[] = { "Knight", "Pyromancer", "Rogue"};
	int size = sizeof(classOptions)/sizeof(classOptions[0]);
	system("cls");
	display(classOptions, size);
}

void menuChoiceDetermine(string selectedOption) {
	if(selectedOption == "Start Game")
        classWindow();
    else if(selectedOption == "Continue")
    	transitionToContinue();
    else if(selectedOption == "Options")
        transitionToOptions();
    else if(selectedOption == "Exit")
    	transitionToExit();
}

void classChoiceDetermine(string selectedOption) {
    playerClass = selectedOption;
    
    if (playerClass == "Knight") {
        playerHp = Knight[0];
        playerPower = Knight[1];
        playerMagic = Knight[2];
        playerAgility = Knight[3];
    }
    else if (playerClass == "Pyromancer") {
        playerHp = Pyromancer[0];
        playerPower = Pyromancer[1];
        playerMagic = Pyromancer[2];
        playerAgility = Pyromancer[3];
    }
    else {
        cout << "Work in progress for this class." << endl;
        return;
    }
	dynamicPlayerHp = playerHp;
    weaponWindow();
}

void weaponWindow() {
    weaponMenu = true;
    classMenu = false;
    mainMenu = false;
    combatMenu = false;

    string weaponOptions[3];
    if (playerClass == "Knight") {
        weaponOptions[0] = "Battleaxe";
        weaponOptions[1] = "Longbow";
        weaponOptions[2] = "Zweihander";
    } else if (playerClass == "Pyromancer") {
        weaponOptions[0] = "Fire Staff";
        weaponOptions[1] = "Flame Wand";
        weaponOptions[2] = "Pyromancer's Tome";
    }

    int size = sizeof(weaponOptions) / sizeof(weaponOptions[0]);
    system("cls");
    display(weaponOptions, size);
}

void monsterDetermine() {
	int monsterNumber = randomNumberGenerator(1 , 2);
	switch(monsterNumber) {
		case 1:
			monster = "Goblin";
			break;
		case 2:
			monster = "Gargoyle";
			break;
	}
	monsterStatsDetermine();
}

void monsterStatsDetermine() {
	if(monster == "Goblin"){
		monsterHp = Goblin[0];
		monsterPower = Goblin[1];
		monsterExp = Goblin[2];
	} else if(monster == "Gargoyle") {
		monsterHp = Gargoyle[0];
		monsterPower = Gargoyle[1];
		monsterExp = Gargoyle[2];	
	}
	dynamicMonsterHp = monsterHp;
}

int randomNumberGenerator(int min, int max) {
	srand(time(NULL));
	int random_number = rand() % (max - min +1) + min;
	return random_number;
}
