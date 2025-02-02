### The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, and the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST. 

#### How does Prim’s Algorithm Work? 
The working of Prim’s algorithm can be described by using the following steps:

Step 1: Determine an arbitrary vertex as the starting vertex of the MST.
Step 2: Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex).
Step 3: Find edges connecting any tree vertex with the fringe vertices.
Step 4: Find the minimum among these edges.
Step 5: Add the chosen edge to the MST if it does not form any cycle.
Step 6: Return the MST and exit

Code:
```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define V 5


int minDistance(vector<bool> &mst, vector<int> &key)
{
    int min=INT_MAX;
    int min_index;
    for (int i=0;i<V;i++)
    {
        if (!mst[i] && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void primMST(vector<vector<int>> &graph)
{
    vector<int> key(V,INT_MAX);
    vector<int> parent(V);
    vector<bool> MST(V,false);
    key[0]=0;
    for (int i=0;i<V-1;i++)
    {
        int u=minDistance(MST,key);
        MST[u]=true;
        for (int v=0;v<V;v++)
        {
            if (!MST[v] && graph[u][v]  && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
      for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
}
int main()
{
      vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                { 2, 0, 3, 8, 5 },
                                { 0, 3, 0, 0, 7 },
                                { 6, 8, 0, 0, 9 },
                                { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}
```
Output:
```

0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5 

```
Time Complexity: O(V2), If the input graph is represented using an adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E * logV) with the help of a binary heap.  In this implementation, we are always considering the spanning tree to start from the root of the graph
Auxiliary Space: O(V)
