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
## Maximums subarray  problem using brutch force approach
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        int st,end;
        int cs;
        int max_=INT_MIN;
        for(int st=0;st<size;st++)
        {       cs=0;
            for (int end=st;end<size;end++)
            {
                cs+=nums[end];
                max_=max(cs,max_);
            }
        }
        return max_;
    }
};
```
**Note** Time complexity is **O(n^2)**
## We will use kadane's algorithm which reduces the time complexity to **O(n)**
Approach
Here, we reset the current_sum to 0 if it is negative as 0>negative value which when included doesnt give the max sum.
