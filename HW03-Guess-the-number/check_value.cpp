#include <iostream>
#include "check_value.h"
#include "systemfunc.h"

namespace check_value{
    int current_value;

/*    void clear_cin() {
	    std::cin.clear();
	    std::cin.sync();
	    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
*/
    int check_value(int target_value){
        int attempt_count = 1;

        // clear_screen();

        do
        {
            std::cout << "Attempt: " << attempt_count  << "." << std::endl;
            std::cout << "Enter your numbers: ";
		    std::cin >> current_value;
            if(std::cin.fail()) {
                current_value = -1; 
                std::cout << "Something wrong enter. Try again" << std::endl;
                clear_cin();
                continue;
            }

            if (current_value != -1) {
                if (current_value > target_value) {
                    std::cout << "less than " << current_value << std::endl << std::endl;        
                } else if (current_value < target_value) {
                    std::cout << "greater than " << current_value << std::endl << std::endl;        
                } else {
                    std::cout << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "Yes! It is right. My congratulations!" << std::endl;
                    std::cout << "-------------------------------------" << std::endl << std::endl;
                    return attempt_count;        
                }
            }
            attempt_count++;
        } while (target_value != current_value);
        return attempt_count;
    }
} // check_value