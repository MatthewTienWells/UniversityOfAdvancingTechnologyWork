#include "Header.h"

//Requests a string from the user and repeats until it receives a valid one. Valid strings are set by the setChoices member.
string Scene::getChoice()
{
	string input;
	//Get user input, then iterate through the choices member to see if it's valid. If the input is invalid, repeat.
	while (find(choices.begin(), choices.end(), input) == choices.end())
	{
		cout << "Choose one of the following:" << endl;
		for (string choice : choices)
		{
			cout << choice << " ";
		}
		cout << ">";
		cin >> input;
	}
	return input;
}

//Records a vector of strings to the class memory for getChoices to use. We need a dedicated setter function to avoid variables being stored as virtual.
void Scene::setChoices(vector<string> choiceSet)
{
	choices = choiceSet;
}

//Plays a short death message and sets the continue flag to false so the game loop will exit
void Scene::death(bool &game_continue)
{
	cout << "You have died in space! Your remains will travel endlessly within the intersteller void." << endl;
	game_continue = false;
}

//Constructor for the Capsule class- sets the proper choices to use in the Capsule scene.
Capsule::Capsule(void)
{
	setChoices({ "spacesuit", "console", "gun", "airlock", "rations" });
}

//Prints out a description of the inside of the capsule
void Capsule::display()
{
	if (!landed)
	{
		cout << "Your shuttlecraft is approaching the asteroid. In your cabin is a spacesuit, a console, a gun, an airlock, and rations." << endl;
	}
	else
	{
		cout << "Your shuttlecraft has landed. In your cabin is a spacesuit, a console, a gun, an airlock, and rations." << endl;
	}
}

//Lands the shuttle. Returns false if the shuttle has already been landed
bool Capsule::land()
{
	if (landed)
	{
		return false;
	}
	else
	{
		landed = true;
		return true;
	}
}

//Consumes rations. Reduces rations by one if any remain, sets the 'hungry' flag to false, and prints out a description of the player's actions
int Capsule::eat(vector<bool*> flags)
{
	//If the hungry flag is set
	if (*flags[2])
	{
		cout << "You quickly eat some rations to keep your energy up!" << endl;
		//Unset the hungry flag
		*flags[2] = false;
	}//If the player is not hungry and there are rations remaining
	else if (ration_count > 0)
	{
		cout << "You're not that hungry, but you sit down and eat anyway." << endl;
	}//If all the rations have been eaten, exit
	else
	{
		cout << "You can't eat any more rations, or you'll actually explode. Good thing the spacesuit is real stretchy." << endl;
		return 0;
	}// Reduce the number of rations
	return ration_count - 1;
}

//Control function for the Capsule scene. Effects vary based on player input.
void Capsule::process(vector<bool*> flags, bool& game_continue, int& location)
{
	display();
	string action = getChoice(); //Get the player's next action
	if (action == "gun")
	{
		if (*flags[1]) //If the gun is equipped
		{
			cout << "You fire the gun! The craft violently depressurizes!" << endl;
			death(game_continue); //Game Over
		}
		else if (*flags[0]) //If the spacesuit is equipped, but not the gun
		{
			cout << "You place the gun in a strap on your spacesuit's side." << endl;
			*flags[1] = true; //Equip the gun
		}
		else
		{
			cout << "You need to put on your spacesuit first, or you won't be able to reach it." << endl;
		}
	}
	if (action == "spacesuit")
	{
		if (*flags[0]) //If the player is wearing the suit
		{
			cout << "You take off the spacesuit." << endl;
			*flags[0] = false; //Unequip the suit
			*flags[1] = false; //Unequip the gun if it was equipped
		}
		else //If the player is not wearing the suit
		{
			cout << "You put on your spacesuit." << endl;
			*flags[0] = true; //Equip the suit
		}
	}
	if (action == "rations")
	{
		ration_count = eat(flags); //Eat a unit of rations
		if (!landed) //If the shuttle is still in flight
		{
			if (ration_count < 7) //If the player has wasted too much time eating
			{
				cout << "You spent too long eating and the ship crashed!" << endl;
				death(game_continue); //Game over
			}
		}
	}
	if (action == "console") //Move to the console scene
	{
		location = 1;
	}
	if (action == "airlock")
	{
		if (!landed) //If the shuttle is in motion
		{
			cout << "You drift off into space." << endl;
			death(game_continue); //Game over
		}
		else if (!*flags[0]) //If the player does not have on a spacesuit
		{
			cout << "You asphyxiate over the next minute." << endl;
			death(game_continue); //Game over
		}
		else
		{
			location = 2; //Move to the crevice scene
			cout << "As you explore the low-gravity surface of ISCO-5532, you notice a flash of movement in a crevice. As you lean over to get a good look, you tumble into the crevice." << endl;
		}
	}
}

//Constructor for the Console class- sets the proper choices to use in the Console scene.
Console::Console(void)
{
	setChoices({ "land", "check", "takeoff", "vent" });
}

//Prints out a description of the shuttle instruments
void Console::display()
{
	cout << "You examine the console. Your pilot training comes to mind, and you consider the tasks that you can perform with the console." << endl;
	cout << "You can land, check systems, takeoff, or vent oxygen." << endl;
}

