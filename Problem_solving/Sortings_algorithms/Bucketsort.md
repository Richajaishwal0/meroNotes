```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<float> &v) {
    for (int i = 1; i < v.size(); i++)
    {   float key=v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
int main()
{
    float arr[]={0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    vector <float> buc[10];
    int buc_i;
    for (int i=0;i<10;i++)
    {
        buc_i=10*arr[i];
        buc[buc_i].push_back(arr[i]);
    }
    for (int i=0;i<10;i++)
    {
        insertion_sort(buc[i]);
    }
    int index=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<buc[i].size(); j++)
        {
            arr[index]=buc[i][j];
            index++;
        }
    }
    for (int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
```cmd
0.12 0.17 0.21 0.23 0.26 0.39 0.68 0.72 0.78 0.94 
```
