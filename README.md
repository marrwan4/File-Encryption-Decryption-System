# Caesar Cipher File Encryption/Decryption

This repository contains a C++ program that encrypts and decrypts text files using the Caesar cipher technique.
The program allows users to select a file and apply the Caesar cipher to either encrypt or decrypt the file's contents.

## Features

- **Encrypt a File**: Shift each letter in the file by 3 positions in the alphabet.
- **Decrypt a File**: Shift each letter in the file back by 3 positions in the alphabet to restore the original text.
- **User-Friendly Interface**: Provides a simple text-based interface to choose encryption, decryption, or exit the program.

## Prerequisites

- A C++ compiler (e.g., `g++`, `clang++`)

## Code Overview
### main.cpp

#### Encryption and Decryption Functions:

- char caesar_cipher_encryption(char c): Encrypts a single character.
- char caesar_cipher_decryption(char c): Decrypts a single character.

#### File Handling Functions:

- string getfile(): Prompts the user for a filename.
- void encrypt(): Reads a file, encrypts its contents, and writes the encrypted content back to the file.
- void decrypt(): Reads a file, decrypts its contents, and writes the decrypted content back to the file.

#### Main Function:

Provides a menu for the user to choose encryption, decryption, or exit the program.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.
