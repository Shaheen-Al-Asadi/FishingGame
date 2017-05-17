#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h> 

using namespace std;

class Fish {

   string Name;
   size_t Value;
   size_t Weight;
   size_t Rarity;

public:

   Fish(size_t randomNum) {

      //When constructor called, it takes in a random number and constructs a fish of that type

      switch (randomNum) {

      case 1:
         Name = "Shrimp";
         Rarity = 1;
         break;

      case 2:
         Name = "Sardine";
         Rarity = 2;
         break;

      case 3:
         Name = "Salmon";
         Rarity = 3;
         break;

      case 4:
         Name = "Tuna";
         Rarity = 4;
         break;

      case 5:
         Name = "Bass";
         Rarity = 5;
         break;

      case 6:
         Name = "Lobster";
         Rarity = 6;
         break;

      case 7:
         Name = "Swordfish";
         Rarity = 7;
         break;

      case 8:
         Name = "Eel";
         Rarity = 8;
         break;

      case 9:
         Name = "Shark";
         Rarity = 9;
         break;

      case 10:
         Name = "Turtle";
         Rarity = 10;
         break;

      default: //Max random number in main is 11;
         Name = "Treasure Chest";
         Rarity = 13;
      }

      //Default attributes being initialized regardless of fish type
      Weight = (rand() % 50 + 1);
      Value = Rarity * Weight;

   }

   void printFish() {
      cout << setw(14) << left << Name;
      cout << " | Value: $" << Value << endl;
   }

   size_t getValue() { return Value; }

};