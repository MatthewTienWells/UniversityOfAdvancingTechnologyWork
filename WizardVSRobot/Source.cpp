#include "Header.h"

class GameStructure //Base class for other classes
{
public:
    int RandomRoll() //Method for getting an int between 1 and 100 inclusive
    {
        default_random_engine Gener = default_random_engine(); //Create a random number generator object
        uniform_int_distribution<int> dist = uniform_int_distribution<int>(1, 100); //Create a range of integers equal to 1 through 100
        return dist(Gener); //Return a random number between 1 and 100
    }

    virtual void Help() = 0; //Pure virtual method
};

class Character : public GameStructure //Base class for character objects
{
private:
    int Health = 100; //Base health for characters
public:
    string Name; //Name for characters. This will be set on initialization for each character
    void SetHealth(int NewValue) //Method for changing the private value Health
    {
        if (NewValue <= 0) //If the character runs out of health
        {
            Health = 0; //Set the health value to 0
            cout << "Character has Expired..." << endl; //Display a death message for the character
        }
        else //If the character is still alive
        {
            Health = NewValue; //Change the private health value
        }
    }

    int GetHealth() //Returns the private health value
    {
        return Health; //Return the value
    }

    void Talk(string name, string stuffToSay) //Method that writes a given name and message to the console
    {
        cout << "I am " + name + ". " + stuffToSay << endl; //Write to console
    }

    void Talk(string stuffToSay) //Method that writes the Name value of the character and a message to the console
    {
        cout << "I am " + Name + ". " + stuffToSay << endl; //Write to console
    }

    virtual int Attack() //Method that returns an damage value. Defaults to 10 damage
    {
        return 10; //Return damage value
    }
};

class Wizard : public Character //Class representing the Space Wizard. Inherits from character.
{
public:
    Wizard() //Constructor
    {
        Name = "Galmaxus"; //Set name
    }

    int CastSpell() //Magic attack
    {
        cout << "Galmaxus attacks!" << endl; //Print narration to the console
        cout << "I cast Gamma Burst!" << endl;
        return Attack(); //Call the attack method for the class
    }

    int Attack() //Overrides the character method Attack
    {
        if (RandomRoll() < 90) //Generate a random number to check if the attack is a critical hit
        {
            return 25; //If the attack is not a critical hit, return damage 25
        }
        else
        {
            cout << "Critical Hit!" << endl; //If the attack was critical, print narration to the console
            return 40; //Return damage 40
        }
    }

    void Help() //Overrides virtual help method
    {
        cout << "Wizards are powerful! They can Cast Spells!" << endl; //Print help message to console
    }
};

class Robot : public Character //Class representing Super Robot. Inherits from character
{
public:
    Robot() //Constructor
    {
        Name = "Dynatron"; //Sets character name
    }
    int RocketFist() //Rocket fist attack
    {
        cout << "Dynatron attacks!" << endl; //Write narration to console
        cout << "Go, Rocket Powered Fist!" << endl;
        return Attack(); //Call the attack method for the class
    }

    int Attack() //Overrides the character method Attack
    {
        if (RandomRoll() < 80) //Generate a random number to check if the attack is a critical hit
        {
            return 25; //If the attack is not a critical hit, return damage 25
        }
        else
        {
            cout << "Critical Hit!" << endl; //If the attack was critical, print narration to the console
            return 30; //Return damage 30
        }
    }

    void Help() //Overrides virtual help method
    {
        cout << "Robots can do anything they're designed for! Fire off a Rocket Fist!" << endl; //Print help message to console
    }
};

