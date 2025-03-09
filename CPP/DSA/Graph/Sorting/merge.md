```cpp
#include <iostream>
#include <vector>
using namespace std;

void mergesort(int * ans, int st, int mid, int end)
{
    int n1= mid-st+1;
    int n2=end-mid;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++)
    {
        L[i]=ans[st+i];
    }
    for (int j=0;j<n2;j++)
    {
        R[j]=ans[mid+1+j];
    }
    int i=0,j=0;
    int index=0;
    int k= st;
    while (i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            
            ans[k]=L[i];
            i++;
        }
        else{
            ans[k]=R[j];
            j++;
        }
   k++;
    }
    while (i<n1)
    {
      ans[k]=L[i];
       k++;
       i++; 
    }
     while (j<n2)
    {
       ans[k]=R[j];
       k++;
       j++; 
    }
}
    
void merge(int *ans, int st, int end)
{
    if (st>=end) return ;
    int mid=st+(end-st)/2;
    merge(ans, st,mid);
    merge(ans,mid+1,end);
    mergesort(ans,st,mid,end);
}
int main()
{   
    int ans[]={4,1,0,88,4,-7};
    merge(ans,0,5);
    for (int i=0;i<6;i++)
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
Time complexity: O(nlogn)
