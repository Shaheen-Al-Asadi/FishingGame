#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "fish.h"

using namespace std;

class Player {

   string Name;
   string Rod;
   string Bait;
   size_t FishLevel;
   size_t Experience;
   size_t Money;
   size_t BaitAmt;

   vector<Fish>FishList;

public:

   Player(string& name) :Name(name), Rod("Basic Rod"), Bait("Basic Bait"), FishLevel(1), Experience(0), Money(0), BaitAmt(50) {
   };

   string& getName() { return Name; }
   string& getRod() { return Rod; }
   string& getBait() { return Bait; }
   size_t getLevel() { return FishLevel; }
   size_t getMoney() { return Money; }
   size_t getExperience() { return Experience; }
   size_t getBaitAmt() { return BaitAmt; }

   void getStats() {
      cout << "=================================\n\n";
      cout << "Your name is: " << getName() << endl;
      cout << "Your fishing level is: " << getLevel() << endl;
      cout << "Experience: " << getExperience() << endl;
      cout << "Using Rod: " << getRod() << endl;
      cout << "Using Bait: " << getBait() << endl;
      cout << "Bait in Inventory: " << getBaitAmt() << endl;
      cout << "Money on Hand: $" << getMoney() << endl << endl;
      cout << "=================================\n\n";
   }

   //Uses fish default constructor to add a fish to fish list
   size_t catchFish() {
      if (BaitAmt > 0) {
         BaitAmt--;
         size_t randomNbr = (rand() % 11 + 1);
         size_t xp = (randomNbr * 11);
         FishList.push_back(Fish(randomNbr)); //push back fish into fishlist vector using a random number to chose a fish type 0-11 + 1 so max outcome = 12 - actuall 11?
         return xp;
      }
      else {
         cout << "No more Fishing Bait left! \nVisit the Fishing Store.\n\n";
         return -1;
      }
   }

   void listFish() {
      size_t total = 0;
      cout << "=== Inventory === \n";
      for (size_t i = 0; i < FishList.size(); i++) {
         cout << "Fish " << left << setw(2) << (i + 1) << " : ";
         FishList[i].printFish();
         total += FishList[i].getValue();
      }
      cout << "Total Value of Inventory: $" << total << endl << endl;
   }

   size_t sellFish() {

      //Add up values of every fish in list and add it to money attribute;
      size_t total = 0;
      for (auto f : FishList) {
         total += f.getValue();
      }
      Money += total;
      //Empty list of Fishlist
      FishList.clear();
      return total;

   }

   void addMoney(int amt) {
      Money += amt;
   }

   void addBait(int amt) {
      BaitAmt += amt;
   }

   bool addExperience(int amt) {
      if (amt > 0) {
         Experience += amt;
         return true;
      }
      return false; //if no bait left, returns -1
   }
};
