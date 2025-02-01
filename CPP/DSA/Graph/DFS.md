## DFS
In Depth First Search (or DFS) for a graph, we traverse all adjacent vertices one by one. When we traverse an adjacent vertex, we completely finish the traversal of all vertices reachable through that adjacent vertex. This is similar to a tree, where we first completely traverse the left subtree and then move to the right subtree. The key difference is that, unlike trees, graphs may contain cycles (a node may be visited more than once). To avoid processing a node multiple times, we use a boolean visited array.
**Note**: There can be multiple DFS traversals of a graph according to the order in which we pick adjacent vertices. Here we pick vertices as per the insertion order.

## Input: adj =  [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
![image](https://github.com/user-attachments/assets/1d581b0f-5503-48ab-9c74-2c715e04b99f)

## **Output** : 1 2 0 3 4
Explanation:  The source vertex s is 1. We visit it first, then we visit an adjacent. 
Start at 1: Mark as visited. Output: 1
Move to 2: Mark as visited. Output: 2
Move to 0: Mark as visited. Output: 0 (backtrack to 2)
Move to 3: Mark as visited. Output: 3 (backtrack to 2)
Move to 4: Mark as visited. Output: 4 (backtrack to 1)


Not that there can be more than one DFS Traversals of a Graph. For example, after 1, we may pick adjacent 0 instead of 2 and get a different DFS. Here we pick in the insertion order.
Code:
```cpp
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void dfsrec(vector<vector<int>>adj, vector<bool>&visited,int s)
{
    visited[s]=true;
    cout<<s<<" ";
    
    for (int x:adj[s])
    {
        if (!visited[x])
        {
            dfsrec(adj,visited,x);
        }
    }
}
void dfs(vector<vector<int>> adj, int s)
{
    vector<bool>visited(adj.size(),false);
    dfsrec(adj,visited,s);
}
int main()
{
    vector<vector<int>> adj(5);
    vector<vector<int>> edge={{0,1},{0,2},{0,3},{2,4},{2,3}};
    for (auto &i:edge)
    {
          addEdge(adj,i[0],i[1]);
    }
    
    dfs(adj,0);
//   for (auto &i:adj)
//   {
//       for (int j:i)
//       {
//             cout<<j<<" ";
//       }
//       cout<<endl;
//   }
}
```
Output:
```
0 1 2 4 3
```
** Note ** : What if there is no continuous range of elements in the graph?? 
Solution: Use **hashmap** with type int, vector 
here is the example code :
```cpp
#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;

void dfsrec(unordered_map<int,vector<int>> &adj,vector<bool> & visited, int i)
{
    visited[i]= true;
    cout<<i<<" ";
    for (int x: adj[i])
    {
        if (!visited[x])
        {
            dfsrec(adj,visited,x);
        }
    }
}
void dfs(unordered_map<int,vector<int>> &adj)
{
    vector<bool>visited(adj.size(),false);
    int srtnode=adj.begin()->first;
    dfsrec(adj,visited,srtnode );
}
void addEdge(unordered_map<int,vector<int>> &adj, int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main()
{
    unordered_map<int,vector<int>> adj;
    vector<vector<int>> edges={{3,4},{3,7},{3,9},{4,1},{4,9},{1,9},{7,9}};
    for (auto & x: edges)
    {
        addEdge(adj,x[0],x[1]);
    }
    for (auto & x:adj)
    {
        cout<<x.first<<":";
        for (auto & i: x.second)
        {
            cout<<i<<",";
        }
        cout<<"\n";
    }
    dfs(adj);
    return 0;
}
```
Output:
```
1:4,9,
9:3,4,1,7,
7:3,9,
4:3,1,9,
3:4,7,9,
1 4 3 7 9 
```
