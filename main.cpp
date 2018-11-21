#include <iostream>
#include <cstring>
#include <sstream>
#include "rlcg.hpp"
#include "ABCFilemaker.hpp"
#include "Seeder.h"
#include "BaseEightyNine.h"

void loggingStart(){
    //freopen("output2.csv", "w", stdout);
    freopen("debug.txt", "w", stderr);
}
/*
int test(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/

int main() {
    loggingStart();
    Seeder testSeeder(0,0,0,0,0,1);
    rlcg::ReversibleLCG reRngTone(testSeeder.getSeed());
    //TODO make better toStream and validate output files match seed
    std::stringstream sstream;
    sstream << testSeeder;
    std::string location = sstream.str();

    freopen("output.tone", "w", stdout);
    for (int i = 0; i < 3201; ++i) {
        std::cout << BaseEightyNine(reRngTone.next()).firstChar();
    }
    rlcg::ReversibleLCG reRngTime(testSeeder.getSeed());
    freopen("output.time", "w", stdout);
    for (int i = 0; i < 3201; ++i){
        std::cout << (reRngTime.next() % 10);
    }
    ABCFilemaker ABC("output.tone", "output.time", location);
    return 0;
}

