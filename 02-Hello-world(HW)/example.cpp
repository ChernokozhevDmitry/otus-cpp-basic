#include "example.h"

#include <iostream>

void example_function() {
	std::cout << "Hello from example function!" << std::endl;
}

void todo_move_me_out() {
	std::cout << "This function should be located in the separated source file" << std::endl;
	std::cout << "Yes! Now I am in separated source file <example.cpp>" << std::endl;
}
