/*Matthew Wells
10/20/2020
Simple Program demonstrating use of the Return command
*/

//Include iostream so we can print to the console.
#include <iostream>
//Include string so we can create string variables to return as
#include <string>

//Declare our usual output elements from the standard library
using std::string;
using std::cout;
using std::endl;

//A function that returns a string object
string helloWorld()
{
	//Returns the string 'Hello, World!' when the function is called
	return "Hello, world!";
}

//A function that returns an unsigned (positive) integer
unsigned int luckyNumber() 
{
	//Returns 7 when the function is called
	return 7;
}

//A function that returns a signed (positive or negative) integer
int unluckyNumber()
{
	//Returns the negative of the luckyNumber function's return value when the function is called
	return luckyNumber() * -1;
}

int main()
{
	//Prints the return value of helloWorld to the console
	cout << helloWorld() << endl;
	//Prints a message to the console including the return value of luckyNumber
	cout << "Your lucky number is " << luckyNumber() << endl;
	//Prints a message to the console including the return value of unluckyNumber
	cout << "Your unlucky number is " << unluckyNumber() << endl;
	//Prints a message to the console including the sum of the return values of luckyNumber and unluckyNumber
	cout << "Put 'em together, and we get " << luckyNumber() + unluckyNumber() << endl;
	//Returns 0, indicating the main function exited properly
	return 0;
}