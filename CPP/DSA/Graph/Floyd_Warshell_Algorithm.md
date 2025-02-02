
### The Floyd Warshall Algorithm is an all pair shortest path algorithm unlike Dijkstra and Bellman Ford which are single source shortest path algorithms. This algorithm works for both the directed and undirected weighted graphs can handle graphs with both positive and negative edge weights. But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative). It follows Dynamic Programming approach to check every possible path going via every possible node in order to calculate shortest distance between every pair of nodes.
Code
```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define V 4 
#define INF INT_MAX
void floydWarshall(int graph[][V])
{
 
 for (int v=0;v<4;v++)
 {
     for (int i=0;i<4;i++)
     {
         for (int j=0;j<4;j++)
         {
             
             if (graph[i][v]!=INF && graph [v][j]!=INF)
             {
                 graph[i][j]=min(graph[i][j], graph[i][v]+graph[v][j]);
             }
         }
     }
 }
//   to detect negative cycle
for (int i=0;i<4;i++)
 {
     for (int j=0;j<4;j++)
     {
         if (graph[i][j]<0)
         {
             cout<<"negative cycle is present";
             break;
     }
     
 }
 }
 for (int i=0;i<4;i++)
 {
     for (int j=0;j<4;j++)
     {
         if (graph[i][j]==INF)
         {
             cout<<"-1"<<" ";
         }
         else{
             cout<<graph[i][j]<<" ";
         }
         
     }
     cout<<endl;
 }
}





int main()

{
     int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    // Function call
    floydWarshall(graph);
    return 0;
}
```
Output:
```
0 5 8 9 
-1 0 3 4 
-1 -1 0 1 
-1 -1 -1 0 
```
## The complexity analysis of the Floyd Warshall algorithm is given below
Time Complexity: O(V3), where V is the number of vertices in the graph and we run three nested loops each of size V
Auxiliary Space: O(V2), to create a 2-D matrix in order to store the shortest distance for each pair of nodes.
