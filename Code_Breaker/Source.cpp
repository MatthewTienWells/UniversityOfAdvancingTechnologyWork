/*
Matthew Wells
10/24/2020
Code Breaker
A word unscrambling game
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Take a string and return the same string scrambled in a random order
string scramble(string word)
{
	//Get the length of the string
	int wordLen = word.length();
	//Store a copy of the string to manipulate
	string tempWord = word;
	//Create a new string to return
	string newWord;
	//Iterate until we've used every character in the string
	while (wordLen > 0)
	{
		//Choose a random number corresponding to the index of a character in the string
		int charPosition = rand() % wordLen;
		//Get the character
		char next = tempWord[charPosition];
		//Add the character to the end of the new string
		newWord += next;
		//Remove the character from the old string
		tempWord.erase(charPosition, 1);
		//Decrement the length count
		wordLen--;
	}
	//Return the new string
	return newWord;
}

//Take a word and hint, scramble the word, and ask the user to unscramble the word
bool guess(string word, string hint, int guesses)
{
	//Tell the player the hint
	cout << "The characters are " << scramble(word) << " and the hint is '" << hint << "'." << endl;
	//Iterate until the player is out of guesses
	while (guesses > 0)
	{
		string playerGuess;
		cout << "You may attempt " << guesses << " more time(s)." << endl;
		cin >> playerGuess;
		//If the player guessed correctly
		if (playerGuess == word)
		{
			//Print correct and exit function with value true
			cout << "Correct!" << endl;
			return true;
		}
		cout << "Incorrect!" << endl;
		//Decrement the number of remaining guesses
		guesses--;
	}
	//Exit with value false
	return false;
}

int main()
{
	//Get a random number seed from the current time
	srand(static_cast<unsigned int>(time(0)));

	//Build arrays, set number of guesses, create score variable
	string hints[10];
	string words[10];
	int MAXGUESSES = 3;
	int score = 0;


	//Store answers and hints
	int wordIndex = 0;
	words[wordIndex] = "key";
	hints[wordIndex++] = "The kind of word this is";
	words[wordIndex] = "ice";
	hints[wordIndex++] = "Crystalline water";
	words[wordIndex] = "deer";
	hints[wordIndex++] = "Does and bucks";
	words[wordIndex] = "nevermore";
	hints[wordIndex++] = "Quoth the raven";
	words[wordIndex] = "sheer";
	hints[wordIndex++] = "Silk or cliffs";
	words[wordIndex] = "seven";
	hints[wordIndex++] = "Consumer of nine";
	words[wordIndex] = "changeling";
	hints[wordIndex++] = "One left behind by fae";
	words[wordIndex] = "crescent";
	hints[wordIndex++] = "Between half and new";
	words[wordIndex] = "arches";
	hints[wordIndex++] = "Twin supports";
	words[wordIndex] = "microcosm";
	hints[wordIndex++] = "As above, so below";

	while (true)
	{
		//Get a random number between 0 and 9 to identify which word we're using first
		int word1 = rand() % 10;
		int word2;
		int word3;
		score = 0;
		//Get a number other than the first number to use next
		do
		{
			word2 = rand() % 10;
		} while (word2 == word1);
		//Get a number other than the first two numbers to use third
		do
		{
			word3 = rand() % 10;
		} while (word3 == word1 || word3 == word2);
		//Ask the player to guess each of the three words
		if (guess(words[word1], hints[word1], MAXGUESSES))
		{
			score++;
		}
		if (guess(words[word2], hints[word2], MAXGUESSES))
		{
			score++;
		}
		if (guess(words[word3], hints[word3], MAXGUESSES))
		{
			score++;
		}
		//Display the player's score and ask if they want to play again
		cout << "Your score was " << score << " out of 3." << endl;
		cout << "Play again? (y/n)" << endl;
		char choice;
		cin >> choice;
		//Either continue if the responded 'y', or end program
		if (choice == 'y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return 0;
}