#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "loadCSVData.h"

std::vector<std::string> split(const std::string& packet)
{
    std::vector<std::string> values;
    std::stringstream stringStream(packet);
    std::string item;

    while (std::getline(stringStream, item, ',')) 
    {
        values.push_back(item);
    }

    return values;
}

Data loadData()
{
    std::cout << "Loading CSV data started \n";

    std::string filename = "mq2_dataset.csv";
    int featureCount = 17;
    int count = 0;

    Data data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) 
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::getline(file, line); // skip header row

    while (std::getline(file, line)) 
    {
        if (line.empty()) 
            continue;

        std::vector<std::string> splitText = split(line);

        if (splitText.size() != featureCount) 
            continue;

        std::vector<double> row;

        for (int i = 0; i < featureCount - 1; ++i) 
        {
            row.push_back(std::stod(splitText[i]));
        }
    
        data.timeStamp.push_back(splitText[0]);
        data.readings.push_back(row);
        data.category.push_back(splitText[featureCount - 1]);

        count++;
    }

    std::cout << "Loading CSV data ended. Total count:" << count << "\n";

    return data;
}