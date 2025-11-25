/*
Nico Ramos 
csci159 la5 
grade calculator 
*/

#include <iostream>
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::getline;

// Gets an integer from 3 to 500 loop + error checking
int getNumGrades();

// Gets a single grade 0 to 100using error checking
double getOneGrade(int index);

// Fills the array with validated grade inputs
void fillArray(double arr[], int size);

// Gets how many values to drop (0 to size/2)
int getDropCount(int size);

// Sorts the array in ascending order (bubble sort)
void sortArray(double arr[], int size);

// Prints array elements after skipping drop from each side
void printMiddle(double arr[], int size, int drop);

// Computes average of array elements after skipping
double computeMiddleAverage(double arr[], int size, int drop);

//-------------------------------------------------------------------------

int main()
{
    // welcome message 
    cout << "Welcome to the grade calculator  " << endl;
    cout << endl;

    int numGrades = getNumGrades();

    double grades[500]; 

    //Fill array with validated grade inputs
    fillArray(grades, numGrades);

    //Ask how many values to drop
    int drop = getDropCount(numGrades);

    // Sort the array
    sortArray(grades, numGrades);

    //Print sorted middle values 
    cout << "The sorted grades (other than the ignored ones) are:" << endl;
    cout << endl;
    printMiddle(grades, numGrades, drop);

    double avg = computeMiddleAverage(grades, numGrades, drop);
    
    cout << "the average of those is " << endl;
    cout << fixed << setprecision(2);
    cout << avg << endl;
    cout << endl;
    cout << "Thank you for using grade calculator " << endl; 

    return 0;
    
}

//-------------------------------------------------------------------------

int getNumGrades()
{
    int grade;
    cout << "Enter how many grades you will be entering:  " << endl;
    cin >> grade;

    // while the number is OUTSIDE 3–500
    while (grade < 3 || grade > 500)
    {
        cout << "Invalid input, Try again " << endl;
        cin >> grade;    
    }
   // return the valid number
    return grade;
}

//-------------------------------------------------------------------------

double getOneGrade(int index)
{
    double grade; 
    cout << "Enter a grade  number  " << (index +1) <<endl;
    cin >> grade;

    while ( grade < 0 || grade > 100)
    {
        cout << "Ivalid  grade entered, try again " << endl;
        cin >> grade;
    }
    cout << "You enterd  " << grade << "  " << endl;
    return grade;
}
//-------------------------------------------------------------------------


void fillArray(double arr[], int size)
{
    // loop from 0 to size-1
    for (int i = 0; i < size; i++)
    {
        double gradeNum = getOneGrade(i);
        arr[i] = gradeNum;
    }

}
//-------------------------------------------------------------------------


int getDropCount(int size)
{
    int drop;
    cout << "Enter how many value would you like to drop? " << endl;
    cin >> drop;
    
    while (drop < 0 || drop > size/2)
    {
        cout << "Invalid value, try again " << endl;
        cin >> drop;
    }

    return drop;
}
//-------------------------------------------------------------------------

void sortArray(double arr[], int size)
{
    // bubble sort, 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size -1 -i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                //swap 
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//-------------------------------------------------------------------------


void printMiddle(double arr[], int size, int drop)
{
    // print values from index drop to size-drop-1
    for (int i = drop; i < size - drop; i++)
    {
        cout << arr[i] << endl;
    }
}
//-------------------------------------------------------------------------

double computeMiddleAverage(double arr[], int size, int drop)
{
    double sum = 0, avg = 0;
    int count = 0;
    for (int i = drop; i < size - drop; i++)
    {
        sum += arr[i];
        count++;
    }
    avg = sum/count;
    return avg;
    
}