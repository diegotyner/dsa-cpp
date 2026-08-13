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
    def solve(self, nums: List[int]) -> int:
        pass


@dataclass
class TestCase:
    nums: List[int]
    expected: int


if __name__ == "__main__":
    s = Solution()

    tests = [
        TestCase([10, 30, 21], 32),
        TestCase([100, 70], 92),
        TestCase([7, 3, 9], 3),
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
