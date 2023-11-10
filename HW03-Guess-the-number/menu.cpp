#include <iostream>
#include "menu.h"
#include "systemfunc.h"

namespace menu{

	bool from_int(int value, MainMenu& result) {
		result = static_cast<MainMenu>(value);
		switch(result) {
			case MainMenu::Game:
			case MainMenu::Rules:
			case MainMenu::RecordTable:
			case MainMenu::ChangePlayerName:
			case MainMenu::Exit:
			return true;
		}
		return false;
	}

	bool from_int(int value, GameLevelMenu& result) {
		result = static_cast<GameLevelMenu>(value);
		switch(result) {
			case GameLevelMenu::Level1:
			case GameLevelMenu::Level2:
			case GameLevelMenu::Level3:
			case GameLevelMenu::Level4:
			case GameLevelMenu::DifficaltySetupByPlayer:
			case GameLevelMenu::Back:
			return true;
		}
		return false;
	}

    MainMenu main(std::string playername){
       	
        clear_screen();
       	MainMenu result_section;
        do{
            std::cout << "Current player name: " << playername << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "M A I N   M E N U" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "Enter:" << std::endl;
            std::cout << "1 - Play Game" << std::endl;
            std::cout << "2 - Rules" << std::endl;
            std::cout << "3 - Record Table" << std::endl;
            std::cout << "4 - Change player name" << std::endl;
            std::cout << "5 - Exit the Game" << std::endl;

            int user_input = -1;
            std::cin >> user_input;

            bool convert_result = from_int(user_input, result_section);
            if(!std::cin.fail() && convert_result) {
                break;
            }
            clear_cin();
        } while(false);
        return result_section;
    }

GameLevelMenu gamelevel(std::string playername){
       	
        clear_screen();
       	GameLevelMenu result_section;
        do{
            std::cout << "Current player name: " << playername << std::endl;
            std::cout << "----------" << std::endl;
            std::cout << "GAME LEVEL" << std::endl;
            std::cout << "----------" << std::endl;
            std::cout << "Enter:" << std::endl;
            std::cout << "1 - Level 1 (guess number from 0 to 9)" << std::endl;
            std::cout << "2 - Level 2 (guess number from 0 to 99)" << std::endl;
            std::cout << "3 - Level 3 (guess number from 0 to 499)" << std::endl;
            std::cout << "4 - Level 4 (guess number from 0 to 999)" << std::endl;
            std::cout << "5 - Difficalty setup by player (guess number from 0 to player number)" << std::endl;
            std::cout << "0 - Back to previous menu" << std::endl;

            int user_input = -1;
            std::cin >> user_input;

            bool convert_result = from_int(user_input, result_section);
            if(!std::cin.fail() && convert_result) {
                break;
            }
            clear_cin();
        } while(false);
        return result_section;
    }    
} // menu