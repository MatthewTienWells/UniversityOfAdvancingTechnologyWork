#include "Header.h"

class use_fridge
{
public:
	void check_fridge_u(unique_ptr<string> portion) //Displays result of processing a unique pointer
	{
		if (!portion) //If portion is empty
		{
			throw AteTooMuchException(); //Throw an exception
		}
		cout << "You check that part of the fridge." << endl; //Print message to the console
		cout << *portion << endl; //Print value of pointer to the console
	}

	void check_fridge_w(weak_ptr<string> portion) //Displays result of processing a weak pointer
	{
		if (portion.expired()) //Make sure the pointer has not expired
		{
			throw AteTooMuchException(); //If pointer has expired, raise exception
		}
		cout << "You check that part of the fridge." << endl; //Print message to the console
		auto pour = portion.lock(); //Lock the weak pointer so it can be dereferenced
		cout << *pour << endl; // Print value of pointer to the console
	}

	void check_fridge_s(shared_ptr<string> portion)
	{
		cout << "You check that part of the fridge." << endl; //Print message to the console
		cout << *portion << endl; // Print value of pointer to the console
		*portion = *portion + "/"; //Add tally mark to the number of times eaten
	}
};

int main()
{
	use_fridge Fridge; //Initialize fridge class
	{
		cout << "Time to see what's in the fridge!" << endl; //Print intro to the console
		shared_ptr<string> water_pipe = make_shared<string>("You get a nice glass of water."); //Create a shared ptr representing the choice to get water
		weak_ptr<string> faucet = water_pipe; //Create a weak ptr as a copy of the faucet ptr
		shared_ptr<string> tupperware = make_shared<string>("You open the package. It seems to be some sort of noodles, maybe? Tastes pretty good reheated. Times eaten: "); //Create a shared pointer representing the choice to get leftovers
		auto cardboard_box = tupperware; //Create a copy of the leftover pointer
		auto bowl_with_plastic_wrap = tupperware; //Create a copy of the leftover pointer
		unique_ptr<string> ingredients = make_unique<string>("It's a full dinner, with protein, vegetables, and dessert. It takes a while to cook, but it's delicious."); //Make a unique pointer representing the choice to make dinner
		string choice; //Create a string to represent player choice
		vector<shared_ptr<string>> containers; //Create a list of shared pointers
		containers.push_back(tupperware); //Put a shared pointer in the list
		containers.push_back(cardboard_box); //Put a shared pointer in the list
		containers.push_back(bowl_with_plastic_wrap); //Put a shared pointer in the list
		while (choice != "end") //Loop until the user enters 'end'
		{
			cout << "Choose what to take. Your options are ingredients, containers, or faucet." << endl << ">"; //Prompt the player to enter a choice
			cin >> choice; //Get the player's choice from the console
			try
			{
				try
				{
					if (choice == "ingredients") //If the choice is ingredients
					{
						Fridge.check_fridge_u(move(ingredients)); //Pass the ingredient pointer to the method for handling it
					}
					else if (choice == "faucet") //If the choice is faucet
					{
						Fridge.check_fridge_w(faucet); //Pass the faucet pointer to the method for handling it
					}
					else if (choice == "containers") //If the choice is containers
					{
						if (!containers.empty()) //If the list of containers list is not empty
						{
							Fridge.check_fridge_s(containers.back()); //Pass the last item in the list to the method for handling it
							containers.pop_back(); //Delete the used pointer from the list
						}
						else
						{
							throw AteTooMuchException(); //Throw an exception for the containers having been used up
						}
					}
					else if (choice == "end") //If the user's choice was 'end', do nothing
					{
					}
					else //If the user gave any other choice
					{
						throw BadChoiceException(); //Raise an invalid choice exception
					}
				}
				catch (BadChoiceException e) //If a bad choice exception was thrown
				{
					cerr << e.what() << endl; //Print an error message to the console
				}
			}
			catch (AteTooMuchException e) //If an ate too much exception is thrown
			{
				cerr << e.what() << endl; //Print an error message to the console
			}
		}
	}
}