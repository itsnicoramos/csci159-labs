//Nico Ramos 
//csci159 lab 1

#include<iostream>
#include<string>

int main()
{  
   std::string cityname;
   int population;
   int year;

   std::cout << "Welcome to lab 1" << std::endl;
   std::cout << "Welcome to Cityicker: the program that lets you enter information about ";
   std::cout << "your favorite city.";
   std::cout << "you will be ask to enter the name of the city, ";
   std::cout << "it's approximate population, and the year you last visited. " << std::endl;
   std::cout << "Enter the name of your favourite city  ";
   std::cout << " (use underscore instead of spaces, e.g: Little_Rocks)" << std::endl;
   std::cin >> cityname;
   std::cout << "Enter the year you last visited " << cityname  << std::endl;
   std::cin >> year; 
   std::cout << "it's approximate population, and the year you last visited." << std::endl;
   std::cin >> population;
   std::cout << std::endl;

   std::cout << "To summarize your choice: " << std::endl;
   std::cout << "   It was the city of " << cityname << std::endl;
   std::cout << "   population: " << population << std::endl;
   std::cout << "   and you last visited in " << year << std::endl;  
  

   return 0;
}

