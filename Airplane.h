#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <vector>
#include <string>

using namespace std;

class Airplane {
public:
    string date;
    string flightNumber;
    int seatsPerRow;
    vector<pair<int, int>> rowRanges;
    vector<int> prices;
    void display() const;

    int getPriceForRow(int row) const;

};



#endif //AIRPLANE_H
