#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;

enum Key { W = 119, S = 115, SPACEBAR = 32 };

int arrowIndex = 0;

string logArray[100];
int logIndex = 0;
int logCount = 0;

string playerDetails;
int playerHp;
int dynamicPlayerHp;
int playerPower;
string playerWeapon;
int weaponStr[2];
int rollAttack = 0;

int playerPotion = 2;
int playerExp = 0;
int playerLevel = 0;


string monsterDetails;
int monsterHp;
int dynamicMonsterHp = 0;
int monsterStr;
int monsterPower;
int monsterExp;


bool mainMenu;
bool classMenu;
bool combatMenu;
bool weaponMenu;
bool firstSpawn = false;




//[0]HP [1]STR [2]MG [3]AGI
string playerClass;
int Knight[2] = {100, 2};
int Pyromancer[2] = {80, 16};

//[0]HP [1]POW [2]FOR [3]XP
string monster;
int Goblin[] = {20, 3, 5, 5};
int Gargoyle[] = {35, 5, 8, 15};
int ShadowWerewolf[] = {70, 13, 15, 100};
int Hydra[] = {50, 10, 12, 70};
int Firedrake[] = {100, 3, 4, 50};
int UndeadWarrior[] = {50, 7, 10, 20};

void menuWindow();
void classWindow();
void weaponWindow();
void menuChoiceDetermine(string);
void classChoiceDetermine(string);
void monsterDetermine();
void monsterStatsDetermine();
void classDisplay(string, const string);
int randomNumberGenerator(int, int);
void weaponDisplay(string, const string);
void descriptionDisplay();
void logDisplay();
void combatDisplay(string, const string);
void windowDetermine(string);
void interaction(string, int);
void topWindowDisplay();
void display(string[], int);
void weaponChoiceDetermine(string);
void introWindow();
void death();
void combatChoiceDetermine(string);
void combatWindow();
void reward();
void battleEnd();
void rewardFail();
void transitionToContinue();
void transitionToOptions();
void transitionToExit();

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
	string classOptions[] = { "Knight", "Pyromancer"};
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
    }
    else if (playerClass == "Pyromancer") {
        playerHp = Pyromancer[0];
        playerPower = Pyromancer[1];
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
	int monsterNumber;
	if(playerLevel < 2)
		monsterNumber = randomNumberGenerator(1 , 2);
	else
		monsterNumber = randomNumberGenerator(1, 6);
	switch(monsterNumber) {
		case 1:
			monster = "Goblin";
			cout<<"\nA rustling from the bushes stops you in your tracks. A goblin emerges, its red eyes gleaming as it snarls, 'Fresh meat!'."<<endl;
			getch();
			break;
		case 2:
			monster = "Gargoyle";
			cout<<"\nA faint rumble shakes the cathedral. With a thunderous roar, a gargoyle breaks free, stone claws poised to strike."<<endl;
			getch();
			break;
		case 3:
			monster = "Hydra";
			cout<<"\nThe ground trembles as a Hydra emerges from the swamp, its many heads snapping hungrily. Venom drips from its fangs as it roars, ready to strike."<<endl;
			getch();
			break;
		case 4:
			monster = "Shadow Werewolf";
			cout<<"\nA growl cuts through the darkness as red eyes glow. The Shadow Werewolf emerges, claws ready to strike."<<endl;
			getch();
			break;
		case 5:
			monster = "Firedrake";
			cout<<"\nThe air blazes with heat as a FireDrake descends, flames curling around its wings. Its molten eyes lock onto you, and a roar shakes the ground."<<endl;
			getch();
			break;
		default:
			monster = "Undead Warrior";
			cout<<"\nRattling echoes through the air as a warrior inflicted with the undead curse steps forward, sword in hand, its hollow eyes glowing with eerie light."<<endl;
			getch();
			break;
	}
	monsterStatsDetermine();
}

void monsterStatsDetermine() {
	if(monster == "Goblin"){
		monsterHp = Goblin[0];
		monsterStr = Goblin[1];
		monsterPower = Goblin[2];
		monsterExp = Goblin[3];
	} else if(monster == "Gargoyle") {
		monsterHp = Gargoyle[0];
		monsterStr = Gargoyle[1];
		monsterPower = Gargoyle[2];
		monsterExp = Gargoyle[3];	
	} else if(monster == "Shadow Werewolf") {
		monsterHp = ShadowWerewolf[0];
		monsterStr = ShadowWerewolf[1];
		monsterPower = ShadowWerewolf[2];
		monsterExp = ShadowWerewolf[3];	
	} else if(monster == "Hydra") {
		monsterHp = Hydra[0];
		monsterStr = Hydra[1];
		monsterPower = Hydra[2];
		monsterExp = Hydra[3];	
	} else if(monster == "Firedrake") {
		monsterHp = Firedrake[0];
		monsterStr = Firedrake[1];
		monsterPower = Firedrake[2];
		monsterExp = Firedrake[3];	
	} else if(monster == "Undead Warrior") {
		monsterHp = UndeadWarrior[0];
		monsterStr = UndeadWarrior[1];
		monsterPower = UndeadWarrior[2];
		monsterExp = UndeadWarrior[3];		
	}
	dynamicMonsterHp = monsterHp;
}

