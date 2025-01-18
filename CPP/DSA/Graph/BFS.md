## BFS
The algorithm starts from a given source and explores all reachable vertices from the given source. It is similar to the Breadth-First Traversal of a tree. Like tree, we begin with the given source (in tree, we begin with root) and traverse vertices level by level using a queue data structure. The only catch here is that, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array.
![image](https://github.com/user-attachments/assets/6824943f-60ce-48c3-a101-a828984e0944)

- Initialization: Enqueue the given source vertex into a queue and mark it as visited.

  - Exploration: While the queue is not empty:
    - Dequeue a node from the queue and visit it (e.g., print its value).
    - For each unvisited neighbor of the dequeued node:
      - Enqueue the neighbor into the queue.
      - Mark the neighbor as visited.
- Termination: Repeat step 2 until the queue is empty.
This algorithm ensures that all nodes in the graph are visited in a breadth-first manner, starting from the starting node.

Code 
```cpp
#include<iostream>
#include <queue>
using namespace std;


void bfs(vector<vector<int>> adjlst,int s)
{
    queue <int>q;
    vector<int>visited(5,false);
    visited[s]=true;
    q.push(s);
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        
        for (int x:adjlst[curr])
        {
            if (!visited[x])
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    
}
void addEdge(vector<vector<int>> &adjlst, int src,int nei)
{
    adjlst[src].push_back(nei);
    adjlst[nei].push_back(src);
}
int main()
{
    vector<vector<int>> adjlst(5);
    addEdge(adjlst,0,1);
    addEdge(adjlst,0,2);
    addEdge(adjlst,1,2);
    addEdge(adjlst,1,3);
    addEdge(adjlst,2,4);
    cout<<"BFS: ";
    bfs(adjlst,0);
   return 0; 
}
```
Output:
```
BFS: 0 1 2 3 4
```
