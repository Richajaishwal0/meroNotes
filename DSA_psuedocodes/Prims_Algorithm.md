### Pseudocode for Prim's Algorithm

1. **Define Data Structures**:
   - `Graph`: Adjacency list or adjacency matrix representation of the graph.
   - `priorityQueue`: A min-heap or a priority queue to store vertices based on the minimum edge weight.
   - `inMST[]`: Boolean array to check if a vertex is included in the Minimum Spanning Tree (MST).
   - `key[]`: Array to store the minimum weight edge for each vertex.
   - `parent[]`: Array to store the parent of each vertex in the MST.

2. **Function: Prim's Algorithm (Graph, source)**
   - Initialize `key[]` with infinity for all vertices and `key[source] = 0`.
   - Initialize `parent[]` with `-1` for all vertices.
   - Initialize `inMST[]` with `false` for all vertices.
   - Add the source vertex to the `priorityQueue` with a key value of 0.
   
3. **While `priorityQueue` is not empty**:
   - Extract the vertex `u` with the minimum key value from the queue.
   - Set `inMST[u] = true`.
   - For each neighbor `v` of `u` in the graph:
     - If `v` is not in the MST and the weight of edge `u-v` is less than `key[v]`:
       - Update `key[v]` with the weight of `u-v`.
       - Update `parent[v]` to `u`.
       - Add `v` to the `priorityQueue` with the updated `key[v]`.

4. **Function: Print MST**
   - For each vertex `v` from 1 to `numberOfVertices - 1`:
     - Print `parent[v] - v` with the weight `key[v]`.

---

### Summary of the Approach
- **Initialization**: Set all key values to infinity and use a priority queue to efficiently fetch the vertex with the smallest edge weight.
- **Building the MST**: Iterate until all vertices are included in the MST, updating key values and parent links as needed.
- **Output**: Use the `parent[]` array to display the MST.
