#include <iostream>
#include <cstring>
#include <sstream>
#include "rlcg.hpp"
#include "ABCFilemaker.hpp"
#include "Seeder.h"
#include "BaseEightyNine.h"


int main() {
    freopen("debug.log", "w", stderr);
    Seeder testSeeder(0,0,0,0,0,1);
    rlcg::ReversibleLCG reRngTone(testSeeder.getSeed());
    //TODO make better toStream and validate output files match seed
    std::stringstream sstream;
    sstream << testSeeder;
    std::string location = sstream.str();
    std::cerr << location;
    freopen("output.tone", "w", stdout);
    for (int i = 0; i < 3201; ++i) {
        std::cout << BaseEightyNine(reRngTone.next()).firstChar();
    }
    fclose(stdout);
    std::cout << "test";
    rlcg::ReversibleLCG reRngTime(testSeeder.getSeed());
    freopen("output.time", "w", stdout);
    for (int i = 0; i < 3201; ++i){
        std::cout << (reRngTime.next() % 10);
    }
    fclose(stdout);
    std::cout << "test";
    ABCFilemaker ABC("output.tone", "output.time", location);
    ABC.makeABCfile();
    return 3;
}

