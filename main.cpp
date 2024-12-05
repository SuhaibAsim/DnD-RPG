#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int arrowIndex = 0;
bool menu = true;
bool classMenu = false;
bool combatMenu = false;

string name;
string monster;

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
int ChEXP = 0;
int ChLVL = 0;
int ChHP;
int ChSTR;
int ChMG;
int ChAGI;

//monster stats
int monsterHP;
int monsterSTR;
int monsterXP;

int dynamicChHP; //HP changes when user takes damage.
int dynamicMonsterHP;
string ChCLASS;


void interaction(const string menuOptions[], int size);
void display(const string menuOptions[], int size);
void menuDisplay(string selectedOption);
void nameDisplay(string selectedOption);
void transitionToGame();
void transitionToContinue();
void transitionToOptions();
void transitionToExit();
void gameStartCheck();
void gameStart();
void gameIntro();
void gameLoop();
void combatDisplay();
void ChstatsDetermine();
string monsterDetermine();
void monsterStatsDetermine();
void monsterStatsDisplay();
int randomNumberGenerator(int limit);

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


void interaction(const string options[], int size) {
	int input = _getch();
    const string selectedOption = options[arrowIndex];
    if(input == SPACEBAR){
    	if(menu == true)
    	menuDisplay(selectedOption);
    	else if(classMenu == true && menu == false && combatMenu == false){
    		ChCLASS = selectedOption;
    		nameDisplay(ChCLASS);
		}
    }
    else if (input == W && arrowIndex > 0){
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


void display(const string options[], int size) {
	const string highlight = " -> ";
    if(menu == true && classMenu == false && combatMenu == false)
    	cout<<"Welcome to <PLACEHOLDER>."<<endl;
    else if(classMenu == true && menu == false && combatMenu == false)
    cout<<"Choose your Class:"<<endl;
    else if(combatMenu == true && menu == false && classMenu == false) {
    	combatDisplay();
    	cout<<"What will you do: "<<endl;
	}
    for (int i = 0; i < size; i++) {
        if (i == arrowIndex) {
        	if(menu == true)
            cout << highlight << options[i] << endl;
            if(classMenu == true && menu == false && combatMenu == false) {
            	if(options[i] == "Knight") {
            		cout<< highlight << options[i] << "\t [HP: 100, STR: 10, MG: 3, AGI: 15]"<<endl;
				} else if (options[i] == "Pyromancer") {
					cout<< highlight << options[i] << "\t [HP: 80, STR: 3, MG: 16, AGI: 32]"<<endl;
				} else if (options[i] == "Rogue") {
					cout<< highlight << options[i] << "\t Haven't decided yet"<<endl;
				}
			} else if(combatMenu == true && menu == false && classMenu == false) {
				cout << highlight << options[i] << endl;
			}   
        }
		 else {
            cout << "    " << options[i] << endl;
        }
    }
    if(combatMenu == true && menu == false && classMenu == false)
    monsterStatsDisplay();
    if(classMenu == true || combatMenu == true)
	cout<<"\n\n\nHP[Health Points]: Represents your total health points.\nSTR[Strength]: Determines the amount of physical damage your deal.\nMG[Magic]: Determines the amount of magic damage you deal. \nAGI[Agility]: Determines the odds of you getting hit by enemy attacks."<<endl;
    
    interaction(options, size);
}

void ChstatsDetermine() {
	if(ChCLASS == "Knight"){
		ChHP = Knight[0];
		ChSTR = Knight[1];
		ChMG = Knight[2];
		ChAGI = Knight[3];
	}
	else if(ChCLASS == "Pyromancer"){
		ChHP = Pyromancer[0];
		ChSTR = Pyromancer[1];
		ChMG = Pyromancer[2];
		ChAGI = Pyromancer[3];		
	}
	else
		cout<<"work in progress.";
	
}

void combatDisplay() {
	dynamicChHP= ChHP;
	cout<<"[NAME: "<<ChCLASS<<" "<<name<<"] ";
	cout<<"[HP: "<<dynamicChHP<<"] ";
	cout<<"[STR: "<<ChSTR<<"] ";
	cout<<"[MG: "<<ChMG<<"] ";
	cout<<"[AGI:"<<ChAGI<<"] "<<endl<<endl;
}

void monsterStatsDisplay() {
	dynamicMonsterHP = monsterHP;
	cout<<"\n[MONSTER: "<<monster<<"] ";
	cout<<"[HP: "<<dynamicMonsterHP<<"] ";
	cout<<"[STR: "<<monsterSTR<<"] ";
	cout<<"[EXP: "<<monsterXP<<"] "<<endl<<endl;
}

int main() {
    string menuOptions[] = { "Start Game", "Continue", "Options", "Exit" };
    int size = sizeof(menuOptions) / sizeof(menuOptions[0]);
    display(menuOptions, size);
}


void transitionToGame() {
	menu = false;
	classMenu = true;
	const string classOptions[] = { "Knight", "Pyromancer", "Rogue"};
	int size = sizeof(classOptions)/sizeof(classOptions[0]);
	system("cls");
	display(classOptions, size);
}


void menuDisplay(string selectedOption) {
	if(selectedOption == "Start Game")
            transitionToGame();
        else if(selectedOption == "Continue")
        	transitionToContinue();
        else if(selectedOption == "Options")
            transitionToOptions();
        else if(selectedOption == "Exit")
            transitionToExit();
}


void nameDisplay(string ChCLASS) {
	cout<<"\nEnter Your Name: ";
	getline(cin, name);
	cout<<"Your "<<ChCLASS<<" has been named: "<< name <<"."<<endl;
	cout<<"Press the SPACEBAR to Start the Game:"<<endl;
	gameStartCheck();
}

void gameStartCheck() {
	if(getch() == SPACEBAR){
		system("cls");
		gameStart();
	}
	else{
		cout<<"Oops... Try Again."<<endl;
		gameStartCheck();
	}
		
}

void gameStart() {
	gameIntro();
	gameLoop();
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
	return;
}

void gameLoop(){
	combatMenu = true;
	menu = false;
	classMenu = false;
	const string action[] = {"Attack", "Defend", "Run"};
	int size = sizeof(action)/sizeof(action[0]);
	ChstatsDetermine();
	monsterDetermine();
	monsterStatsDetermine();
	cout<<"\nYou encountered a: "<<monster;
	getch();
	system("cls");
	display(action, size);
}

string monsterDetermine() {
	int monsterNumber = randomNumberGenerator(2);
	switch(monsterNumber){
		case 1:
			monster = "Goblin";
			break;
		case 2:
			monster = "Gargoyle";
			break;
	}
	return monster;
}

void monsterStatsDetermine() {
	if(monster == "Goblin"){
		monsterHP = Goblin[0];
		monsterSTR = Goblin[1];
		monsterXP = Goblin[2];
	} else if(monster == "Gargoyle") {
		monsterHP = Gargoyle[0];
		monsterSTR = Gargoyle[1];
		monsterXP = Gargoyle[2];	
	}
	return;
}

int randomNumberGenerator(int limit) {
	int min = 1;
	int max = limit;
	srand(time(NULL));
	int random_number = rand() % (max - min +1) + min;
	return random_number;
}
