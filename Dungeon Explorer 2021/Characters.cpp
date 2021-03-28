#include "Header.h"
#include "Items.cpp"

class Character //Base Class for entities
{
private:
	int max_health = 100; //Maximum health
	int health = max_health; //Remaining health
	int attack = 10; //Attack power
	int attack_speed = 5; //Seconds between entity attacks
	int defense = 10; //Percentage chance of avoiding damage from an attack
	string damage_type = "bludgeon"; //Type of damage entity deals by default
	string name = "Uninitialized Name"; //Name of entity
	string equipped_weapon; //Active weapon for character
	string equipped_armor; //Active armor for character
	string loot_table; //File to pull loot table from
	vector<string> immunities; //Types of damage entity is immune to
	vector<Item*> inventory; //List of items on character
	bool death = false; //Flag representing if the entity has died

	int RandomRoll() //Method for getting an int between 1 and 100 inclusive
	{
		default_random_engine Gener = default_random_engine(); //Create a random number generator object
		uniform_int_distribution<int> dist = uniform_int_distribution<int>(1, 100); //Create a range of integers equal to 1 through 100
		return dist(Gener); //Return a random number between 1 and 100
	};

	bool Is_Immune(string damage_type) //Test for immunity to damage
	{
		return find(immunities.begin(), immunities.end(), damage_type) != immunities.end(); //Return whether damage_type is in the entity's immunities
	};

	void RandomLoot() //Set inventory randomly from the loot table file
	{
		ifstream infile(loot_table); //Open the loot table file
		vector<string> table; //Create a table of strings
		string currentline; //Create a string to hold the current line
		while (getline(infile, currentline)) //Read each line from the file into currentline
		{
			table.push_back(currentline); //Add the current line to the table
		}
		if (RandomRoll() > 50) //Flip a coin to see if the entity drops loot
		{
			currentline = table.at(RandomRoll() % table.size()); //Select a random line from the loot table
			Item Treasure(currentline); //Construct an item from the data
			Item* loot = &Treasure; //Create pointer to loot
			inventory.push_back(loot); //Add the treasure to the inventory of this entity
		}
	};
public:
	Character() {} //Allow for construction with default values

	Character(string data) //Constructor function
	{
		string parsed; //String to hold parsed data from input string
		stringstream data_stream(data); //Create a stream containing the input data
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		max_health = stoi(parsed, nullptr); //Parse data into max_health
		health = max_health; //Remaining health
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		attack = stoi(parsed, nullptr); //Parse data into attack
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		attack_speed = stoi(parsed, nullptr); //Parse data into attack speed
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		defense = stoi(parsed, nullptr); //Parse data into defense
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		damage_type = parsed; //Set damage type entity deals
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		name = parsed; //Set entity name
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		equipped_weapon = parsed; //Set equipped weapon for entity
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		equipped_armor = parsed; //Set equipped armor for entity
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		loot_table = parsed; //Set loot table file for entity
		getline(data_stream, parsed, ':'); //Read data stream until colon
		stringstream immunities_stream(parsed); //Turn immunities into a data stream
		while (getline(immunities_stream, parsed, ';')) //Iterate through immunities
		{
			immunities.push_back(parsed); //Add immunity to list
		}
		stringstream inventory_stream(parsed); //Turn inventory into a data stream
		while (getline(inventory_stream, parsed, ':')) //Iterate through inventory
		{
			Item gear = Item(parsed); //Create item from string
			Item* loot = &gear; //Create pointer to item
			inventory.push_back(loot); //Add item to inventory
		}
	}

	tuple<int, string> weak_attack() //Call to execute a weak attack and get damage back
	{
		sleep_for(nanoseconds(attack_speed * 1000)); //Wait for the time listed in attack_speed
		return tuple<int, string>(attack, damage_type); //Return default damage and damage type
	};

	tuple<int, string> strong_attack() //Call to execute a strong attack and get damage back
	{
		sleep_for(nanoseconds(attack_speed * 1500)); //Wait for 1.5 times the time listed in attack_speed
		return tuple<int, string>(attack * 2, damage_type); //Return twice the standard damage and the standard damage type
	};

