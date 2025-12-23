#pragma once

#include "Cipher.h"

using namespace std;

class CaesarCipher : public Cipher {
public:
    explicit CaesarCipher(int shift);
    string encrypt(const string &text) const override;
    string decrypt(const string &text) const override;

private:
    int shiftBy;
    char shiftChar(char c, int delta) const;
};
