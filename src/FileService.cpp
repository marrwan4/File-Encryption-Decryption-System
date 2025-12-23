#include "FileService.h"

#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

string FileService::readFile(const string &path) const {
    ifstream input(path, ios::in | ios::binary);
    if (!input) {
        throw runtime_error("Unable to open file for reading: " + path);
    }
    return string((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
}

void FileService::writeFile(const string &path, const string &content) const {
    ofstream output(path, ios::out | ios::binary | ios::trunc);
    if (!output) {
        throw runtime_error("Unable to open file for writing: " + path);
    }
    output.write(content.data(), static_cast<streamsize>(content.size()));
    output.flush();
}
