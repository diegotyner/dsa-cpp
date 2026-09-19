import java.util.*;

class Solution {
    // public int solve(List<Integer> nums) {
    public boolean solve(int[] nums) {
      HashSet<Integer> seen = new HashSet<>();
      for (int num : nums) {
        if (seen.contains(num)) {
          return true;
        } else {
          seen.add(num);
        }
      }
      return false; // TODO
    }

    record TestCase(int[] nums, boolean expected) {}

    public static void main(String[] args) {
        Solution s = new Solution();

        // List<TestCase> tests = List.of(
        List<TestCase> tests = List.of(
            new TestCase(new int[]{1,2,3,1}, true),
            new TestCase(new int[]{1,2,3,4}, false),
            new TestCase(new int[]{1,1,1,3,3,4,3,2,4,2}, true)
        );

        int correct = 0;
        for (int i = 0; i < tests.size(); i++) {
            TestCase t = tests.get(i);
            // int actual = s.solve(t.nums());
            boolean actual = s.solve(t.nums());
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
