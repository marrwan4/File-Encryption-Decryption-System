#pragma once

#include <string>

using namespace std;

class FileService {
public:
    string readFile(const string &path) const;
    void writeFile(const string &path, const string &content) const;
};