	void take_attack(int damage_value, string damage_type) //Function to process damage to entity
	{
		if (RandomRoll() > defense && !Is_Immune(damage_type) && !death) //Roll to see if an attack landed and if the entity is not immune
		{
			health -= damage_value; //Reduce current health by damage
			if (health <= 0) //If character had no health remaining
			{
				death = true; //Set death flag
			}
		}
	};

	void get_status() //Display entity's current status
	{
		if (max_health == health) //At full health
		{
			cout << name << " is ready for a fight! Be on your guard!" << endl; //Print to console
		}
		else if (4 * health < 3 * max_health) //Above 3 quarters health
		{
			cout << name << " is still standing strong! Keep fighting!" << endl; //Print to console
		}
		else if (2 * health < max_health) //Above half health
		{
			cout << name << " is starting to look fatigued! Press on!" << endl; //Print to console
		}
		else if (4 * health < max_health) //Above one quarter health
		{
			cout << name << " looks weak! You can do this!" << endl; //Print to console
		}
		else if (health > 0) //Below one quarter health
		{
			cout << "You have " << name << " on the ropes! Finish this!" << endl; //Print to console
		}
		else //At 0 health
		{
			cout << name << " has been slain. The corpse lies at your feet." << endl; //Print to console
		}
	}

	vector<Item*> die() //Function to process character death
	{
		cout << name << " falls to the ground, lifeless." << endl; //Print message to console
		if (!inventory.empty()) //If the entity was carrying items
		{
			cout << "On the foe was the following:" << endl; //Print message to console
			for(int i = 0; i < inventory.size(); i++) //Iterate through inventory
			{
				cout << (*inventory[i]).name << endl; //Print list of items dropped
			}
		}
		return inventory; //Return items
	};

	void combat_routine(bool* player_engaged, Player* user) //Run combat routine
	{
		heal(); //Heals to max
		tuple<int, string> damage_data; //Create a tuple to hold damage scale and type
		while (*player_engaged && !death) //Loop until the player dies, runs, or kills this character
		{
			if (RandomRoll() <= 50) //Get 50% chance
			{
				damage_data = weak_attack(); //Perform a weak attack
				cout << name << " goes for a quick attack!" << endl; //Print message to console
				(*user).take_attack(get<0>(damage_data), get<1>(damage_data)); //Run take_attack method for player
			}
			else
			{
				damage_data = strong_attack(); //Perform a strong attack
				cout << name << " goes for a strong attack!" << endl; //Print message to console
				(*user).take_attack(get<0>(damage_data), get<1>(damage_data)); //Run take_attack method for player
			}
		}
	};

	thread combat_thread(bool* player_engaged, Player* user) //Wrapper for combat routine to allow threading
	{
		return thread(&Character::combat_routine, this, player_engaged, user); //Return thread running combat routine method
	};

	void equip(Item equipment) //Equip item
	{
		if (equipment.weapon) //If item is a weapon
		{
			damage_type = equipment.damage_type; //Change character damage type dealt
			attack = equipment.stat_mod; //Change character damage amount dealt
			attack_speed = equipment.secondary_stat_mod; //Change speed of character attacks
			if (!equipped_weapon.empty()) //If a weapon is currently equipped
			{
				cout << name << " unequipped " << equipped_weapon << " and equipped " << equipment.name << endl; //Print message to console
			}
			else //If no weapon is equipped
			{
				cout << name << " equipped " << equipment.name << endl; //Print message to console
			}
			equipped_weapon = equipment.name; //Set name of equipped weapon
		}
		else //If item is not a weapon
		{
			immunities.clear(); //Remove immunities from character
			immunities.push_back(equipment.damage_type); //Add immunity from item to character
			defense = equipment.stat_mod; //Change character defense value
			max_health = equipment.secondary_stat_mod; //Change character's maximum health
			if (!equipped_armor.empty()) //If armor is currently equipped
			{
				cout << name << " unequipped " << equipped_armor << " and equipped " << equipment.name << endl; //Print message to console
			}
			else //If no armor is equipped
			{
				cout << name << " equipped " << equipment.name << endl; //Print message to console
			}
			equipped_armor = equipment.name; //Set name of equipped weapon
		}
	};

