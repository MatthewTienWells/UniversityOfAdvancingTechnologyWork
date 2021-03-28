#pragma once

#include<iostream>
#include<string>
#include<thread>
#include<vector>
#include<random>
#include<chrono>
#include<fstream>
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::thread;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::find;
using std::tuple;
using std::for_each;
using std::get;
using std::exception;
using std::ifstream;
using std::stringstream;
using std::stoi;

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

struct InvalidUserInputException : public exception //Custom exception for when the user gives malformed input at a prompt
{
    const char* what() const throw () {
        return "Provided input does not match specified parameters.";
    }
};