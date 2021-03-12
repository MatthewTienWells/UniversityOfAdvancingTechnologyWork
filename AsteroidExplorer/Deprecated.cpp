/*Matthew Wells
11/1/2020
Asteroid Explorer, an interactive text adventure
*/

#include<iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//Plays opening text
string opening()
{

	cout << "Congratulations, brave space explorer! You have been chosen to land upon and examing the newly discovered asteroid ISCO-5532!" << endl;
	//Get player input, loop until it is valid
	string choice;
	do
	{
		cout << "continue or quit?" << endl;
		cout << ">";
		cin >> choice;
	} while (choice != "continue" and choice != "quit");
	return choice;
}

//Gets the player choice when in the shuttle module
string checkModule(bool landed)
{
	if (!landed)
	{
		cout << "Your shuttlecraft is approaching the asteroid. In your cabin is a spacesuit, a console, a gun, an airlock, and rations." << endl;
	}
	else
	{
		cout << "Your shuttlecraft has landed. In your cabin is a spacesuit, a console, a gun, an airlock, and rations." << endl;
	}
	//Get player input, loop until it is valid
	string choice;
	do
	{
		cout << "What will you use?" << endl;
		cout << ">";
		cin >> choice;
	} while (choice != "spacesuit" and choice != "console" and choice != "gun" and choice != "rations" and choice != "airlock");
	return choice;
}


//Gets the player choice when using the instrument console
string useInstruments()
{
	cout << "You examine the console. Your pilot training comes to mind, and you consider the tasks that you can perform with the console." << endl;
	cout << "You can land, check systems, takeoff, or vent oxygen." << endl;
	//Get player input, loop until it is valid
	string choice;
	do
	{
		cout << "land, check, takeoff, vent?" << endl;
		cout << ">";
		cin >> choice;
	} while (choice != "land" and choice != "check" and choice != "takeoff" and choice != "vent");
	return choice;
}

//Displays the correct message for equipping or unequipping the suit, changes the value for wearing suit flag.
int suitToggle(int wearing)
{
	//If the suit is equipped, unequip it
	if (wearing == 1)
	{
		cout << "You take off the space suit." << endl;
		return 0;
	}
	//If the suit is not equipped, equip it
	else
	{
		cout << "You put on the space suit." << endl;
		return 1;
	}
}

//Gets player input while exploring the surface of the asteroid
string exploreCrevice(bool has_gun)
{
	string choice;
	//If the player did not equip the gun, they have three choices, otherwise, they have five.
	if (!has_gun)
	{
		cout << "You see a strange, fuzzy alien nearby. The crevice walls are too steep to climb in your spacesuit." << endl;
		cout << "You can throw a rock, walk the opposite direction, or tackle the alien." << endl;
		//Get player input, loop until it is valid
		do
		{
			cout << "throw, walk, or tackle?" << endl;
			cout << ">";
			cin >> choice;
		} while (choice != "throw" and choice != "walk" and choice != "tackle");
		return choice;
	}
	else
	{
		cout << "You see a strange, fuzzy alien nearby. The crevice walls are too steep to climb in your spacesuit." << endl;
		cout << "You can throw a rock, walk the opposite direction, shoot the ground, shoot the alien, or tackle the alien." << endl;
		//Get player input, loop until it is valid
		do
		{
			cout << "throw, walk, ground, alien, or tackle?" << endl;
			cin >> choice;
		} while (choice != "throw" and choice != "walk" and choice != "tackle" and choice != "ground" and choice != "alien");
		return choice;
	}
}

//Displays outcomes in the crevice
int creviceEndings(string choice)
{
	if (choice == "tackle")
	{
		cout << "You lunge for the alien, but are viciously mauled." << endl;
		cout << "You lose." << endl;
		return 0;
	}
	if (choice == "alien")
	{
		cout << "You fire upon the alien. Its acid blood sprays everywhere, breaching your spacesuit. You asphyxiate." << endl;
		cout << "You lose." << endl;
		return 0;
	}
	if (choice == "throw")
	{
		cout << "You throw a rock at the alien, but are viciously mauled." << endl;
		cout << "You lose." << endl;
		return 0;
	}
	if (choice == "tackle")
	{
		cout << "You walk around, but find the walls to steep in one direction, and the alien blocks the other." << endl;
		return 1;
	}
}

