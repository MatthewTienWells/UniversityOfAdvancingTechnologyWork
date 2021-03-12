#pragma once
#include<iostream>
#include<string>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::exception;

struct FileNotFoundException : public exception //Custom exception for when program attempts to read from a nonexistent file
{
   const char* what() const throw () {
      return "File does not exist";
   }
};

struct FilePermissionsMissingException : public exception //Custom exception for when program attempts to create a file but fails
{
    const char* what() const throw () {
        return "File could not be generated. Directory missing or you lack permissions.";
    }
};

struct FileStreamCorruptedException : public exception //Custom exception for when an active file stream is corrupted or closed unexpectedly
{
    const char* what() const throw () {
        return "File stream has been corrupted. Data may have been lost.";
    }
};

struct InvalidUserInputException : public exception //Custom exception for when the user gives malformed input at a prompt
{
    const char* what() const throw () {
        return "Provided input does not match specified parameters.";
    }
};