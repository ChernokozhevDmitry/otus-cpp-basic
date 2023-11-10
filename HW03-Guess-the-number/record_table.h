#pragma once

namespace record_table{
    struct PlayersRecord {
        std::string name;
	    int attempts;
    };
    
    bool CompareBy2Field(const PlayersRecord &a, const PlayersRecord &b);
    void write_file(std::string playername, int attempts, std::string file_name);
    void read_file(std::string file_name);
} // record_table