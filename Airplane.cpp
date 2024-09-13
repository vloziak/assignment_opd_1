#include "Airplane.h"

#include <fstream>
#include <sstream>
#include <iostream>

string date;
string flightNumber;
int seatsPerRow;
vector<pair<int, int>> rowRanges;
vector<int> prices;

void Airplane::display() const {
    cout << "Date: " << date << "\n";
    cout << "Flight Number: " << flightNumber << "\n";
    cout << "Seats per row: " << seatsPerRow << "\n";
    for (size_t i = 0; i < rowRanges.size(); ++i) {
        cout << "Rows " << rowRanges[i].first << "-" << rowRanges[i].second << ": $" << prices[i] << "\n";
    }
    cout << "-------------------\n";
}

int Airplane::getPriceForRow(int row) const {
    for (size_t i = 0; i < rowRanges.size(); ++i) {
        if (row >= rowRanges[i].first && row <= rowRanges[i].second) {
            return prices[i];
        }
    }
    return -1;
}
