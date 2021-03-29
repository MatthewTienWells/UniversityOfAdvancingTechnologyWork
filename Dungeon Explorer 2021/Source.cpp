#include "Header.h"

class Location;

bool player_yes_no() //Get a yes or no from the player
{
	string choice; //string to hold player input
	cout << endl << ">"; //Show prompt symbol
	cin >> choice; //Get player input
	while (choice != "y" && choice != "n" && choice != "Y" && choice != "N") //Loop until player provides valid input
	{
		cout << "Please enter either Y for yes or N for no." << endl << ">"; //Instruct player on how to provide valid input
		cin >> choice; //get player input
	}
	if (choice == "y" || choice == "Y") //If the player answered in the affirmative.
	{
		return true;
	}
	else
	{
		return false;
	}
}

void help() //Display help info
{
	cout << "Welcome to Dungeon Explorer." << endl;
	cout << "Your goal is to find the treasure at the end of this dungeon complex." << endl;
	cout << "You may move deeper into the dungeon, or move back to return to prior areas." << endl;
	cout << "Most rooms either have a puzzle, or an enemy." << endl;
	cout << "To clear a puzzle, equip the required item from your inventory, then attempt to move through the room." << endl;
	cout << "To clear a combat room, defeat the enemy within it." << endl;
	cout << "Once you've cleared a room, you can move through it freely." << endl;
	cout << "To navigate, use items, or check your stats, just follow the text prompts." << endl << endl;
	cout << "Combat Tips:" << endl;
	cout << "While in combat, you can enter the commands 'weak', 'strong', or 'run'." << endl;
	cout << "Entering the command 'weak' will attempt to strike your foe. If it hits, you'll deal damage equal to your attack stat." << endl;
	cout << "Entering the command 'strong' will do the same thing, but it will take 50% longer and deal twice your attack stat in damage." << endl;
	cout << "Entering the command 'run' will take you to the previous room, ending combat." << endl;
	cout << "You and enemies heal completely when you aren't in combat, so don't be afraid to run and take a second shot at it later." << endl;
	cout << "You can change your stats by equipping items. You can equip one weapon and one non-weapon at a time." << endl;
	cout << "Some weapons don't work on certain enemies, and some non-weapons can grant you immunity to certain enemies." << endl;
	cout << "If you can't win a fight, try changing your equipped gear." << endl;
	cout << "The higher your defense is, the less likely an attack is to connect." << endl;
	cout << "Enemies will keep attacking while you choose your commands or execute attacks, so be quick and think ahead!" << endl;
}

class Item
{
public:
	bool weapon = false; //Whether item is a weapon
	int stat_mod = 0; //Attack or defense change
	int secondary_stat_mod = 0; //Attack speed or health change
	string damage_type = ""; //Type of damage item deals or defends against
	string name = "Uninitialized Name"; //Item name

	Item() {} //Default constructor

	Item(string data) //Constructor
	{
		string parsed; //String to hold parsed data from input string
		stringstream data_stream(data); //Create a stream containing the input data
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		if (parsed == "true") //If the first entry in the data is 'true'
		{
			weapon = true; //Set weapon to true
		}
		else //Otherwise
		{
			weapon = false; //Set weapon to false
		}
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		stat_mod = stoi(parsed, nullptr); //Parse data into stat_mod
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		secondary_stat_mod = stoi(parsed, nullptr); //Parse data into secondary_stat_mod
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		damage_type = parsed; //Set damage type from the parsed data
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		name = parsed; //Set name from parsed data
	}

	void set_attr(bool weapon_flag, int stat_mod_1, int stat_mod_2, string type_damage, string nameID) //Override attributes
	{
		weapon = weapon_flag; //Set weapon
		stat_mod = stat_mod_1; //Set stat_mod
		secondary_stat_mod = stat_mod_2; //Set secondary stat mod
		damage_type = type_damage; //Set damage type
		name = nameID; //Set name
	}
};

class Weapon : public Item
{
public:
	bool weapon = true; //Note this item is a weapon
	int stat_mod = 10; //Attack value with item equipped
	int secondary_stat_mod = 5; //Attack speed with item equipped

