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
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hm;

        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if (hm.count(num)) 
                return std::vector<int> {hm[num], i};
            else 
                hm[target-num] = i;
        }
        return std::vector<int> {-1}; 
    }
};

struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
};

int main() {
    std::vector<TestCase> tests = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}}
    };

    Solution sol;
    int correct = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        TestCase& t = tests[i];
        auto actual = sol.twoSum(t.nums, t.target);
        bool passed = (actual == t.expected);
        correct += passed;

        std::cout << "Test " << i << ": " << (passed ? "PASS" : "FAIL") << "\n";
        std::cout << "\tExpected: " << t.expected << "\n";
        std::cout << "\tActual:   " << actual << "\n";
    }

    std::cout << "\n" << correct << " / " << tests.size() << " correct.\n";
    return 0;
}