int randomNumberGenerator(int min, int max) {
	srand(time(NULL));
	int random_number = rand() % (max - min +1) + min;
	return random_number;
}

void classDisplay(string class_, const string highlight) {
	if(class_ == "Knight")
   	cout<< highlight << class_ << "\t [VIG: 100, POW: 2]"<<endl;
	else if (class_ == "Pyromancer") 
	cout<< highlight << class_ << "\t [VIG: 80, MAG: 16]"<<endl;
}

void weaponDisplay(string weapon, const string highlight) {
	cout<< highlight << weapon;
	
	if(playerClass == "Knight"){
		if(weapon == "Battleaxe")
			cout<< "\t [FOR: 1d8]"<<endl;
		else if(weapon == "Longbow")
			cout<< "\t [FOR: 1d5]"<<endl;
		else
			cout<< "\t [FOR: 2d13]"<<endl;
	} else if(playerClass == "Pyromancer") {
		if(weapon == "Fire Staff")
			cout<< "\t [FOR: 2d3]"<<endl;
		else if(weapon == "Flame Wand")
			cout<< "\t [FOR: 1d4]"<<endl;
		else if(weapon == "Pyromancer's Tome")
			cout<< "\t [FOR: 3d2]"<<endl;
	}
}

void descriptionDisplay() {
	string classStatsDes[] = {"CLASS STATS DESCRIPTION:","VIG [Vigour]: Your vitality and endurance. If it drops to zero, your character falls.", "POW [Power]: Your physical strength, used by Knights to boost weapon damage.", "MAG [Magic]: Your magical energy, used by Pyromancers to enhance spell damage."};
	string weaponStatsDes[] = {"WEAPON STATS DESCRIPTION:","FOR [Force]: The strength of your attacks, rolled as dice.", "1d8: Rolls one 8-sided die and takes the result.", "2d6: Rolls two 6-sided dice and sums their results.", "3d12: Rolls three 12-sided dice and totals the results."};
	if(mainMenu == true) {
		cout<<"[W]: Navigate upwards."<<endl;
		cout<<"[S]: Navigate downwards."<<endl;
		cout<<"[SPACEBAR]: Confirm action."<<endl;
		cout<<"\n\n\n[A dungeons and dragons role-playing game made by Shahab Burhan, Suhaib Asim and Ayan Qaiser.]";
	}
	else if(classMenu == true) {
		for(int i=0; i<4; i++)
		cout<<classStatsDes[i]<<endl;
	} else if(weaponMenu == true) {
		for(int i=0; i<5; i++)
			cout<<weaponStatsDes[i]<<endl;
	} else if(combatMenu == true) {
		for(int i=0; i<4; i++)
			cout<<classStatsDes[i]<<endl;
			cout<<"\n\n";
		for(int i=0; i<5; i++)
			cout<<weaponStatsDes[i]<<endl;
	}
}

void logDisplay() {
	if(combatMenu == true && mainMenu == false && classMenu == false && weaponMenu == false) {
		cout<<"\n\n";
		logCount = 0;
    	string temp[3];
		for (int i = 99; i >= 0 && logCount < 3; i--) {
    		if (!logArray[i].empty()) {
    			temp[logCount] = logArray[i];
				logCount++;
			}
		}
		if (logCount > 0) {
        	for (int i = logCount - 1; i >= 0; i--)
            	cout << temp[i] << endl;
    } else 
        cout << "No logs available." << endl;
	}
}

void combatDisplay(string option, const string highlight) {
	if(option == "Attack")
		cout << highlight << option <<"\t [FOR + POW]"<<endl;
	else if(option == "Heal")
	   	cout << highlight << option << "\t [Potions: " << playerPotion << "]" << endl;
	else
		cout<< highlight << option << endl;
}

void windowDetermine(string selectedOption) {
	arrowIndex = 0;
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
	if(combatMenu == true && mainMenu == false && weaponMenu == false && classMenu == false) {
		cout<<playerDetails<<endl<<endl;
		cout<<"What will you Do: "<<endl;
	}
	else if(mainMenu == true && classMenu == false && weaponMenu == false && combatMenu == false)
    	cout<<"NIGHTFALL DUNGEONS."<<endl;
    else if(classMenu == true && mainMenu == false && weaponMenu == false && combatMenu == false)
    	cout<<"Choose your Class:"<<endl;
    else if(weaponMenu == true && mainMenu == false && classMenu == false && combatMenu == false)
    	cout<<"Select your Weapon: "<<endl;
    cout<<"\n";
}

