# Depth First Search - DFS
This is the implementation of DFS in the graph has no weight and direction

Time complexity: O(V+E), with V = number of vertices, E = number of edges

```python
def DFS(adjacency_li, visited, path, start):
    next_vertices = [] # dfs using stack instead of queue
    next_vertices.append(start)
    visited[start] = True
    path[start] = -1
    while len(next_vertices) > 0:
        u = next_vertices.pop()
        for v in adjacency_li[u]:
            if not visited[v]:
                visited[v] = True
                path[v] = u
                next_vertices.append(v) 

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
    path = [0 for i in range(V)]
    for i in range(E):
        u, v = map(int, input().split())
        adjacency_li[u].append(v)
        adjacency_li[v].append(u)
    start, end = map(int, input().split())
    DFS(adjacency_li, visited, path, start)
    ouput_path(path, start, end)
```

