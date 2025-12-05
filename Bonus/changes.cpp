/*
   Nico Ramos 
   csci159 bonus lab 

*/

#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;

// ====================================================================================
// ========== package definition and function prototypes ==============================
// ====================================================================================

struct Package {
   string sender;
   string recipient;
   string content;
   string address;
   float value;
};

// note that p is now a pointer to a package
void fillPkg(Package *p);

// note that p is now a pointer to a package
void printPkg(Package *p);

// ====================================================================================
// ========== queue definition and function prototypes ================================
// ====================================================================================

const int MaxPackages = 4;

struct Queue {
    Package* pkgArray[MaxPackages]; // now this is an array of pointers for packages
    int front;
    int back;
    int size;
};

void initQ(Queue &q);

int getSizeQ(Queue q);

// note the package parameter is now a pointer to a package
bool insertQ(Package *p, Queue &q);

// note the package parameter is now a pointer, passed by reference
bool removeQ(Package* &p, Queue &q);

void printQ(Queue q);

// ====================================================================================
// ========== command-handling definitions and function prototypes ====================
// ====================================================================================

const char Help = 'H';
const char Quit = 'Q';
const char Insert = 'I';
const char Remove = 'R';
const char Size = 'S';
const char Print = 'P';
const char Error = 'E';

void commandHelp();

char getCommand();

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

void processCommand(char command, Queue &Q)
{
   Package *pkg = nullptr; 
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
         pkg = new Package;
         fillPkg(pkg);
         if (insertQ(pkg, Q)) {
            cout << "Insertion successful" << endl;
         } else {
            cout << "Insertion failure for package:" << endl;
            printPkg(pkg);
            delete pkg;
         }
         break;

      case Remove:
         if (removeQ(pkg, Q)) {
            cout << "Successful removal of package:" << endl;
            printPkg(pkg);
            delete pkg;
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

float getValue()
{
   const int SkipChars = 80; // chars to ignore on bad input
   const char Eoln = '\n'; // assumed end-of-input character for skipping

   float value; // cash value of package's contents
   cout << "Enter content dollar value, e.g. 20.99: ";
   cin >> value;
   if (cin.fail()) {
     
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

void fillPkg(Package *p)
{
   if (p == nullptr)
   {
      cerr << "Error, NULL detected " << endl;
      return;
   }
   const int SkipChars = 80; 
   const char Eoln = '\n'; 
   cin.ignore(SkipChars, Eoln);

   cout << "Enter sender: ";
   getline(cin, p->sender);

   while (p->sender.length() == 0 )
   {
      cout << "Enter sender: ";
      getline(cin, p->sender);
   }   
}

void printPkg(Package *p)
{
   if (p == nullptr)
   {
      cerr << "Error, NULL detected " << endl; 
      return;
   }
   cout << "Package details " << endl;
   cout << "Sender: " << p->sender << endl;
   cout << "Recipient: " << p->recipient << endl;
   cout << "Content: " << p->content << endl;
   cout << "Address: " << p->address << endl; 
   cout << "Value:  " << p->value << endl; 
}


// ====================================================================================
// ========== queue function implementations ========================================
// ====================================================================================

void initQ(Queue &q)
{
   q.front = -1;
   q.back = -1;
   q.size = 0;
}


int getSizeQ(Queue q)
{
   return q.size;
}


bool insertQ(Package *p, Queue &q)
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


bool removeQ(Package* &p, Queue &q)
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