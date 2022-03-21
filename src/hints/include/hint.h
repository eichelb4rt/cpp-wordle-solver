#ifndef HINTS_H_
#define HINTS_H_

#include <set>
#include <map>
#include <string>
#include <vector>

#define WORD_LENGTH 5

enum Color { NONE, GREEN, YELLOW, GRAY };

class Hint {
public:
    std::vector<Color> colors;
    std::string word;
    std::set<char> gray_chars;

    Hint(const std::string _word, const std::vector<Color> _colors);
};

bool isCompatible(const std::string input, const Hint hint);

#endif // HINTS_H_