#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Data
{
    std::vector<std::string> timeStamp;
    std::vector<std::vector<double>> readings;
    std::vector<std::string> category;
};

Data loadData();