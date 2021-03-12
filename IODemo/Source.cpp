#include "Header.h"

class Journal //Class that will hold all our file IO functionality
{
private:
	string defaultFileName = "IODemoDefault.txt"; //Placeholder name for the journal file- this is used if a name is not specified
	string currentFileName = defaultFileName; //Name of the journal file

	ofstream OpenFileW() //Opens the current journal file in append mode.
	{
		try
		{
			ofstream outfile(currentFileName, std::ios_base::app); //Create an out file stream in append mode
			if (outfile.is_open()) //Test to ensure the stream is open
			{
				return outfile; //If test passes, return the stream object
			}
			else //If test fails
			{
				throw FilePermissionsMissingException(); //Throw a permission missing exception
			}
		}
		catch (FilePermissionsMissingException e) //If a permission missing exception occurs
		{
			throw e; //Escalate permission missing exceptions
		}
	}

	ofstream OpenFileW(string filename) //Create an out file stream with name FILENAME in append mode
	{
		try
			{
				ofstream outfile(filename, std::ios_base::app); //Create an out file stream with name FILENAME in append mode
				if (outfile.is_open()) //Test if stream is open
				{
					currentFileName = filename; //Set current journal file to opened file 
					return outfile; //Return file stream object
				}
				else //If stream is not open
				{
					throw FilePermissionsMissingException(); //Throw a permission missing exception
				}
			}
		catch (FilePermissionsMissingException e) //If a permission missing exception occurs
		{
			throw e; //Escalate permission missing exceptions
		}	
	}

	ifstream OpenFileR() //Open current journal file in read mode
	{
		try
		{
			ifstream infile(currentFileName); //Create an input file stream object with the current journal file
			if (infile.is_open()) //Test to ensure stream is open
			{
				return infile; //Return file stream object
			}
			else //If stream does not open
			{
				throw FileNotFoundException(); //Throw a file not found exception
			}
		}
		catch (FileNotFoundException e) //If a file not found exception is caught
		{
			throw e; //Raise file not found exceptions
		}
	}

	ifstream OpenFileR(string filename) //Open file FILENAME in read mode
	{
		try
		{
			ifstream infile(filename); //Create an input file stream object with file FILENAME
			if (infile.is_open()) //Test to ensure the file exists and is open
			{
				currentFileName = filename; //Set current journal file to FILENAME
				return infile; //Return input stream object
			}
			else //If file could not be opened
			{
				throw FileNotFoundException(); //Raise a file not found exception
			}
		}
		catch (FileNotFoundException e) //If a file not found exception occurs
		{
			throw e; //Raise file not found exception
		}
	}

	void WriteToFile(string data, string fileToWrite) //Write to a file with name FILETOWRITE
	{
		try
		{
			ofstream outfile = OpenFileW(fileToWrite); //Open the file with the given name, or open a new file if no such file exists
			outfile << data; //Save the provided data to the file
			outfile.close(); //Close the file
		}
		catch (FilePermissionsMissingException e) //If a file permission error occurs
		{
			cerr << e.what(); //Display an error message
		}
	}

	void WriteToFile(string data) //Write to the currently selected journal file
	{
		try
		{
			ofstream outfile = OpenFileW(); //Open the current journal file
			outfile << data; //Save provided data to the journal file
			outfile.close(); //Close the file stream
		}
		catch (FilePermissionsMissingException e) //If a file permission error occurs
		{
			cerr << e.what(); //Display an error message
		}
	}


	void ReadFromFile() //Read the current journal file and output to the console
	{
		try
		{
			ifstream infile = OpenFileR(); //Open the current journal file
			string fromFile; //This string will store data read from the file
			try
			{
				while (getline(infile, fromFile)) //Iterate through each line of the file
				{
					cout << fromFile << endl; //Print the line to the console
					if (infile.bad()) //Test if the stream becomes corrupted
					{
						throw FileStreamCorruptedException(); //Throw a stream corruption error
					}
				}
				infile.close(); //Close the file stream
			}
			catch (FileStreamCorruptedException e) //If a stream corruption error occurs
			{
				cerr << e.what() << endl; //Display an error message
			}
		}
		catch (FileNotFoundException e) //If a file not found error occurs
		{
			cerr << e.what() << endl; //Display an error message
		}
	}

