Code
```cpp
#include <iostream>
#include <algorithm>
using namespace std;


struct Item{
  int profit;
  int weight;
};
static bool comp(struct Item a, struct Item b)
{
    int r1= (double) a.profit/ (double) a.weight;
    int r2=(double) b.profit/ (double) b.weight;
    return r1>r2;
}
int knapSack(int W, struct Item arr [], int N)
{
 sort(arr,arr+N,comp);
 
 int finalValue=0;
 for (int i=0;i<N;i++)
 {
     if (arr[i].weight<=W)
     {
         W-=arr[i].weight;
         finalValue+=arr[i].profit;
     }
     else
    {
        finalValue+=arr[i].profit * (double)W / (double) arr[i].weight;
        break;
    }
 }
 return finalValue;
}
int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int  N = sizeof(arr)/sizeof(arr[0]);
    cout<< knapSack(W,arr,N);
    return 0;
}

```
Output:
```
240
```
