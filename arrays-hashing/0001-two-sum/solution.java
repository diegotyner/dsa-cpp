import java.util.*;

class Solution {
    public List<Integer> solve(List<Integer> nums, int target) {
      // Turns out leetcode uses int[] and not List<Integer>
      // Swaps documented in code
      Map<Integer, Integer> hm = new HashMap<>();
      for (int i=0; i<nums.size(); i++) { // .size() becomes .length
        int num = nums.get(i); // this becomes a straight index, nums[i]
        if (hm.containsKey(num)) {
          return List.of(hm.get(num), i); // new int[] {hm.get(num), i}
        } else {
          hm.put(target-num, i);
        }
      }
      return List.of(-1,-1); // new int[] {-1}
    }

    record TestCase(List<Integer> nums, int target, List<Integer> expected) {}

    public static void main(String[] args) {
        Solution s = new Solution();

        List<TestCase> tests = List.of(
            new TestCase(List.of(2,7,11,15), 9, List.of(0,1)),
            new TestCase(List.of(3,2,4), 6, List.of(1,2)),
            new TestCase(List.of(3,3), 6, List.of(0,1))
        );

        int correct = 0;
        for (int i = 0; i < tests.size(); i++) {
            TestCase t = tests.get(i);
            List<Integer> actual = s.solve(t.nums(), t.target());
            boolean passed = actual.equals(t.expected());
            correct += passed ? 1 : 0;

            System.out.printf("Test %d: %s%n", i, passed ? "PASS" : "FAIL");
            System.out.printf("\tExpected: %s%n", t.expected());
            System.out.printf("\tActual:   %s%n", actual);
        }

        System.out.printf("%n%d / %d correct.%n", correct, tests.size());
    }
}
