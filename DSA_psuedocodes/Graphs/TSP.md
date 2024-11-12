
# TSP (Traveling Salesman Problem) Using Branch and Bound

## 1. Definition
The Traveling Salesman Problem (TSP) using the Branch and Bound approach finds the shortest possible route that visits each vertex once and returns to the starting point. The algorithm uses a bounding function to eliminate paths that cannot possibly yield the optimal solution, significantly reducing the number of paths that need to be explored.

## pseudocode
```plaintext
Function: solveTSPBranchAndBound(graph, n)
    n: Number of vertices in the graph.
    bestCost = ∞: Initialize the best cost as infinity.
    bestPath[]: Array to store the best path.

Function: calculateLowerBound(currentPath, visited, graph)
    cost = Sum of the current path's edges
    For each unvisited vertex:
        Add the minimum outgoing edge weight to cost.
    Return cost.

Function: branchAndBound(level, currentCost, currentPath, visited)
    If level == n:
        Add the cost to return to the starting vertex: currentCost += graph[currentPath[level - 1]][currentPath[0]]
        If currentCost < bestCost:
            Update bestCost = currentCost
            Update bestPath = currentPath
        Return
    For each vertex v from 0 to n - 1:
        If v is not visited:
            Mark v as visited.
            Add v to currentPath.
            Calculate newCost = currentCost + graph[currentPath[level - 1]][v]
            Calculate the lower bound for the new path using calculateLowerBound.
            If newCost + lowerBound < bestCost:
                Recur: branchAndBound(level + 1, newCost, currentPath, visited)
            Backtrack: Unmark v as visited and remove v from currentPath.

Main Function: tspBranchAndBound(graph, start)
    Initialize visited[] as false for all vertices.
    Mark start as visited.
    Initialize currentPath[] and add start to it.
    Call branchAndBound(1, 0, currentPath, visited).
    Return bestCost and bestPath.
```

## 3. Explanation of Terms and Concepts
- **Level**: Represents the depth of the current path in the solution tree (how many vertices are visited).
- **`currentPath[]`**: Stores the vertices visited so far in the path.
- **`visited[]`**: Tracks which vertices have been visited to avoid revisiting them.
- **`currentCost`**: Cumulative cost of the current path.
- **`bestCost`**: The minimum cost found so far across all explored paths.
- **`bestPath[]`**: The path with the minimum cost.
- **`calculateLowerBound`**: Estimates the minimum possible cost to complete the TSP from the current path.

## 4. Time Complexity
The worst-case time complexity of the Branch and Bound approach for TSP is `O(n!)`, where `n` is the number of vertices. However, due to branch pruning, it is generally much faster than a brute-force solution.

## 5. Sample Input and Output

### Input:
Consider a 4-vertex graph with the following adjacency matrix:

```plaintext
graph = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]
```
- **Start Vertex**: `0`

### Output:
The algorithm returns the minimum cost and the path:

```plaintext
Minimum Cost: 80
Best Path: [0, 1, 3, 2, 0]
```

In this example:
- The minimum cost path starts at vertex 0, visits vertices 1, 3, and 2, and then returns to vertex 0, with a total cost of 80.

