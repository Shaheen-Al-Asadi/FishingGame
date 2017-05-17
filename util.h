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

bool menu(Player& Player1) {

   cout << "Keep Fishing? [F], View Stats [S], Buy Equipment [E], Quit [Q]:\n\n"; //Case switch this for efficiency in future as a base menu //add option to see stats/move location/go to shop here
   char quit;
   cin.get(quit);

   if (quit == 'q' || quit == 'Q') {
      return false;
      //cin.ignore(); quits instantly without an extra key
   }

   if (quit == 's' || quit == 'S') {
      cout << endl;
      Player1.getStats();
      cin.ignore(); //remove last newline from quit
      cout << "Press any key to continue fishing...\n";
      cin.get();
      return true;
   }

   if (quit == 'z' || quit == 'Z') {
      cout << "\n" << "Secret 'Z' CheatCode Used - Added $100,000 \nPress any key to continue...\nYou go back outside and catch more fish.\n\n";
      Player1.addMoney(100000);
      cin.ignore(); //remove last newline from quit
      cin.get();
      return true;
   }

   if (quit == 'e' || quit == 'E') {

      int choicex = 0;

      std::cout << "\n" << "===========================\nWelcome to the Fishing Shop!\n===========================\n\n";

      while (choicex != 3) { //while player hasnt exited shop

         cout << "Purchase Bait: $1000 for 100 Bait [ 1 ] \n\n";
         cout << "Donate to Store as an Investment: $10000 [ 2 ] \n\n";
         cout << "Return back to fishing... [ 3 ]\n\n";
         cin >> choicex;
         cin.ignore(); //remove last newline from quit

         switch (choicex) {
         case 1:
            if (Player1.getMoney() >= 1000) {
               Player1.addMoney(-1000);
               Player1.addBait(100);
            }
            else {
               cout << "You dont have enough money!\n\n";
            }
            return true;
            break;

         case 2:
            if (Player1.getMoney() >= 10000) {
               Player1.addMoney(-10000);
               cout << "Thanks for your Investment! We will upgrade our store soon!\n\n";
            }
            else {
               cout << "You dont have enough money!\n\n";
            }
            return true;
            break;

         case 3:
            return true;
            break;

         }
      }

      cout << "Press any Key to continue fishing...\n\n";
      cin.get();
      return true;
   }

   //switch (choice) {} only takes int's 

}