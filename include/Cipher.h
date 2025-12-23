#pragma once

#include <string>

using namespace std;

class Cipher {
public:
    virtual ~Cipher() = default;
    virtual string encrypt(const string &text) const = 0;
    virtual string decrypt(const string &text) const = 0;
};
