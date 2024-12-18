```cpp
#include <iostream>
// #include <vector>
using namespace std;

class Solution {
public:
    void insertion_sort(int arr[], int n) {
        int i,j,key;
        for ( i=1;i<n;i++) {
            key=arr[i];
            j=i-1;
            while (j>=0 && arr[j]>key) {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }

    }
    void print_arr(int arr[],int n) {
        for (int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    Solution obj; //creating object for the class solution
    obj.insertion_sort(arr,n);
    obj.print_arr(arr,n);
    return 0;
}
```

```cmd
Enter the size of an array
5
Enter the elements of the array
5 9 8 1 0
0 1 5 8 9 
```
