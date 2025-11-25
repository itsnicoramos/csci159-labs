//Nico Ramos
//csci159 lab 2 part 1 

#include <iostream>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;


// Function prototype for step 6 

double rootOfSumSquares(double x, double y);


int main()
{
	//This is the code section for step 1 
	
	int numerator, denominator, quotient, remainder;
	
	cout << "Enter a fist integer value: ";
	cin >> numerator;
	cout << "Enter a second integer value: ";
	cin >> denominator;

	
	 quotient = numerator / denominator;
	 remainder = numerator % denominator;

	cout << "numerator = " << numerator << ", denominator = " << denominator << ", quotient = " << quotient <<", remainder = " << remainder << endl;
	
	//This is the code section for step 2 
	
	cout << "The maximum value for int: " << INT_MAX  << endl;
	cout << "The maximum value for float: " << FLT_MAX << endl;
	cout << "The maximum value for int + 1 " << INT_MAX << endl;
	cout <<	"The maximm value for float * 2 " << FLT_MAX << endl;

	//This is the code section for step 3 
	
	char userInitial;
	char testChar;
	testChar = '!';

	cout << "Enter user initial: " << endl;
    cin >> userInitial;
	cout << "userInitial is " << userInitial << endl;
	cout << testChar << endl;

	//This is the code section for step 4 
	
	const int ColWidth = 15;

	cout << setw(ColWidth) << numerator << endl;
	cout << setw(ColWidth) << denominator << endl;
	cout << setw(ColWidth) << userInitial << endl;
	cout << setw(ColWidth) <<  testChar  << endl;
	
	//This is the code for step 5 
	
	cout << setprecision(5);

	const double Pi = 3.1415;
	double third = 1/3.0;

	cout << Pi << endl;
	cout << third << endl;

	//Calling the function prototype for step 6 
	
	double xVal, yVal;
	double answer;

	cout << "Enter two numeric values: " << endl;
	cin >> xVal >> yVal;

	answer = rootOfSumSquares(xVal, yVal);

	cout << "For inputs " << xVal << " and " << yVal;

	cout << ", the root of the sum of their squares is ";

	cout << answer <<endl;
	

	return 0;
}


// Full version of the function for step 6

double rootOfSumSquares(double x, double y)
{
	double sumSqs;
	double root;
	sumSqs = x*x + y*y;
	root = sqrt(sumSqs);
	return root;
}
