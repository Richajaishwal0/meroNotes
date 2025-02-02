```cpp
#include <iostream>
#include <vector>
using namespace std;

int sizee =0;
void heapify(int *arr,int sizee, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if (l<sizee && (arr[l]> arr[largest]))
    {
        largest=l;
    }
    if (r<sizee && (arr[r]>arr[largest]))
    {
        largest=r;
    }
    if (largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,sizee,largest);
    }
}
void insert(int * arr, int elem)
{
    if (sizee==0)
    {
        arr[0]=elem;
        sizee++;
        return;
    }
    else{
        arr[sizee]=elem;
        sizee++;
        for (int i=sizee/2-1;i>=0;i--)
        {
            heapify(arr,sizee,i);
        }
    }
}
void deletee(int *arr, int ele)
{
    if (sizee==0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }
    else{
        int i;
        for (i=0;i<sizee;i++)
        {
            if (arr[i]==ele)
            {
                break;
            }
        }
        if (i == sizee)
        {
            cout << "Element not found!" << endl;
            return;
        }

        swap(arr[i],arr[sizee-1]);
        sizee--;
        for (int i=sizee/2-1;i>=0;i--)
        {
            heapify(arr,sizee,i);
        }
    }
}
void printa(int array[])
{
    for (int i=0;i<sizee;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main()
{   
    // int ans[]={1,2,8,3,9,5};
    // int size 10;
    int array[10];
  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);
  printa(array);
  deletee(array,3);
   printa(array);

    return 0;
}
```
Output:
```
9 5 4 3 2 
9 5 4 2 
```
