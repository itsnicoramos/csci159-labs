/*
    Nico Ramos
    CSCI 159  Lab 6
*/

#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

// specify the maximum number of circles the program is capable of handling
const int maxCircle = 20;

struct Circle  {
    double x, y;   // center coordinates
    double rad;    // radius > 0
};


int getNumCircs(int max);
double getNumber(string promptInfo, bool mustBePositive = false);
void fill(Circle& c);
void fillAll(Circle circs[], int num);
bool overlap(Circle c1, Circle c2);
void print(Circle c);
void printOverlaps(Circle circs[], int numCircs);

//-----------------------------------------------------------------------------------------
// Main routine
//-----------------------------------------------------------------------------------------
int main()
{
    Circle circles[maxCircle];

    int numberCircles = getNumCircs(maxCircle);

    fillAll(circles, numberCircles);

    printOverlaps(circles, numberCircles);

    return 0;
}

//-----------------------------------------------------------------------------------------
// get a valid number of circles 1..max
int getNumCircs(int max)
{
    const int LineLen = 80;
    const char Eoln = '\n';

    int numCs;
    cout << "Please enter the desired number of circles, 1.. " << max << endl;
    cin >> numCs;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(LineLen, Eoln);
        cerr << "The value must be an integer, please try again." << endl;
        numCs = getNumCircs(max);
    }
    else if (numCs < 1 || numCs > max)
    {
        cerr << "The value must be in the range 1.. " << max << ", please try again." << endl;
        numCs = getNumCircs(max);
    }

    return numCs;
}

//-----------------------------------------------------------------------------------------
// get a real number, optionally enforcing positivity
double getNumber(string promptInfo, bool mustBePositive)
{
    const int LineLen = 80;
    const char Eoln = '\n';

    cout << "Please enter a number";
    if (mustBePositive)
        cout << " greater than zero";
    cout << " for the " << promptInfo << ": ";

    double num;
    cin >> num;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(LineLen, Eoln);
        cerr << "The value must be a number, please try again." << endl;
        num = getNumber(promptInfo, mustBePositive);
    }
    else if (mustBePositive && num <= 0)
    {
        cerr << "The value must be greater than zero, please try again." << endl;
        num = getNumber(promptInfo, mustBePositive);
    }

    return num;
}

//-----------------------------------------------------------------------------------------
// fill a single circle
void fill(Circle& c)
{
    c.x = getNumber("x coordinate");
    c.y = getNumber("y coordinate");
    c.rad = getNumber("radius", true);
}

//-----------------------------------------------------------------------------------------
// fill all circles
void fillAll(Circle circs[], int num)
{
    for (int pos = 0; pos < num; pos++)
    {
        fill(circs[pos]);
    }
}

//-----------------------------------------------------------------------------------------
// check if two circles overlap
bool overlap(Circle c1, Circle c2)
{
    double xdist = c1.x - c2.x;
    double ydist = c1.y - c2.y;
    double distance = sqrt(xdist * xdist + ydist * ydist);

    // if the distance between centers is greater than sum of radii  no overlap
    if (distance > (c1.rad + c2.rad))
        return false;

    return true;
}

//-----------------------------------------------------------------------------------------
// print a single circle
void print(Circle c)
{
    cout << " (" << c.x << ", " << c.y << ": " << c.rad << ") ";
}

//-----------------------------------------------------------------------------------------
// print all overlapping circle pairs
void printOverlaps(Circle circs[], int numCircs)
{
    int count = 0;

    for (int c1 = 0; c1 < numCircs - 1; c1++)
    {
        for (int c2 = c1 + 1; c2 < numCircs; c2++)
        {
            if (overlap(circs[c1], circs[c2]))
            {
                cout << "Circles ";
                print(circs[c1]);
                cout << "and";
                print(circs[c2]);
                cout << "overlap." << endl;
                count++;
            }
        }
    }

    if (count == 0)
    {
        cout << "No overlapping circles found." << endl;
    }
}