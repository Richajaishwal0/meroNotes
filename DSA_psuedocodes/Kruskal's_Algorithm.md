### Pseudocode for Kruskal's Algorithm

1. **Define Data Structures**:
   - `Graph`: A list of edges, where each edge has a `source`, `destination`, and `weight`.
   - `parent[]`: Array to represent the parent of each vertex for the Union-Find structure.
   - `rank[]`: Array to represent the rank of each vertex for efficient Union-Find operations.
   - `MST`: A list to store the edges of the Minimum Spanning Tree.

2. **Function: Find (vertex)**
   - If `parent[vertex]` is not the vertex itself:
     - Recursively call `Find(parent[vertex])`.
   - Return `parent[vertex]`.

3. **Function: Union (vertex1, vertex2)**
   - `root1 = Find(vertex1)`
   - `root2 = Find(vertex2)`
   - If `root1` is not equal to `root2`:
     - If `rank[root1] > rank[root2]`: `parent[root2] = root1`
     - Else if `rank[root1] < rank[root2]`: `parent[root1] = root2`
     - Else:
       - `parent[root2] = root1`
       - Increment `rank[root1]`

4. **Function: Kruskal's Algorithm (Graph)**
   - Sort all the edges in non-decreasing order of their weights.
   - Initialize `parent[]` and `rank[]` for all vertices.
   - For each vertex `v`: `parent[v] = v` and `rank[v] = 0`.
   - For each edge `(u, v, weight)` in the sorted edge list:
     - If `Find(u)` is not equal to `Find(v)`:
       - Add the edge `(u, v, weight)` to `MST`.
       - Call `Union(u, v)`.
   - Return `MST`.

5. **Function: Print MST**
   - For each edge `(u, v, weight)` in `MST`:
     - Print `u - v` with `weight`.

---

### Summary of the Approach
- **Sorting**: Sort the edges by weight to ensure the smallest edge is considered first.
- **Union-Find**: Use a Union-Find data structure to detect cycles and determine if an edge should be added to the MST.
- **Building the MST**: Add edges one by one, ensuring no cycles are formed, until all vertices are connected.

This pseudocode gives a clear and efficient way to implement Kruskal's Algorithm. Let me know if you'd like any part of it explained further or modified!
