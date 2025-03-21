#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dfs(vector<bool> & visited, vector <vector<int>> &adjlst, vector <int> &dp, int i)
{
    visited[i]=true;
    for (int x: adjlst[i])
        {
            if (!visited[x])
            {
                dfs(visited, adjlst, dp, x);
            }
                dp[i]=max(dp[i], 1+ dp[x]);
            
        }
}
int  longestPath(vector <vector<int>> &adjlst, int V)
{
    vector <bool> visited(V,false);
    vector <int> dp(V+1,0);
    for (int i=0;i<V;i++)
        {
            if (!visited[i])
            {
                dfs(visited, adjlst, dp, i);
            }
        }
    int max_=INT_MIN;
    for (int i=0;i<=V;i++)
        {
            max_=max(max_, dp[i]);
        }
    return max_;
}
int main()
{
    vector<vector<int>> array={{1, 2},{1, 3},{3, 2},{2, 4},{3, 4}};
    int V=4;
    vector <vector<int>> adjlst(V+1) ;
    for (auto &x: array)
        {
            adjlst[x[0]].push_back(x[1]);
        }
    
    int ans=longestPath(adjlst, V);
    cout<<ans;
    return 0;
}
