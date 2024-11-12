## Kruskal Algorithm 
###  Definition
Kruskal's algorithm is a greedy algorithm that finds a Minimum Spanning Tree (MST) for a connected, weighted, undirected graph. It works by adding the smallest edge to the MST, ensuring no cycles are formed, and continues until all vertices are connected.

### Example
Consider a graph with vertices `{A, B, C, D}` and weighted edges:
- `A - B` with weight 4
- `A - C` with weight 1
- `B - C` with weight 3
- `B - D` with weight 2
- `C - D` with weight 5

Kruskal's algorithm will sort these edges by weight and add the smallest edge to the MST until it connects all vertices without forming any cycles.

### Pseudocode
```plaintext
Define Data Structures:
    Graph: A list of edges, where each edge has a source, destination, and weight.
    parent[]: Array to represent the parent of each vertex for the Union-Find structure.
    rank[]: Array to represent the rank of each vertex for efficient Union-Find operations.
    MST: A list to store the edges of the Minimum Spanning Tree.

Function: Find (vertex)
    If parent[vertex] is not the vertex itself:
        Recursively call Find(parent[vertex])
    Return parent[vertex]

Function: Union (vertex1, vertex2)
    root1 = Find(vertex1)
    root2 = Find(vertex2)
    If root1 is not equal to root2:
        If rank[root1] > rank[root2]: 
            parent[root2] = root1
        Else if rank[root1] < rank[root2]: 
            parent[root1] = root2
        Else:
            parent[root2] = root1
            Increment rank[root1]

Function: Kruskal’s Algorithm (Graph)
    Sort all edges in non-decreasing order of their weights.
    Initialize parent[] and rank[] for all vertices.
    For each vertex v:
        parent[v] = v
        rank[v] = 0
    For each edge (u, v, weight) in the sorted edge list:
        If Find(u) is not equal to Find(v):
            Add the edge (u, v, weight) to MST
            Call Union(u, v)
    Return MST

Function: Print MST
    For each edge (u, v, weight) in MST:
        Print u - v with weight
```

### Time Complexity
The time complexity of Kruskal's algorithm is `O(E log E)`, where `E` is the number of edges in the graph, as sorting the edges dominates the computation time. With efficient Union-Find, each union/find operation takes nearly constant time.

### Input
A list of edges representing a connected, weighted, undirected graph.
Example:
- Graph represented as:
    ```
    A - B: weight 4
    A - C: weight 1
    B - C: weight 3
    B - D: weight 2
    C - D: weight 5
    ```

### Output
The edges in the MST and their weights.
Example:
- The MST might look like:
    ```
    A - C: weight 1
    B - D: weight 2
    B - C: weight 3
    ```
