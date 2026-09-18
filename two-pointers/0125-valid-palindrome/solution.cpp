#include <cctype>
#include <iostream>
#include <string>
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
    bool solve(std::string s) {
      std::vector<char> string_builder;
      for (char ch : s) {
        if (std::isalnum(ch)) {
          string_builder.push_back(std::tolower(ch));
        }
      }
      std::string normalized(string_builder.begin(), string_builder.end());
      int lp=0, rp=normalized.length()-1;
      while (lp < rp) {
        if (normalized[lp] != normalized[rp]) {
          return false;
        }
        lp++;
        rp--;
      }
      return true;
    }
};

struct TestCase {
    std::string s;
    bool expected;
};

int main() {
    std::vector<TestCase> tests = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true}
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
