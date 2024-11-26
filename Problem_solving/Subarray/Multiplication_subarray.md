Here we will find the maximum multiplication of the subarray in an array.
For this we have four important cases.
1. If all the element are positive the multiplication is the product of all the elements.
2. If there are even number of "-" ves then we will apply the same approach.
3. If there are odd number of "-"ves then we have to calculate the max product among the prefix and suffix of that negative element.
4. If there are "0s"then again we have to calculate the max product among the prefix and suffix of that negative element and reset the product to 1
5. when the element is 0.
