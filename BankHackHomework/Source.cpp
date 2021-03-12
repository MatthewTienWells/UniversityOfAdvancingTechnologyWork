/*Matthew Wells
11/8/2020
Bank Swap - A demonstration of reference variables*/

#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::endl;

//Displays the current value of Joe's Coffee Shop and Terror Corp LTD
void standardDisplay(int joes, int terror);
//Swaps the bank accounts for Joe's and Terror Corp then displays them
void hackedDisplay(int& joes, int& terror);

int main() 
{
	//Joe's bank account
	int joes = 20;
	//Terror Corp's bank account
	int terror = 100000000;
	//Reference to Joe's bank acoount
	int& r_joes = joes;
	//Reference to Terror Corp's bank account
	int& r_terror = terror;
	cout << "Displaying bank account information:" << endl;
	standardDisplay(joes, terror);
	cout << "Hacking..." << endl << "Hacking..." << endl << "Hacking..." << endl << "HACKING TOO MUCH!!!" << endl << "Hacking less..." << endl;
	cout << "Hacking complete!" << endl;
	hackedDisplay(r_joes, r_terror);
	return 0;
}

void standardDisplay(int joes, int terror)
{
	cout << "Joe's Coffee Shop ('Good coffee, good times') currently has a balance of: " << joes << endl;
	cout << "Terror Corp LTD ('Not a terrorist money laundering front') currently has a balance of: " << terror << endl;
}

void hackedDisplay(int&joes, int& terror)
{
	//Save Joe's bank account to a temp variable
	int money = joes;
	//Put Terror Corp's money into Joe's account
	joes = terror;
	//Put Joe's money into Terror Corp's account
	terror = money;
	standardDisplay(joes, terror);
}
	