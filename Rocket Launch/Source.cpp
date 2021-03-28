#include "Header.h"

void launch(unique_ptr<int> rockets, shared_ptr<bool> abort) //Program to automatically launch rockets on a timer
{
	//while (!*abort && *rockets > 0) //Loop until all rockets are launched or the abort flag is set
	//{
	//	cout << "Cuurent thread is " << get_id() << endl; //Print ID of thread to the console
	//	cout << "Launching next rocket in 3 seconds." << endl << endl; //Print message to timer
	//	sleep_for(3000ms); //Wait for three seconds
	//	if (!*abort) //If the abort flag has not been set in the three seconds
	//	{
	//		*rockets -= 1; //Decrement remaining rockets
	//		cout << "Rocket launch successful!" << endl << endl; //Print message to the console
	//	}
	//}
	//if (*rockets == 0) //If no rockets remain
	//{
	//	cout << "All rockets have been launched! Enter any input to continue." << endl; //Print message to the console.
	//}
	//else
	//{
	//	cout << "Aborted launch sequence with " << *rockets << " remaining." << endl; //IF abort was triggered, print alternate message to console
	//}
}

int main() //Main function
{
	unique_ptr<int> rockets(new int(10)); //Create a unique pointer holding the number of rockets
	shared_ptr<bool> abort(new bool(false)); //Create a shared pointer representing the abort flag
	string trigger; //String to hold user input
	cout << "Using main thread " << get_id() << endl;
	cout << "Prepared to begin launch! Please enter input to begin launch sequence!" << endl; //Print prompt to console
	getline(cin, trigger); //Wait for input
	cout << "Launching rocket number 1!" << endl; //Print message to console
	*rockets -= 1; //Decrement remaining rockets
	cout << "Rocket launch successful!" << endl; //Print message to console
	cout << "Transferring control to space cadet. Enter any input to order abort." << endl;
	thread cadet (launch, rockets, abort); //Start seperate threat for space cadet launching rockets
	getline(cin, trigger); //Wait for user input
	*abort = true; //Set abort flag to true so launch will halt if it is running.
	//cadet.join(); //Wait for cadet thread to exit
	cout << "Rejoined main thread " << get_id() << endl; //Print message to console signifying main thread has joined cadet thread
	return 0; //Exit
}