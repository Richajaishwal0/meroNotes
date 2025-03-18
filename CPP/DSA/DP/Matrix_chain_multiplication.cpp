#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrix(vector <int> & arr, vector<vector<int>> & dp,int i, int j)
{
     if (i==j )return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int minn=INT_MAX;
    for (int k=i;k<j;k++)
        {
            int steps= arr[i-1] * arr[j] * arr[k]+ matrix(arr,dp,i,k) +matrix(arr,dp,k+1,j);
            minn=min(steps, minn);
        }
    return minn;
}
int main()
{
    vector <int> arr={1,2,3,4,3};
       vector<vector<int>> dp(5,vector<int> (5,-1));
   int ans= matrix(arr,dp,1,arr.size()-1);
    cout<<ans;
}

Output:
30
