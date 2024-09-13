#include <string>
#include <vector>

#include "Airplane.h"
#include "FileReader.h"

using namespace std;

int main() {
    FileReader reader;
    vector<Airplane> records = reader.readRecords("C:\\ОП\\assignment_opd_1\\example.txt");

    for (const auto& record : records) {
        record.display();
    }

    return 0;
}
