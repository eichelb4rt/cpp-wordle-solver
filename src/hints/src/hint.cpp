#include "hint.h"
#include <stdexcept>

using namespace std;

Hint::Hint(const std::string _word, const std::vector<Color> _colors) : gray_chars() {
    // check for valid arguments
    if (_word.length() != _colors.size()) {
        throw invalid_argument("Word must be same length as color vector.");
    }
    if (_word.length() != WORD_LENGTH) {
        throw invalid_argument("Words must be " + to_string(WORD_LENGTH) + " characters long.");
    }

    // init attributes
    word = _word;
    colors = _colors;

    // fill gray chars map with all the gray chars in the word
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (colors[i] == GRAY) {
            gray_chars.insert(_word[i]);
        }
    }
}

/**
 * @brief checks if an input word is compatible with a hint.
 *
 * @param input WORD_LENGTH-long word that is checked for compatibility with hint.
 * @param hint WORD_LENGTH-long hint defining rules for the word.
 * @return true if input follows rules defined by hint.
 * @return false if not.
 */
bool isCompatible(const std::string input, const Hint hint) {
    // input words must have defined word length
    if (input.length() != WORD_LENGTH) {
        return false;
    }

    // prepare the yellow chars that are in there
    map<char, bool> found_chars;
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (hint.colors[i] == YELLOW) {
            found_chars[hint.word[i]] = false;
        }
    }
    // look if the word matches the pattern
    for (int i = 0; i < WORD_LENGTH; ++i) {
        // if we found a green char that we already know is there, it is compatible at this index -> continue
        if (hint.colors[i] == GREEN && input[i] == hint.word[i]) {
            continue;
        }
        // if a gray char is found, incompatible
        if (hint.gray_chars.find(input[i]) != hint.gray_chars.end()) {
            return false;
        }
        // if a green char is not found on position, incompatible
        if (hint.colors[i] == GREEN && input[i] != hint.word[i]) {
            return false;
        }
        // if a yellow char is found on the same position, incompatible
        if (hint.colors[i] == YELLOW && input[i] == hint.word[i]) {
            return false;
        }
        // char was found
        found_chars[input[i]] = true;
    }
    // if a yellow char was not found, incompatible
    for (auto const& entry : found_chars) {
        // entry: (char, was_found), == false for readability
        if (entry.second == false) {
            return false;
        }
    }
    // input word is compatible
    return true;
}