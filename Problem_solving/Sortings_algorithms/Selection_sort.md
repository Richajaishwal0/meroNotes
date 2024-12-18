```cpp
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    void selection_sort(int arr[], int n) {
        for (int i=0;i<n;i++) {
            int min_index=i;
            for (int j=i+1;j<n;j++) {
                if (arr[min_index]>arr[j]) {
                    min_index=j;
                }
            }
            swap(arr[i],arr[min_index]);
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
    obj.selection_sort(arr,n);
    obj.print_arr(arr,n);
    return 0;
}
```
```cmd
Enter the size of an array
5
Enter the elements of the array
8 3 2 9 4 
2 3 4 8 9 

```
