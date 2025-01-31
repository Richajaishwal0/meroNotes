## The idea is to generate a  SPT (shortest path tree)  with a given source as a root.
Maintain an Adjacency Matrix with two sets, 
- one set contains vertices included in the shortest-path tree, 
- other set includes vertices not yet included in the shortest-path tree. 
At every step of the algorithm, find a vertex that is in the other set (set not yet included) and has a minimum distance from the source. 

```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define V 9

int minDistance(vector<int> dist, vector<bool> spnSet)
{
    int min=INT_MAX;
    int min_index;
    for (int v=0;v<V;v++)
    {
        if (spnSet[v]==false && dist[v]<=min)
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
void printSolution(vector<int> dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
void djkstra(vector<vector<int>> graph, int src)
{
    vector <int> dist(V);
    vector <bool> spnSet(V);
    for (int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        spnSet[i]=false;
    }
    dist[src]=0;
    for (int count=0;count<V-1;count++)
    {
        int u=minDistance(dist,spnSet);
        spnSet[u]=true;
        for (int v=0; v<V;v++)
        {
            if (!spnSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+ graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main()
{
  vector<vector<int>> graph={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
                        
                        
    djkstra(graph,0);
}
```
Output:
```
Vertex 	 Distance from Source
0 				0
1 				4
2 				12
3 				19
4 				21
5 				11
6 				9
7 				8
8 				14
```
