### Pseudocode for TSP Using Branch and Bound

1. **Function: solveTSPBranchAndBound(graph, n)**
   - `n`: Number of vertices in the graph.
   - `bestCost = ∞`: Initialize the best cost as infinity.
   - `bestPath[]`: Array to store the best path.

2. **Function: calculateLowerBound(currentPath, visited, graph)**
   - `cost = Sum of the current path's edges`
   - For each unvisited vertex:
     - Add the minimum outgoing edge weight to `cost`.
   - Return `cost`.

3. **Function: branchAndBound(level, currentCost, currentPath, visited)**
   - If `level == n`:
     - Add the cost to return to the starting vertex: `currentCost += graph[currentPath[level - 1]][currentPath[0]]`
     - If `currentCost < bestCost`:
       - Update `bestCost = currentCost`
       - Update `bestPath = currentPath`
     - Return
   - For each vertex `v` from 0 to `n - 1`:
     - If `v` is not visited:
       - Mark `v` as visited.
       - Add `v` to `currentPath`.
       - Calculate `newCost = currentCost + graph[currentPath[level - 1]][v]`
       - Calculate the lower bound for the new path using `calculateLowerBound`.
       - If `newCost + lowerBound < bestCost`:
         - Recur: `branchAndBound(level + 1, newCost, currentPath, visited)`
       - Backtrack: Unmark `v` as visited and remove `v` from `currentPath`.

4. **Main Function: tspBranchAndBound(graph, start)**
   - Initialize `visited[]` as `false` for all vertices.
   - Mark `start` as visited.
   - Initialize `currentPath[]` and add `start` to it.
   - Call `branchAndBound(1, 0, currentPath, visited)`.
   - Return `bestCost` and `bestPath`.

### Summary of the Approach
- **Branch and Bound**: This method systematically explores possible paths and uses lower bound calculations to prune paths that cannot yield a better solution than the current best.
- **Efficiency**: By pruning unnecessary branches, the algorithm reduces the number of paths explored compared to brute-force, making it more efficient for medium-sized graphs.
