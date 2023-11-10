#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <ctime>

#include "check_value.h"
#include "menu.h"
#include "random_value.h"
#include "record_table.h"
#include "systemfunc.h"




int main(int argc, char** argv) {

   int difficalty = 0;
   std::string playername = "Anonimus";
   menu::MainMenu mainmenuresult = menu::MainMenu::Nothing; // !QUASTION! начальное присваивание, подробнее в menu.h
   menu::GameLevelMenu gamelevelmenuresult = menu::GameLevelMenu::Nothing; // !QUASTION! начальное присваивание, подробнее в menu.h
   bool witharguments = true;
   bool badarguments = false;

   switch (argc) {
      case 1:{
         witharguments = false;
         break;
      }
      case 2:{
         std::string arg1_value = std::string(argv[1]);
         if (arg1_value == "-table") {
            mainmenuresult = menu::MainMenu::RecordTable;
         }
         else {
            badarguments = true;
         }  
         break;   
      }
      case 3:{
         std::string arg1_value = std::string(argv[1]);
         std::string arg2_value = std::string(argv[2]);
        
         try
         {
            difficalty = stoi(arg2_value);
         }
         catch(std::invalid_argument)
         {
            difficalty = 0;
         }         
         
         if (arg1_value == "-max") {
            if (difficalty == 0) {
               badarguments = true;
            }
            else { 
               mainmenuresult = menu::MainMenu::Game;
               gamelevelmenuresult = menu::GameLevelMenu::DifficaltySetupByPlayer;
            }
         }
         else if (arg1_value == "-level") {
            switch (difficalty) {
               case 0: {
                  badarguments = true;  
               }
               case 1: {
                  mainmenuresult = menu::MainMenu::Game;
                  gamelevelmenuresult = menu::GameLevelMenu::Level1;
                  difficalty = 9; break;
               }
               case 2: {
                  mainmenuresult = menu::MainMenu::Game;
                  gamelevelmenuresult = menu::GameLevelMenu::Level2;
                  difficalty = 99; break;
               }
               case 3: {
                  mainmenuresult = menu::MainMenu::Game;
                  gamelevelmenuresult = menu::GameLevelMenu::Level3;
                  difficalty = 499; break;
               }
               case 4: {                  
                  mainmenuresult = menu::MainMenu::Game;
                  gamelevelmenuresult = menu::GameLevelMenu::Level4;
                  difficalty = 999; break;
               }
               default : {
                  difficalty = 0;
                  badarguments = true;
                  break;
               }
            }
         }
         else {
            badarguments = true;
         }
         break;
      }
       default: {
         badarguments = true;
      }
   }   
   
   if (badarguments) {
      std::cout << "Arguments is wrong." << std::endl;
      std::cout << "You can use only this constructions:" << std::endl;
      std::cout << "<-max> <guess number from 0 to player number>" << std::endl;
      std::cout << "<-level> <1..4> to choose level difficalty" << std::endl;
      std::cout << "<-table> to choose record table" << std::endl;
      std::cout << "Please try again." << std::endl;
      press_any_key();
      return 0;
   }

   do{  // enter name section (not in menu.h)

      clear_screen();

      if (!witharguments){
         std::cout << "Hi, this is a game \"Guess the number\"." << std::endl;
         std::cout << "Enter your name (without spaces please)." << std::endl;
         std::cout << "You are: ";
         std::cin >> playername;
         clear_screen();
      }

      do {  // MainMenu section

         if (!witharguments){
            mainmenuresult = menu::main(playername);
         }
         switch (mainmenuresult) {
            case menu::MainMenu::Game  : {
               if (!witharguments){
                  gamelevelmenuresult = menu::gamelevel(playername);
               }   
               switch (gamelevelmenuresult) {
                  case menu::GameLevelMenu::Level1 : {
                     difficalty = 9;
                     break;
                  }   
                  case menu::GameLevelMenu::Level2 : {
                     difficalty = 99;
                     break;
                  }   
                  case menu::GameLevelMenu::Level3 : {
                     difficalty = 499;
                     break;
                  }   
                  case menu::GameLevelMenu::Level4 : {
                     difficalty = 999;
                     break;
                  }   
                  case menu::GameLevelMenu::DifficaltySetupByPlayer: {
                     if (!witharguments){
                        do {
                           std::cout << "Enter maximum value for the guess number: ";
                           std::cin >> difficalty;
                           if (std::cin.fail() || difficalty <= 0) {
                              std::cout << "Something wrong enter. Try again." << std::endl;
                              clear_cin();
                              difficalty = 0;
                           }
                        } while(difficalty == 0);
                     }             
                     break;
                  }   
                  case menu::GameLevelMenu::Back  : {
                     difficalty = 0;
                     break;
                  }   
                  default : {
                      difficalty = 0;
                      continue;
                  }
               }      
               if (difficalty > 0) {
                  int attempt_number = check_value::check_value(get_random_value(difficalty));
                  std::cout << "Total attempts: " << attempt_number << std::endl << std::endl;
                  std::cout << "Press any key to back in main menu." << std::endl;
                  press_any_key();
                  
                  record_table::write_file(playername, attempt_number, "record_table.txt");
                  
                  continue;
                  break;
               } 
               break;  
            }   
            case menu::MainMenu::Rules  : {
               clear_screen();
               std::cout << "Current player name: " << playername << std::endl;
               std::cout << "---------" << std::endl;
               std::cout << "R U L E S" << std::endl;
               std::cout << "---------" << std::endl;
               std::cout << "I will generate a number, and you need to guess it." << std::endl;
               std::cout << "Enter any numbers, and I will tell your number more or less than mine." << std::endl;
               std::cout << "The fewer attempts there are, the higher the record will be." << std::endl << std::endl;
               std::cout << "Press any key to back in main menu." << std::endl;
               press_any_key();
               continue;
               break;
            }
            case menu::MainMenu::RecordTable  : {
               clear_screen();
               std::cout << "Current player name: " << playername << std::endl;
               std::cout << "-----------------------" << std::endl;
               std::cout << "R E C O R D   T A B L E" << std::endl;
               std::cout << "-----------------------" << std::endl;
               record_table::read_file("record_table.txt");         
               std::cout << "Press any key to back in main menu." << std::endl;
               press_any_key();
               continue;
               break;
            }
            case menu::MainMenu::ChangePlayerName  : {
               break;
            }   
            case menu::MainMenu::Exit  : {
               std::cout << "By! Hope to see you later." << std::endl;
               break;
            }   
            default : {
               continue;
            }   
         }
      } while(!witharguments && mainmenuresult != menu::MainMenu::Exit && mainmenuresult != menu::MainMenu::ChangePlayerName); // MainMenu section
   } while(!witharguments && mainmenuresult != menu::MainMenu::Exit); // enter name section (not in menu.h)
   return 0;
}