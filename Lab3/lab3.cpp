//Nico Ramos
//csci 159 lab 3  part 2 


#include <iostream>
#include <string>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setprecision;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::cerr;

int  getValidCalls(string employeeName);
int getValidMissedCalls();
double calculateHours(double calls , double totalCalls);
void displayResult(string employee1, string employee2, string employee3, double hours1, double hours2, double hours3, double hoursUnanswered);

int main()
{
	//Displaying the welcome message
	
	cout << "Welcome to EvelKall monitoring!" << endl;
	cout << "We estimate your staff's working hours based on the result of weekly call sample. " <<endl;
	cout << "At  the moment assume you have 3 staff members, and round the result to the nearest 0.1 hours. " << endl;
	
	string employee1, employee2, employee3;
	cout <<"Please enter the first name of the first employee: " << endl;
	cin >> employee1;
	cout << employee1 << endl;
	cout <<"Please enter the second name of the second employee: " << endl;
	cin >> employee2;
	cout << employee2 << endl;
	cout <<"Please enter the third name of the third employee: " << endl;
	cin >> employee3;
	cout << employee3 << endl;
	
	int numCalls1 = getValidCalls(employee1);
	int numCalls2 = getValidCalls(employee2);
	int numCalls3 = getValidCalls(employee3);

	cout << "Enter how many did: " << employee1 << " answer? " << numCalls1 << endl;
	cin >> numCalls1;

	cout << "Enter how many did: " << employee2 << " answser? " << numCalls2 << endl;
	cin >> numCalls2;

	cout << "Enter how many did: " << employee3 << " answer? " << numCalls3 <<endl;
	cin >> numCalls3;

	int unanswered = getValidMissedCalls();
	
	double  totalCalls = numCalls1 + numCalls2 + numCalls3 + unanswered;
	double hours1 = calculateHours(numCalls1, totalCalls);
    double hours2 = calculateHours(numCalls2, totalCalls);
    double hours3 = calculateHours(numCalls3, totalCalls);
    double hoursUnanswered = calculateHours(unanswered, totalCalls);
	
    displayResult(employee1,employee2,employee3, hours1, hours2,hours3, hoursUnanswered);

	return 0;
	
}

int  getValidCalls(string employeeName)
{
	int numCalls;

	cout << "Enter how many calls the employee answered: " << endl;
	cin >> numCalls;

	if (cin.fail())
	{
		cerr << "Sorry, your input is an invalid input. Please try again" << endl;
		cin.clear();
		cin.ignore(80, '\n');
		getValidCalls(employeeName);
	} 
	
	return numCalls;
	
}

int getValidMissedCalls()
{
	int missedCall;
	cout << "Enter how many calls are unanswered: " << endl;
	cin >> missedCall;

	if (cin.fail())
	{
		cerr << "Sorry, you entered an invalid input. Please try again" << endl;
		cin.clear();
		cin.ignore(80, '\n');
		getValidMissedCalls();
	}

	return missedCall;
}

double calculateHours(double calls, double totalCalls)
{
    double hours = (calls / totalCalls) *168;
    return hours;
}

void displayResult(string employee1, string employee2, string employee3, double hours1, double hours2, double hours3, double hoursUnanswered)
{
    cout << "Based on the information you provided, here is the following results: " << endl;
	cout << endl;
	cout << "Estimated weekly hours: " << endl; 
	cout << fixed << setprecision(1);
	cout << setw(12) << left << employee1 << setw(10) << right << hours1 << endl;
	cout << setw(12) << left << employee2 << setw(10) << right << hours2 << endl;
	cout << setw(12) << left << employee3 << setw(10) << right << hours3 << endl;
	cout << setw(12) << left << "Unansered" << setw(10) << right << hoursUnanswered << endl;
	cout << endl;
	cout << "Thanks for using EvelKall Monitoring!" << endl;
	
}
