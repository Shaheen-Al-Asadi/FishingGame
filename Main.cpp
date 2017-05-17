#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h> 
#include "player.h"
#include "fish.h"
#include "util.h"

using namespace std;

int main() {

   //Setting seed for true random numbers
   time_t seed = time(NULL);
   srand(seed);

   cout << "=====================\n";
   cout << "Welcome to The Fishing Game \n";
   cout << "=====================\n";

   string nameInput = "Shaheen";
   Player Player1(nameInput);
   //Player1.getStats(); shows stats first time in game

   bool KeepPlaying = true;
   while (KeepPlaying == true) {

      cout << "Catching 10 fish...\n";
      for (int i = 0; i < 10; i++) {

         //addexperience returns false if o experience was gained, thus catchfish returnes -1 for no bait left , break out of loop
         if (!Player1.addExperience( Player1.catchFish() ) ){
            break;
         }

      }
      cout << "Done Catching Fish...\n\n";

      Player1.listFish();

      cout << "Selling Fish in Inventory, Profit: $" << Player1.sellFish() << endl << endl;
      
      bool KeepPlayingBuffer = menu(Player1); //asks to keep fishing, view stats , shop or quit
      if (KeepPlayingBuffer == false) { KeepPlaying = false; } //prevents menu from just closing keep playing - bad design sorry fam

   }

   cout << "Press any key to continue...";
   cin.get();
   return 0;
}