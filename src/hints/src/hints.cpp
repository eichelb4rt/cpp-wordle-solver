#include "hints.h"

using namespace std;

Hint::Hint(const std::string _word, const std::vector<Color> _colors) {
    word = _word;
    colors = _colors;
}

bool is_compatible_with_hint(const std::string input, const Hint hint) {
    return false;
}

bool is_compatible_with_hints(const std::string input, const std::vector<Hint> hints) {
    return false;
}