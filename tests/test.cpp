#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "../solutions/solution.cpp"  // Include the implementation

int main() {
    Solution sol;

    vector<pair<string, bool>> test_cases = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([])", true},
        {"{[()]}", true},
        {"{[(])}", false},
        {"", true},
        {"(((((((", false},
        {"{[]}", true},
        {"([)]", false}
    };

    bool allPassed = true;

    for (size_t i = 0; i < test_cases.size(); ++i) {
        const auto& [input, expected] = test_cases[i];
        bool result = sol.isValid(input);
        bool passed = result == expected;

        cout << "Test Case " << (i + 1) << ": Input: \"" << input
             << "\" | Expected: " << (expected ? "true" : "false")
             << " | Result: " << (result ? "true" : "false")
             << " | " << (passed ? "Passed" : "Failed") << endl;

        if (!passed) allPassed = false;
    }

    return allPassed ? 0 : 1;
}
