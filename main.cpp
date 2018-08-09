#include <iostream>
#include "BaseEightyEight.h"

void loggingStart(){
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}

int main() {
    loggingStart();
    return 0;
}