import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "solutions")))

from solution import Solution

def run_tests():
    sol = Solution()

    test_cases = [
        ("()", True),
        ("()[]{}", True),
        ("(]", False),
        ("([])", True),
        ("{[()]}", True),
        ("{[(])}", False),
        ("", True),
        ("(((((((", False),
        ("{[]}", True),
        ("([)]", False)
    ]

    all_passed = True

    for i, (input_str, expected) in enumerate(test_cases, 1):
        result = sol.isValid(input_str)
        print(f"Test Case {i}: Input: \"{input_str}\" | Expected: {expected} | Result: {result} | {'Passed' if result == expected else 'Failed'}")
        if result != expected:
            all_passed = False

    return 0 if all_passed else 1

if __name__ == "__main__":
    exit(run_tests())
