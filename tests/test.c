#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../solutions/solution.c"  // Include your C solution

int main() {
    struct {
        const char *input;
        bool expected;
    } test_cases[] = {
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

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    bool allPassed = true;

    for (int i = 0; i < num_tests; i++) {
        const char *input = test_cases[i].input;
        bool expected = test_cases[i].expected;
        bool result = isValid((char *)input);

        printf("Test Case %d: %s\n", i + 1, result == expected ? "Passed" : "Failed");

        if (result != expected) {
            allPassed = false;
        }
    }

    return allPassed ? 0 : 1;
}
