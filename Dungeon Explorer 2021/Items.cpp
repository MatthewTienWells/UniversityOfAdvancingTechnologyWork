#include "Header.h"
 
class Item
{
public:
	bool weapon = false; //Whether item is a weapon
	int stat_mod = 0; //Attack or defense change
	int secondary_stat_mod = 0; //Attack speed or health change
	string damage_type = "bludgeoning"; //Type of damage item deals or defends against
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
};

class Weapon : public Item
{
public:
	bool weapon = true; //Note this item is a weapon
	int stat_mod = 10; //Attack value with item equipped
	int secondary_stat_mod = 5; //Attack speed with item equipped
};

class Armor : public Item
{
public:
	bool weapon = false; //Note that this item is not a weapon
	int stat_mod = 10; //Defense value with armor equipped
	int secondary_stat_mod = 100; //Health value with armor equipped
};

class Earplugs : public Armor
{
public:
	string damage_type = "sonic"; //This item protects from sonic damage
	string name = "Earplugs"; //Item name
};

class Spear : public Weapon
{
public:
	int secondary_stat_mod = 2; //Attack speed with weapon equipped
	string name = "Iron Spear"; //Name
	string damage_type = "piercing"; //Type of damage dealt
};

class Sword : public Weapon
{
public:
	int stat_mod = 15; //Attack value with weapon equipped
	string name = "Iron Sword"; //Name
	string damage_type = "slashing"; //Type of damage dealt

	Sword() {}
};

class Club : public Weapon
{
public:
	int stat_mod = 30; //Attack value with weapon equipped
	int secondary_stat_mod = 10; //Attack speed with weapon equipped
	string name = "Iron Club"; //Name
	string damage_type = "bludgeoning"; //Type of damage dealt
};

class Torch : public Weapon
{
public:
	int stat_mod = 50; //Attack value with weapon equipped
	int secondary_stat_mod = 15; //Attack speed with weapon equipped
	string name = "Torch"; //Name
	string damage_type = "heat"; //Type of damage dealt
};

class Mail : public Armor
{
public:
	int stat_mod = 15; //Defense value with armor equipped
	string name = "Chainmail"; //Name
};

class Breastplate : public Armor
{
	int stat_mod = 20; //Defense value with armor equipped
	string name = "Plate Armor"; //Name
};

class MagicPlate : public Armor //Legendary item to be dropped by boss
{
	int stat_mod = 30; //Defense value with armor equipped
	int secondary_stat_mod = 200; //Health value with armor equipped
	string name = "Enchanted Plate Armor"; //Name
	string damage_type = "bludgeoning"; //Immunity with armor equipped
};

class Pendant : public Armor
{
	int secondary_stat_mod = 150; //Health value with pendant equipped
	string name = "Pendant of Life"; //Name
};

class SlayerBlade : public Weapon //Legendary item to be dropped by boss
{
	int stat_mod = 50; //Attack value with weapon equipped
	string damage_type = "slashing"; //Weapon damage type
	string name = "Legendary Slayer's Blade"; //Name
};

class Key : public Weapon //Key. Only good for solving puzzles
{
	int stat_mod = 1; //Attack value with key equipped
	string damage_type = "piercing"; //Key damage type
	string name = "Key"; //Name
};
