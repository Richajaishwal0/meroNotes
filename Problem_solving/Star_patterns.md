## 1. **Square Pattern**

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

---

## 2. **Hollow Square Pattern**

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

---

## 3. **Right Aligned Square of Stars**

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

---

## 4. **Left Aligned Square of Stars**

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

---

## 5. **Right-Angled Triangle Pattern**

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

---

## 6. **Pyramid Pattern**

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

---

## 7. **Hollow Pyramid Pattern**

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

---

## 8. **Inverted Pyramid Pattern**

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

---

## 9. **Inverted Hollow Pyramid**

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

---

## 10. **Diamond Pattern**

```
*
**
***
****
***
**
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
    {
        for (int j=0;j<i+1;j++)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    for (int i=n-1;i>0;i--)
    {
        for (int j=i;j>0;j--)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    return 0;
}
```

---

## 11. **Inverted Diamond Pattern**

```
   *
  **
 ***
****
 ***
  **
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
    {
        for (int k=n-i-1;k>0;k--)
        {
            cout<<" ";
        }
        for (int j=0;j<i+1;j++)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    for (int i=n-1;i>0;i--)
    {
        for (int k=i;k<n;k++)
        {
            cout<<" ";
        }
        for (int j=i;j>0;j--)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    return 0;
}
```

---

## 12. **Full Diamond Pattern**

```
   *
  ***
 *****
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
{    int n=4;
    for (int i=0;i<n;i++)
    {
        for (int k=n-i-1;k>0;k--)
        {
            cout<<" ";
        }
        for (int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    for (int i=n-1;i>0;i--)
    {
        for (int k=i;k<n;k++)
        {
            cout<<" ";
        }
        for (int j=2*i-1;j>0;j--)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    return 0;
}
```
## 13. **Full Diamond Pattern**
```
*         
        *         
        *         
        *         
* * * * * * * * * 
        *         
        *         
        *         
        *
```
```c++
#include <iostream>

using namespace std;


int main() {
    int n = 9;
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j<=n; j++) {
           if (i == n/2+1 || j == n/2+1) {
                cout << "* ";
            }else {
                cout << "  ";
            }
       }
       cout << endl;
   }
    return 0;
}
```
