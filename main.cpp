#include <iostream>
#include "BaseEightyEight.h"

void loggingStart(){
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}

int main() {
    loggingStart();
    std::cout << "Hello, World!" << std::endl;
    BaseEightyEight five = BaseEightyEight(5);
    std::cout << "\n 5: "; five.printEightyEight();
    BaseEightyEight eightyEight = BaseEightyEight(88);
    std::cout << "\n 88: " ; eightyEight.printEightyEight();
    std::cout << "\n Finished";
    return 0;
}