```
* * * *
* * * *
* * * *
* * * *
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```

```
****
*  *
*  *
****

```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==0 || i==n-1 ||j==0 || j==n-1)
             {
                cout<<"*";
             }
            else
            {
                    cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
```

```
 ****
  ****
   ****
    ****
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<i+1;k++)
        {
            cout<<" ";
        }
            for (int j=0;j<n;j++)
            {
                cout<<"*";
            }
        cout<<endl;
    }
    return 0;
}
```

```
     ****
    ****
   ****
  ****

```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n-i+1;k++)
        {
            cout<<" ";
        }
            for (int j=0;j<n;j++)
            {
                cout<<"*";
            }
        cout<<endl;
    }
    return 0;
}
```
```
*
**
***
****
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {
            for (int j=0;j<i+1;j++)
            {
                cout<<"*";
            }
        cout<<endl;
    }
    return 0;
}
```

```
   *
  ***
 *****
*******
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {       for (int k=0;k<n-i-1;k++)
    {
        cout<<" ";
    }
        for (int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
```
```
   *
  * *
 *   *
*******
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {       for (int k=0;k<n-i-1;k++)
    {
        cout<<" ";
    }
            for (int j=0;j<2*i+1;j++)
            {
                if (j==0 || j==2*i || i==0 || i==n-1){
                    cout<<"*";
                }
                else
                {
                    cout<<" ";
                }
            }
        cout<<endl;
    }
    return 0;
}
```
```
*******
 *****
  ***
   *
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {       for (int k=0;k<i;k++)
    {
        cout<<" ";
    }
            for (int j=2*(n-i)-1;j>0;j--)
            {
                    cout<<"*";
            }
        cout<<endl;
    }
    return 0;
}
```
```
*******
 *   *
  * *
   *
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{ int n=4;
    for (int i=0;i<n;i++)
    {       for (int k=0;k<i;k++)
    {
        cout<<" ";
    }
        for (int j=0;j<2*(n-i)-1;j++)
        {
            if (i==0 || i==n-1 || j==0 || j==2*(n-i)-2)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

        }
        cout<<endl;

    }
    return 0;
}
```
