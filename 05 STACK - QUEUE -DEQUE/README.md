# Stack - Queue - Deque
## Stack
Stack is a data structure that store items in the **LIFO** (Last in first out) manner

![image](https://user-images.githubusercontent.com/43443323/124728905-2eba7180-df3a-11eb-8b0a-ae9b81f36706.png)


```python
# implement using list
stack = []

stack.append(value) # add item

value = stack.pop() # get the last item and remove it from the stack

size = len(stack) # get size of stack

# implement using Collections.deque
from collections import deque
stack = deque()

stack.append(value) # add item

value = stack.pop() # get the last item and remove it from the stack

```
Collections.deque was built from **Doubly-linked list** data structure, so time complexity for operations like add or remove take 0(1), retrive item like stack[1] take O(n) to traversal

List was built upon blocks of contiguous memory, meaning that the items in the list are stored right next to each other. So retrive item like stack[1] just take O(1), because of the contiguous memory layout so that list might need to take more time to .append() some objects

## Queue
Queue is a data structure that store items in the **FIFO** (First in first out) manner

![image](https://user-images.githubusercontent.com/43443323/124730560-ac32b180-df3b-11eb-9bf8-5ad33db9dfd8.png)

**Enqueue**: add an item to the queue

**Dequeue**: remove an item to the queue

**Front**: the top item

**Back or rear**: the last item

```python
# implement using list
queue = []

queue.append(value) # add item

value = queue.pop(0) # get the first item and remove it from the queue

size = len(queue) # get size of queue

# implement using deque
from collections import deque
queue = deque()

queue.append(value) # add item

value = queue.popleft() # get the first item and remove it from the queue

size = len(queue) # get size of queue
```
The same problem with implement stack using list

## Deque
Combine of stack and queue, deque was built from **Doubly-linked list** data structure, each entry has store in its own block and reference to both previous and next block
