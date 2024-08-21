//Header Guards
#ifndef DECRYPTION_H
#define DECRYPTION_H


#include <string>

/**
 * Doxygen compatible comments
 * @class CaesarCipher
 * @brief A class that includes declaration for functions and data to decrypt encrypted text files.
 */
class CaesarCipher {
private:
    // An integer array to store the number of occurrences of each letter in the encrypted file
    int frequency[26]; 

public:
    /**
     * @brief Class constructor .
     */
    CaesarCipher();

    /**
     * @brief This function counts the frequency of each character in the given encrypted file.
     * @param encryptedText The parameter which corresponds to the file name.
     */
    void character_count(const std::string& encryptedText);

    /**
     * @brief This function displays the frequency of each character
     */
    void print_analysis_array() const;

    /**
     * @brief This function decrypts the file with a given key
     * @param encryptedText Encrypted filename.
     * @param decryptionKey decryption key (0-25). 0 for A and 25 for Z.
     * @return decrypted file.
     */
    std::string decrypt(const std::string& encryptedText, int decryptionKey) const;

    /**
     * @brief This function finds the index of the most frequent character
     * @return the index of the most frequent character.
     */
    int max_index() const;

    /**
     * @brief Convert lowercase to uppercase
     * @param character character to convert.
     * @return The uppercase version of the passed input character.
     */
    char to_upper(char character) const;

    /**
     * @brief This func checks that if a character is alphabetic or not.
     * @param character character to check.
     * @return return true if alphabet else false.
     */
    bool is_alpha(char character) const;

    /**
     * @brief Check whether the passed character is uppercase or not
     * @param character character to check
     * @return return true if character is uppercase else false.
     */
    bool is_upper(char character) const;
};

#endif