
## Quick Reference for Java Data Structures

## Algorithms

```java
import java.util.*;
Collections.sort(list);                              // ascending
Collections.sort(list, Collections.reverseOrder());  // descending
Collections.max(list);                                 // max value directly (not an iterator)
Collections.reverse(list);
list.indexOf(target);                                   // index or -1 (no iterator concept)

// arrays specifically (not List) use a separate utility class:
import java.util.Arrays;
Arrays.sort(arr);                                       // primitive arrays sort ascending only
Arrays.sort(arr, Collections.reverseOrder());           // only works on Object[] (e.g. Integer[]), not int[]
```

**Gotcha vs. C++:** primitive arrays (`int[]`) and `List<Integer>` are genuinely different types with different available methods — `Arrays.sort` for primitives, `Collections.sort` for Lists. There's no single unified `sort` like `std::sort`.

## Arrays

Java's `ArrayList` is the vector equivalent. Raw arrays (`int[]`) exist and are fixed-size, closer to C-style arrays.

```java
import java.util.*;
List<Integer> list = new ArrayList<>(List.of(1, 2, 3));
list.add(4);              // append
list.remove(list.size() - 1);  // remove last (by index, not value — see gotcha below)
list.size();
list.isEmpty();
list.get(0);              // bounds-checked, throws IndexOutOfBoundsException
list.set(0, 99);           // overwrite at index
list.add(0, 99);           // insert at position
list.remove(0);            // remove at index
```

## Strings

```java
String s = "abc";
s = s + "d";               // immutable — every "mutation" returns a NEW string
s.length();
s.substring(1, 3);         // "bc" — (start, END index exclusive, NOT length like C++'s substr)
s + "xyz";                 // concat
s.indexOf("bc");           // index or -1

// for actual mutation (loops building strings), use StringBuilder:
StringBuilder sb = new StringBuilder();
sb.append('d');
sb.deleteCharAt(sb.length() - 1);
sb.toString();
```
**Gotcha, important:** Java strings are fully immutable — there's no in-place `push_back`. Any "modification" allocates a new String, which is O(n) and quietly murders performance in a loop. Use `StringBuilder` for anything stack/loop-like, same role as C++ building a string char-by-char.

## Stack

```java
import java.util.*;
Deque<Integer> st = new ArrayDeque<>();   // preferred over legacy Stack class
st.push(1);
st.peek();
st.pop();                  // removes AND returns the value (unlike C++'s void pop())
st.isEmpty();
```

## Queue / Deque

```java
import java.util.*;
Queue<Integer> q = new ArrayDeque<>();
q.offer(1);                // add (prefer over .add(), doesn't throw on failure)
q.peek();
q.poll();                  // removes AND returns (unlike C++'s void pop())

Deque<Integer> dq = new ArrayDeque<>();
dq.addLast(1);
dq.addFirst(0);
dq.pollLast();
dq.pollFirst();
```

## Heap

```java
import java.util.*;
PriorityQueue<Integer> pq = new PriorityQueue<>();              // MIN-heap by default (opposite of C++!)
pq.offer(5);
pq.peek();                  // smallest
pq.poll();                  // removes AND returns

// max-heap:
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
```

## Set / Map (unordered/hash-based)

```java
import java.util.*;
Set<Integer> set = new HashSet<>();
set.add(1);
set.contains(1);            // O(1) avg — Java has no separate .count(), just contains

Map<Integer, Integer> map = new HashMap<>();
map.merge(5, 1, Integer::sum);        // closest equivalent to C++'s um[5] += 1 default-init behavior
// or more plainly:
map.put(5, map.getOrDefault(5, 0) + 1);
map.containsKey(5);
map.get(5);                 // returns null if missing (NOT an "end iterator" — must null-check or use getOrDefault)
```
**Gotcha:** there's no `map[key] += 1` auto-default-init syntax like C++. `getOrDefault` or `merge` are the idioms — forgetting this and calling `map.get(key) + 1` on a missing key throws a NullPointerException (auto-unboxing a null Integer).

## Pair

```java
import java.util.*;
// Java has NO built-in Pair class in core java.util (unlike C++'s std::pair)
// Common workarounds:
int[] pair = {1, 2};                       // fine for primitives
Map.Entry<Integer, Integer> p = Map.entry(1, 2);   // immutable, from java.util.Map
p.getKey();
p.getValue();
// or just define your own tiny record:
record Pair(int first, int second) {}
```
**Gotcha:** this is the biggest structural gap versus C++ — no first-class pair type in core Java. `int[]` of size 2 is the quick-and-dirty LeetCode idiom; `record` (Java 16+) is the clean modern way if you want named fields.

## Iterators / for-each

```java
for (int x : arr) {...}     // same syntax as C++, works on arrays and any Iterable
```

---

**One meta-note for the repo:** the "Gotcha" callouts above are probably worth keeping as a permanent section style in this file specifically *because* you're doing this side-by-side with C++ — the min-heap/max-heap default flip and the mutable-vs-immutable string difference are exactly the kind of thing that causes silent bugs when your brain autopilots from one language's idiom into the other's syntax.
