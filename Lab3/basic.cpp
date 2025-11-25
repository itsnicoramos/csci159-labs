//Nico Ramos 
//csci159 lab3 part 1

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;


void stepOne();
void stepTwo();
void stepThree();

int main()
{
    stepOne();
    stepTwo();
    stepThree();

    return 0;
}

void stepOne()
{
	//get the user's score 
	float score;
	cout << "Enter a test score from 0-100" << endl;
	cin >> score;
	//check if fail 
	if ( score < 49.5)
	{
		cout << "Sorry, but is an F grade " << endl;
	}
	//check for A+
	else if (score >= 89.5)
	{
		cout << "Congrats, that is an A+ grade" << endl;
	}
	//give a message for anything in between 
	else 
	{
		cout << "That was somewhere in D to A range" << endl;
	}
}

void stepTwo()
{
	//get a positive number greater than 0 from the user
	float posNum;
	cout << "Enter a number greater than 0 e.g. 17.123: ";
	cin >> posNum;
	cout << "You entered " << posNum << endl; 
	// check for non-numeric input causing cin to fail 
	if (cin.fail())
	{
		cerr <<"Sorry, only numeric input is accepted, please try again" << endl;
		cin.clear(); //clean up the internal error 
		cin.ignore(80, '\n'); //clean out the garbage text in the input buffer
		cin >> posNum;
	}
	//otherwise i.e. if didn't fail, we can check if the value was too small 
	else if (posNum <= 0)
	{
		cerr << "Sorry, your value (" << posNum << ") was not greater than 0";
		cerr << "Please try again" << endl;
		cin >> posNum;
	}
	//echo their response back to them 
	cout << "You entered " <<posNum <<endl;
}

void  stepThree()
{
	//get an integer in the range from 1-100
	int score;
	cout << "Please enter an integer in the range 1-100: ";
	cin >> score;

	//check for non-integer input cin to fail 
	if(cin.fail())
	{
		cerr << "Sorry, only integer input is accepted, plese try again" << endl;
		cin.clear(); 
		cin.ignore(80, '\n'); //clean the garbage text in input buffer 
		stepThree(); //start a new run  of the function to try again 
	}
	//otherwise, i.e. if cin didn't fail, we can check  if  the value was too small 

	else if (score < 1 )
	{
		cerr << "Sorry, your value (" << score << ") was smaller than 1.";
		cerr << "Please try again" << endl;
		stepThree();
	}
	// otherwise we can check of too big 

	else if ( score > 100)
	{
		cerr << "Your value (" << score << ") was bigger than 100.";
		cerr << "Please try again" << endl;
		stepThree(); 
	}
	//otherwise echo their response back to them 
	else
	{
		cout<<"You selected a valid value: " << score << endl;
	}
	
	
}
