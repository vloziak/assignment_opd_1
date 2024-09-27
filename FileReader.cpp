#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Airplane> FileReader::readRecords(const string& filePath) {
    vector<Airplane> records;
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return records;
    }

    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        string flightNumber, date;
        int seatsPerRow;

        stream >> date >> flightNumber >> seatsPerRow;

        vector<Seat> seatMap;

        int startRow, endRow, price;
        char dollarSign;
        while (stream >> startRow >> dollarSign >> endRow >> price >> dollarSign) {
            for (int row = startRow; row <= endRow; ++row) {
                for (char seatLetter = 'A'; seatLetter < 'A' + seatsPerRow; ++seatLetter) {
                    string seatInfo = to_string(row) + seatLetter;
                    seatMap.emplace_back(seatInfo, price);
                }
            }
        }

        Airplane airplane(flightNumber, date, seatsPerRow, seatMap);
        records.push_back(airplane);
    }

    file.close();
    return records;
}