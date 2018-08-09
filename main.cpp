#include <iostream>
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
    loggingStart();
    rlcg::ReversibleLCG myRng(465);
    return 0;
}

