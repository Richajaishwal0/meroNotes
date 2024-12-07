```c++
// C++ program for implementation longest arthimetic subarray
#include <iostream>
#include <climits>
using namespace std;

/* Function to sort array using insertion sort */
void Min_reapt( )
{   
    
     int arr[] = {1,5,3,4,3,5,6};
     int n=sizeof(arr)/sizeof(arr[0]);
     int min_=INT_MAX;
     int N=7;
     int ind[N]={-1,-1,-1,-1,-1,-1,-1};
     for (int i=0;i<n;i++)
     {
         if (ind[arr[i]]!=-1)
         {
             min_=min(min_,ind[arr[i]]);
         }
         else{
             ind[arr[i]]=i;
         }
     }
     if (min_==INT_MAX)
     {
         cout<<-1<<endl;
     }
     else {
         cout<<min_<<endl;
     }
     
}


// Driver method
int main()
{
   Min_reapt();


    return 0;
}

```
Approach
- initialise the array with the element as -1.
- Keep the record of each elements index in that array, and return the min_index of the repeating element.
