


# C++ Star & Number Pattern Collection

## Index

1. [Square Pattern](#1-square-pattern)
2. [Hollow Square Pattern](#2-hollow-square-pattern)
3. [Right Aligned Square of Stars](#3-right-aligned-square-of-stars)
4. [Left Aligned Square of Stars](#4-left-aligned-square-of-stars)
5. [Right-Angled Triangle Pattern](#5-right-angled-triangle-pattern)
6. [Pyramid Pattern](#6-pyramid-pattern)
7. [Hollow Pyramid Pattern](#7-hollow-pyramid-pattern)
8. [Inverted Pyramid Pattern](#8-inverted-pyramid-pattern)
9. [Inverted Hollow Pyramid](#9-inverted-hollow-pyramid)
10. [Diamond Pattern](#10-diamond-pattern)
11. [Hollow Diamond Pattern](#11-hollow-diamond-pattern)
12. [Half Diamond Pattern](#12-half-diamond-pattern)
13. [Number Pyramid](#13-number-pyramid)
14. [Floyd's Triangle](#14-floyds-triangle)
15. [Pascal's Triangle](#15-pascals-triangle)
16. [Butterfly Pattern](#16-butterfly-pattern)
17. [Hollow Butterfly Pattern](#17-hollow-butterfly-pattern)
18. [Zig-Zag Pattern](#18-zig-zag-pattern)
19. [Numeric Palindrome Pyramid](#19-numeric-palindrome-pyramid)

    
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

## 15. **0-1 Pattern**

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
## 16. **NumberPattern**
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
## 17. **Palindrome Pattern**
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
## 18 **Zig-Zag Pattern**
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

## Some of the questions from SDE striver sheets 
1.
```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i=1;i<5;i++)
    {
        
        for (int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        int a=8-2*i;
        for (int k=1;k<=a;k++)
        {
            cout<<"  ";
        }
        for (int l=i;l>=1;l--)
        {
            cout<<l<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```
Output:
```
1             1 
1 2         2 1 
1 2 3     3 2 1 
1 2 3 4 4 3 2 1 
```
2.
```
#include <iostream>
using namespace std;
int main()
{
    int k=1;
     
    for (int i=1;i<=5;i++)
    {  
        for (int j=1;j<=i;j++)
        {
            cout<<k<<" ";
            k++;
        }
      
        cout<<endl;
    }

    return 0;
}
```
Output:
```
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
```
3 
```cpp
#include <iostream>
using namespace std;
int main()
{   
    for (int i=0;i<5;i++)
    {       char a='A';
        for (int j=0;j<=i;j++)
        {
            cout<<a++<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```
Output:
```
A
A B
A B C
A B C D
A B C D E
```
4 
```cpp
#include <iostream>
using namespace std;
int main()
{   
    for (int i=0;i<5;i++)
    {       char a='A';
        for (int j=0;j<=5-i-1;j++)
        {
            cout<<a++<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```
Output:
```
A B C D E 
A B C D 
A B C 
A B 
A 
```
5
```cpp
#include <iostream>
using namespace std;
int main()
{   char a='A';  
    for (int i=0;i<5;i++)
    {  
        for (int j=0;j<=i;j++)
        {
            cout<<a<<" ";
        }
        a++;
        cout<<endl;
    }

    return 0;
}
```
Output:
```
A
B B
C C C
D D D D
E E E E E
```
6
```cpp
#include <iostream>
using namespace std;

int main()
{   char a;
    for (int i=1;i<=4;i++)
    {
         a='A'; 
        for (int k=1;k<4-i+1;k++)
        {
            cout<<"  ";
        }
        for (int j=1;j<=2*i-1;j++)
        {
            cout<<a<<" ";
            if (j<=(2*i-1)/2)
            {   
                a++;
            }
            else{
                a--;
            }
             
        }
        cout<<endl;
        
    }
    return 0;
}
```
Output:
```
      A 
    A B A 
  A B C B A 
A B C D C B A 
```
7
```cpp
#include <iostream>
using namespace std;

int main()
{   
    char a;
    char in=4;
    for (int i=0;i<5;i++)
    {       a='A';
    
        for (int j=0;j<=i;j++)
        {
            cout<<char(a+in)<<" ";
            // in++;
            a++;
        }
        in--;
         cout<<endl;
    }
    
   
        
    return 0;
}
```
Output:
```
E 
D E 
C D E 
B C D E 
A B C D E 
```
8
```cpp
#include <iostream>
using namespace std;

int main()
{  
    
    for (int i=0;i<5;i++)
    {
       for (int j=0;j<5-i;j++)
       {
           cout<<"*";
       }
       for (int k=0;k<2*i+1;k++)
       {
           if (k!=0)
           {
             cout<<" ";   
           }
       }

       for (int j=0;j<5-i;j++)
       {
           cout<<"*";
       }
        cout<<endl;
        
    }
for (int i=0;i<5;i++)
{
   for (int j=0;j<=i;j++)
       {
           cout<<"*";
       }
       for (int k=0;k<2*(4-i)+1;k++)
       {
           if (k!=0)
           {
             cout<<" ";   
           }
       }
        for (int l=0;l<=i;l++)
       {
           cout<<"*";
       }
       cout<<endl;
}
    
   
        
    return 0;
}
```
Output:
```
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
```
9
```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<=i;j++)
        {
            cout<<"* ";
        }
        for (int k=0;k<2*(4-i);k++)
        {
            cout<<"  "; 
        }
        for (int j=0;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4-i;j++)
        {
            cout<<"* ";
        }
        for (int k=0;k<2*(i)+2;k++)
        {
            cout<<"  "; 
        }
         for (int j=0;j<4-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}
```
```
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 

```
10 

``` cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i=1;i<=7;i++)
    {
        for (int j=1;j<=7;j++)
        {
            if (i==1 || j==1 || i==7 || j==7)
            {
                cout<<"4 ";
            }
            else if (i==2 || i==6 || j==2 || j==6 ){
                cout<<"3 ";
            }
            else if (i==3 || i==5 || j==3 || j==5)
            {
                cout<<"2 ";
            }
            else{
                cout<<"1 ";
            }
        }
        
       cout<< endl;
    }

    return 0;
}
```
```
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
```
