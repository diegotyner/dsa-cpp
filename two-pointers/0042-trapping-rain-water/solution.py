# https://leetcode.com/problems/trapping-rain-water/description/
from typing import List, Optional, Tuple, Dict, Set
from collections import defaultdict, deque, Counter, OrderedDict
from dataclasses import dataclass
import heapq
import bisect
import functools
import itertools
import math
import sys


class Solution:
    def solve(self, nums: list[int]) -> int:
      # For this problem, we'll do a squeezing two pointer, taking the lowest "edge"
      # at each point as the bounding wall, and shrinking the smaller of the two edges
      tot = 0
      n = len(nums)
      lp, rp = 0, n-1
      maxl, maxr = 0,0

      while lp < rp:
        left, right = nums[lp], nums[rp]
        divet = min(left,right)
        print(maxl, maxr, max(0, max(maxl,maxr) - divet))
        tot += max(0, max(maxl,maxr) - divet)
        if left < right:  # left smaller, shrink lp
          lp += 1
          maxl = max(maxl, left)
        else:
          rp -= 1
          maxr = max(maxr, right)

      return tot


@dataclass
class TestCase:
    nums: list[int]
    expected: int


if __name__ == "__main__":
    s = Solution()

    tests = [
        TestCase([0,1,0,2,1,0,1,3,2,1,2,1], 6),
        TestCase([4,2,0,3,2,5], 9),
    ]

    correct = 0
    for i, t in enumerate(tests):
        actual = s.solve(t.nums)
        passed = actual == t.expected
        correct += passed

        print(f"Test {i}: {'PASS' if passed else 'FAIL'}")
        print(f"\tExpected: {t.expected}")
        print(f"\tActual:   {actual}")

    print(f"\n{correct} / {len(tests)} correct.")