int main() //Main function, executes when program is run.
{
    Wizard Galmaxus; //Initialize wizard object
    Robot Dynatron; //Initialize robot object
    string taunt; //Initialize string to hold dialogue while taking taunt action
    string choice = ""; //Initialize an empty string to hold player choices

    cout << "Welcome to the battle for the fate of the galaxy!" << endl; //Write intro to the console
    cout << "The Space Wizard Galmaxus seeks the power of the Everstone to remake the cosmos!" << endl;
    cout << "Dynatron, defender of the Galactic Alliance, wishes to prevent the apocalyptic power of the Everstone from ever being used again!" << endl;
    cout << "The two forces must now clash for the supreme power in the Alpha Quadrant!" << endl;
    cout << "Choose your character! Wizard, or Robot?" << endl; //Ask player which character they want to play as

    while (choice != "Wizard" && choice != "Robot") //Loop until a valid choice is given
    {
        cout << "Wizard / Robot ?" << endl; //Display choices
        cout << ">";
        cin >> choice; //Get player input
    }

    if (choice == "Wizard") //If the player wishes to play as the wizard
    {
        while (Galmaxus.GetHealth() > 0 && Dynatron.GetHealth() > 0) //Enter gameplay loop until one character dies
        {
            cout << "Your health is " << to_string(Galmaxus.GetHealth()) << endl; //Display turn intro
            cout << "The battle rages on! What will the great sorceror do?" << endl;
            choice = ""; //Set player choice to an empty string
            while (choice != "Taunt" && choice != "Cast" && choice != "Help") //Loop until a valid choice is given
            {
                cout << "Taunt / Cast / Help" << endl; //Display choices
                cout << ">";
                cin >> choice; //Get player input
            }
            if (choice == "Taunt") //If player takes the taunt action
            {
                cout << "Enter your taunt" << endl; //Display prompt for taunting
                cout << ">"; 
                cin.ignore(); //Ensure getline does not immediately exit from the previous command
                cin.clear(); //Clear the buffer
                getline(cin, taunt, '\n'); //Use getline to grab a whole line of input
                Galmaxus.Talk(taunt); //Display taunt to the console
            }
            if (choice == "Cast") //If player takes the Cast action
            {
                int EnemyHealth = Dynatron.GetHealth(); //Get current enemy health
                EnemyHealth -= Galmaxus.CastSpell(); //Run attack method, calculate new health value
                Dynatron.SetHealth(EnemyHealth); //Set new enemy health
            }
            if (choice == "Help") //If player takes the Help action
            {
                Galmaxus.Help(); //Display help message
            }
            if (Dynatron.GetHealth() != 0) //If the Robot is still alive
            {
                int PlayerHealth = Galmaxus.GetHealth(); //Get current player health
                PlayerHealth -= Dynatron.RocketFist(); //run enemy attack routine, calculate new health value
                Galmaxus.SetHealth(PlayerHealth); //Set new player health
            }
        }
        if (Galmaxus.GetHealth() == 0) //If player character is dead
        {
            cout << "You lose! The galaxy is doomed to a slow death by entropy." << endl; //Display loss message
        }
        else //If enemy is dead
        {
            cout << "You win! The power to save the universe is yours!" << endl; //Display victory message
        }
    }

    if (choice == "Robot") //If player wishes to play as the robot
    {
        while (Galmaxus.GetHealth() > 0 && Dynatron.GetHealth() > 0) //Enter gameplay loop until one character dies
        {
            cout << "Your health is " << to_string(Dynatron.GetHealth()) << endl; //Display turn intro
            cout << "The battle rages on! What will the heroic android do?" << endl;
            choice = ""; //Set player choice to an empty string
            while (choice != "Taunt" && choice != "Punch" && choice != "Help") //Loop until a valid choice is given
            {
                cout << "Taunt / Punch / Help" << endl; //Display choices
                cout << ">";
                cin >> choice; //Get player input
            }
            if (choice == "Taunt") //If player takes the taunt action
            {
                cout << "Enter your taunt" << endl; //Display prompt
                cout << ">";
                cin.ignore(); //Ensure getline does not immediately exit from the previous command
                cin.clear(); //Clear the buffer
                getline(cin, taunt, '\n'); //Use getline to grab a whole line of input
                Dynatron.Talk(taunt); //Display taunt to the console
            }
            if (choice == "Punch") //If player takes the punch action
            {
                int EnemyHealth = Galmaxus.GetHealth(); //Get current enemy health
                EnemyHealth -= Dynatron.RocketFist(); //Run attack method, calculate new health value
                Galmaxus.SetHealth(EnemyHealth); //Set new enemy health
            }
            if (choice == "Help") //If player takes the help action
            {
                Dynatron.Help(); //Display help message
            }
            if (Galmaxus.GetHealth() != 0) //If enemy is not dead
            {
                int PlayerHealth = Dynatron.GetHealth(); //Get current player health
                PlayerHealth -= Galmaxus.CastSpell(); //Run attack method, calculate new health value
                Dynatron.SetHealth(PlayerHealth); //Set new player health
            }
        }
        if (Dynatron.GetHealth() == 0) //If player character is dead
        {
            cout << "You lose! The galaxy is destroyed by the mad wizard." << endl; //Display loss message
        }
        else //If enemy character is dead
        {
            cout << "You win! The universe is safe once again!" << endl; //Display victory message
        }
    }
};
