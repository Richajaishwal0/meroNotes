## Record Breaker is a famous Kickstart problem where the element of array is said to be record breaker day if its greater than all the element towards its left and greater than its right single element.
- Approach
  - Calculate the max element before the current element and compare it with the current element if the current element is greater then check if it's greater then its corresponding right element.
  - The first and last element of the array should be checked using separate conditions.
  - Increase the count
  ```c++
  // C++ program for implementation longest arthimetic subarray
#include <iostream>
#include <climits>
using namespace std;

/* Function to sort array using insertion sort */
int recordBreaker( )
{   
    
     int arr[] = {1,2,0,7,2,0,2,2};
     int n=sizeof(arr)/sizeof(arr[0]);
     int max_=INT_MIN;
     int count=0;
     if (arr[0]>arr[1]) count++;
     if (arr[n-1]>arr[n-2]) count++;
     for (int i=1;i<n-1;i++)
     {
         max_=max(max_,arr[i-1]);
         if (arr[i]>max_ && arr[i]>arr[i+1])
         {
             cout<<arr[i]<<" ";
             count++;
             
         }
         
         
     }
     cout<<endl;
     return count;
}


// Driver method
int main()
{
    cout<<recordBreaker();


    return 0;
}

  ```
