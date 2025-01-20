## Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.
Code:
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void TopologicalSortUtil(vector<vector<int>> &adj, vector<bool>&visited, stack<int> &st, int s)
{
    visited[s]=true;
    for (int x:adj[s])
    {
        if (!visited[x])
        {
            TopologicalSortUtil(adj,visited,st,x);
        }
    }
    st.push(s);
}
void TopologicalSort( vector<vector<int>> adj, int V)
{
    vector<bool>visited(V);
    stack<int> st;
    for (int i=0;i<V;i++)
    {
        if (!visited[i])
        {
            TopologicalSortUtil(adj,visited,st,i);
        }
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main()
{
    vector<vector<int>> edge={{ 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };
    vector<vector<int>> adj(4);
    
    for (auto &i:edge)
    {
        adj[i[0]].push_back(i[1]);
    }
    TopologicalSort(adj,4);
    return 0;
}
```
Output:
```
3 0 1 2
```
