#include <iostream>
#include <filesystem>
#include "systemfunc.h"

void clear_screen() {
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void clear_cin() {
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void press_any_key() {
#ifdef _WIN32
   system("pause");
#else
   system("read");
#endif
}
