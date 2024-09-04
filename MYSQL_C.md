# Overall connection between C and Mysql
## Default Installation Path:
1.Open File Explorer.<hr>
2.Navigate to the Connector Installation Directory:<hr>
```
use this to enter the directory where you can find the "mysql.h"
 C:\Program Files\MySQL\MySQL Connector C X.Y\include.
```
<hr>
3.Locate mysql.h<hr>
    
    **Open the include directory. Look for mysql.h within this directory.**
4.Open Dev-C++.
5.Go to Tools -> Compiler Options.
6.Navigate to Directories Tab.  
     - Include Directories:
       - Click Add and browse to the directory containing mysql.h. 
         Example path:
     ``` C:\Program Files\MySQL\MySQL Server X.Y\include. ```
    - Library Directories:
        - Click Add and browse to the directory containing MySQL library files. 
          Example path:
     ``` C:\Program Files\MySQL\MySQL Server X.Y\lib.```
