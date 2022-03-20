#ifndef HINTS_H_
#define HINTS_H_

#include <string>
#include <vector>

#define WORD_LENGTH 5

enum Color { NONE, GREEN, YELLOW, GRAY };

class Hint {
public:
    std::vector<Color> colors;
    std::string word;

    Hint(const std::string _word, const std::vector<Color> _colors);
};

bool is_compatible_with_hint(const std::string input, const Hint hint);

bool is_compatible_with_hints(const std::string input, const std::vector<Hint> hints);

#endif // HINTS_H_