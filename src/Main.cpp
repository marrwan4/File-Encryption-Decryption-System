#include "..\include\CaesarCipher.h"
#include "..\include\FileService.h"
#include "..\include\RouteCipher.h"

#include <iostream>
#include <limits>
#include <memory>
#include <string>

using namespace std;


namespace {

char promptAction() {
    cout << "Choose an action:\n";
    cout << "A) Encrypt a file\n";
    cout << "B) Decrypt a file\n";
    cout << "C) Exit\n";
    cout << "Your choice: ";

    string choice;
    getline(cin, choice);
    return choice.empty() ? ' ' : static_cast<char>(toupper(static_cast<unsigned char>(choice[0])));
}

char promptCipher() {
    cout << "Select cipher:\n";
    cout << "1) Caesar (+3 shift)\n";
    cout << "2) Route cipher (columnar spiral)\n";
    cout << "Your choice: ";

    string choice;
    getline(cin, choice);
    return choice.empty() ? ' ' : choice[0];
}

string promptFilePath() {
    cout << "Enter file path (relative or absolute): ";
    string path;
    getline(cin, path);
    return path;
}

int promptPositiveInt(const string &message) {
    while (true) {
        cout << message;
        int value = 0;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

} // namespace

int main() {
    FileService fileService;
    bool running = true;

    cout << "File Encryption/Decryption Utility\n";
    cout << "----------------------------------\n";

    while (running) {
        const char action = promptAction();
        if (action == 'C') {
            running = false;
            continue;
        }

        if (action != 'A' && action != 'B') {
            cout << "Please choose A, B, or C.\n\n";
            continue;
        }

        const char cipherChoice = promptCipher();
        unique_ptr<Cipher> cipher;

        if (cipherChoice == '1') {
            cipher = make_unique<CaesarCipher>(3);
        } else if (cipherChoice == '2') {
            const int key = promptPositiveInt("Enter route cipher column count (secret key): ");
            cipher = make_unique<RouteCipher>(key);
        } else {
            cout << "Please choose 1 or 2.\n\n";
            continue;
        }

        const string path = promptFilePath();
        try {
            const string input = fileService.readFile(path);
            const string output = (action == 'A') ? cipher->encrypt(input) : cipher->decrypt(input);
            fileService.writeFile(path, output);
            cout << ((action == 'A') ? "File encrypted." : "File decrypted.") << "\n\n";
        } catch (const exception &ex) {
            cerr << "Operation failed: " << ex.what() << "\n\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
