## Quick Reference for C++ Data Structures

## Algorithms

Incredible common, will be using constantly

```cpp
#include <algorithm>
std::sort(v.begin(), v.end());                          // ascending
std::sort(v.begin(), v.end(), std::greater<int>());     // descending
std::max_element(v.begin(), v.end());                    // iterator to max
std::reverse(v.begin(), v.end());
std::find(v.begin(), v.end(), target);                   // iterator or v.end()
```

## Arrays

In C++ this is usually done with vectors. C style arrays exist, but aren't favored due to losing things like arr.length on function calls. Also, O(1) appending for vectors, immutable for C style.

```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4);          // append
v.pop_back();             // remove last
v.size();                 // count
v.empty();
v[0];                     // no bounds check
v.at(0);                  // bounds-checked, throws
v.insert(v.begin(), 0);   // insert at position
v.erase(v.begin());       // remove at position
```

## Strings

```cpp
#include <string>
std::string s = "abc";
s.push_back('d');         // "abcd"
s.pop_back();
s.size();                 // (also s.length())
s.substr(1, 2);           // "bc" — (start, len)
s + "xyz";                // concat
s.find("bc");             // index or std::string::npos
```

## Stack

(Can be implemented with vectors, but on stack problems this forces you into good habits)

```cpp
#include <stack>
std::stack<int> st;
st.push(1);
st.top();                 // peek
st.pop();                 // removes, returns void
st.empty();
```

## Queue / Deque

```cpp
#include <queue>
std::queue<int> q;
q.push(1);
q.front();
q.pop();                  // removes, returns void

#include <deque>
std::deque<int> dq;
dq.push_back(1);
dq.push_front(0);
dq.pop_back();
dq.pop_front();
```

## Heap

Implemented with a priority queue, max-heap by default

```cpp
#include <queue>
std::priority_queue<int> pq;          // max-heap by default
pq.push(5);
pq.top();                              // largest
pq.pop();

// min-heap:
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

## Set / Map (unordered)

Ordered sets/maps exist, but usually unneeded.

```cpp
#include <unordered_set>
std::unordered_set<int> us;
us.insert(1);
us.count(1);                    // O(1) avg
us.contains(20);    // clearer, but incompatible on some older versions

#include <unordered_map>
std::unordered_map<int, int> um;
um[5] += 1;                     // default-inits to 0 if missing
um.count(5);
um.find(5);                     // iterator or um.end()
```

## Pair

Occasionally useful for weighted graph problems or as tiebreakers in heaps

```cpp
#include <utility>
std::pair<int, int> p = {1, 2};
p.first;
p.second;
```

## Iterators

```cpp
for (int x : arr) {...}
```
