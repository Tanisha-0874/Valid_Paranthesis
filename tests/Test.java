package tests;

import solutions.Solution;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String[][] testCases = {
            {"()", "true"},
            {"()[]{}", "true"},
            {"(]", "false"},
            {"([])", "true"},
            {"{[()]}", "true"},
            {"{[(])}", "false"},
            {"", "true"},
            {"(((((((", "false"},
            {"{[]}", "true"},
            {"([)]", "false"}
        };

        boolean allPassed = true;

        for (int i = 0; i < testCases.length; i++) {
            String input = testCases[i][0];
            boolean expected = Boolean.parseBoolean(testCases[i][1]);
            boolean result = sol.isValid(input);
            boolean passed = result == expected;

            System.out.printf("Test Case %d: %s\n", i + 1, passed ? "Passed" : "Failed");

            if (!passed) {
                allPassed = false;
            }
        }

        System.exit(allPassed ? 0 : 1);
    }
}
