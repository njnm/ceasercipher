#include <iostream>
#include <fstream>
#include "Decryption.h"

using namespace std;

/**
 * @brief Main function for decryption of encrypted files.
 * @param argc This indicates number of command line options
 * @param argv array of command line args
 * @return 0 on success, 1 on error.
 */
int main(int argc, char* argv[]) 
{
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_encrypted.txt> <output_decrypted.txt>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    CaesarCipher cipher;
    string line;
    string encryptedText;

    while (getline(inputFile, line)) {
        encryptedText += line + "\n";
    }

    cipher.character_count(encryptedText);
    cipher.print_analysis_array();

    int maxIndex = cipher.max_index();
    int suggestedKey = (maxIndex - ('E' - 'A') + 26) % 26;
    char suggestedChar = 'A' + suggestedKey;
    cout << "Suggested key (based on frequency analysis): " << suggestedKey
         << " (character: '" << suggestedChar << "')\n";

    while (true) {
        int selectedKey;
        cout << "Enter the decryption key (0-25): ";
        cin >> selectedKey;

        string sampleText = cipher.decrypt(encryptedText, selectedKey);
        cout << "Sample of decrypted text " << selectedKey << ":\n";
        cout << sampleText.substr(0, 300) << "\n";  

        char confirmDecryption;
        cout << "Do you want to save the decrypted text? (y/n): ";
        cin >> confirmDecryption;

        if (confirmDecryption == 'y' || confirmDecryption == 'Y') {
            outputFile << sampleText;
            cout << "The decrypted text has been saved to " << argv[2] << ".\n";
            break;
        } else {
            cout << "You can try another key.\n";
        }
    }

    return 0;
}
