```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int ans[]={4,1,0,88,4,-7};
    // insertion sort 
    int n=sizeof(ans)/sizeof(ans[0]);
   int j;
    for (int i=0;i<n;i++)
    {
        int key=ans[i];
        int j=i-1;
        while (j>=0 && ans[j]>key)
        {
            ans[j+1]=ans[j];
            j--;
        }
        ans[j+1]=key;
        
    }
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
```
Output:
```
-7 1 0 4 4 88
```
Time complexity:
O(n <sup> 2</sup>)
