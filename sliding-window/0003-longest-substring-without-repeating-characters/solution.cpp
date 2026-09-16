#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>

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
    int solve(std::string s) {
      // For this problem, we need to find the maximum string with no repeats
      // We can solve this by maintaining a maximal sliding window, making sure to cull repeats

      // Sliding window problems take this general template
      // lp = 0
      // for rp in range(n)
      //  while !condition(lp, rp)
      //    lp++
      //  best = max(best, rp-lp+1)

      int best = 0;
      size_t lp = 0;
      std::unordered_map<char, int> in_window;

      for (size_t rp = 0; rp < s.length(); rp++) {
        char cur = s[rp];
        in_window[cur]++;
        while (in_window[cur] > 1) {
          char edge = s[lp];
          in_window[edge]--;
          lp++;
        }
        best = std::max(best, static_cast<int>(rp - lp + 1));
      }
      return best; // TODO
    }
};

struct TestCase {
    std::string s;
    int expected;
};

int main() {
    std::vector<TestCase> tests = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        auto actual = sol.solve(t.s);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
