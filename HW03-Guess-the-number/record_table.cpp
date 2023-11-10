#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>  
#include <fstream>
#include <vector>
#include "record_table.h"
#include "systemfunc.h"



namespace record_table{
    std::vector<PlayersRecord> high_score;

	std::ostream& operator<< (std::ostream& os, const PlayersRecord& PlayersRecord) {
        os << PlayersRecord.name << " " << PlayersRecord.attempts;
        return os;
    }

    std::istream& operator>>(std::istream& is, PlayersRecord& PlayersRecord) {
	is >> PlayersRecord.name >> PlayersRecord.attempts;
        return is;
    }

	bool CompareBy2Field(const PlayersRecord &a, const PlayersRecord &b) {
    	if(a.name < b.name) {
            return true;
		}
        if(a.name == b.name) {
        	if(a.attempts < b.attempts) {
            	return true;
			}
		}	
  		return false;
	}

    void write_file(std::string playername, int attempts, std::string file_name) {
		const std::string filename{file_name};
		{
			PlayersRecord Player{playername, attempts};

			std::ofstream file(filename, std::ios_base::app);

			if (!file.is_open()) {
				std::cerr << "Could not open file for writing: " << filename << std::endl;
				return;
			}

			file << Player;
			file << std::endl;
		} 
	}

   void read_file(std::string file_name) {
		PlayersRecord Player;
		const std::string filename{file_name};
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Could not open file for reading: " << filename << std::endl;
			return;
		}
		while (true) {
		    file >> Player;
			if (file.fail()) {
				break;
			}
			high_score.push_back(Player);
		}
		
		const std::string high_score_filename {"high_score.txt"}; // !QUASTION! почему здесь фигурные скобки, а не присваивание? 

		std::sort(high_score.begin(), high_score.end(), CompareBy2Field);

		if(std::remove(high_score_filename.c_str()) != 0) {  // !QUASTION! c_str для string в char, иначе ругалась компиляция на remove
			std::cout << "Delete file error: " << high_score_filename << std::endl;
		}	
		
		write_file(high_score[0].name, high_score[0].attempts, high_score_filename);
		std::cout << high_score[0].name << "   " << high_score[0].attempts << std::endl;
		for(int count = 1; count < high_score.size(); count++) {
		  	if (high_score[count].name != high_score[count-1].name) {
				write_file(high_score[count].name, high_score[count].attempts, high_score_filename);
				std::cout << high_score[count].name << "   " << high_score[count].attempts << std::endl;
			}
		}	
	}
} // record_table