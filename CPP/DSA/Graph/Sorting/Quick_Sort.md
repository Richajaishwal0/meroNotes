```cpp
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> & arr,int l, int r)
{
    int pivot= arr[l];
    int i=l;
    int j=r;
    while (i<j)
    {
        while (i<=r-1 && arr[i]<=pivot)
        {
            i++;
        }
        while (j>=l+1 && arr[j]>pivot)
        {
            j--;
        }
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}
void quicksort(vector<int> & arr,int l, int r)
{
    if (l<r)
    {
        int j=partition(arr,l,r);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,r);
    }
}
int main()
{
    vector<int> arr={4,6,2,5,7,9,1,3,2,0,7};
    quicksort(arr,0,arr.size()-1);
    for (int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
Output:
```
0 1 2 2 3 4 5 6 7 7 9
```
