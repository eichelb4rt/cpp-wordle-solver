#include <catch2/catch_test_macros.hpp>
#include "hints.h"

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
    REQUIRE(is_compatible_with_hint("PENIS", hint));

    // incompatible with slightly different word
    REQUIRE_FALSE(is_compatible_with_hint("PEBIS", hint));
    // incompatible with permutation
    REQUIRE_FALSE(is_compatible_with_hint("ENISP", hint));
    // incompatible with completely different word
    REQUIRE_FALSE(is_compatible_with_hint("DICKS", hint));
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
    REQUIRE(is_compatible_with_hint("OOXOO", hint));
    
    // can't be on the same spot
    REQUIRE_FALSE(is_compatible_with_hint("XOOOO", hint));
    // is not contained
    REQUIRE_FALSE(is_compatible_with_hint("OOOOO", hint));
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
    REQUIRE(is_compatible_with_hint("XOOOX", hint));

    // incompatible if on the same spot
    REQUIRE_FALSE(is_compatible_with_hint("XXOOO", hint));
    // incompatible if not contained
    REQUIRE_FALSE(is_compatible_with_hint("XOOOO", hint));
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
    REQUIRE(is_compatible_with_hint("XOOOO", hint));

    // incompatible if contained (other than on the green position)
    REQUIRE_FALSE(is_compatible_with_hint("XOOOX", hint));
    // incompatible if not on green position
    REQUIRE_FALSE(is_compatible_with_hint("OOXXO", hint));
    // incompatible if both missing
    REQUIRE_FALSE(is_compatible_with_hint("OOOOO", hint));
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
    REQUIRE(is_compatible_with_hint("OOOOO", hint));

    // incompatible if occuring on same spot
    REQUIRE_FALSE(is_compatible_with_hint("XOOOO", hint));
    // incompatile on different spots
    REQUIRE_FALSE(is_compatible_with_hint("OXOOO", hint));
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
    REQUIRE(is_compatible_with_hint("PENIS", hint));

    // shorter test word 
    REQUIRE_FALSE(is_compatible_with_hint("PEN", hint));
    // longer test word
    REQUIRE_FALSE(is_compatible_with_hint("PEEEENIS", hint));    
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