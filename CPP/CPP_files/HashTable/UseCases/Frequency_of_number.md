## Count Frequencies of Elements
## Problem: Given an array, count the frequency of each element
## Example Input: arr = [1, 2, 2, 3, 3, 3]
## Output: {1: 1, 2: 2, 3: 3}

Code:
```c++
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{   int arr[]={1,2,2,3,3};
    unordered_map<int,int> f;
   for (int i=0;i<5;i++)
   {
           if (f.find(arr[i])==f.end())
           {
               f[arr[i]]=1;
           }
           else{
               f[arr[i]]++;
           }
       }
    for (auto &it:f)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
```