	void unequip(bool weapon) //remove a piece of equipment from character
	{
		if (weapon) //If equipment was weapon, reset damage stats
		{
			int attack = 10; //Attack power
			int attack_speed = 5; //Seconds between entity attacks
			string damage_type = "bludgeon"; //Type of damage entity deals by default
			equipped_weapon.clear(); //Remove name of weapon
		}
		else //If equipment was armor, reset defensive stats
		{
			int max_health = 100; //Maximum health
			int defense = 10; //Percentage chance of avoiding damage from an attack
			immunities.clear(); //Remove immunities from character
			equipped_armor.clear(); //Remove name of armor
		}
	}

	void heal() //Heal this character to max
	{
		health = max_health; //Set health
	}

	bool is_alive() //Return whether character is alive
	{
		return !death; //Return if the death flag has not been set
	}

	string get_armor() //Get equipped armor
	{
		return equipped_armor; //Return string representing armor
	}

	string get_weapon() //Get equipped weapon
	{
		return equipped_weapon; //Return string representing equipped weapon
	}

	void print_stats() //Print entity stats to the console
	{
		cout << "Health: " << health << endl;
		cout << "Defense: " << defense << endl;
		cout << "Speed: " << attack_speed << endl;
		cout << "Attack: " << attack << endl;
		cout << "Weapon type: " << damage_type << endl;
		cout << "Immunities: " << endl;
		for (int i = 0; i++; i > immunities.size())
		{
			cout << "      " << immunities.at(i) << endl;
		}
	}

	vector<Item*> get_inventory() //Returns entity inventory
	{
		return inventory;
	}

	void add_to_inventory(vector<Item*> new_items) //Adds new items to inventory
	{
		for (int i = 0; i++; i > new_items.size()) //Iterate through new items
		{
			inventory.push_back(new_items.at(i)); //Add item to inventory
		}
	}

	int get_health() //Returns entity's current health
	{
		return health;
	}
};

class Slime : public Character
{
private:
	string name = "Slime"; //Set name
	vector<string> immunities = { "piercing", "slashing" }; //Set damage immunities
};

class Tiny_Slime : public Slime
{
private:
	string name = "Little Slime"; //Set name
	int max_health = 50; //Set maximum health for tiny slime
	int health = max_health; //Set health to max health
	int attack = 3; //Set attack power
	int attack_speed = 3; //Set attack speed
	int defense = 20; //Set defense rate
};

class Big_Slime : public Slime
{
	string name = "Huge Slime"; //Set name
	int max_health = 200; //Set maximum health for big slime
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 8; //Set attack speed
	int defense = 5; //Set defense rate
};

class Metal_Slime : public Slime
{
	string name = "Legendary Silver Slime"; //Set name
	vector<string> immunities = { "piercing", "slashing", "heat" }; //Set damage immunities 
	int max_health = 250; //Set maximum health for metal slime
	int health = max_health; //Set health to max health
	int attack = 5; //Set attack power
	int attack_speed = 10; //Set attack speed
	int defense = 50; //Set defense rate
};

class Bandit : public Character
{
	string name = "Bandit Sentry"; //Set name
	int max_health = 150; //Set maximum health for bandit
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 6; //Set attack speed
	string damage_type = "slashing"; //Set damage type
};

class Bandit_Leader : public Bandit
{
	string name = "Sidonia the Slayer"; //Set name
	int max_health = 180; //Set maximum health for bandit
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 3; //Set attack speed
	string damage_type = "slashing"; //Set damage type
};

class Siren : public Character
{
	string name = "Lurking Siren"; //Set name
	int max_health = 90; //Set maximum health
	int health = max_health; //Set health to max health
	int attack = 40; //Set attack
	int attack_speed = 15; //Set attack speed
	string damage_type = "sonic"; //Set damage type
	vector<string> immunities = { "heat" }; //Set damage immunity
};

