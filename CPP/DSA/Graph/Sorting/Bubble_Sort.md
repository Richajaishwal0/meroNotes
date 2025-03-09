```cpp
#include <iostream>
#include <vector>
using namespace std;


int main()
{   
    int ans[]={4,1,0,88,4,-7};
    // Bubble sort 
    int n=sizeof(ans)/sizeof(ans[0]);
    
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (ans[j]>ans[j+1])
            {
                swap(ans[j],ans[j+1]);
            }
            
        }
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
-7 0 1 4 4 88
```
Time complexity: O(n<sup>2</sup> )
