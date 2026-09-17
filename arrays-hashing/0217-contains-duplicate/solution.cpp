#include <iostream>
#include <vector>
#include <unordered_set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

class Solution {
public:
    bool solve(std::vector<int>& nums) {
      std::unordered_set<int> seen;
      for (int x : nums) {
        if (seen.count(x)) {
          return true;
        }
        seen.insert(x);
      }
      return false;
    }
};

struct TestCase {
    std::vector<int> nums;
    bool expected;
};

int main() {
    std::vector<TestCase> tests = {
        {{1,2,3,1}, true},
        {{1,2,3,4}, false},
        {{1,1,1,3,3,4,3,2,4,2}, true}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        auto actual = sol.solve(t.nums);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
