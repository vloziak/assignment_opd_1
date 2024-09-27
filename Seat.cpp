#include "Seat.h"
#include <fstream>

using namespace std;


bool Seat::isAvailable() const {
    return !is_booked;
}

void Seat::book(const string &user) {
    is_booked = true;
    username = user;
}

void Seat::release() {
    is_booked = false;
    username = "";
}

string Seat::getSeatInfo() const {
    return seat_number + (is_booked ? " booked by " + username : " available") + ", price: " + to_string(price);
}