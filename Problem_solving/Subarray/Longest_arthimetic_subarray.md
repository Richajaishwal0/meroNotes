```c++
// C++ program for implementation longest arthimetic subarray
#include <iostream>
using namespace std;

/* Function to sort array using insertion sort */
int longestSubarray( )
{   
    
     int arr[] = { 2,4,6,8,12,16,20,24};
     int count=2;
     int pd=arr[1]-arr[0];
     int ans=2;
     int i=2;
     while (i<8)
     {
         if (pd==arr[i]-arr[i-1]){
             count++;
         }
         else{
             count=2;
             pd=arr[i]-arr[i-1];
         }
         ans=max(ans,count);
         i++;
     }
     return ans;
}


// Driver method
int main()
{
    cout<<longestSubarray();


    return 0;
}

```
Approach:
- check if the previous diff is equal to the current diff,if its true then increase the count of the element.
- else reinitialize the count to 2 and previous difference to the difference of new subarray.
- return the maximum count of the subarray length.
