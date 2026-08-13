#include <iostream>
#include <vector>

class Solution {
public:
    int solve(std::vector<int>& nums) {
        return -1; // TODO
    }
};

struct TestCase {
    std::vector<int> nums;
    int expected;
};

int main() {
    std::vector<TestCase> tests = {
        {{10, 30, 21}, 32},
        {{100, 70}, 92},
        {{7, 3, 9}, 3}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        int actual = sol.solve(t.nums);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
