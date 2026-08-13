#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> us(nums.begin(), nums.end());

        int best = 0;
        for (int num : us) {
            if (us.count(num-1)) continue;
            int i = 1;
            while (us.count(num+i)) i++;
            best = std::max(best, i);
        }
        
        return best;
    }
};

struct TestCase {
    std::vector<int> nums;
    int expected;
};

int main() {
    std::vector<TestCase> tests = {
        {{100, 4, 200, 1, 3, 2}, 4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2}, 3}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {

        TestCase& t = tests[i];
        int actual = sol.longestConsecutive(t.nums);
        bool pass = (actual == t.expected);
        correct += pass;

        std::cout << "Test " << i << ": " << (pass ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