//Control function for the Console scene. Effects vary based on player input.
void Console::process(bool& game_continue, Capsule& inside)
{
	display();
	string action = getChoice();
	if (action == "land") //Attempt to land the shuttle
	{
		if (inside.land()) //Call the shuttle's landing method
		{
			cout << "You safely land the shuttle." << endl;
		}
		else
		{
			cout << "You have already landed!" << endl;
		}
	}
	if (action == "takeoff") //Quits, earning a non-standard game over
	{
		cout << "You decide you've explored enough already, and fire the rockets on a return path.";
		cout << " When you return to Earth you are forever dishonored for so badly flubbing." << endl;
		game_continue = false;
	}
	if (action == "vent")
	{
		cout << "You vent the atmosphere from the shuttle. You now have no atmosphere." << endl;
		death(game_continue); //game over
	}
	if (action == "check") //Does nothing
	{
		cout << "Systems normal." << endl;
	}
}

//Constructor for the Asteroid class- sets the proper choices to use in the asteroid scene.
Asteroid::Asteroid(void)
{
	setChoices({ "throw", "walk", "tackle" });
}

//Prints out a description of the asteroid crevice area
void Asteroid::display(vector<bool*> flags)
{
	if (!*flags[1])//If the player lacks a gun
	{
		cout << "You see a strange, fuzzy alien nearby. The crevice walls are too steep to climb in your spacesuit." << endl;
		cout << "You can throw a rock, walk the opposite direction, or tackle the alien." << endl;
	}
	else //If the player has a gun
	{
		cout << "You see a strange, fuzzy alien nearby. The crevice walls are too steep to climb in your spacesuit." << endl;
		cout << "You can throw a rock, walk the opposite direction, shoot the ground, shoot the alien, or tackle the alien." << endl;
	}
}

//Control function for the Asteroid scene. Effects vary based on player input.
void Asteroid::process(vector<bool*> flags, bool& game_continue)
{
	if (*flags[1]) //If the player has a gun, add more opptions to the asteroid scene
	{
		addOptions();
	}
	display(flags);
	string action = getChoice();
	if (action == "tackle")
	{
		cout << "You lunge for the alien, but are viciously mauled." << endl;
		death(game_continue); //Game over
	}
	if (action == "alien")
	{
		cout << "You fire upon the alien. Its acid blood sprays everywhere, breaching your spacesuit. You asphyxiate." << endl;
		death(game_continue); //Game over
	}
	if (action == "throw")
	{
		cout << "You throw a rock at the alien, but are viciously mauled." << endl;
		death(game_continue); //Game over
	}
	if (action == "walk") //Nothing happens
	{
		cout << "You walk around, but find the walls to steep in one direction, and the alien blocks the other." << endl;
		if (*flags[2]) //If the player did not eat any rations
		{
			cout << "You really wish you'd eaten before coming out here." << endl; //Flavor text
		}
	}
	if (action == "ground")
	{
		cout << "You use your gun to propel yourself out of the crevice." << endl;
		cout << "You return to Earth with the news that ISCO-5532 is inhabited! You are hailed as a hero." << endl;
		cout << "You win!" << endl;
		game_continue = false; //Player wins!
	}
}

//Changes the options available to the player in the Asteroid scene. Should be called when entering the Asteroid scene if the player has a gun.
void Asteroid::addOptions()
{
	setChoices({ "throw", "walk", "tackle", "ground", "alien" });
}

//Asks the player's if they want to play the game. Entering quit results in an immediate game-over.
void beginGame(string name, bool& game_continue)
{
	cout << "Congratulations, " << name << "! You have been chosen to land upon and examing the newly discovered asteroid ISCO-5532!" << endl;
	//Get player input, loop until it is valid
	string choice;
	do
	{
		cout << "continue or quit?" << endl;
		cout << ">";
		cin >> choice;
	} while (choice != "continue" and choice != "quit");
	game_continue = choice == "continue";
	if (choice == "quit")
	{
		cout << "You turn down the mission. You live a quiet life." << endl; //Nonstandard game over
	}
}

//Asks the player if they want to try playing the game again.
bool tryAgain()
{
	cout << "Would you like to try again? 'y/n'" << endl;
	string answer;
	cin >> answer;
	if (answer == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Main function.
int main()
{
	//Get player name and greet them
	cout << "Hello! What's your name?" << endl << ">";
	string name;
	cin >> name;
	bool retry = true;
	//Game loop
	while (retry)
	{
		//Set up gameplay flags, creat a vector with pointers to them that we can pass to the classes
		bool spacesuit = false;
		bool gun = false;
		bool hungry = true;
		vector<bool*> flags = { &spacesuit, &gun, &hungry };
		//Genearate the scenes
		Capsule inside;
		Console instruments;
		Asteroid outside;
		//Note our current location inside the capsule
		int location = 0;
		//game_continue is set to off on a game over
		bool game_continue = true;
		beginGame(name, game_continue); //Show the intro
		while (game_continue) //Loop until game over
		{
			if (location == 0)
			{
				inside.process(flags, game_continue, location); //Capsule scene
			}
			if (location == 1)
			{
				instruments.process(game_continue, inside); //Console scene
				location = 0;
			}
			if (location == 2)
			{
				outside.process(flags, game_continue); //Crevice scene
			}
		}
		retry = tryAgain(); //Ask if the player wants to play again
	}
}