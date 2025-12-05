/*
   Nico Ramos
   csci 159 lab6

*/

#include <iostream>
#include <string>
#include <cctype>

// list of elements used from iostream and string libraries
using std::string;
using std::cout;
using std::getline;
using std::cin;
using std::cerr;
using std::endl;

// ====================================================================================
// ========== package definition and function prototypes ==============================
// ====================================================================================

// datatype describing a package for delivery
struct Package {
   string sender; // name of sender
   string recipient; // name of receiver
   string content; // description of package contents
   string address; // full address of receiver
   float value; // estimated value of contents
};

// fill package p with user-supplied data
void fillPkg(Package &p);

// display package p's information
void printPkg(Package p);

// ====================================================================================
// ========== queue definition and function prototypes ================================
// ====================================================================================

// maximum number of packages we can be processing at once
const int MaxPackages = 4;

// datatype describing a queue of packages, implemented as a circular buffer
// (an array with tracked front and back positions, with the potential for front
//   and back to 'wrap-around' as items are inserted and removed over time)
struct Queue {
    Package pkgArray[MaxPackages]; // actual array of packages
    int front; // position of front package in queue (-1 if empty)
    int back; // position of back package in queue (-1 if empty)
    int size; // number of elements currently in the queue (0 if empty)
};

// initialize a package queue (as empty)
void initQ(Queue &q);

// looks up and returns the number of elements currently in queue q
int getSizeQ(Queue q);

// adds new package to the back of queue q, copying its values from p
// returns true if successful, false otherwise
//    (can fail if the queue is full)
bool insertQ(Package p, Queue &q);

// removes front package from queue q, copies data into p
// returns true if successful, false otherwise
//    (can fail if the queue is empty)
bool removeQ(Package &p, Queue &q);

// displays the information about each package in the queue
void printQ(Queue q);

// ====================================================================================
// ========== command-handling definitions and function prototypes ====================
// ====================================================================================

// constants representing the valid package commands
const char Help = 'H';   // command for displaying help menu
const char Quit = 'Q';   // command for quitting the program
const char Insert = 'I'; // command to get package info from the user and insert into the queue
const char Remove = 'R'; // command to remove a package from the queue and display its info
const char Size = 'S';   // command to display the current number of packages in the queue
const char Print = 'P';  // command to print the information for all packages in the queue
                         // (starting from front of queue and continuing to the back)
const char Error = 'E';  // used to represent any invalid commands

// display the available processing commands
void commandHelp();

// get a valid package command from the user
// (repeats until a valid command is provided)
char getCommand();

// command to process a command, applying it to the given queue
void processCommand(char command, Queue &Q);

// ====================================================================================
// ========== main routine ==========================================================
// ====================================================================================
int main()
{
   // set up a queue of packages
   Queue pkgs;
   initQ(pkgs);

   // introduce the user to the program and display the instructions
   cout << "\nWelcome to the package processor!\n";
   commandHelp();

   // keep processing commands until the user decides to quit
   char command;
   do {
      command = getCommand();
      processCommand(command, pkgs);
   } while (command != Quit);

   return 0;
}

// ====================================================================================
// ========== command-handling function implementations ===============================
// ====================================================================================

// display the available processing commands
void commandHelp()
{
   cout << "The available commands are:" << endl;
   cout << "   " << Help  << " to display this help menu" << endl;
   cout << "   " << Quit  << " to exit the program" << endl;
   cout << "   " << Insert << " to add a new package to the back of the queue" << endl;
   cout << "   " << Remove << " to remove and display the front queue package" << endl;
   cout << "   " << Size  << " to see the number of packages currently queued" << endl;
   cout << "   " << Print << " to show each of the packages currently queued" << endl;
}

// get a valid package command from the user
// (repeats until a valid command is provided)
char getCommand()
{
   char cmd = 'E';
   cout << "\nEnter a command (";
   cout << Help << Quit << Insert << Remove << Size << Print << "): ";
   cin >> cmd;
   cmd = toupper(cmd); // convert to uppercase for simpler comparisons
   switch (cmd) {
      case Help:
      case Quit:
      case Insert:
      case Remove:
      case Size:
      case Print:
         return cmd;
      default:
         cerr << "Error: " << cmd << " is not a valid option, please try again" << endl;
         cmd = getCommand();
   }
   return cmd;
}

