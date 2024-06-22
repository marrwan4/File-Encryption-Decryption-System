#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Declare a file stream object
fstream dataFile;

// Function to encrypt a single character using Caesar cipher
char caesar_cipher_encryption(char c) {
    // If the character is not alphabetic, return it unchanged
    if (!isalpha(c)) {
        return c;
    }
    // Encrypt lowercase characters
    if (islower(c)) {
        return (c - 'a' + 3) % 26 + 'a';
    } 
    // Encrypt uppercase characters
    else if (isupper(c)) {
        return (c - 'A' + 3) % 26 + 'A';
    } 
    // Default return for any other case (shouldn't reach here)
    else {
        return c;
    }
}

// Function to decrypt a single character using Caesar cipher
char caesar_cipher_decryption(char c) {
    // If the character is not alphabetic, return it unchanged
    if (!isalpha(c)) {
        return c;
    }
    // Decrypt lowercase characters
    if (islower(c)) {
        return (c - 'a' - 3 + 26) % 26 + 'a';
    } 
    // Decrypt uppercase characters
    else if (isupper(c)) {
        return (c - 'A' - 3 + 26) % 26 + 'A';
    } 
    // Default return for any other case (shouldn't reach here)
    else {
        return c;
    }
}

// Function to get the filename from the user
string getfile() {
    cout << "Please enter the file name including extention if it's in the same directory, or enter the absloute path: ";
    string file_name;
    getline(cin, file_name);
    return file_name;
}

// Function to encrypt the contents of a file
void encrypt() {
    string encryption = "";
    string Filename;
    ifstream dataFile;

    // Loop until a valid file is opened
    while (true) {
        Filename = getfile();
        dataFile.open(Filename, ios::in);
        if (dataFile.fail()) {
            cout << "Error opening file, Please try again." << endl;
        } else {
            break;
        }
    }

    // Read the file character by character and encrypt each character
    char character;
    while (dataFile.get(character)) {
        encryption += caesar_cipher_encryption(character);
    }
    cout << "File has been encrypted." << endl;

    // Close the input file
    dataFile.close();

    // Write the encrypted content back to the file
    ofstream outFile(Filename, ios::out | ios::trunc);
    outFile << encryption;
    outFile.flush();
    outFile.close();
}

// Function to decrypt the contents of a file
void decrypt() {
    string decryption = "";
    string Filename;
    ifstream dataFile;

    // Loop until a valid file is opened
    while (true) {
        Filename = getfile();
        dataFile.open(Filename, ios::in);
        if (dataFile.fail()) {
            cout << "Error opening file, Please try again." << endl;
        } else {
            break;
        }
    }

    // Read the file character by character and decrypt each character
    char character;
    while (dataFile.get(character)) {
        decryption += caesar_cipher_decryption(character);
    }
    cout << "File has been decrypted." << endl;

    // Close the input file
    dataFile.close();

    // Write the decrypted content back to the file
    ofstream outFile(Filename, ios::out | ios::trunc);
    outFile << decryption;
    outFile.flush();
    outFile.close();
}

// Main function to drive the program
int main() {
    cout << "Welcome Dear User" << endl;
    cout << "Please notice that Program auto saves the file" << endl;
    while (true) {
        cout << "What do you want to do?" << endl;
        cout << "----------------------" << endl;
        cout << "A) Encrypt a file" << endl;
        cout << "B) Decrypt a file" << endl;
        cout << "C) Exit the program" << endl;
        cout << "----------------------" << endl;
        cout << "Please enter your choice: ";
        string choice;
        getline(cin, choice);
        if (choice == "A" || choice == "a") {
            encrypt();
        } else if (choice == "B" || choice == "b") {
            decrypt();
        } else if (choice == "C" || choice == "c") {
            return 0;
        } else {
            cout << "Please enter a valid choice." << endl;
        }
    }
    return 0;
}
