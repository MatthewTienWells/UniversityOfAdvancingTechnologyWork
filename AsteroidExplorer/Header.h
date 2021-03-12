/*Matthew Wells
11/13/2020
Asteroid Explorer- A text adventure*/

#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::find;

//Define the scene class- this will act as a parent class for each scene of the game
class Scene
{
public:
	string getChoice();
	Scene() = default;
protected:
	string description;
	void death(bool &game_continue);
	void setChoices(vector<string> choiceSet);
private:
	vector<string> choices;
};

//Defines the Capsule class- this represents the scene inside the command shuttle's living space
class Capsule :public Scene
{
public:
	//See function definitions
	void display();
	bool land();
	void process(vector<bool*> flags, bool &game_continue, int& location);
	int eat(vector<bool*> flags);
	Capsule();
private:
	//Whether or not the capsule has landed on the asteroid
	bool landed = false;
	//The amount of rations remaining
	int ration_count = 10;
};

//The Console class. Represents the shuttle control scene.
class Console :public Scene
{
public:
	//See function definitions
	void display();
	void process(bool& game_continue, Capsule& inside);
	Console();
};

//The Asteroid class. Controls the crevice scene.
class Asteroid :public Scene
{
public:
	//See function definitions
	void display(vector<bool*> flags);
	void process(vector<bool*> flags, bool& game_continue);
	void addOptions();
	Asteroid();
};

//Asks the player if they would like to restart when the game is over.
bool tryAgain();

//Shows the start of the game
void beginGame(string name, bool &game_continue);