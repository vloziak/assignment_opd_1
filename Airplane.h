#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "Seat.h"
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
    vector<Seat> seat_map;

    Airplane(const string &flightNumber, const string &flightDate, int seatsPerRow, const vector<Seat> &seats)
        : flightNumber(flightNumber), date(flightDate), seatsPerRow(seatsPerRow), seat_map(seats) {}


    void display() const;
    int getPriceForRow(int row) const;
    vector<string> checkSeatAvailability() const;
    bool bookSeat(const string &seatNumber, const string &username);
    void returnSeat(const string &seatNumber);
    string viewBookedTickets() const;
    string getFlightNumber() const;
    string getDate() const;

};

#endif //AIRPLANE_H