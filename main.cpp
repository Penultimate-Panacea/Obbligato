#include <iostream>
#include <cstring>
#include "rlcg.hpp"
#include "Seeder.h"

void loggingStart(){
    freopen("output.txt", "w", stdout);
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
    rlcg::ReversibleLCG reRng(testSeeder.getSeed());
    for (int i = 0; i < 99; ++i) {
        std::cout << reRng.next() << std::endl;
    }
        return 0;
}

