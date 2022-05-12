// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: May, 11th, 2022
// This program asks the user to enter a two numbers and the operation they'd
// like to perform. After asking, it completes the calculation if the responses
// are valid & displays it to the user.
#include <iostream>
#include <cmath>
#include <iomanip>

// This function calculates the numbers user entered with the corresponding
// operator.
double calculate(char sign, float firstNumber, float secondNumber) {
    float results;
    if (sign == '+') {
        results = firstNumber + secondNumber;
    } else if (sign == '-') {
        results = firstNumber - secondNumber;
    } else if (sign == '/') {
        results = firstNumber / secondNumber;
    } else if (sign == '*') {
        results = firstNumber * secondNumber;
    } else if (sign == '%') {
        results = fmod(firstNumber, secondNumber);
    }
    return results;
}


int main() {
    // declare variables & strings
    float firstNum;
    float secondNum;
    std::string firstNumStr, secondNumStr;
    double userResults;
    char userSign;

    std::cout <<"This program will perform calculations between two numbers.";
    std::cout << std::endl;
    std::cout << std::endl;

    // get user input
    std::cout << "Enter the operation you'd to perform (+, -, *, /, %): ";
    std::cin >> userSign;

    // checks to see if user enters a valid operator
    if (userSign == '+' || userSign == '-' || userSign == '*' \
        || userSign == '/' || userSign == '%') {
            // get user input
            std::cout << "Enter the first number: ";
            std::cin >> firstNumStr;

            try {
                // converts from string to float
                firstNum = std::stof(firstNumStr);

                // gets second input
                std::cout << "Enter the second number: ";
                std::cin >> secondNumStr;
                std::cout << std::endl;

                try {
                    // convert from string to float
                    secondNum = std::stof(secondNumStr);

                    // assigns a variable to a function call, giving it
                    // a returned value.
                    userResults = calculate(userSign, firstNum, secondNum);

                    // display results to user
                    std::cout << "The results of " << firstNum << " ";
                    std::cout << userSign << " " << secondNum;
                    std::cout << " is " << std::fixed << std::setprecision(2);
                    std::cout << userResults << ".";

                // handles any error cases.
                } catch (std::invalid_argument) {
                    std::cout << secondNumStr << " is not a valid number.\n";
                    std::cout << "" << std::endl;
                }

            // handles any error cases
            } catch (std::invalid_argument) {
               std::cout << firstNumStr << " is not a valid number.\n";
               std::cout << "" << std::endl;
            }

    } else {
        std::cout << userSign << " is not a valid operator.";
    }
}
