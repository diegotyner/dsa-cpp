# LRU Cache

Design problem — tests your ability to combine data structures (hash map +
doubly linked list) to hit tight time complexity requirements.

## Problem

Design a data structure that implements a **Least Recently Used (LRU) cache**
with a fixed `capacity`.

- When the cache is full and a new key needs to be inserted, evict the **least
  recently used** key first.
- Accessing a key (via `get` or `put`) counts as a "use" and marks that key as
  the **most recently used**.

## API

```
LRUCache(capacity: int)
    Initialize the cache with a positive size capacity.

get(key: int) -> int
    Return the value associated with `key` if it exists, otherwise -1.
    Marks `key` as most recently used.

put(key: int, value: int) -> None
    Insert or update the value for `key`.
    Marks `key` as most recently used.
    If inserting a new key exceeds `capacity`, evict the least recently
    used key first.
```

## Expected behavior

- Both `get` and `put` must run in **O(1) average time**.
- `put` on a key that already exists updates its value (does not count as
  eviction) and refreshes its recency.
- Capacity is fixed at construction and does not change.

## Example

```
LRUCache cache = new LRUCache(2)  // capacity = 2

cache.put(1, 1)     //            cache: {1=1}
cache.put(2, 2)     //            cache: {1=1, 2=2}
cache.get(1)        // returns 1, cache: {2=2, 1=1}
cache.put(3, 3)     // evicts key 2, cache: {1=1, 3=3}
cache.get(2)        // returns -1 (not found)
cache.put(4, 4)     // evicts key 1, cache: {3=3, 4=4}
cache.get(1)        // returns -1 (not found)
cache.get(3)        // returns 3
cache.get(4)        // returns 4
```

## Constraints

- `1 <= capacity <= 3000`
- `0 <= key, value <= 10^4`
- At most `2 * 10^5` calls total to `get` and `put`
