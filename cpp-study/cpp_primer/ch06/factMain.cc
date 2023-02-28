#include <iostream>
#include "Chapter6.h"

int main() {

        int val;
        std::cout << "Enter a number: ";
        std::cin >> val;
        std::cout << "The factorial is " << fact(val) << std::endl;
        return 0;
}
