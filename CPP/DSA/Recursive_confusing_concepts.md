```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void intobuttom(stack <int> &st,int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return ;
    }
    int topel=st.top();
    st.pop();
    intobuttom(st,ele);
    st.push(topel);
}
void reverse(stack <int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele=st.top();
    st.pop();
    reverse (st);
    intobuttom(st,ele);
}
int main()
{   stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);

    return 0;
}
```
Here is an example of reversing the stack using recursion which is quite confusing for me due to the recursive call. 
