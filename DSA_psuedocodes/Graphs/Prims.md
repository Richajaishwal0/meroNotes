## Prims algorithm 
### Definition
Prim's algorithm is a greedy algorithm that finds a Minimum Spanning Tree (MST) for a weighted, undirected graph. The MST is a subset of the edges in the graph that connects all vertices together without any cycles and with the minimum possible total edge weight.

### Example
Consider a graph with vertices `{A, B, C, D}` and weighted edges:
- `A - B` with weight 4
- `A - C` with weight 1
- `B - C` with weight 3
- `B - D` with weight 2
- `C - D` with weight 5

Prim's algorithm will start from a source (say, `A`) and build the MST step by step by adding the shortest edge that connects a vertex in the MST with a vertex outside the MST.

### Pseudocode
```plaintext
Define Data Structures:
    Graph: Adjacency list or adjacency matrix representation of the graph.
    priorityQueue: A min-heap or a priority queue to store vertices based on the minimum edge weight.
    inMST[]: Boolean array to check if a vertex is included in the Minimum Spanning Tree (MST).
    key[]: Array to store the minimum weight edge for each vertex.
    parent[]: Array to store the parent of each vertex in the MST.

Function: Prim’s Algorithm(Graph, source)
    Initialize key[] with infinity for all vertices and key[source] = 0.
    Initialize parent[] with -1 for all vertices.
    Initialize inMST[] with false for all vertices.
    Add the source vertex to the priorityQueue with a key value of 0.

    While priorityQueue is not empty:
        Extract the vertex u with the minimum key value from the queue.
        Set inMST[u] = true.
        
        For each neighbor v of u in the graph:
            If v is not in the MST and the weight of edge u-v is less than key[v]:
                Update key[v] with the weight of u-v.
                Update parent[v] to u.
                Add v to the priorityQueue with the updated key[v].

Function: Print MST
    For each vertex v from 1 to numberOfVertices - 1:
        Print parent[v] - v with the weight key[v].
```

### Time Complexity
The time complexity of Prim's algorithm is `O(E log V)`, where `V` is the number of vertices and `E` is the number of edges, assuming we use a min-heap priority queue.

### Input
An adjacency matrix or list representing a connected, weighted, undirected graph.
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
- Starting from `A`, the MST might look like:
    ```
    A - C: weight 1
    B - D: weight 2
    C - B: weight 3
    ```
