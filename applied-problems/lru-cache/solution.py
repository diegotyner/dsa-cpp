
class LL_Node():
    def __init__(self, key, val):
        self.forward: LL_Node|None = None
        self.back: LL_Node|None = None
        self.key = key
        self.val = val

class LRU_Cache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.key_to_node = {}
        self.head: LL_Node|None = None
        self.tail: LL_Node|None = None

    def remove(self, node: LL_Node):
        next, prev = node.forward, node.back
        if next:
            next.back = prev
        else:
            self.head = prev
        if prev:
            prev.forward = next
        else:
            self.tail = next

    def append(self, node: LL_Node):
        old_tail = self.tail
        if old_tail:
            old_tail.back = node
            node.forward = old_tail
        else:
            self.head = node
            node.forward = None
        node.back = None
        self.tail = node

    def put(self, key: int, val: int) -> None:
        node = None
        if key in self.key_to_node:
            node = self.key_to_node[key]
            node.val = val
            self.remove(node)
        else: # else, need to create
            node = LL_Node(key, val)
            self.key_to_node[key] = node
            if len(self.key_to_node) > self.capacity: # need to evict
                old_head = self.head
                if old_head:
                    self.remove(old_head)
                    self.key_to_node.pop(old_head.key)
        self.append(node)

    def get(self, key: int) -> int:
        if key not in self.key_to_node:
            return -1
        node = self.key_to_node[key]
        self.remove(node)
        self.append(node)
        return node.val
