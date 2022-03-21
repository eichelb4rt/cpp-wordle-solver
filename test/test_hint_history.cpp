#include <catch2/catch_test_macros.hpp>
#include "hint_history.h"

using namespace std;

TEST_CASE("can add hints to hint history", "[hints]") {
    const string hint_word = "PENIS";
    const vector<Color> hint_colors = {
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN
    };
    const Hint hint(hint_word, hint_colors);

    HintHistory history;
    bool err = history.add(hint);
    
    REQUIRE_FALSE(err);
    REQUIRE(history.nrHints == 1);
    REQUIRE(history.hints.size() == 1);
}