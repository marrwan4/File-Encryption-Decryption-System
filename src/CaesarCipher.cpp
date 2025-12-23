#include "CaesarCipher.h"

#include <cctype>

using namespace std;

CaesarCipher::CaesarCipher(int shift) : shiftBy(shift % 26) {}

string CaesarCipher::encrypt(const string &text) const {
    string result;
    result.reserve(text.size());
    for (char c : text) {
        result.push_back(shiftChar(c, shiftBy));
    }
    return result;
}

string CaesarCipher::decrypt(const string &text) const {
    string result;
    result.reserve(text.size());
    for (char c : text) {
        result.push_back(shiftChar(c, 26 - shiftBy));
    }
    return result;
}

char CaesarCipher::shiftChar(char c, int delta) const {
    if (!isalpha(static_cast<unsigned char>(c))) {
        return c;
    }
    const char base = islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
    return static_cast<char>((c - base + delta) % 26 + base);
}