	void ReadFromFile(string filename) //Read a file with name FILENAME and output it to the console
	{
		try
		{
			ifstream infile = OpenFileR(filename); //Open the file FILENAME in read mode
			string fromFile; //This string will hold data from the file
			try
			{
				while (getline(infile, fromFile)) //Iterate through each line in the file
				{
					cout << fromFile << endl; //Output the line to the console
					if (infile.bad()) //Test if the stream becomes corrupted
					{
						throw FileStreamCorruptedException(); //Throw a stream corruption error
					}
				}
				infile.close(); //Close the file stream
			}
			catch (FileStreamCorruptedException e) //If a stream corruption error is raised
			{
				cerr << e.what() << endl; //Display an error message
			}
		}
		catch (FileNotFoundException e) //If a file not found exception is raised 
		{
			cerr << e.what() << endl; //Display an error message
		}
	}

public:
	void IOInterface() //Interface method. When called, this opens up an interface to the journal in the console.
	{
		int linebreaks = 0; //Number of linebreaks entered to the console
		string choice; //The user's most recent input
		string filename; //The file that the user wishes to modify if not using the current file
		cout << "Welcome, user." << endl; //Display intro
		while (choice != "end") //Loop until the user gives the end program command
		{
			try
			{
				cout << "Would you like to read, write, or end program?" << endl; //Display choices to console
				cout << ">";
				cin >> choice; //Get user input
				if (choice == "write") //If the user chose to write
				{
					cout << "Use a new file? y/n" << endl; //Ask if the user wants a new journal file
					cout << ">";
					cin >> choice; //Get user input
					if (choice != "y" && choice != "n") //If the user did not enter 'y' or 'n'
					{
						throw InvalidUserInputException(); //Raise an invalid input exception
					}
					if (choice == "y") //If the user wants to use a new file
					{
						cout << "Enter file location, user." << endl; //Prompt the user for a filename
						cout << ">";
						cin >> filename; //Get user input
						cout << "Enter your data, then press the enter key three times to let me know you're done." << endl; //Prompt the user to enter data
						linebreaks = 0; //Reset the number of linebreaks
						while (linebreaks < 3) //Loop until the user enters three linebreaks consecutively
						{
							getline(cin, choice); //Get a line of input from the console
							if (choice == "") //If the input line was empty
							{
								linebreaks += 1; //Record a line break
							}
							else
							{
								choice = choice + "\n"; //Add a linebreak to the end of the user input
								while (linebreaks > 0) //For each empty line recorded prior to the current line
								{
									WriteToFile("\n", filename); //Write an empty line to the file
									linebreaks -= 1; //Reduce the linebreak count by 1
								}
								WriteToFile(choice, filename); //Write the user input to the file
							}
						}
					}
					if (choice == "n") //IF the user wishes to use the current journal file
					{
						cout << "Enter your data, then press the enter key three times to let me know you're done." << endl; //Prompt the user to enter data
						linebreaks = 0; //Reset the number of linebreaks
						while (linebreaks < 3) //Loop until the user enters three linebreaks consecutively
						{
							getline(cin, choice); //Get a line of input from the console
							if (choice == "") //If the input line was empty
							{
								linebreaks += 1; //Record a line break
							}
							else
							{
								choice = choice + "\n"; //Add a linebreak to the end of the user input
								while (linebreaks > 0) //For each empty line recorded prior to the current line
								{
									WriteToFile("\n"); //Write an empty line to the file
									linebreaks -= 1; //Reduce the linebreak count by 1
								}
								WriteToFile(choice); //Write the user input to the file
							}
						}
					}
				}
				else if (choice == "read") //If the user wishes to read from a file
				{
					cout << "Would you like to read from a different file than the current one, user? y/n" << endl; //Ask the user if they want to change files
					cout << ">";
					cin >> choice; //Get user input
					if (choice != "y" && choice != "n") //If the user gives input other than 'y' or 'n'
					{
						throw InvalidUserInputException(); //Throw a user input error
					}
					if (choice == "y") //If the user wishes to use a new file
					{
						cout << "Enter file location, user." << endl; //Prompts the user for a filename
						cout << ">";
						cin >> choice; //Gets user input
						cout << "Loading data now..." << endl; //Confirms user input
						cout << endl;
						ReadFromFile(choice); //Prints contents of file to console
						cout << endl;
					}
					if (choice == "n") //If the user wishes to use the current journal file
					{
						cout << "Loading data..." << endl; //Confirms user input
						cout << endl;
						ReadFromFile(); //Prints contents of file to console
						cout << endl;
					}
				}
				else if (choice == "end") //If the user chooses to end program
				{
					cout << "Goodbye, user. Thank you for using this journal software." << endl; //Says goodbye to user
				}
				else //If unexpected input is provided
				{
					throw InvalidUserInputException();
				}
			}
			catch (InvalidUserInputException) //If invalid input error was raised
			{
				cout << "User, you have to type your choices exactly as I say them! I can't understand you if you aren't specific!" << endl; //Chastises user
			}
		}
	}
};

int main() //Main function, runs when program is called
{
	Journal assistant = Journal(); //Create a new journal object
	assistant.IOInterface(); //Trigger the journal's interface
	return 0;
}