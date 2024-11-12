# Dijkstra's Algorithm

## 1. Definition
Dijkstra's Algorithm is an algorithm for finding the shortest paths from a source node to all other nodes in a graph with non-negative edge weights. It efficiently calculates the minimum distance from the source to each node by iteratively selecting the node with the smallest known distance and updating the distances of its neighbors.

## 2. Example
Consider a weighted graph with nodes and edges, where the weights represent distances between the nodes. For example:

- Nodes: `A, B, C, D, E`
- Edges with weights: `(A, B, 1), (A, C, 4), (B, C, 2), (B, D, 5), (C, E, 1), (D, E, 3)`

If we set `A` as the source, Dijkstra’s Algorithm will calculate the shortest path from `A` to each node, resulting in the shortest distances to reach `B`, `C`, `D`, and `E`.

## 3. Pseudocode

```plaintext
Function Dijkstra(graph, source):
    Initialize:
        dist[]: Array to store minimum distance from source to each node, set to ∞ for all nodes except source which is 0
        visited[]: Boolean array to track if a node has been visited, initialized to false
        previous[]: Array to track the previous node for each node in the shortest path, initialized to NULL

    For each node in the graph:
        u = FindMinimumDistanceNode(dist, visited)
        if u == -1:
            break  # No more reachable nodes
        
        Mark u as visited
        For each neighbor v of u:
            If v is not visited and dist[u] + weight(u, v) < dist[v]:
                dist[v] = dist[u] + weight(u, v)
                previous[v] = u

    Return dist, previous  # dist[] gives shortest path distances, previous[] helps reconstruct paths

Function FindMinimumDistanceNode(dist, visited):
    minDist = ∞
    minNode = -1
    For each node u:
        if visited[u] == false and dist[u] < minDist:
            minDist = dist[u]
            minNode = u
    Return minNode
```

## 4. Time Complexity
- **Time Complexity:** `O((V + E) log V)`, where `V` is the number of vertices (nodes) and `E` is the number of edges in the graph.
- Using a min-heap (priority queue) to efficiently select the minimum distance node improves the time complexity for dense graphs.

## 5. Sample Input and Output

### Input:
Consider the following graph represented by an adjacency list:

- **Nodes**: `A, B, C, D, E`
- **Edges with weights**:
  - `A -> B` (weight = 1)
  - `A -> C` (weight = 4)
  - `B -> C` (weight = 2)
  - `B -> D` (weight = 5)
  - `C -> E` (weight = 1)
  - `D -> E` (weight = 3)

If we represent nodes as indices, the adjacency list could look like:

```plaintext
graph = {
    A: [(B, 1), (C, 4)],
    B: [(C, 2), (D, 5)],
    C: [(E, 1)],
    D: [(E, 3)],
    E: []
}
source = A
```

### Output:
After running Dijkstra's algorithm from source `A`, the algorithm provides two outputs:

1. **Shortest Distance Array (`dist[]`)**: 
   - `dist[A] = 0`
   - `dist[B] = 1`
   - `dist[C] = 3` (reached via B with a distance of 1 + 2)
   - `dist[D] = 6` (reached via B with a distance of 1 + 5)
   - `dist[E] = 4` (reached via C with a distance of 3 + 1)

2. **Previous Node Array (`previous[]`)**:
   - `previous[A] = None` (or NULL, as it’s the source)
   - `previous[B] = A`
   - `previous[C] = B`
   - `previous[D] = B`
   - `previous[E] = C`

Using the `previous[]` array, you can reconstruct paths from `A` to any other node.

### Full Output Example:

```plaintext
dist = {
    A: 0,
    B: 1,
    C: 3,
    D: 6,
    E: 4
}

previous = {
    A: None,
    B: A,
    C: B,
    D: B,
    E: C
}
```

### Reconstructed Path (for example from `A` to `E`):
- Start at `E`, trace back using `previous[]`: `E -> C -> B -> A`
- **Shortest Path**: `A -> B -> C -> E`
```


