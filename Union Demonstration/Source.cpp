/*Matthew Wells
10-28-2020
Union Demonstration*/

#include <iostream>

//We declare the member types of the union 'example'
union example
{
	int integer;
	char letter;
	float number;
};

int main()
{
	//Create an object of example named ex
	example ex;

	//Declare that we are using ex as an integer, then set it to 22
	ex.integer = 22;
	//Print the value of ex
	std::cout << "The current value is " << ex.integer << std::endl;

	//Declare that we are using ex as a letter, then set it to 'z'
	ex.letter = 'z';
	//Print the value of ex
	std::cout << "The current value is " << ex.letter << std::endl;

	//Note that we can no longer access ex.integer, as it has been overwritten with ex.letter

	//Declare that we are using ex as a float, and set it to 3.14159
	ex.number = 3.14159;
	//Print the value of ex
	std::cout << "The current value is " << ex.number << std::endl;

	return 0;
}