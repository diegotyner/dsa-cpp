#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

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
  std::vector<std::vector<std::string>> solve(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> hash_to_ls;
    for (std::string s : strs) {
      std::string hash = s;
      std::sort(hash.begin(), hash.end());
      hash_to_ls[hash].push_back(s);
    }

    std::vector<std::vector<std::string>> ret;
    for (const auto & [_, anagram_group ] : hash_to_ls) {
      ret.push_back(anagram_group);
    }

    return ret; // TODO
    }
};

struct TestCase {
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> expected;
};

int main() {
    std::vector<TestCase> tests = {
      {{"eat","tea","tan","ate","nat","bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
      {{""}, {{""}}},
      {{"a"}, {{"a"}}}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        auto actual = sol.solve(t.strs);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
