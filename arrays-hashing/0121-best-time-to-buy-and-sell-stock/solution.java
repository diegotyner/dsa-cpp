import java.util.*;

class Solution {
    // public int solve(List<Integer> nums) {
    public int solve(int[] nums) {
      int profit = 0, lowest = Integer.MAX_VALUE;
      for (int num : nums) {
        lowest = Math.min(lowest, num);
        profit = Math.max(profit, num-lowest);
      }
      return profit;
    }

    record TestCase(int[] nums, int expected) {}

    public static void main(String[] args) {
        Solution s = new Solution();

        // List<TestCase> tests = List.of(
        List<TestCase> tests = List.of(
            new TestCase(new int[]{7,1,5,3,6,4}, 5),
            new TestCase(new int[]{7,6,4,3,1}, 0)
        );

        int correct = 0;
        for (int i = 0; i < tests.size(); i++) {
            TestCase t = tests.get(i);
            // int actual = s.solve(t.nums());
            int actual = s.solve(t.nums());
            // boolean passed = actual == t.expected();
            boolean passed = actual == t.expected();
            correct += passed ? 1 : 0;

            System.out.printf("Test %d: %s%n", i, passed ? "PASS" : "FAIL");
            // System.out.printf("\tExpected: %s%n", t.expected());
            System.out.printf("\tExpected: %s%n", t.expected());
            // System.out.printf("\tActual:   %s%n", actual);
            System.out.printf("\tActual:   %s%n", actual);
        }

        System.out.printf("%n%d / %d correct.%n", correct, tests.size());
    }
}