//Runs the story for the game.
int game()
{
	int wearing_spacesuit = 0;
	bool carrying_gun = false;
	bool landed = false;
	bool in_ship = true;
	if (opening() == "quit")
	{
		cout << "You turn down the mission. You live a quiet life." << endl;
		return 0;
	}
	//Loop through the shuttle scene until the player loses the game or leaves the ship while it has landed
	while (in_ship)
	{
		//Get the player's next action
		string choice = checkModule(landed);
		if (choice == "spacesuit")
		{
			wearing_spacesuit = suitToggle(wearing_spacesuit);
		}
		if (choice == "gun")
		{
			if (wearing_spacesuit == 1)
			{
				if (carrying_gun)
				{
					cout << "You fire the gun! The craft violently depressurizes!" << endl;
					cout << "You lose." << endl;
					return 0;
				}
				else
				{
					cout << "You place the gun in a strap on your spacesuit's side." << endl;
					carrying_gun = true;
				}
			}
			else
			{
				cout << "You remember that you need to put on your spacesuit to holster the gun." << endl;
			}
		}
		if (choice == "rations")
		{
			cout << "You decide to ignore the landing sequence and have a snack. The shuttle crashes into the asteroid and explodes." << endl;
			cout << "You lose." << endl;
			return 0;
		}
		if (choice == "console")
		{
			//Get the player's choice of what to do at the console
			string console_choice = useInstruments();
			if (console_choice == "land")
			{
				if (!landed)
				{
					cout << "You safely land the shuttle." << endl;
					landed = true;
				}
				else
				{
					cout << "You have already landed the shuttle!" << endl;
				}
			}
			if (console_choice == "check")
			{
				cout << "Systems nominal." << endl;
			}
			if (console_choice == "takeoff")
			{
				if (landed)
				{
					cout << "You decide you've explored enough already. When you return to Earth you are forever dishonored for so badly flubbing." << endl;
					cout << "You lose." << endl;
					return 0;
				}
				cout << "You trigger the takeoff system early. The shuttle spirals out of control and crashes." << endl;
				cout << "You lose." << endl;
				return 0;
			}
			if (console_choice == "vent")
			{
				cout << "You vent the atmosphere from the shuttle. You now have no atmosphere." << endl;
				cout << "You lose." << endl;
				return 0;
			}
		}
		if (choice == "airlock")
		{
			//If the ship is landed, proceed to the next scene
			if (landed)
			{
				in_ship = false;
			}
			//If the ship has not landed, the player loses
			else
			{
				cout << "You drift off into space." << endl;
				cout << "You lose." << endl;
				return 0;
			}
		}
	}
	//If the player is not wearing the spacesuit in this scene, they automatically lose
	if (!wearing_spacesuit)
	{
		cout << "You asphyxiate immediately." << endl;
		cout << "You lose." << endl;
		return 0;
	}
	cout << "As you explore the low-gravity surface of ISCO-5532, you notice a flash of movement in a crevice. As you lean over to get a good look, you tumble into the crevice." << endl;
	//Play the crevice scene until the player loses or shoots the ground (they must have the gun to shoot the ground)
	string choice;
	while (choice != "ground")
	{
		choice = exploreCrevice(carrying_gun);
		if (creviceEndings(choice) == 0)
		{
			return 0;
		}
	}
	cout << "You use your gun to propel yourself out of the crevice." << endl;
	cout << "You return to Earth with the news that ISCO-5532 is inhabited! You are hailed as a hero." << endl;
	cout << "You win!" << endl;
	return 0;
}

//Main function, plays game and asks if user wishes to replay.
//int main()
//{
//	char replay;
//	int check;
//	//Play the game once, and then again until the player answers something other than y when asked to replay
//	do
//	{
//		check = game();
//		cout << "Play again (y/n)?" << endl;
//		cin >> replay;
//	} while (replay == 'y');
//	return check;
//}