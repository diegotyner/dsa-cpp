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
      size_t n = nums.size();
      int tot = 0;
      int lp=0, rp=n-1;
      int maxl=0, maxr=0;

      while (lp<rp) {
        int left=nums[lp], right=nums[rp];
        int divet = std::min(left,right);
        tot += std::max(0, std::max(maxl,maxr)-divet);
        if (left < right) {
          lp += 1;
          maxl = std::max(maxl, left);
        } else { // else right smaller
          rp -= 1;
          maxr = std::max(maxr, right);
        }
      }
      return tot;
    }
};

struct TestCase {
    std::vector<int> nums;
    int expected;
};

int main() {
    std::vector<TestCase> tests = {
      {{ 0,1,0,2,1,0,1,3,2,1,2,1 }, 6,},
      {{4,2,0,3,2,5}, 9,},
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
