#include "hints.h"
#include <stdexcept>

using namespace std;

Hint::Hint(const std::string _word, const std::vector<Color> _colors) : gray_chars() {
    if (_word.length() != _colors.size()) {
        throw invalid_argument("Word must be same length as color vector.");
    }
    if (_word.length() != WORD_LENGTH) {
        throw invalid_argument("Words must be " + to_string(WORD_LENGTH) + " characters long.");
    }
    word = _word;
    colors = _colors;
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (colors[i] == GRAY) {
            gray_chars.insert(word[i]);
        }
    }
}

bool is_compatible_with_hint(const std::string input, const Hint hint) {
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

bool is_compatible_with_hints(const std::string input, const std::vector<Hint> hints) {
    return false;
}