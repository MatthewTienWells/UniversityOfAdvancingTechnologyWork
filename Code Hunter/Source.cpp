/*
DEBUGGED BY
Matthew Wells
10/25/2020
Code Hunter
*/

#include <iostream>
#include <string>

using namespace std;


int main()
{
	string textToAnalyze;
	int foo = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int spaces = 0;
	int lengthOfStringSubmittedForAnalysis = 0;
	int unknownCharacters = 0;
	int checkSum = 0;
	int bar = 0;

	cout << "Welcome to the CIA code Hunter Program!" << endl;
	cout << "Please type in text to analyze: " << endl;
	//Get a sentence from the user
	getline(cin, textToAnalyze);

	//Iterate through each letter in the sumbitted sentence
	for (int i = 0; i < textToAnalyze.length(); ++i)
	{
		//Test the character against each vowel
		if (textToAnalyze[i] == 'a' || textToAnalyze[i] == 'e' || textToAnalyze[i] == 'i' ||
			textToAnalyze[i] == 'o' || textToAnalyze[i] == 'u' || textToAnalyze[i] == 'A' ||
			textToAnalyze[i] == 'E' || textToAnalyze[i] == 'I' || textToAnalyze[i] == 'O' ||
			textToAnalyze[i] == 'U')
		{
			//FIXED: This decremented before- it should increment the number of vowels
			++vowels;
		}
		//If the character is not a vowel, but is a letter
		else if ((textToAnalyze[i] >= 'a' && textToAnalyze[i] <= 'z') || (textToAnalyze[i] >= 'A' && textToAnalyze[i] <= 'Z'))
		{
			//FIXED: This line is correct, but was commented out. It increments consonants.
			++consonants;
		}
		//If the character is greater than or equal to 0 and less than or equal to 9
		else if (textToAnalyze[i] >= '0' && textToAnalyze[i] <= '9')
		{
			//Increment digits
			++digits;
		}
		//If the character is a space
		else if (textToAnalyze[i] == ' ')
		{
			//Increment spaces
			++spaces;
		}
		//If the character is something else
		else
		{
			//Increment unknown characters
			++unknownCharacters;
		}
	}

	//Get the length of the sentence and the number of characters analyzed
	lengthOfStringSubmittedForAnalysis = textToAnalyze.length();
	checkSum = unknownCharacters + vowels + consonants + digits + spaces;

	//Display the results
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White spaces: " << spaces << endl;
	cout << "Length of string submitted for analysis: " << lengthOfStringSubmittedForAnalysis << endl;
	cout << "Number of characters CodeHunter could not identify: " << unknownCharacters << endl;
	cout << "Checksum: " << checkSum << endl;

	//Test to see if the right number of characters were analyzed
	if (checkSum == lengthOfStringSubmittedForAnalysis)
	{
		cout << "This program self checking has found this Analysis to be valid." << endl;
	}
	else
	{
		cout << "WARNING! *** This program self checking has found this Analysis to be invalid! Do not use this data!" << endl;
	}

	system("pause");

	return 0;
}