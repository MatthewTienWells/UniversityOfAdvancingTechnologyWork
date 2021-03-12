//Matthew Wells
//10/18/2020
//WelcomeToTheJungle
//A Jumanji text adventure

//Includes the iostream, which lets us read and write to the console
#include<iostream>
//Includes the string object, which lets us store string elements as variables
#include<string>

//Declares cin from the standard library, which allows to to get console input
using std::cin;
//Declares cout from the standard library, which allows us to print to the console
using std::cout;
//Declares the string variable type
using std::string;
//Declares the endline character, which breaks up console output.
using std::endl;

//The main function, which runs automatically. This program creates an interactive text adventure.
int main()
{
	//Creates string variables to store character names
	string player;
	string playerFriend;
	string rival;
	string otherFriend;
	//Define positive integers as a variable type
	typedef unsigned int positive;
	//Create a constant representing how far away from the goal the characters start at
	const int MILES = 500;
	//Create a positive integer representing how far the characters travel before finding a map
	positive traveled;

	//Ask the player a series of questions to populate the variables
	cout << "Please enter your first name:" << endl;
	cin >> player;
	cout << "Please enter one of your friend's first names:" << endl;
	cin >> playerFriend;
	cout << "Please enter one of your rival's first names:" << endl;
	cin >> rival;
	cout << "Please enter another one of your friend's first names:" << endl;
	cin >> otherFriend;
	cout << "Please enter a positive number:" << endl;
	cin >> traveled;

	//Print the text adventure to the console
	cout << "One day, " << player << ", " << playerFriend << ", " << rival << ", and " << otherFriend << " were being compelled to engage in illegal labor." << endl;
	cout << "They discovered a mysterious VIDEO GAME, and decided to play it instead." << endl;
	cout << "When they started the game, they were sent to a jungle." << endl; 
	cout << player << " was transformed into a KEVIN HART, and " << playerFriend << " was transformed into a DWAYNE 'THE ROCK' JOHNSON." << endl;
	cout << rival << " was transformed into a JACK BLACK, and " << otherFriend << " was transformed into a KAREN GILLIAN." << endl;
	cout << rival << " was immediately eaten by an ENRAGED HIPPOPOTAMUS, but " << playerFriend << " saved them with their new MUSCLES." << endl;
	cout << "Soon, the four were lost in a maze of twisty jungle paths, all alike." << endl;
	cout << "They traveled for " << traveled / 4.0 << " miles, but were attacked by HYENAS." << endl;
	cout << "Fortunately, " << rival << " distracted them with their incredible COMEDY STYLINGS, and " << otherFriend << " defeated them with BRITISHNESS." << endl;
	cout << player << " found a JEEP and a MAP, after travelling a further " << 3 * traveled / 4.0 << " miles." << endl;
	cout << player << " realized they were travelling the wrong way. They turned around and travelled another " << traveled + MILES << " miles." << endl;
	cout << "The four beat the VIDEO GAME, and learned the true meaning of friendship." << endl;
}