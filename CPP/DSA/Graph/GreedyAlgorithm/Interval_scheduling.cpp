#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int>a, vector<int>b)
{
    return (a[1]<b[1]);
}
vector<vector<int>> Scheduling(vector<vector<int>> vec, int N)
{
    sort(vec.begin(),vec.end(),comp);
    vector<vector<int>> ans;
    ans.push_back(vec[0]);
    int i=0,j=1;
    while(j<N)
    {
        if (vec[j][0]>=vec[i][1] && vec[j][1]>vec[i][1])
        {
            ans.push_back({vec[j][0],vec[j][1]});
            i=j;
        }
        j++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr={{3,7},{2,4},{5,8},{6,9},{1,11},{10,12},{0,3}};
    int N=arr.size();
    vector<vector<int>> a=Scheduling(arr,N);
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<a[i].size();j++)
        {
            cout << a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
