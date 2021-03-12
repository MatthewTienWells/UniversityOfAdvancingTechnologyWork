/*Matthew Wells
11/8/2020
Bakery- An example of pointer based coding*/

#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

//Sets the time to bake
void setClock(int& timer);
//Sets the temperature to bake at
void setTemperature(int& temperature);
//Bakes the bread and displays the results
void bake(int timer, int temperature, string* inner, string* outer);


int main()
{
	string bakeQuality[8] = { "Raw", "Gooey", "Soft", "Firm", "Crunchy", "Hard", "Charred", "Burnt" };
	int oven_timer = 0;
	int oven_temperature = 0;
	int &p_timer = oven_timer;
	int &p_temp = oven_temperature;
	string* inner = bakeQuality;
	string* outer = bakeQuality;
	string choice;
	do {
		cout << "Would you like to set the oven temperature, set the oven timer, or finish?" << endl;
		cout << "enter 'timer', 'temp', or 'finish'" << endl << ">";
		cin >> choice;
		if (choice == "timer")
		{
			setClock(p_timer);
		}
		if (choice == "temp")
		{
			setTemperature(p_temp);
		}
	} while (choice != "finish");
	bake(oven_timer, oven_temperature, inner, outer);
	cout << "You finished baking!" << endl;
	return 0;
}

void setClock(int& timer)
{
	cout << "Set the oven timer!" << endl << ">";
	cin >> timer;
}

void setTemperature(int& temperature)
{
	cout << "Set the oven temperature!" << endl << ">";
	cin >> temperature;
}

void bake(int timer, int temperature, string *inner, string *outer)
{
	cout << "Baking for " << timer << " minutes at " << temperature << " degrees." << endl;
	int crust = 0;
	int core = 0;
	//Calculate how much the crust bakes
	crust += (temperature / 75 - 4) * timer / 60;
	//Calculate how much the inside of the bread bakes- weighted towards longer baking
	core += (temperature / 75 - 4) * timer / 60 - 3;
	if (timer > 240)
	{
		core += 1;
	}
	if (timer > 360)
	{
		core += 1;
	}
	if (timer > 420)
	{
		core += 1;
	}
	if (crust < 0)
	{
		crust = 0;
	}
	if (core < 0)
	{
		core = 0;
	}
	if (crust > 7)
	{
		crust = 7;
	}
	if (core > 7)
	{
		core = 7;
	}
	//Set the baking levels for the dough
	inner += core;
	outer += crust;
	//Display results
	cout << "Your bread is " << *inner << " on the inside, and " << *outer << " on the outside." << endl;
}