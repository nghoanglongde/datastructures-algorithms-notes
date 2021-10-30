# Depth First Search - DFS
This is the implementation of DFS in the graph has no weight and direction. Time and space complexity of DFS will be based on the appearance of graph

+ Time and Space complexity - Adjacency list: O(V+E) = O(max(V, E)), with V = number of vertices, E = number of edges

+ Time and Space complexity - Adjacency matrix: O(n^2), with n is the number of nodes in the graph

+ In DFS, we use Stack instead of Queue likes BFS

+ DFS not always can find the shortest path from start_input to end_input likes BFS 

```python
def DFS(adjacency_li, visited, path, start):
    next_vertices = [] # dfs using stack instead of queue
    next_vertices.append(start)
    visited[start] = True
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
    path = [-1 for i in range(V)]
    for i in range(E):
        u, v = map(int, input().split())
        adjacency_li[u].append(v)
        adjacency_li[v].append(u)
    start, end = map(int, input().split())
    DFS(adjacency_li, visited, path, start)
    ouput_path(path, start, end)
```
