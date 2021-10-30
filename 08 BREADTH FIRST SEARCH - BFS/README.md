# Breadth First Search - BFS
This is the implementation of BFS in the graph has no weight and direction. Time and space complexity of BFS will be based on the appearance of graph

+ Time and Space complexity - Adjacency list: O(V) = O(V), with V = number of vertices

+ Time and Space complexity - Adjacency matrix: O(n^2), with n is the number of nodes in the graph

+ In BFS, we use Queue instead of Stack likes DFS, and BFS always can find the shortest path from start_input to end_input

```python
from queue import Empty, Queue

def BFS(adjacency_li, visited, path, start):
    next_vertices = Queue()
    next_vertices.put(start)
    visited[start] = True
    while not next_vertices.empty():
        u = next_vertices.get()
        for v in adjacency_li[u]:
            if not visited[v]:
                visited[v] = True
                path[v] = u
                next_vertices.put(v) 

def ouput_path(path, start, end):
    temp = []
    if start == end:
        print(start)
        return
    elif path[end] == -1:
        print("No path")
        return 
    else:
        while True:
            temp.append(end)
            end = path[end]
            if start == end:
                temp.append(start)
                break
        for i in range(len(temp) - 1, -1, -1):
            print(temp[i], end=' ')


if __name__ == '__main__':
    V, E = map(int, input().split())
    adjacency_li = [[] for i in range(V)]
    visited = [False for i in range(V)]
    path = [-1 for i in range(V)]
    for i in range(E):
        u, v = map(int, input().split())
        adjacency_li[u].append(v)
        adjacency_li[v].append(u)
    start, end = map(int, input().split())
    BFS(adjacency_li, visited, path, start)
    ouput_path(path, start, end)
```
