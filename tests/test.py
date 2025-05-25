import sys
import os

# Add the solutions directory to the path
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
        passed = result == expected
        print(f"Test Case {i}: {'Passed' if passed else 'Failed'}")
        if not passed:
            all_passed = False

    return 0 if all_passed else 1

if __name__ == "__main__":
    exit(run_tests())
