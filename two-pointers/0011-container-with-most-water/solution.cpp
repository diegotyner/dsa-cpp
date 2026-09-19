#include <iostream>
#include <vector>

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
    int solve(std::vector<int>& nums) {
      int n = nums.size();
      int lp=0, rp=n-1;
      int best = 0;

      while (lp < rp) {
        int left=nums[lp], right=nums[rp];
        int bounding = std::min(left, right);
        int area = bounding*(rp-lp);
        if (area > best) {
          best = area;
        }
        if (left < right) {
          lp++;
        } else {
          rp--;
        }
      }
      return best; // TODO
    }
};

struct TestCase {
    std::vector<int> nums;
    int expected;
};

int main() {
    std::vector<TestCase> tests = {
        {{1,8,6,2,5,4,8,3,7}, 49},
        {{1,1}, 1},
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
