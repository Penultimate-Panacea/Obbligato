#include <iostream>
#include <cstring>
#include "rlcg.hpp"


void loggingStart(){
    freopen("output.txt", "w", stdout);
 //   freopen("error.txt", "w", stderr);
}
/*
int test(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/

std::string buildSeed(){
    //TODO seperate input from build
    unsigned int hall;
    unsigned int floor;
    unsigned int room;
    unsigned char wall; //1-6 TODO add bounds
    unsigned char shelf; //1-7 TODO add bounds
    unsigned char book; //1-25 TODO add bounds
    std::string seed;
    std::cout << "Please enter the hall of the library: " << std::endl; //Temp Interface
    std::cin >> hall;
    std::cout << "Please enter the floor of the hall: " << std::endl;
    std::cin >> floor;
    std::cout << "Please enter the room of the floor: " << std::endl;
    std::cin >> room;
    std::cout << "Please enter the wall of the room: " << std::endl;
    std::cin >> wall;
    std::cout << "Please enter the shelf of the library: " << std::endl;
    std::cin >> shelf;
    std::cout << "Please enter the book on the shelf: " << std::endl;
    std::cin >> book; //End Temp Interface
    seed = "h";
    seed += (char)hall;
    seed += "-f";
    seed += (char)floor;
    seed += "-r";
    seed += (char)room;
    seed += "-w";
    seed += (char)wall;
    seed += "-s";
    seed += shelf;
    seed += "-b";
    seed += book;
    return seed;

}

int main() {
    std::string lookupSeed;
    loggingStart();
    lookupSeed = buildSeed();
    rlcg::ReversibleLCG myRng(lookupSeed);
    return 0;
}