	Weapon() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Armor : public Item
{
public:
	bool weapon = false; //Note that this item is not a weapon
	int stat_mod = 10; //Defense value with armor equipped
	int secondary_stat_mod = 100; //Health value with armor equipped

	Armor() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Earplugs : public Armor
{
public:
	string damage_type = "sonic"; //This item protects from sonic damage
	string name = "Earplugs"; //Item name

	Earplugs() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Spear : public Weapon
{
public:
	int secondary_stat_mod = 2; //Attack speed with weapon equipped
	string name = "Iron Spear"; //Name
	string damage_type = "piercing"; //Type of damage dealt

	Spear() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Sword : public Weapon
{
public:
	int stat_mod = 15; //Attack value with weapon equipped
	string name = "Iron Sword"; //Name
	string damage_type = "slashing"; //Type of damage dealt

	Sword() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Club : public Weapon
{
public:
	int stat_mod = 30; //Attack value with weapon equipped
	int secondary_stat_mod = 8; //Attack speed with weapon equipped
	string name = "Iron Club"; //Name
	string damage_type = "bludgeoning"; //Type of damage dealt

	Club() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class WoodClub : public Club
{
public:
	int stat_mod = 20; //Attack value with weapon equipped
	string name = "Wood Club"; //Name

	WoodClub() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Torch : public Weapon
{
public:
	int stat_mod = 50; //Attack value with weapon equipped
	int secondary_stat_mod = 12; //Attack speed with weapon equipped
	string name = "Torch"; //Name
	string damage_type = "heat"; //Type of damage dealt

	Torch() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Mail : public Armor
{
public:
	int stat_mod = 15; //Defense value with armor equipped
	string name = "Chainmail"; //Name

	Mail() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Breastplate : public Armor
{
public:
	int stat_mod = 20; //Defense value with armor equipped
	string name = "Plate Armor"; //Name

	Breastplate() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class MagicPlate : public Armor //Legendary item to be dropped by boss
{
public:
	int stat_mod = 30; //Defense value with armor equipped
	int secondary_stat_mod = 200; //Health value with armor equipped
	string name = "Enchanted Plate Armor"; //Name
	string damage_type = "bludgeoning"; //Immunity with armor equipped

	MagicPlate() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Pendant : public Armor
{
public:
	int secondary_stat_mod = 150; //Health value with pendant equipped
	string name = "Pendant of Life"; //Name

	Pendant() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class SlayerBlade : public Weapon //Legendary item to be dropped by boss
{
public:
	int stat_mod = 50; //Attack value with weapon equipped
	string damage_type = "slashing"; //Weapon damage type
	string name = "Legendary Slayer's Blade"; //Name

	SlayerBlade() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};

class Key : public Weapon //Key. Only good for solving puzzles
{
public:
	int stat_mod = 1; //Attack value with key equipped
	string damage_type = "piercing"; //Key damage type
	string name = "Key"; //Name

	Key() //Constructor
	{
		set_attr(weapon, stat_mod, secondary_stat_mod, damage_type, name); //Set base class attributes
	}
};


class Character //Base Class for entities
{
private:
	vector<Item> item_list; //Create private list of items to keep randomly generated loot out of method scope

	int RandomRoll() //Method for getting an int between 1 and 100 inclusive
	{
		default_random_engine Gener(rd()); //Seed rng
		uniform_int_distribution<int> dist = uniform_int_distribution<int>(1, 100); //Create a range of integers equal to 1 through 100
		int num = dist(Gener); //Return a random number between 1 and 100
		return num;
	};

	bool Is_Immune(string damage_type) //Test for immunity to damage
	{
		return find(immunities.begin(), immunities.end(), damage_type) != immunities.end(); //Return whether damage_type is in the entity's immunities
	};

public:
	int max_health = 100; //Maximum health
	int health = max_health; //Remaining health
	int attack = 10; //Attack power
	int attack_speed = 5; //Seconds between entity attacks
	int defense = 10; //Percentage chance of avoiding damage from an attack
	string damage_type = "bludgeon"; //Type of damage entity deals by default
	string name = "Uninitialized Name"; //Name of entity
	string equipped_weapon; //Active weapon for character
	string equipped_armor; //Active armor for character
	string loot_table = "StandardLoot.txt"; //File to pull loot table from
	vector<string> immunities; //Types of damage entity is immune to
	vector<Item*> inventory; //List of items on character
	bool death = false; //Flag representing if the entity has died
	random_device rd; //Get seed for random number generator

	void set_attr(int life, int atk, int spd, int def, string type_damage, string nameID, string loot_file, vector<string> res, vector<Item*> holding) //Set all attributes from child class
	{
		max_health = life;
		attack = atk;
		attack_speed = spd;
		defense = def;
		damage_type = type_damage;
		name = nameID;
		loot_table = loot_file;
		immunities = res;
		inventory = holding;
	}

	Character() //Allow for construction with default values
	{}

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
		sleep_for(milliseconds(attack_speed * 500)); //Wait for the time listed in attack_speed
		if (!death)
		{
			return tuple<int, string>(attack, damage_type); //Return default damage and damage type
		}
		else
		{
			return tuple<int, string>(0, damage_type); //Return 0 damage if entity died while attacking
		}
	};

	tuple<int, string> strong_attack() //Call to execute a strong attack and get damage back
	{
		sleep_for(milliseconds(attack_speed * 750)); //Wait for 1.5 times the time listed in attack_speed
		if (!death)
		{
			return tuple<int, string>(attack * 2, damage_type); //Return twice the standard damage and the standard damage type
		}
		else
		{
			return tuple<int, string>(0, damage_type); //Return 0 damage if entity died while attacking
		}
	};

	void take_attack(int damage_value, string damage_type) //Function to process damage to entity
	{
		if (RandomRoll() > defense && !Is_Immune(damage_type) && !death) //Roll to see if an attack landed and if the entity is not immune
		{
			health -= damage_value; //Reduce current health by damage
			cout << name << " takes " << damage_value << " " << damage_type << " damage!" << endl << ">"; //Print message to the console about damage taken
			if (health <= 0) //If character had no health remaining
			{
				death = true; //Set death flag
			}
		}
		else if (Is_Immune(damage_type)) //If the entity is immune
		{
			cout << name << " is immune to " << damage_type << " attacks!" << endl << ">"; //Note that entity is immune to the attack
		}
		else //If attack failed
		{
			cout << "The attack failed to connect!" << endl << ">"; //Print failure message
		}
	};

	void get_status() //Display entity's current status
	{
		if (max_health == health) //At full health
		{
			cout << name << " is ready for a fight! Be on your guard!" << endl; //Print to console
		}
		else if (4 * health > 3 * max_health) //Above 3 quarters health
		{
			cout << name << " is still standing strong! Keep fighting!" << endl; //Print to console
		}
		else if (2 * health > max_health) //Above half health
		{
			cout << name << " is starting to look fatigued! Press on!" << endl; //Print to console
		}
		else if (4 * health > max_health) //Above one quarter health
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
		RandomLoot(); //Get inventory from table
		cout << name << " falls to the ground, lifeless." << endl; //Print message to console
		if (!inventory.empty()) //If the entity was carrying items
		{
			cout << "On the foe was the following:" << endl; //Print message to console
			for (int i = 0; i < inventory.size(); i++) //Iterate through inventory
			{
				cout << (*inventory[i]).name << endl; //Print list of items dropped
			}
		}
		return inventory; //Return items
	};

	virtual void combat_routine(bool* player_engaged, Character* user) //Run combat routine
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

	thread combat_thread(bool* player_engaged, Character* user) //Wrapper for combat routine to allow threading
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
		cout << "Health: " << max_health << endl;
		cout << "Defense: " << defense << endl;
		cout << "Speed: " << attack_speed << endl;
		cout << "Attack: " << attack << endl;
		cout << "Weapon type: " << damage_type << endl;
		cout << "Immunities: " << endl;
		for (int i = 0; i < immunities.size(); i++)
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
		for (int i = 0; i < new_items.size(); i++) //Iterate through new items
		{
			inventory.push_back(new_items.at(i)); //Add item to inventory
		}
	}

	int get_health() //Returns entity's current health
	{
		return health;
	}

	void RandomLoot() //Set inventory randomly from the loot table file
	{
		ifstream infile(loot_table); //Open the loot table file
		vector<string> table; //Create a table of strings
		string currentline; //Create a string to hold the current line
		while (getline(infile, currentline)) //Read each line from the file into currentline
		{
			table.push_back(currentline); //Add the current line to the table
		}
		if (RandomRoll() > 10) //Flip a coin to see if the entity drops loot
		{
			currentline = table.at(RandomRoll() % table.size()); //Select a random line from the loot table
			Item Treasure(currentline); //Construct an item from the data
			item_list.push_back(Treasure); //Move generated item out of local scope
			Item* loot = &(item_list.at(0)); //Create pointer to loot
			inventory.push_back(loot); //Add the treasure to the inventory of this entity
		}
	};

	virtual void win_game() {} //Virtual function

	virtual void move(Location* place) {} //Virtual function
};

class Slime : public Character
{
public:
	string name = "Slime"; //Set name
	int attack = 7; //Set attack power
	vector<string> immunities = { "piercing", "slashing" }; //Set damage immunities

	Slime() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Tiny_Slime : public Slime
{
public:
	string name = "Little Slime"; //Set name
	int max_health = 50; //Set maximum health for tiny slime
	int health = max_health; //Set health to max health
	int attack = 3; //Set attack power
	int attack_speed = 3; //Set attack speed
	int defense = 20; //Set defense rate

	Tiny_Slime() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Big_Slime : public Slime
{
public:
	string name = "Huge Slime"; //Set name
	int max_health = 160; //Set maximum health for big slime
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 8; //Set attack speed
	int defense = 5; //Set defense rate

	Big_Slime() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Metal_Slime : public Slime
{
public:
	string name = "Legendary Silver Slime"; //Set name
	vector<string> immunities = { "piercing", "slashing", "heat" }; //Set damage immunities 
	int max_health = 250; //Set maximum health for metal slime
	int health = max_health; //Set health to max health
	int attack = 5; //Set attack power
	int attack_speed = 10; //Set attack speed
	int defense = 50; //Set defense rate

	Metal_Slime() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Bandit : public Character
{
public:
	string name = "Bandit Sentry"; //Set name
	int max_health = 150; //Set maximum health for bandit
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 8; //Set attack speed
	string damage_type = "slashing"; //Set damage type

	Bandit() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Bandit_Leader : public Bandit
{
public:
	string name = "Sidonia the Slayer"; //Set name
	int max_health = 180; //Set maximum health for bandit
	int health = max_health; //Set health to max health
	int attack = 15; //Set attack power
	int attack_speed = 6; //Set attack speed
	string damage_type = "slashing"; //Set damage type

	Bandit_Leader() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Siren : public Character
{
public:
	string name = "Lurking Siren"; //Set name
	int max_health = 90; //Set maximum health
	int health = max_health; //Set health to max health
	int attack = 40; //Set attack
	int attack_speed = 15; //Set attack speed
	string damage_type = "sonic"; //Set damage type
	vector<string> immunities = { "heat" }; //Set damage immunity

	Siren() //Constructor
	{
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
	}
};

class Location //Class representing rooms in the dungeon
{
private:
	Location* parent; //Parent of this location

public:
	bool combat = false; //Flag representing if the room is a combat challenge
	bool cleared = false; //Flag representing whether the player may proceed
	string solution; //String representing the item a player must have equipped to pass a puzzle challenge
	string solved_descriptor; //Description for a puzzle being solved
	string descriptor = "a stone chamber. It seems this was once a natural cave, but the walls have been worked by human hands."; //Description of the room
	Character* foe;
	vector<Location*> children; //List of child rooms for this room

	Location() {} //Default constructor

	void set_attr(bool fight, bool complete, string key, string unlock, string description, Character* enemy) //Set all attributes from base class, either with themselves or new values
	{
		combat = fight;
		cleared = complete;
		solution = key;
		solved_descriptor = unlock;
		descriptor = description;
		foe = enemy;
	}

	Location(string data, vector<Location*> child_rooms, Location* caller) //Construct a puzzle room
	{
		Character* foe; //The enemy for a combat challenge
		foe = new Character;
		Location* parent; //Pointer to the parent of this room
		string parsed; //String to hold parsed data from input string
		stringstream data_stream(data); //Create a stream containing the input data
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		solution = parsed; //Set solution to first entry in data
		getline(data_stream, parsed, ';'); //Read data stream until semicolon
		solved_descriptor = parsed; //Set solved descriptor to parsed data
		getline(data_stream, parsed); //Read rest of data stream
		descriptor = parsed; //Add description
		children = child_rooms; //Set rooms that can be entered after this room is completed
		parent = caller; //Set parent room that can be returned to
	}

	Location(string description, vector<Location*> child_rooms, Location* caller, Character enemy) //Construct a combat room
	{
		Character* foe; //The enemy for a combat challenge
		foe = new Character;
		Location* parent; //Pointer to the parent of this room
		combat = true; //Set combat flag to true
		descriptor = description; //Set room description
		foe = &enemy; //Set character to fight
		children = child_rooms; //Set rooms that can be entered after this room is completed
		parent = caller; //Set parent room that can be returned to
	}

	void add_child(Location* child) //Make another room the child of this one
	{
		children.push_back(child); //Add the child room to the list of this rooms children
		(*child).set_parent(this); //Associate this room as the child's parent
	}

	void set_parent(Location* parent_room) //Set the parent of this room
	{
		parent = parent_room; //Override current parent room with new parent
	}

	Location* return_room() //Activate when room is returned to from a later room
	{
		cout << "Backtracking, you return to " << descriptor << endl;
		return this;
	}

	virtual void enter_room(Character* player) //Activate when room is entered
	{
		if (!cleared) //If the room has not yet been cleared
		{
			string choice; //String to hold player input
			if (combat) //If this room is a combat challenge
			{
				cout << "You peer into the chamber beyond." << endl << "Inside, you see: " << descriptor << endl; //Print message to console
				cout << "You catch a glimpse of movement in the chamber." << endl;
				cout << "Enter the chamber and fight? (Y/N)";
				if (player_yes_no()) //If the player answered in the affirmative.
				{
					bool engaged = true; //Boolean representing whether the player is engaged in combat
					bool* player_engaged = &engaged; //Pointer to pass to player and foe
					thread enemy_AI = foe->combat_thread(player_engaged, player); //Begin foe AI
					(*player).combat_routine(player_engaged, foe); //Initiate combat interface
					enemy_AI.join(); //Wait for enemy AI thread to exit
					if (!(*foe).is_alive())
					{
						cleared = true;
					}
				}
				else //If the player answered negatively
				{
					retreat(player); //Return to parent room
				}
			}
			else //If the room is a puzzle challenge
			{
				cout << "A quick look inside the room reveals it is unoccupied." << endl; //Print description to console
				cout << "You venture inside to find " << descriptor << endl;
				cout << "Use an item? (Y/N)";
				if (player_yes_no()) //If the player answered in the affirmative.
				{
					if (solution == (*player).get_armor() || solution == (*player).get_weapon()) //If the player has the solution to the puzzle equipped
					{
						cout << solved_descriptor << endl; //Print the text representing the puzzle being solved to the console
						cleared = true;
					}
					else
					{
						cout << "You thought you might have an idea of how to get through here, but now you aren't so sure. Maybe a different item?" << endl; //Print failure message
					}
				}
				else //If the player answered negatively
				{
					cout << "You decide that you'll need something else here. But have you already found it?" << endl;
				}
			}
		}
		else
		{
			return_room(); //Play message for returning to this room
		}
	}

	bool change_room(Character* player) //Change location to somewhere else
	{
		string choice; //String representing player choice
		if (!cleared)
		{
			cout << "The path forward is blocked: " << descriptor << endl;
			cout << "Use an item? (Y/N)";
			if (player_yes_no()) //If the player answered in the affirmative.
			{
				if (solution == (*player).get_armor() || solution == (*player).get_weapon()) //If the player has the solution to the puzzle equipped
				{
					cout << solved_descriptor << endl; //Print the text representing the puzzle being solved to the console
					cleared = true; //Set flag to show the way forward is open
					return change_room(player); //Call self again now that way is open
				}
				else
				{
					cout << "You thought you might have an idea of how to get through here, but now you aren't so sure. Maybe a different item?" << endl; //Print failure message
					return false; //Return false to representing that the player did not move
				}
			}
			else //If the player answered negatively
			{
				cout << "Would you like to return to a previous area? (Y/N)"; //Ask if the player wants to go back
				if (player_yes_no()) //If the player answers affirmatively
				{
					retreat(player); //Go back to the parent room
					return true; //Exit with value true showing player moved
				}
				else
				{
					return false; //Exit with value false showing player didn't move
				}
			}
		}
		else //If this room has been cleared
		{
			if (children.size() != 0)
			{
				cout << "Do you want to continue deeper into the dungeon? (Y/N)"; //Ask if the player wants to move forward
				if (player_yes_no()) //If the player answers affirmatively
				{
					cout << "Moving forward, you see " << children.size() << " doors. Which one will you enter? Input a number." << endl << ">"; //Ask the player what door to enter
					cin >> choice; //Get player input
					try //Validate input
					{
						unsigned int door = stoi(choice); //Convert input to unsigned int
						if (door > children.size() || door == 0) //Make sure input is not outside expected range
						{
							throw InvalidUserInputException(); //Throw error if input is outside expected range
						}
					}
					catch (...) //If validation failed
					{
						cout << "That's not a valid choice." << endl; //Warn user input was incorrect
						return false; //Exit method with value false showing player did not move
					}
					unsigned int door = stoi(choice); //Convert input to unsigned int
					(*player).move(children.at(door - 1)); //Set new player location
					return true; //Exit with value true showing playert moved
				}
				else if (parent) //If player answers no to venturing deeper
				{
					cout << "Would you like to return to a previous area? (Y/N)"; //Ask if the player wants to go back
					if (player_yes_no()) //If the player answers affirmatively
					{
						retreat(player); //Go back to the parent room
						return true; //Exit with value true showing player moved
					}
					else
					{
						return false; //Exit with value false showing player didn't move
					}
				}
			}
			else if (parent)
			{
				cout << "There doesn't seem to be any way forward from here." << endl;
				cout << "Would you like to return to a previous area? (Y/N)"; //Ask if the player wants to go back
				if (player_yes_no()) //If the player answers affirmatively
				{
					retreat(player); //Go back to the parent room
					return true; //Exit with value true showing player moved
				}
				else
				{
					return false; //Exit with value false showing player didn't move
				}
			}
		}
		return false; //If none of the options were taken
	}

	void retreat(Character* player) //Sends the player back one room
	{
		(*player).move(parent); //Return to parent room
	}

	string get_descriptor()
	{
		return descriptor;
	}
};

class Entrance : public Location //Starting room where the player appears at the beginning of the game
{
public:
	Entrance()
	{
		bool cleared = true;
		string descriptor = "the entrance to the dungeon. To the west is a cave mouth leading out into the mountains you trekked through to reach this place."; //Description of the room
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}

	void enter_room(Character* player) //Call when entering this room
	{
		cout << "The caves of Alorna. A legendary treasure sleeps within. It's taken you many days to reach this place, but you will have that treasure." << endl; //Print message to console
		cout << "Gathering your bearings, you see " << get_descriptor() << endl;
		cout << "From here, you can head further into the caves." << endl;
	}

	bool change_room(Character* player) //Change location to somewhere else
	{
		string choice; //String representing player choice
		cout << "Do you want to continue deeper into the dungeon? (Y/N)"; //Ask if the player wants to move forward
		if (player_yes_no()) //If the player answers affirmatively
		{
			cout << "Moving forward, you see " << children.size() << " doors. Which one will you enter? Input a number." << ">"; //Ask the player what door to enter
			cin >> choice; //Get player input
			try //Validate input
			{
				unsigned int door = stoi(choice); //Convert input to unsigned int
				if (door > children.size() || door == 0) //Make sure input is not outside expected range
				{
					throw InvalidUserInputException(); //Throw error if input is outside expected range
				}
			}
			catch (...) //If validation failed
			{
				cout << "That's not a valid choice." << endl; //Warn user input was incorrect
				return false; //Exit method with value false showing player did not move
			}
			unsigned int door = stoi(choice); //Convert input to unsigned int
			(*player).move(children.at(door - 1)); //Set new player location
			return true; //Exit with value true showing player moved
		}
		else //If player answers no to venturing deeper
		{
			return false; //Exit with value false showing player didn't move
		}
	}
};

class Treasure_Room : public Location //Class representing the treasure room at the end of the game
{
private:
	bool cleared = true;
	string descriptor = "the treasure room. Glistening gems top piles of gold, while strange enchanted items cast a shimmering light over it all."; //Description of the room
public:
	Treasure_Room() //Constructor
	{
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
	void enter_room(Character* player) //Call when entering this room
	{
		cout << "Steeling yourself for anything, you make your way into the next chamber." << endl; //Print message to console
		cout << "To your surprise and delight, you open the door into " << descriptor << endl;
		cout << "You've found the legendary treasure of Alorna! You are now fabulously wealthy! Congratulations!" << endl;
		(*player).win_game(); //Mark player as having won game
	}
};

class Slime_Chamber : public Location //Class representing a room that is a slime combat challenge
{
private:
public:
	Slime_Chamber() //Constructor
	{
		string descriptor = "a room with walls and floor covered in a greenish-brown muck."; //Room description
		bool combat = true; //Set combat flag
		Character* foe; //create pointer to enemy
		foe = new Slime; //Set enemy
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Bandit_Outpost : public Location //Class representing a room that is a bandit combat challenge
{
private:
	string descriptor = "a room lit by a magical, smokeless fire. Supplies are carelessly sprawled across the floor."; //Room description
	bool combat = true; //Set combat flag
public:
	Bandit_Outpost()
	{
		Character* foe; //Create pointer to enemy
		foe = new Bandit; //Set enemy
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Locked_Cage : public Location //Class representing a room that requires a key to pass
{
private:
	string descriptor = "a stone chamber with a lattice of iron built between you and the other end. A door with a heavy-looking lock is set in it."; //Room description
	string solution = "Key"; //Set the solution to the puzzle
	string solved_descriptor = "The key fits into the heavy iron door perfectly, and it creaks open when you pull."; //Text to show when the puzzle is solved
public:
	Locked_Cage() //Constructor
	{
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Firewood_Chamber : public Location //Class representing a room that requires a torch to pass
{
private:
	string descriptor = "a store room of some sort. Piles of dry firewood are stacked up against the opposite wall.";  //Room description
	string solution = "Torch"; //Set the solution to the puzzle
	string solved_descriptor = "The wood burns swiftly, forcing you to stand beyond the door, but the smoke excapes through a crack in the wall. The way is soon clear."; //Text to show when the puzzle is solved
public:
	Firewood_Chamber() //Constructor
	{
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Waterfall_Cavern : public Location //Class representing a room that requires ear plugs to pass
{
private:
	string descriptor = "a large cavern, with a waterfall running through it. The sound of the falls echoing across the chamber is so loud you can't focus on searching."; //Room description
	string solution = "Earplugs"; //Set the solution to the puzzle
	string solved_descriptor = "Now able to focus, you discover a pathway behind the waterfall leading deeper into the caves."; //Text to show when the puzzle is solved
public:
	Waterfall_Cavern() //Constructor
	{
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Slimy_Room : public Location //Class representing a room that is a slime combat challenge
{
public:
	Slimy_Room()
	{
		string descriptor = "a room with walls and floor dotted with a green liquid."; //Room description
		bool combat = true; //Set combat flag
		Character* foe; //Create pointer to enemy
		foe = new Tiny_Slime; //Set enemy
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Slime_Flooded_Room : public Location //Class representing a room that is a slime combat challenge
{
private:
	string descriptor = "a room flooded with a foul-smelling, viscous red liquid."; //Room description
	bool combat = true; //Set combat flag
public:
	Slime_Flooded_Room()
	{
		Character* foe; //Create pointer to enemy
		foe = new Big_Slime; //Set enemy
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Siren_Pool : public Location //Class representing a chamber inhabited by the Siren
{
private:
	string descriptor = "an underground lake. A river runs from it back towards the waterfall."; //Room description
	bool combat = true; //Set combat flag
public:
	Siren_Pool()
	{
		Item* cage_key; //Generate pointer to treasure
		Character* foe; //Create pointer to enemy
		foe = new Siren; //Set enemy
		cage_key = new Key; //Generate treasure
		vector<Item*> loot_list; //Create list of special loot
		loot_list.push_back(cage_key); //Add key to list
		(*foe).add_to_inventory(loot_list); //Add list to inventory of siren
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Rusty_Room : public Location //Class representing a room inhabited by the Metal Slime
{
private:
	string descriptor = "a room filled with rusted bits of weapons and armor. It smells strongly of copper."; //Room description
	bool combat = true; //Set combat flag
public:
	Rusty_Room()
	{
		Item* armor; //Generate pointer to treasure
		Character* foe; //Create pointer to enemy
		foe = new Metal_Slime; //Generate enemy
		armor = new MagicPlate; //Generate magic armor
		vector<Item*> loot_list; //Create list of special loot
		loot_list.push_back(armor); //Add armor to list
		(*foe).add_to_inventory(loot_list); //Add list to inventory of metal slime
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Bandit_Hideout : public Location //Class representing the bandit's hideout
{
private:
	string descriptor = "a massive chamber. It seems to have been converted into living space, and it's well decorated, if a little tacky."; //Room description
	bool combat = true; //Set combat flag
public:
	Bandit_Hideout()
	{
		Item* swordPtr; //Create pointer to item
		Character* foe; //Create pointer to enemy
		foe = new Bandit_Leader; //Generate enemy
		swordPtr = new SlayerBlade;
		vector<Item*> loot_list; //Create list of special loot
		loot_list.push_back(swordPtr); //Add sword to list
		(*foe).add_to_inventory(loot_list); //Add list to inventory of bandit leader
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Special_Slime_Chamber : public Slime_Chamber //Class representing the slime chamber where the player is guaranteed to find ear plugs
{
public:
	Special_Slime_Chamber()
	{
		Item* plugs; //Create pointer to treasure
		Character* foe; //Create pointer to enemy
		foe = new Slime; //Generate enemy
		plugs = new Earplugs; //Create treasure
		vector<Item*> loot_list; //Create list of special loot
		loot_list.push_back(plugs); //Add ear plugs to list
		(*foe).add_to_inventory(loot_list); //Add list to inventory of slime
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Vine_Room : public Location //Class representing a room that requires a sword to pass
{
private:
	string descriptor = "a room with a hole in the ceiling. Vines hang down from above, blocking the path"; //Room description
	string solution = "Iron Sword"; //Set the solution to the puzzle
	string solved_descriptor = "You slice through the vines with your sword, clearing the way."; //Text to show when the puzzle is solved
public:
	Vine_Room() //Constructor
	{
		set_attr(combat, cleared, solution, solved_descriptor, descriptor, foe); //Set base class attributes
	}
};

class Player :public Character
{
private:
	Location* current_room; //Room player is in
	bool quit = false; //Flag indicating player wishes to exit program
	bool won_game = false; //Flag indicating player won game
public:

	Player() //Constructor
	{
		cout << "Please enter your name" << endl << ">"; //Prompt user for name
		cin >> name; //Set player name
		inventory.clear(); //Remove random character loot
		set_attr(max_health, attack, attack_speed, defense, damage_type, name, loot_table, immunities, inventory); //Override all base attributes, either with themselves or new values
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
				cout << "Are you sure you want to quit? All progress will be lost! (Y/N)"; //Warn player their progress will be lost
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
			cout << "You have " << get_health() << " health remaining." << endl << ">";
			if (*player_engaged && (*foe).is_alive() && !death) //If the combat is still active
			{
				cin >> choice; //Get player input for next action
			}
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
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << "      " << i + 1 << ": " << (*inventory.at(i)).name << endl;
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

int main()
{
	cout << "Welcome to Dungeon Explorer. Your goal is to find the treasure at the end of the dungeon. Follow the command prompts to play." << endl; //Display intro message
	Player user; //Initialize player character
	cout << "If this is your first time playing, use the 'help' command." << endl; //Instruct player on how to open the instructions
	Item* starting_club; //Create weapon pointer for player
	Item* starting_armor; //Create armor pointer for player
	Item* starting_sword; //Create second weapon pointer for player
	starting_club = new WoodClub(); //Generate weapon
	starting_sword = new Sword(); //Generate alternate weapon
	starting_armor = new Mail(); //Generate armor
	vector<Item*> starting_gear; //Gear player begins with
	starting_gear.push_back(starting_club); //Add club to starting gear
	starting_gear.push_back(starting_armor); //Add mail to starting gear
	starting_gear.push_back(starting_sword); //Add sword to starting gear
	user.add_to_inventory(starting_gear); //Give gear to player
	user.equip(*starting_club); //Equip sword for player
	user.equip(*starting_armor); //Equip armor for player
	Entrance room1; //Initialize dungeon chambers
	Slimy_Room room2;
	Locked_Cage room3;
	Waterfall_Cavern room4;
	Vine_Room room5;
	Bandit_Outpost room6;
	Firewood_Chamber room7;
	Siren_Pool room8;
	Slime_Flooded_Room room9;
	Special_Slime_Chamber room10;
	Slimy_Room room11;
	Bandit_Hideout room12;
	Bandit_Outpost room13;
	Rusty_Room room14;
	Slimy_Room room15;
	Slime_Chamber room16;
	Slime_Flooded_Room room17;
	Treasure_Room room18;
	room1.add_child(&room2); //Set paths between dungeon chambers
	room1.add_child(&room3);
	room2.add_child(&room4);
	room2.add_child(&room5);
	room3.add_child(&room6);
	room3.add_child(&room7);
	room4.add_child(&room8);
	room4.add_child(&room9);
	room5.add_child(&room10);
	room5.add_child(&room11);
	room6.add_child(&room12);
	room7.add_child(&room13);
	room7.add_child(&room14);
	room9.add_child(&room15);
	room9.add_child(&room16);
	room9.add_child(&room17);
	room12.add_child(&room18);
	user.move(&room1); //Put user in starting area
	room1.enter_room(&user); //Play message for entering dungeon
	user.controls(); //Hand control over to player
}