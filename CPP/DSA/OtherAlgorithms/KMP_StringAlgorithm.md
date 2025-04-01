1. Brutch Force Approach
   Code:
   ```
   #include <iostream>
#include <string>

using namespace std;

int kmp(string a, string pattern)
{
    int n=a.size();
    int m=pattern.size();
    for (int i=0;i<n-m+1;i++)
    {
        int j=0;
        while (j<m && a[i+j]==pattern[j])
        {
            j++;
        }
        if (j==m) return i;
    }
    return -1;
}
int main ()
{
    string a = "aaaaaaaamaaaaaab";
    string pattern="aaaaaab";
    int ans=kmp(a,pattern);
    cout<<ans;
    return 0;
}
   ```
   Output:
```
9
```
