#pragma once

#include "Cipher.h"

#include <string>
#include <vector>

using namespace std;

class RouteCipher : public Cipher {
public:
    explicit RouteCipher(int columns);
    string encrypt(const string &text) const override;
    string decrypt(const string &text) const override;

private:
    int columns;
    string transformText(const string &text) const;
    string spiralRead(const vector<vector<char>> &grid) const;
    vector<vector<char>> spiralFill(const string &text, int rows) const;
};
