#include <catch2/catch_test_macros.hpp>
#include "hint.h"

using namespace std;

TEST_CASE("all green is only compatible with exact copy", "[hints]") {
    const string hint_word = "PENIS";
    const vector<Color> hint_colors = {
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN
    };
    const Hint hint(hint_word, hint_colors);

    // compatible with exact copy
    REQUIRE(isCompatible("PENIS", hint));

    // incompatible with slightly different word
    REQUIRE_FALSE(isCompatible("PEBIS", hint));
    // incompatible with permutation
    REQUIRE_FALSE(isCompatible("ENISP", hint));
    // incompatible with completely different word
    REQUIRE_FALSE(isCompatible("DICKS", hint));
}

TEST_CASE("yellow chars have to appear in a different spot", "[hints]") {
    const string hint_word = "XOOOO";
    const vector<Color> hint_colors = {
        YELLOW,
        NONE,
        NONE,
        NONE,
        NONE
    };
    const Hint hint(hint_word, hint_colors);

    // compatible if somewhere else
    REQUIRE(isCompatible("OOXOO", hint));
    
    // can't be on the same spot
    REQUIRE_FALSE(isCompatible("XOOOO", hint));
    // is not contained
    REQUIRE_FALSE(isCompatible("OOOOO", hint));
}

TEST_CASE("a char can be green and yellow", "[hints]") {
    const string hint_word = "XXOOO";
    const vector<Color> hint_colors = {
        GREEN,
        YELLOW,
        NONE,
        NONE,
        NONE
    };
    const Hint hint(hint_word, hint_colors);

    // compatible if somewhere else
    REQUIRE(isCompatible("XOOOX", hint));

    // incompatible if on the same spot
    REQUIRE_FALSE(isCompatible("XXOOO", hint));
    // incompatible if not contained
    REQUIRE_FALSE(isCompatible("XOOOO", hint));
}

TEST_CASE("a char can be green and gray", "[hints]") {
    const string hint_word = "XXOOO";
    const vector<Color> hint_colors = {
        GREEN,
        GRAY,
        NONE,
        NONE,
        NONE
    };
    const Hint hint(hint_word, hint_colors);

    // compatible if not contained (other than on the green position)
    REQUIRE(isCompatible("XOOOO", hint));

    // incompatible if contained (other than on the green position)
    REQUIRE_FALSE(isCompatible("XOOOX", hint));
    // incompatible if not on green position
    REQUIRE_FALSE(isCompatible("OOXXO", hint));
    // incompatible if both missing
    REQUIRE_FALSE(isCompatible("OOOOO", hint));
}

TEST_CASE("gray letters cannot be contained", "[hints]") {
    const string hint_word = "XOOOO";
    const vector<Color> hint_colors = {
        GRAY,
        NONE,
        NONE,
        NONE,
        NONE
    };
    const Hint hint(hint_word, hint_colors);

    // compatible if not contained
    REQUIRE(isCompatible("OOOOO", hint));

    // incompatible if occuring on same spot
    REQUIRE_FALSE(isCompatible("XOOOO", hint));
    // incompatile on different spots
    REQUIRE_FALSE(isCompatible("OXOOO", hint));
}


TEST_CASE("words with different length are incompatible", "[hints]") {
    const string hint_word = "PENIS";
    const vector<Color> hint_colors = {
        NONE,
        NONE,
        NONE,
        NONE,
        NONE
    };
    const Hint hint(hint_word, hint_colors);

    // matching legth
    REQUIRE(isCompatible("PENIS", hint));

    // shorter test word 
    REQUIRE_FALSE(isCompatible("PEN", hint));
    // longer test word
    REQUIRE_FALSE(isCompatible("PEEEENIS", hint));    
}

TEST_CASE("faulty hints cannot be constructed", "[hints]") {
    const string hint_word = "PEN";
    const vector<Color> hint_colors = {
        NONE,
        NONE,
        NONE,
        NONE,
        NONE
    };

    // invalid hint structure
    REQUIRE_THROWS_AS(Hint(hint_word, hint_colors), std::logic_error);
}