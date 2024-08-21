#include "Decryption.h"
#include <cctype>
#include <iostream>

using namespace std;

 /**
     * @brief Class constructor .
 */
CaesarCipher::CaesarCipher() {
    for(int i = 0; i < 26; ++i) {
        frequency[i] = 0;
    }
}

/**
     * @brief This function counts the frequency of each character in the given encrypted file.
     * @param encryptedText The parameter which corresponds to the file name.
     */

void CaesarCipher::character_count(const std::string& encryptedText) {
    for (char character : encryptedText) {
        if (is_alpha(character)) {
            character = to_upper(character);
            frequency[character - 'A']++;
        }
    }
}

/**
     * @brief This function displays the frequency of each character
     */
void CaesarCipher::print_analysis_array() const {
    for (int i = 0; i < 26; ++i) {
        cout << static_cast<char>('A' + i) << " occurs " << frequency[i] << " times\n";
    }
}

/**
     * @brief This function decrypts the file with a given key
     * @param encryptedText Encrypted filename.
     * @param decryptionKey decryption key (0-25). 0 for A and 25 for Z.
     * @return decrypted file.
     */
std::string CaesarCipher::decrypt(const std::string& encryptedText, int decryptionKey) const {
    std::string decryptedText = "";
    for (char character : encryptedText) {
        if (is_alpha(character)) {
            char offset = is_upper(character) ? 'A' : 'a';
            character = (character - offset - decryptionKey + 26) % 26 + offset;
        }
        decryptedText += character;
    }
    return decryptedText;
}

/**
     * @brief This function finds the index of the most frequent character
     * @return the index of the most frequent character.
     */
int CaesarCipher::max_index() const {
    int maxIndex = 0;
    for (int i = 1; i < 26; ++i) {
        if (frequency[i] > frequency[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
/**
     * @brief Convert lowercase to uppercase
     * @param character character to convert.
     * @return The uppercase version of the passed input character.
     */
char CaesarCipher::to_upper(char character) const {
    return character >= 'a' && character <= 'z' ? character - ('a' - 'A') : character;
}
/**
     * @brief This func checks that if a character is alphabetic or not.
     * @param character character to check.
     * @return return true if alphabet else false.
     */
bool CaesarCipher::is_alpha(char character) const {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}
/**
     * @brief Check whether the passed character is uppercase or not
     * @param character character to check
     * @return return true if character is uppercase else false.
     */
bool CaesarCipher::is_upper(char character) const {
    return character >= 'A' && character <= 'Z';
}
