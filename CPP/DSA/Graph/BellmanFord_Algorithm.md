### The Bellman-Ford algorithm is a single-source shortest path algorithm that finds the shortest path from a given source vertex to all other vertices in a graph. Unlike Dijkstra’s algorithm, Bellman-Ford can handle graphs with negative edge weights, making it useful in various scenarios.
Code:
```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


void bellmanford(vector<vector<int>> graph, int V, int src)
{
   
    vector<int> dist(V,INT_MAX);
     dist[src]=0;
    for (int i=0;i<V-1;i++)
    {
        for (auto it: graph)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if (dist[u]!=INT_MAX && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    
    for (auto it: graph)
    {    
             int u=it[0];
            int v=it[1];
            int wt=it[2];
         if (dist[u]!=INT_MAX && dist[u]+wt<dist[v])
            {
               cout<<"Negative cycles detected.";
               return;
            }
    }
    for (int i=0;i<V;i++)
    {
        cout<<i<<"\t\t\t"<<dist[i]<<endl;
    }
}


int main()
{
    int V=6;
    int src=0;
    vector<vector<int>> graph
        = { { 0, 1, 5 }, { 0, 2, 7 }, { 1, 2, 3 },
            { 1, 3, 4 }, { 1, 4, 6 }, { 3, 4, -1 },
            { 3, 5, 2 }, { 4, 5, -3 } };
            bellmanford(graph,V,src);

    return 0;
}
```
Output:
```
0			0
1			5
2			7
3			9
4			8
5			5
```
![image](https://github.com/user-attachments/assets/46720278-9ddc-4915-a0d0-44ca68c18112)
