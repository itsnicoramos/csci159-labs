// Nico Ramos 
// ccsi 159 lab4 part 2 
// Estimating pi by random dart throwing

#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::setprecision;
using std::setw;
using std::fixed;
using std::right;
using std::left;


int getNumDarts();
int throwDarts(int totalThrows);
double generateRandom();
bool didHitCircle(float x, float y);
double estimatePi(int hits, int total);
void displayResult(int hits, int total,  double  piEstimate);
//--------------------------------------------------------------------------

int main()
{
    
   srand(time(NULL)); // initializes the random number generator, done once at start of main
    
   int totalThrows, hits;
   double piEstimate;
   
   totalThrows = getNumDarts();

   hits = throwDarts(totalThrows);

   piEstimate = estimatePi(hits, totalThrows);

   displayResult(hits, totalThrows, piEstimate);

   return 0;
    
}


//--------------------------------------------------------------------------

int getNumDarts()
{
    bool  validInput = false;

    int dart; 
    // keep ask the user until they enter a positive integer 
    //if user enters 0 or negative number or a character string, then return error message 
    // once valid input is received we just return it 
    
    while(!validInput)
    {
        cout << "Enter the desire samole (number of points) as an integer (e.g.217)" << endl;
        cin >> dart;

        if (cin.fail())
        {
            cerr << "Invalid input, Only numbers are allowed ";
            cerr << "Try again " << endl; 
            cin.clear();
            cin.ignore(80, '\n');
        }
        else if ( dart <= 0)
        {
            cerr << "Invalid input, only numbers that is positive ";
            cerr << "Try again " << endl; 
            cin.clear();
            cin.ignore(80, '\n');
        }
        else 
        {
            validInput = true; 
        }
    }

    return dart; 

}

//--------------------------------------------------------------------------

// handles the simulation logic
// loops from 1 to totalThrows
// calls a helper to generate random x, y
// calls another helper to check if the dart hit the circle
// returns the count of darts that hit inside

int throwDarts(int totalThrows)
{
    int hits = 0;

    for (int dart = 1; dart <= totalThrows; dart++  )
    {
        float x, y;

        x = generateRandom();
        y = generateRandom();
        didHitCircle(x, y);
        if (didHitCircle(x, y))
        {
            hits++;  
        }
    }
    return hits; 
}

//--------------------------------------------------------------------------

double generateRandom ()
{
    double randomValue = static_cast<double>(rand()) / RAND_MAX; 
    randomValue = randomValue * 2 -1;

    return randomValue;
   
}

//--------------------------------------------------------------------------

// calculates distance from center using sqrt(x*x + y*y)
// returns true if distance <= 1, otherwise false

bool didHitCircle(float x, float y)
{
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    if (distance <= 1 )
    {
        return true;
    }
    else 
    {
        return false; 
    }
}
//--------------------------------------------------------------------------

// calculates the final value of pi = 4.0 * hits / total
// returns the  estimate
double estimatePi(int hits, int total)
{
    double pi = 4.0 * static_cast<double>(hits)/total; // converting both hits and total as integer -> to a  double before division 
    return pi;
}

//--------------------------------------------------------------------------

void displayResult(int hits, int total, double piEstimate)
{
    const int LabelWidth = 25;
    const int ValueWidth = 10;

    cout << fixed << setprecision(5);
    cout << "\n-------------------------------------------" << endl;
    cout << "Pi Simulation Results:\n" << endl;

    cout << setw(LabelWidth) << left << "Total darts thrown:" 
         << setw(ValueWidth) << right << total << endl;
    cout << setw(LabelWidth) << left << "Darts landed in circle:" 
         << setw(ValueWidth) << right << hits << endl;
    cout << setw(LabelWidth) << left << "Estimated value of Pi:" 
         << setw(ValueWidth) << right << piEstimate << endl;
    
    cout << "-------------------------------------------\n" << endl;

}
