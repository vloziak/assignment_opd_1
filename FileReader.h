#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>
#include "Airplane.h"
using namespace std;
class FileReader {
public:
    vector<Airplane> readRecords(const string& filePath);
};
#endif //FILEREADER_H