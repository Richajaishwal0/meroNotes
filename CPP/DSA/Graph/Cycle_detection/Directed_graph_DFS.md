## DFS
o find cycle in a directed graph we can use the  Depth First Traversal  (DFS) technique. It is based on the idea that there is a cycle in a graph  only if there is a back edge  [i.e., a node points to one of its ancestors in a DFS tree] present in the graph. 


To detect a back edge, we need to keep track of the visited nodes that are in the current recursion stack [i.e., the current path that we are visiting].  Please note that all ancestors of a node are present in recursion call stack during DFS. So if there is an edge to an ancestor in DFS, then this is a back edge. 


Note: If the graph is disconnected then get the DFS forest and check for a cycle in individual graphs by checking back edges

Code:
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool cyclicUtil(vector<vector<int>> adj,vector<bool> visited, vector<bool>recstack, int s)
{
    if (!visited[s])
    {
        visited[s]=true;
        recstack[s]=true;
        
        
        for (int x:adj[s])
        {
            if (!visited[x] && cyclicUtil(adj,visited,recstack,x))
            {
                return true;
            }
            else if (recstack[x])
            {
                return true;
            }
        }
    }
        recstack[s]=false;
        return false;
}

bool iscyclic(vector<vector<int>> adj, int s)
{
    vector<bool> visited(adj.size(),false);
    vector <bool> recstack(adj.size(),false);
    
    for (int i=0;i<adj.size();i++)
    {
        if (!visited[i] && cyclicUtil(adj,visited,recstack,s))
        {
            return true;
        }
       
    }
    return false;
}
int main()
{
    vector<vector<int>>adj(5);
     adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    
    if (iscyclic(adj,0))
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
```
Output:
```
True
```