class Player :public Character
{
private:
	Location* current_room; //Room player is in
	bool quit = false; //Flag indicating player wishes to exit program
	bool won_game = false; //Flag indicating player won game
	bool death = false; //Flag representing if the entity has died
public:
	Player() //Constructor
	{
		Location* current_room; //Room player is in
	}
	void controls() //Interface for basic controls. Should be called once to start game, and loops until player dies, wins, or quits
	{
		string choice; //String representing player input
		while (!death && !quit && !won_game)
		{
			cout << "From here, you can access your inventory, check your stats, move, check the instructions, or quit." << endl;
			cout << "Enter 'inventory', 'stats', 'move', 'help', or 'quit'" << endl << ">";
			cin >> choice; //Get player input
			if (choice == "inventory")
			{
				reequip(); //Open inventory
			}
			else if (choice == "stats")
			{
				print_stats(); //Display stats
			}
			else if (choice == "move")
			{
				navigate(); //Attempt to enter a new area
			}
			else if (choice == "help")
			{
				help(); //Display instructions
			}
			else if (choice == "quit")
			{
				cout << "Are you sure ypu want to quit? All progress will be lost! (Y/N)" << endl << ">"; //Warn player their progress will be lost
				if (player_yes_no()) //Ask again if player wants to quit
				{
					quit = true;
				}
			}
			else
			{
				cout << "Sorry, couldn't understand that command. Please enter commands in all lowercase and exactly as listed." << endl;
			}
		}
	}

	void combat_routine(bool* player_engaged, Character* foe) //Initiate combat interface
	{
		heal(); //Heals to max
		string choice; //String representing player input
		tuple<int, string> damage_data; //Create a tuple to hold damage scale and type
		while (*player_engaged && (*foe).is_alive() && !death) //Loop until the player kills foe, runs, or dies.
		{
			if (choice == "weak") //If player entered 'weak'
			{
				damage_data = weak_attack(); //Perform a weak attack
				cout << "You strike swiftly, sacrificing power for agility!" << endl; //Print message to console
				(*foe).take_attack(get<0>(damage_data), get<1>(damage_data)); //Run take_attack method for enemy
			}
			else if (choice == "strong") //If player entered 'strong'
			{
				damage_data = strong_attack(); //Perform a strong attack
				cout << "You focus your strength, putting your full power into the blow!" << endl; //Print message to console
				(*foe).take_attack(get<0>(damage_data), get<1>(damage_data)); //Run take_attack method for enemy
			}
			else if (choice == "run")
			{
				cout << "You make a run for it!" << endl; //Print message to the console
				*player_engaged = false; //Flag player as out of combat
				(*current_room).retreat(this); //Send player to previous room
			}
			else
			{
				cout << "Keep calm, and enter a command. 'weak' for a fast attack, 'strong' for a powerful attack, or 'run' to get away." << endl; //Show instructions for combat
			}
			(*foe).get_status(); //Display info on enemy
			cout << "You have " << get_health() << " health remaining."; 
			cin >> choice; //Get player input for next action
		}
		if (death)
		{
			cout << "You were defeated by your foe! Perhaps the next adventurer will be more lucky." << endl << "GAME OVER" << endl; //Display death message
			*player_engaged = false; //Set player as out of combat
		}
		else if (!(*foe).is_alive()) //If foe has died
		{
			add_to_inventory((*foe).die()); //Add foe's inventory to own inventory
		}
		else
		{
			cout << "You narrowly escaped!" << endl; //Show message on console
		}
	}

	void move(Location* new_location) //Assign new current location to player
	{
		current_room = new_location;
	}

	void navigate() //Open movement interface for current room, then open interface for new room if player moves
	{
		if ((*current_room).change_room(this)) //Use movement interface for current room
		{
			(*current_room).enter_room(this); //Enter new room if player changed locations
		}
	}

	void reequip() //Inventory interface for changing equipment
	{
		string choice; //String representing player input
		cout << "You are currently wearing " << get_armor() << " and wielding " << get_weapon() << endl; //Display equipped items
		vector<Item*> inventory = get_inventory(); //Get current inventory
		cout << "You are currently in possesion of:" << endl;
		for (int i = 0; i++; i > inventory.size())
		{
			cout << "      " << i+1 << ": " << (*inventory.at(i)).name << endl;
		}
		cout << "Enter a number to equip that item, or enter any other input to return to the menu." << endl << ">";
		cin >> choice;
		try //Validate input
		{
			unsigned int equipment = stoi(choice); //Convert input to unsigned int
			if (equipment > inventory.size() || equipment == 0) //Make sure input is not outside expected range
			{
				return; //Exit
			}
		}
		catch (...)
		{
			return; //Exit
		}
		unsigned int equipment = stoi(choice); //Convert input to unsigned int
		equip(*inventory.at(equipment - 1)); //Equip item
	}

	void win_game() //Sets flag that game is over and player won
	{
		won_game = true;
		cout << "You won! Please play again soon!" << endl;
	}
};