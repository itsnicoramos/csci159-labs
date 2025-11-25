/*
    Nico Ramos
    csci159 lab5 
  
*/

#include <iostream>
#include <cstring>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::getline;

// exchange the values in the two parameters
void swap(char &c1, char &c2);

// sort the letters in the array by their ascii value (i.e. comparing using <)
// (sorts using a bubblesort)
void sortLetters(char text[]);

// use a linear search to find the first appearance of the target char in the text
// and return its position (returns -1 if the target is never found)
int linearSearch(char text[], char target);

// use a binary search to find an appearance of the target char in the text
// and return its position (returns -1 if the target is never found)
int binarySearch(char text[], char target);

// display the text and summarize the search results
void report(char text[], char target, int pos, bool wasItOrig);


//-----------------------------------------------------------------------
int main()
{    
   // declare a constant for the array size, say 50
   // and declare two character arrays of that size
   const int arrSize = 50;
   char c1[arrSize];
   char c2[arrSize];
   
   //prompt the user to enter a line of text and read it in into the array 
   cout << "Please, enter a text: " << endl; 
   cin.getline(c1, arrSize);
   cout << "c1 contains " << c1 << endl;
   cout << "Please, enter another text: " << endl; 
   cin.getline(c2, arrSize);
   cout << "c2 contains " << c2 << endl;

   //copy content into the second array then passing the second arrray into the sorting func
   strcpy(c1, c2);
   cout << "c1: " << c1 << endl;
   cout << "c2: " << c2 << endl;
   sortLetters(c2);

   // declare two int variables to hold the location where the target character is found,
   // then call linearSearch on the original array and store the returned value in one of
   //    the int variables and call binary search on the sorted array (and store the
   //    returned value in  the  other int variable)
   char target;
   cout << "Enter a character to search for: " << endl;
   cin >> target;

   int userVal1, userVal2;
   userVal1 = linearSearch(c1, target);
   userVal2 = binarySearch(c2, target);
   
    // calling  the report function twice:
   //    once passing the original array, the user char, the found position from linear search,
   //        and true (indicating this is the original),
   //    once passing the sorted array, user char, found position from binary search, false
   report(c1, target, userVal1, true);
   report(c2, target, userVal2, false);
   return 0;
}
//-----------------------------------------------------------------------

void sortLetters(char text[])
{
   // bubblesort will need to know how many characters we have stored,
   //    we can get this using strlen(text)
   int size = strlen(text);
   // our outer loop needs to make N-1 passes for an array holding N chars
   //    our inner loop can go from positions 1 to N-1
   //        at each position it compares the character in the current position
   //           to the character before it, swapping them if they are out of order
   //           (not doing anything if the order is ok)
   for(int i =0; i < size - 1; i++)
   {
      for(int j = 0; j < size - 1 -i; j++)
      {
         if(text[j] > text[j + 1])
         {
            //calling  the swap function
           swap(text[j], text[j + 1]);
         }
      }
   }
}
//-----------------------------------------------------------------------

int linearSearch(char text[], char target)
{
   // search each position from 0 to the end,
   //    we can stop either at strlen(text) or when we reach a position in text
   //       that contains the null terminator, '\0'
   //    at each position check if the character there matches the target,
   //       if so then we found it, return the current position
   // if we get out of the loop it means we never found the target value
   //    so return -1
   for (int pos = 0; pos < (int)strlen(text); pos++)
   {
      if (text[pos] == target)
      {
         return pos; // if found 
      }
   }
   return -1; // not found
}

//-----------------------------------------------------------------------

int binarySearch(char text[], char target)
{
   // set up the bounds for the array section we're searching (initially the whole thing)
   // note that strlen(text) will tell you the position of the last relevant character
   int low = 0;
   int high = strlen(text) -1; 
   int mid;
   // repeat as long as lower is still <= upper:
       // compute the midpoint between lower and upper
       // if the character at the midpoint is less than the target
       //    then set lower to midpoint+1
       // otherwise if the character at the midpoint is greater than the target
       //    then change upper to midpoint-1
       // otherwise we found it, return midpoint
   while (low <= high)
   {
      mid = (low + high)/2; 
      if (text[mid] == target)
      {
         return mid; // found it 
      }
      else if (text[mid] < target) 
      {
         low = mid + 1; //target must be in the upper half of the array 
      }
      else 
      {
         high = mid - 1; // target must be in lower half of the array 
      }
   }
   // after the loop return false (since getting there means we didn't find it)
   return -1; 
}

//-----------------------------------------------------------------------

void report(char text[], char target, int pos, bool wasItOrig)
{
   // display the text, telling the user which it was (original or sorted)
   // cout << text works fine for displaying null-terminated char array content
   cout << "The original content was  " << text << endl;
   // tell them if we found the target or not,
   //    and what position we found it in (if it was found)
   if (wasItOrig)
      {
         cout << "This is the original array. " << endl;
      }
   else if (!wasItOrig)
      {
         cout << "This was the sorted array. " << endl; 
      }
   //check the result separetly 
   if ( pos ==  -1 )
      {
         cout << "The target character  " << target << " was not found" <<endl; 
      }
   else 
      {
         cout << "The target character was found  at " << pos << " " << endl;
      }
   
   cout << endl;
}

//-----------------------------------------------------------------------

void swap(char &c1, char &c2)
{  
   char temp = c1;
   c1 = c2;
   c2 = temp;
}
