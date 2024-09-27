#ifndef SEAT_H
#define SEAT_H
#include <vector>
#include <string>

using namespace std;

class Seat {
    string seat_number;
    double price;
    bool is_booked;
    string username;
public:
    Seat(const string &seatNumber, double seatPrice)
        : seat_number(seatNumber), price(seatPrice), is_booked(false), username("") {}

    bool isAvailable() const;

    void book(const string &user);

    void release();

    string getSeatInfo() const;
};
#endif //SEAT_H