/*Matthew Wells
11/11/2020
A demo of the rand function*/

#include<iostream>
#include<ctime>

using std::cout;
using std::endl;

int main()
{
	//Keep track of the number of times we've iterated
	int iter = 0;
	int ran;
	//We'll iterate 10 times to generate 10 random numbers
	while (iter < 10)
	{
		iter += 1;
		ran = rand();
		cout << ran << endl;
	}
	//We can use the modulus operator to bound the maximum random number without changing constants
	iter = 0;
	while (iter < 10)
	{
		iter += 1;
		ran = rand() % 100;
		cout << ran << endl;
	}
	//We can set a seed that changes the randomization algorithm
	srand(time(NULL));
	iter = 0;
	while (iter < 10)
	{
		iter += 1;
		ran = rand() % 100;
		cout << ran << endl;
	}
}