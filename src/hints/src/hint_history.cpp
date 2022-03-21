#include "hint_history.h"

using namespace std;

/**
 * @brief Construct a new Hint History::Hint History object
 *
 */
HintHistory::HintHistory() : hints(), nrHints(0) {}

/**
 * @brief Construct a new Hint History::HintHistory object
 *
 * @param _hints predefined History of hints
 */
HintHistory::HintHistory(const std::vector<Hint> _hints) {
    hints = _hints;
    nrHints = _hints.size();
}


/**
 * @brief Adds a hint to the hint history.
 *
 * @param hint The hint that is added to the history.
 * @return true maximum number of hints was already reached, therefore not added.
 * @return false if successfully added.
 */
bool HintHistory::add(const Hint hint) {
    if (nrHints >= MAX_HINTS)
        return true;

    hints.push_back(hint);
    ++nrHints;
    return false;
}

bool isCompatible(const std::string input, const HintHistory history) {
    return false;
}
