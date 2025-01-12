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
## 14. **Inverted Pattern**
```
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

```
```c++
#include <iostream>
using namespace std;

int  main()
{
	int i,j;
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=6-i;j++)
		{
			cout<<j<<" ";;
		}
		cout<<endl;
	}
	return 0;
}
```
## 15. **0-1 Pattern **
```
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```
```c++
#include <iostream>
using namespace std;

int  main()
{
	int i,j;
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=i;j++)
		{	
			if ((i+j)%2==0)
			{
				cout<<1<<" ";	
			}
			else
			{
				cout<<0<<" ";
			}
				
		}
		cout<<endl;
	}
	return 0;
}
```
## 16. **NumberPattern **
```
    1
   1 2
  1 2 3
 1 2 3 4
1 2 3 4 5

```
```c++
#include <iostream>
using namespace std;

int  main()
{
	int i,j,k;
	int n=5;
	for (i=1;i<=n;i++)
	{
		for (k=0;k<n-i;k++)
		{
			cout<<" ";
		}
		for (j=1;j<=i;j++)
		{	
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```
## 17. ** Palindrome Pattern **
```
        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5

```
```c++
#include <iostream>
using namespace std;

int  main()
{
	int i,j,k;
	int n=5;
	for (i=1;i<=n;i++)
	{
		for (k=0;k<n-i;k++)
		{
			cout<<"  ";
		}
		for (j=i;j>=1;j--)
		{	
			cout<<j<<" ";
		}
		for (j=2;j<=i;j++)
		{	
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```
## Zig-Zag Pattern
```
  *   *
 * * * *
*   *   *
```
```c++
#include <iostream>
using namespace std;

int  main()
{
	int i,j,k;
	int n=3;
	for (i=1;i<=n;i++)
	{
	for (j=1;j<=9;j++)
	{
		if ((i+j)%4==0)
		{
			cout<<"*";
		}
		else if(i==2 && j%4==0)
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
