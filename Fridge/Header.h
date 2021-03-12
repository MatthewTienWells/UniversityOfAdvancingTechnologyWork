#pragma once

#include<iostream>
#include<random>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;
using std::make_unique;
using std::vector;
using std::exception;
using std::move;
using std::cerr;
using std::to_string;

struct BadChoiceException : public exception //Custom exception for when the user gives malformed input at a prompt
{
    const char* what() const throw () {
        return "Sorry, not one of the choices.";
    }
};

struct AteTooMuchException : public exception //Custom exception for when the user consumes all the food of a type
{
    const char* what() const throw () {
        return "You've had enough of that, you can't stand any more.";
    }
};