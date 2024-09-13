#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Airplane> FileReader::readRecords(const string& filePath) {
    vector<Airplane> records;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return records;
    }

    string line;
    while (getline(file, line)) {
        Airplane record;
        istringstream stream(line);

        stream >> record.date >> record.flightNumber >> record.seatsPerRow;

        int startRow, endRow, price;
        char dollarSign;
        while (stream >> startRow >> dollarSign >> endRow >> price >> dollarSign) {
            record.rowRanges.emplace_back(startRow, endRow);
            record.prices.push_back(price);
        }

        records.push_back(record);
    }

file.close();
return records;
}