// command to process a command, applying it to the given queue
void processCommand(char command, Queue &Q)
{
   Package pkg; // used by insert and remove
   switch (command) {
      case Help:
         commandHelp();
         break;

      case Quit:
         cout << "\nBye!\n" << endl;
         break;

      case Size:
         cout << "The current number of queued packages is " << getSizeQ(Q) << endl;
         break;

      case Print:
         printQ(Q);
         break;

      case Insert:
         fillPkg(pkg);
         if (insertQ(pkg, Q)) {
            cout << "Insertion successful" << endl;
         } else {
            cout << "Insertion failure for package:" << endl;
            printPkg(pkg);
         }
         break;

      case Remove:
         if (removeQ(pkg, Q)) {
            cout << "Successful removal of package:" << endl;
            printPkg(pkg);
         } else {
            cout << "Removal failure" << endl;
         }
         break;

      default:
         cerr << "Error: an invalid command reached processCommand\n";
         cerr << "   please notify the devs that their code is broken\n";
         break;
   }
}


// ====================================================================================
// ========== package function implementations ======================================
// ====================================================================================

// get and return a package dollar value
// (repeat until valid amount provided)
float getValue()
{
   const int SkipChars = 80; // chars to ignore on bad input
   const char Eoln = '\n'; // assumed end-of-input character for skipping

   float value; // cash value of package's contents
   cout << "Enter content dollar value, e.g. 20.99: ";
   cin >> value;
   if (cin.fail()) {
      // garbage input, clear from input buffer before trying again
      cin.clear();
      cin.ignore(SkipChars,Eoln);
      cerr << "Error: that was not a numeric value, please try again" << endl;
      value = getValue();
   } else if (value < 0) {
      // negative values not accepted
      cerr << "Error: the value cannot be negative, please try again" << endl;
      value = getValue();
   }
   return value;
}

// fill package p with user-supplied data
void fillPkg(Package &p)
{
   const int SkipChars = 80; 
   const char Eoln = '\n'; 
   cin.ignore(SkipChars, Eoln);

   cout << "Enter sender: ";
   getline(cin, p.sender);

   while (p.sender.length() == 0 )
   {
      cout << "Enter sender: ";
      getline(cin, p.sender);
   }   
}

// display package p's information
void printPkg(Package p)
{
   cout << "Package details " << endl;
   cout << "Sender: " << p.sender << endl;
   cout << "Recipient: " << p.recipient << endl;
   cout << "Content: " << p.content << endl;
   cout << "Address: " << p.address << endl; 
   cout << "Value:  " << p.value << endl; 
}


// ====================================================================================
// ========== queue function implementations ========================================
// ====================================================================================

// initialize a package queue (as empty)
void initQ(Queue &q)
{
   // here using -1 as defaults for front and back whenever the queue is empty
   q.front = -1;
   q.back = -1;
   q.size = 0;
}

// looks up and returns the number of elements currently in queue q
int getSizeQ(Queue q)
{
   return q.size;
}

// adds new package to the back of queue q, copying its values from p
// returns true if successful, false otherwise
//    (can fail if the queue is full)
bool insertQ(Package p, Queue &q)
{
   if (q.size >= MaxPackages)
   {
      cout << "The package is full, try again " << endl;
      return false;
   }
   else if (q.size == 0)
   {
      q.front = 0;
      q.back = 0;
      q.size = 1;
      q.pkgArray[0] = p;
   }
   else
   {
      q.back++;

      if (q.back >= MaxPackages)
      {
         q.back = 0;   // wrap-around
      }

      q.size++;
      q.pkgArray[q.back] = p;
   }
   return true;
}

// removes front package from queue q, copies data into p
// returns true if successful, false otherwise
//    (can fail if the queue is empty)
bool removeQ(Package &p, Queue &q)
{
   if (q.size == 0)
   {
      cout << "Can't remove from an empty queue, try again " << endl;
      return false;
   }
   else if (q.size == 1)
   {
      p = q.pkgArray[q.front];   // copy OUT of queue
      q.size = 0;
      q.front = -1;
      q.back = -1;
   }
   else
   {
      p = q.pkgArray[q.front];   // get element
      q.front++;                 // move front forward

      if (q.front >= MaxPackages)
      {
         q.front = 0;            // wrap-around
      }

      q.size--;                  // shrink queue
   }

   return true;
}

// displays the information about each package in the queue
void printQ(Queue q)
{
   if (q.size == 0)
   {
      cout << "The queue is empty" << endl;
      return;
   }

   int pos = q.front;

   while (pos != q.back)
   {
      printPkg(q.pkgArray[pos]);
      pos++;

      if (pos >= MaxPackages)
      {
         pos = 0;
      }
   }

   // print last element
   printPkg(q.pkgArray[q.back]);
}