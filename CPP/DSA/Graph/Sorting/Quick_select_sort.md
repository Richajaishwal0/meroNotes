```cpp
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r;
    while (i < j)
    {
        while (i <= r - 1 && arr[i] <= pivot)
            i++;
        while (j >= l + 1 && arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

int quickselect(vector<int> &arr, int l, int r, int k)
{
    if (l <= r)
    {
        int j = partition(arr, l, r);
        if (j == k)
            return arr[j];
        else if (k < j)
            return quickselect(arr, l, j - 1, k);
        else
            return quickselect(arr, j + 1, r, k);
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3, 2, 0, 7};
    int k = 4; // example: change this to whatever k you want

    // For k-th smallest:
    int smallest = quickselect(arr, 0, arr.size() - 1, k - 1);
    cout << k << "th smallest element is: " << smallest << endl;

    // For k-th largest:
    int largest = quickselect(arr, 0, arr.size() - 1, arr.size() - k);
    cout << k << "th largest element is: " << largest << endl;

    return 0;
}

```
Output:
```

4th smallest element is: 2
4th largest element is: 6
```
Time complexity:
O(n ^3)
