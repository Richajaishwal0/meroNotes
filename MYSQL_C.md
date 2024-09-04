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
 <hr>
4.Open Dev-C++.
<hr>
5.Go to Tools -> Compiler Options.
<hr>
6.Navigate to Directories Tab.  
       - Include Directories:<br>
          - Click Add and browse to the directory containing mysql.h. <br>
         Example path:
               ``` 
               C:\Program Files\MySQL\MySQL Server X.Y\include. 
               ```
           - Library Directories:<br>
        - Click Add and browse to the directory containing MySQL library files.<br>
          Example path:<br>
              ``` 
              C:\Program Files\MySQL\MySQL Server X.Y\lib.
              ```<br>