void display(string options[], int size) {
	
	topWindowDisplay();

	const string highlight = " -> ";

    for (int i = 0; i < size; i++) {
        if (i == arrowIndex) {
        	string option = options[i];
            if(classMenu == true && mainMenu == false && weaponMenu == false && combatMenu == false)
            	classDisplay(option, highlight);
            else if(weaponMenu == true && mainMenu == false && classMenu == false && combatMenu == false)
				weaponDisplay(option, highlight);
			else if(combatMenu == true && mainMenu == false && classMenu == false && weaponMenu == false)
				combatDisplay(option, highlight);
           	else 
				cout << highlight << option << endl;  
        }
		else
            cout << "    " << options[i] << endl;
}
	logDisplay();
	cout<<endl<<endl<<monsterDetails<<endl<<endl;
	descriptionDisplay();
	interaction(options, size);
}

void weaponChoiceDetermine(string weapon) {
	playerWeapon = weapon;
	if(playerClass == "Knight") {
		if(playerWeapon == "Battleaxe") {
			weaponStr[0] = 1;
			weaponStr[1] = 8;
		} else if (playerWeapon == "Longbow") {
			weaponStr[0] = 1;
			weaponStr[1] = 5;
		} else if (playerWeapon == "Zweihander") {
			weaponStr[0] = 2;
			weaponStr[1] = 13;
		}	
	} else if(playerClass == "Pyromancer") {
		if(playerWeapon == "Fire Staff") {
			weaponStr[0] = 2;
			weaponStr[1] = 6;
		} else if(playerWeapon == "Flame Wand") {
			weaponStr[0] = 1;
			weaponStr[1] = 4;
		} else if(playerWeapon == "Pyromancer's Tome") {
			weaponStr[0] = 3;
			weaponStr[1] = 6;
		}
	}

	introWindow();
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

void death() {
	system("cls");
	cout<<"Darkness closes in, cold and unyielding. The clinking chains fall silent, and the echoes of your footsteps fade into nothing. The weight of your failure"<<endl;
	cout<<"is crushing - a forgotten soul lost to the labyrinth."<<endl;
	getch();
	cout<<""<<endl;
	cout<<"The serpent coils tighter, the dungeon consuming you whole. Somewhere far above, the faint sliver of light dims, swallowed by the horrors you could not overcome."<<endl;
	cout<<"The goblins cackle in the distance, the dragon roars triumphantly, and the presence in the shadows stirs, its hunger sated—for now."<<endl;
	getch();
	cout<<""<<endl;
	cout<<"Your journey ends here, but the dungeon remains. Waiting. Watching. Perhaps another will rise where you have fallen."<<endl;
	cout<<""<<endl;
	cout<<"GAME OVER!";
	exit(0);
}

void combatChoiceDetermine(string action) {
	rollAttack = 0;
	bool monsterSpawn = true;

	if(action == "Attack") {
		for(int i = 0; i < weaponStr[0]; i++){
			rollAttack =  rollAttack + randomNumberGenerator(weaponStr[0] , weaponStr[1]);
		}
		
		dynamicMonsterHp = dynamicMonsterHp - (rollAttack + playerPower);
		logArray[logIndex] = "> You attack the monster: " + monster + " [DMG: " + to_string(rollAttack) + "+" + to_string(playerPower) + " = " + to_string(rollAttack+playerPower) + "]";
		logIndex++;
		if(dynamicMonsterHp <= 0) {
			battleEnd();
			if(randomNumberGenerator(1 , 100) <= 60)
				reward();
			else
				rewardFail();
			for(int i = 0; i < 100; i++)
				logArray[i].clear();
			action = "";
		}
	}
	else if(action == "Heal") {
		if(playerPotion > 0){
			dynamicPlayerHp = dynamicPlayerHp + 30;
			playerPotion--;
			logArray[logIndex] = "> You drink the potion to regain your vigour [HP: +30], Remaining Potions: "  + to_string(playerPotion);
			logIndex++;
		} else {
			logArray[logIndex] = "> You have run out of healing potions.";
			logIndex++;
		}
		monsterSpawn = false;
	}
	else if(action == "Run") {
		if(randomNumberGenerator(1, 100) < 50) {
			system("cls");
			cout<<"You manage to escape successfully, putting distance between yourself and the danger. However,"<<endl;
			cout<<"your relief is short-lived, as the path ahead soon reveals yet another looming monstrosity waiting to challenge you."<<endl;
			monsterSpawn = false;
			for(int i = 0; i < 100; i++)
				logArray[i].clear();
			getch();
		} else {
			logArray[logIndex] = "> You were unable to run away.";
			logIndex++;
		}
	}
	
	
	if(dynamicMonsterHp > 0 && monsterSpawn == true) {
		int monsterRollAttack = randomNumberGenerator(1 , monsterStr);
		dynamicPlayerHp = dynamicPlayerHp - (monsterRollAttack + monsterPower);
		logArray[logIndex] = "> The monster: " + monster + " attacks you " + "[DMG: " + to_string(monsterRollAttack) + "+" + to_string(monsterPower) + " = " + to_string(monsterRollAttack+monsterPower) + "]";
		logIndex++;
		if(dynamicPlayerHp <= 0)
			death();
	} else {
		monsterSpawn = true;
		if(dynamicMonsterHp <= 0)
		monsterDetermine();
	}
	combatWindow();
}

void combatWindow() {
	combatMenu = true;
	mainMenu = false;
	classMenu = false;
	weaponMenu = false;
	
	if (firstSpawn == false){
		monsterDetermine();
		firstSpawn = true;
	}
		
	playerDetails = "[Class:" + playerClass + "] [VIG:" + to_string(dynamicPlayerHp) + "] [FOR:" + to_string(weaponStr[0]) + "d" + to_string(weaponStr[1]) + "] [POW:" + to_string(playerPower) + "]";
	monsterDetails = "[Monster:" + monster + "] [VIG:" + to_string(dynamicMonsterHp) + "] [FOR:1d" + to_string(monsterStr) + "] [POW:" + to_string(monsterPower) + "]";
	
	string action[] = {"Attack", "Heal", "Run"};
	int size = sizeof(action)/sizeof(action[0]);
	system("cls");
	display(action, size);
}

void reward() {
	playerPotion++;
	cout<<"As the dust settles, your gaze falls upon a small, glimmering vial nestled amidst the debris. The liquid within glows a soft crimson,"<<endl;
	cout<<"swirling as if alive — a Potion of Healing. Its warmth radiates through the glass, promising to restore strength"<<endl;
	cout<<"to the weary and mend wounds inflicted by the dungeon's perils.";
	cout<<""<<endl<<endl;
	getch();
	cout<<"With careful hands, you claim the potion, knowing it may be the difference between survival and oblivion in the trials ahead."<<endl;
	getch();
	cout<<"\nPotions in Inventory: "<<playerPotion<<endl;
	getch();
	cout<<"\nBut before you can even catch your breath, the ground trembles beneath your feet, and from the shadows, a new monster emerges—its eyes locked onto you,"<<endl;
	cout<<"hunger in its gaze. This grueling gauntlet is far from over."<<endl;
	getch();
}

void battleEnd() {
	system("cls");
	int choiceNum = randomNumberGenerator(1 , 5);
	if(choiceNum == 1) {
		cout<<"The last of the monster crumples to the floor, its lifeless form casting long shadows in the dim light. Silence follows,"<<endl;
		cout<<"broken only by the sound of your own breathing. The dungeon feels quieter now, as if even the walls are waiting for your next move.";
	} else if(choiceNum == 2) {
		cout<<"With a final, decisive blow, the creature falls, his twisted form dissolving into the shadow from which it came. The air grows still, the echo"<<endl;
		cout<<"of battle fading into the silence of the dungeon. For now, the danger has passed, but the path ahead remains uncertain.";
	} else if(choiceNum == 3) {
		cout<<"The vile creature collapses, defeated and motionless. A heavy silence settles over the area, broken only by the faint drip of blood from the walls."<<endl;
		cout<<"The victory is yours, but the dungeon is far from conquered. What awaits you deeper within?";
	} else if(choiceNum == 4) {
		cout<<"The monstrous threat has been vanquished, his body littering the ground, marking the end of this skirmish. You stand amidst the carnage,"<<endl;
		cout<<"your breath heavy and your body sore, but victorious. The dungeon’s dark heart still beats ahead, waiting for you.";
	} else if(choiceNum == 5) {
		cout<<"As the final creature falls with a thud, the echoes of battle die away. The dungeon, once alive with the sounds of chaos,"<<endl;
		cout<<"now falls into an eerie quiet. The threat has passed for now but the deeper dangers of the dungeon loom ahead, waiting for the next challenge.";
	}
	cout<<""<<endl<<endl;
	cout<<"Your victory brings hope in this wretched place. As you rest, you feel the strength of your newfound experience. [EXP: +"<<monsterExp<<"]"<<endl<<endl;
	getch();
}

void rewardFail() {
	cout<<"The creature lies still, but upon searching, you find no treasure or spoils to claim. Before you can catch your breath,"<<endl;
	cout<<"a new foe emerges from the shadows, ready to test your strength once more."<<endl;
	getch();
}

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



























