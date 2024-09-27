#include "Airplane.h"
#include <fstream>
#include <iostream>
using namespace std;

void Airplane::display() const {
    cout << "Date: " << date << "\n";
    cout << "Flight Number: " << flightNumber << "\n";
    cout << "Seats per row: " << seatsPerRow << "\n";
    for (size_t i = 0; i < rowRanges.size(); ++i) {
        cout << "Rows " << rowRanges[i].first << "-" << rowRanges[i].second << ": $" << prices[i] << "\n";
    }
    cout << "-------------------\n";
}

string Airplane::getFlightNumber() const {
    return flightNumber;
}

string Airplane::getDate() const {
    return date;
}

int Airplane::getPriceForRow(int row) const {
    for (size_t i = 0; i < rowRanges.size(); ++i) {
        if (row >= rowRanges[i].first && row <= rowRanges[i].second) {
            return prices[i];
        }
    }
    return -1;
}

vector<string> Airplane::checkSeatAvailability() const {
    vector<string> available_seats;
    for (const auto &seat : seat_map) {
        if (seat.isAvailable()) {
            available_seats.push_back(seat.getSeatInfo());
        }
    }
    return available_seats;
}

bool Airplane::bookSeat(const string &seatNumber, const string &username) {
    for (auto &seat : seat_map) {
        if (seat.isAvailable() && seat.getSeatInfo().find(seatNumber) != string::npos) {
            seat.book(username);
            return true;
        }
    }
    return false;
}

void Airplane::returnSeat(const string &seatNumber) {
    for (auto &seat : seat_map) {
        if (seat.getSeatInfo().find(seatNumber) != string::npos) {
            seat.release();
            return;
        }
    }
}

string Airplane::viewBookedTickets() const {
    string booked_tickets;
    for (const auto &seat : seat_map) {
        if (!seat.isAvailable()) {
            booked_tickets += seat.getSeatInfo() + "\n";
        }
    }
    return booked_tickets.empty() ? "No booked tickets.\n" : booked_tickets;
}