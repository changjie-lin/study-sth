// Defect: If the items with the same ISBNS do not come consecutively,
// the program would not count it correctly.

#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> valItem) {
            if (valItem.isbn() == currItem.isbn())
                ++cnt;
            else {
                std::cout << currItem << " occurs " << cnt << " times "
                          << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }

        std::cout << currItem << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}
