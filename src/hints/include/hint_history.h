#ifndef HINT_HISTORY_H_
#define HINT_HISTORY_H_

#include <string>
#include <vector>
#include "hint.h"

#define MAX_HINTS 6

class HintHistory {
public:
    int nrHints;
    std::vector<Hint> hints;

    HintHistory();
    HintHistory(const std::vector<Hint> hints);

    bool add(const Hint hint);
};

bool isCompatible(const std::string input, const HintHistory history);

#endif // HINT_HISTORY_H_