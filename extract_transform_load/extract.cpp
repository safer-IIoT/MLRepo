#include <iostream>
#include "loadCSVData.h"

int main()
{
    Data rows = loadData();

    std::cout << rows.category[0];
    return 0;
}