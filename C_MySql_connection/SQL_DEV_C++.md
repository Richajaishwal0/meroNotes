# Connect Sql and Dev C++ globally(for overall  programs).
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
a.Include Directories:<br>
i. Click Add and browse to the directory containing mysql.h. <br>
Example path:
 here x,y are the versions of the sql
 **C:\Program Files\MySQL\MySQL Server X.Y\include.**
b. Library Directories:<br>
i. Click Add and browse to the directory containing MySQL library files.<br>
Example path:
<h>
 **C:\Program Files\MySQL\MySQL Server X.Y\lib.**

 ---

 ## Working with mysql in C

- Connecting to mysql database from C requires `mysql.h` header file
- `mysql.h` can be found in `C:\Program Files\MySQL\MySQL Server 8.0\include`
- Addtionary it requires `libmysql.dll` library
- DLL stands for dynamically link library. I'll .... explore fruther
- But, `mysql.h` requires further dependencies such as `file_types.h`, `mysql.h`, etc.


![image](https://github.com/user-attachments/assets/c528a40b-1189-4daa-a2ca-ebe9c0b9d476)

 ```bash
gcc -I "C:\Program Files\MySQL\MySQL Server 8.0\include" -L "C:\Program Files\MySQL\MySQL Server 8.0\lib" -o output.exe code.c
```

```bash
gcc -I ".\proj\include" -L ".\proj\lib" -o output.exe code.c
```

## Configuring Dev C++ for using mysql library

- Go to Tools > Compiler Options > Directories 
![image](https://github.com/user-attachments/assets/3c0d5a76-dc3a-46f3-958f-161e9e0f9327)


