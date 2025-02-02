### n Kruskal’s algorithm, sort all edges of the given graph in increasing order. Then it keeps on adding new edges and nodes in the MST if the newly added edge does not form a cycle. It picks the minimum weighted edge at first and the maximum weighted edge at last. Thus we can say that it makes a locally optimal choice in each step in order to find the optimal solution.
How to find MST using Kruskal’s algorithm?
Below are the steps for finding MST using Kruskal’s algorithm:

Sort all the edges in non-decreasing order of their weight. 
Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
Repeat step#2 until there are (V-1) edges in the spanning tree.
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class DSU{
    int * parent;
    int * rank;
public:
    DSU(int n)
    {
        parent=new int[n];
        rank=new int[n];
          for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    int find(int i)
    {
        if(parent[i]==-1)
        {return i;}
        return parent[i]=find(parent[i]);
        
    }
    void unite(int x, int y)
    {
        int s1=find(x);
        int s2=find(y);
        if (s1!=s2)
        {
            if (rank[s1]<rank[s2])
            {
                parent[s1]=s2;
            }
            else if (rank[s2]<rank[s1])
            {
                parent[s2]=s1;
            }
            else{
                parent[s2]=s1;
                rank[s1]++;
            }
        }
    }
    
};
class Graph{
    vector<vector<int>> edgelist;
    int V;
    public:
    Graph(int V)
    {
        this->V=V;
    }
    void addEdge(int x, int y , int w)
    {
        edgelist.push_back({w,x,y});
    }
    
    void krukshal()
    {
        
        sort(edgelist.begin(),edgelist.end());
        DSU  s(V);
         int ans=0;
        int count=0;
        for (auto i : edgelist)
        {
            int w=i[0];
            int x=i[1];
            int y=i[2];
            if (s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans+=w;
                count++;
                cout<<x<<" -- "<<y<<" == "<<w<<endl;
            }
            if (count==V-1){
                break;
            }
            
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.krukshal();
}
```
Output:
```
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
```
Time Complexity: O(E * logE) or O(E * logV) 

Sorting of edges takes O(E * logE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(logV) time.
So overall complexity is O(E * logE + E * logV) time. 
The value of E can be at most O(V2), so O(logV) and O(logE) are the same. Therefore, the overall time complexity is O(E * logE) or O(E*logV)
