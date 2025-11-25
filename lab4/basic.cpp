// Nico Ramos
// Csci 159 lab4 part 1  

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

// set which character to use for yes/no 
const char YES = 'Y';
const char NO = 'N';

// Set maximum number of input characters to clear broken input 
const int AccuracyIteration = 10;

bool skipThis(string section);
float stepOne();
void stepTwo();


int main()
{
    // running  the two steps, giving the user chances to skip either or both 
    if(!skipThis("step one by itself"))
    {
        float positiveNum;
        positiveNum = stepOne();
        cout << "Your number was " << positiveNum << endl;
        cout << "End of step one " << endl;
    }
    if (!skipThis("step two"))
    {
        stepTwo();
    }
    return 0;
}

// -------------------------------------------------------------
bool skipThis(string section)
{
    char skipOrNot;
    bool validAnswer = false; 

    do {
        cout << "Do you want to skip? " << section << " (Y or N)" << endl; 
        cin >> skipOrNot; 
        skipOrNot = toupper(skipOrNot);

        if (skipOrNot == 'y' || skipOrNot == 'Y')
        {
            return true; 
        }
        else if (skipOrNot == 'n' || skipOrNot == 'N')
        {
            validAnswer = true;
        }
        else 
        {
            cerr << "Sorry invalid input, please enter Y or N " << endl; 
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (!validAnswer);

    return false; // getting out of the loop because user say no to skipping 
}
// -------------------------------------------------------------
float stepOne()
{
    float finalNum;
    bool validNumber = false;

    while(!validNumber)
    {
        cout << "Enter a number grater than 1 " << endl;
        cin >> finalNum;

        if (cin.fail())
    {
        cerr << "Invalid input, try again " << endl;
        cin.clear();
        cin.ignore(80, '\n');
    }
    else if (finalNum <= 1 )
    {
        cerr << "The input is less than 1 ";
        cerr << "Try again " << endl; 
        cin.clear();
        cin.ignore(80, '\n');
    }
    else 
    {
        validNumber = true;
    }
    }
    
     return finalNum;
}
// -------------------------------------------------------------
void stepTwo()
{
    float  originalNum ,estimate, square, lowerBound, upperBound;
    int estimateNum;

    // calling  stepOne and store the result in originalNum
    originalNum = stepOne();
    lowerBound = 1;
    upperBound = originalNum;

    for (estimateNum = 1; estimateNum < AccuracyIteration; estimateNum++)
    {

        estimate = (lowerBound + upperBound)/2;
        square = pow(estimate, 2);   

        // check if it close enough to the correct square root then break the loop 
        if (square <= originalNum  + 0.01 && square >= originalNum - 0.01)
        {
            cout << "Close enough, accurate result reach  " << endl;
            break; 
        }

        if (square >= originalNum)
        {
            upperBound = estimate;
        }
        else if (square <= originalNum)
        {
            lowerBound = estimate; 
        }
        else 
        {
            cout << "Exact answer found! " << endl;
        }
        
        cout << "Guess number  " << estimateNum << " and the current estimate " << estimate << endl;

    }

    cout << "Our final estimate was  " << estimate << ", whose square is " << square  << " (target was 12)"<< endl;
}