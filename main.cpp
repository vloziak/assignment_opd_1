#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"
#include "FileReader.h"

using namespace std;


int main() {
    FileReader reader;
    vector<Airplane> records = reader.readRecords("/Users/victorialoziak/Documents/GitHub/assignment_opd_1/example.txt");

    for (const auto& record : records) {
        cout << "Booked tickets for flight: " << record.getFlightNumber() << " on " << record.getDate() << ":\n";
        cout << record.viewBookedTickets();  
    }


    return 0;
}