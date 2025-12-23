#include "RouteCipher.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

RouteCipher::RouteCipher(int columnsCount) : columns(columnsCount) {
    if (columns <= 0) {
        throw invalid_argument("Route cipher requires a positive column count");
    }
}

string RouteCipher::encrypt(const string &text) const {
    const string filtered = transformText(text);
    if (filtered.empty()) {
        return "";
    }

    const int rows = static_cast<int>(filtered.size()) / columns;
    vector<vector<char>> grid(rows, vector<char>(columns));

    int k = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            grid[r][c] = filtered[static_cast<size_t>(k++)];
        }
    }
    
    return spiralRead(grid);
}

string RouteCipher::decrypt(const string &text) const {
    const string filtered = transformText(text);
    if (filtered.empty()) {
        return "";
    }

    const int rows = static_cast<int>(filtered.size()) / columns;
    const auto grid = spiralFill(filtered, rows);

    string result;
    result.reserve(filtered.size());
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            result.push_back(grid[r][c]);
        }
    }
    return result;
}

string RouteCipher::transformText(const string &text) const {
    string filtered;
    filtered.reserve(text.size());

    for (char ch : text) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            filtered.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
        }
    }

    while (!filtered.empty() && (filtered.size() % static_cast<size_t>(columns) != 0)) {
        filtered.push_back('X');
    }

    if (filtered.empty()) {
        return filtered;
    }

    return filtered;
}

string RouteCipher::spiralRead(const vector<vector<char>> &grid) const {
    const int rows = static_cast<int>(grid.size());
    const int total = rows * columns;

    int sr = 0, sc = columns - 1, er = rows - 1, ec = 0;
    string result;
    result.reserve(static_cast<size_t>(total));

    while (static_cast<int>(result.size()) < total) {
        for (int r = sr; r <= er && static_cast<int>(result.size()) < total; ++r) {
            result.push_back(grid[r][sc]);
        }
        --sc;

        for (int c = sc; c >= ec && static_cast<int>(result.size()) < total; --c) {
            result.push_back(grid[er][c]);
        }
        --er;

        for (int r = er; r >= sr && static_cast<int>(result.size()) < total; --r) {
            result.push_back(grid[r][ec]);
        }
        ++ec;

        for (int c = ec; c <= sc && static_cast<int>(result.size()) < total; ++c) {
            result.push_back(grid[sr][c]);
        }
        ++sr;
    }

    return result;
}

vector<vector<char>> RouteCipher::spiralFill(const string &text, int rows) const {
    const int total = static_cast<int>(text.size());
    vector<vector<char>> grid(rows, vector<char>(columns));

    int sr = 0, sc = columns - 1, er = rows - 1, ec = 0;
    int k = 0;

    while (k < total) {
        for (int r = sr; r <= er && k < total; ++r) {
            grid[r][sc] = text[static_cast<size_t>(k++)];
        }
        --sc;

        for (int c = sc; c >= ec && k < total; --c) {
            grid[er][c] = text[static_cast<size_t>(k++)];
        }
        --er;

        for (int r = er; r >= sr && k < total; --r) {
            grid[r][ec] = text[static_cast<size_t>(k++)];
        }
        ++ec;

        for (int c = ec; c <= sc && k < total; ++c) {
            grid[sr][c] = text[static_cast<size_t>(k++)];
        }
        ++sr;
    }

    return grid;
}
