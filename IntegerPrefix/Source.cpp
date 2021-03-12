/*Matthew Wells
11/4/2020
IntegerPrefix, a short demonstration of the use of octal and hexadecimal notation.*/

#include<iostream>


int main()
{
	//By default we use decimal integers
	int dec = 10;
	//But we can also use octal integers, by preceding them with the digit 0- here I define oct as 10 in base 8.
	int oct = 012;
	//We can also use hexadecimal integers, which we precede with 0x- here I define hexd as 20 in base 16.
	int hexd = 0x14;
	if (dec == oct)
	{
		std::cout << "Decimal 10 is octal 12." << std::endl;
	}
	if (dec + oct == hexd)
	{
		std::cout << "Decimal 20 = hexadecimal 14" << std::endl;
	}
	return 0;
}