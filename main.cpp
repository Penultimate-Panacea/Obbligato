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



int main() {
    std::string lookupSeed;
    loggingStart();
    rlcg::ReversibleLCG myRng(lookupSeed);
    return 0;
}

