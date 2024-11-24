### Binary search
 In the binary searching of an element with the time complexity of **O(logn)**,where the initial index is: lets say **start** and the ending index is **end** and suppose we want to find the index in which the new element has to be inserted in the array that is already sorted then, the value of **start** after the completion of the loop
  gives the position where the element has to be inserted.

`
 You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
`
Solution: 
```c++
 class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long size=digits.size();
        vector <int> ab;
        long sum=0;
        for (int i=0;i<size;i++)
        {
            sum=sum*10+digits[i];
        }
        long add=sum+1;
        while (add>0)
        {
            ab.push_back(add%10);
            add/=10;
        }
        reverse(ab.begin(),ab.end());
        return ab;
    }
    
};
```
This logic is fine but dont lead to efficient solution due to the size of the integer and long. So better to apply next way as given below:
```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long size=digits.size();
        for (int i=size-1;i>=0;i--)
        {
            if (digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
          digits.insert(digits.begin(),1); // as loops exits without returning only if the last digit is 9 i.e to be made 0 and then we need to insert 1 at the beginning .
          return digits; 
    } 
  
};
```
** Access the single element from the set
```
*setname.begin(); to access the first element
to access the element at 2nd index.
auto it=setname.begin();
// Move iterator to the third element (index 2)
std::advance(it, 2);
cout <<*it<<endl;
```
