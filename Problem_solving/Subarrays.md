## All possible subarrays  present in the array
```c++
 void subarray()
        {
            int arr[]={1,2,3,4,5};
            int st=0;
            int end=5;
            for (int i=st;i<end;i++)
            {
                for (int j=i;j<end;j++)
                {
                    for (int k=i;k<=j;k++)
                    {
                        cout<<arr[k];
                    }
                    cout<<" ";
                }
                cout<<endl;
            }
        }
```
```cmd
1 12 123 1234 12345
2 23 234 2345
3 34 345
4 45
5
```
