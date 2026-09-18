#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
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
    std::vector<int> solve(std::vector<int>& nums, int k) {
      // We'll build a counter for each element, then create a heap out of it and pop k times
      std::unordered_map<int, int> counter;
      for (auto num : nums) {
        counter[num]++;
      }

      std::priority_queue<std::pair<int, int>> max_heap;
      for (const auto & [num, freq] : counter) {
        max_heap.push({freq, num});
      }
      
      std::vector<int> output;
      for (int i=0; i < k; i++) {
        int most_freq = max_heap.top().second;
        max_heap.pop();
        output.push_back(most_freq);
      }

      return output; // TODO
    }
};

struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
};

int main() {
    std::vector<TestCase> tests = {
      {{1,1,1,2,2,3}, 2, {1,2}},
      {{1}, 1, {1}},
      {{1,2,1,2,1,2,3,1,3,2}, 2, {1,2}}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        auto actual = sol.solve(t.nums, t.k);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
