# Connecting MySql with Dev C++  for C/C++programming
## Here I have metioned the steps to be followed to connect Dev C++ to MySql by creating a project.
### 1.First of all, You have to make the new project in DEV C++ inside a folder.
Below are some references to  make the project in Dev C++
![image](https://github.com/user-attachments/assets/a7b7305b-d0be-4100-8f17-3e742725159c)
![image](https://github.com/user-attachments/assets/a2a37017-c7b2-413a-a05c-95364550ba4c)
### 2.Next step is to install MySQL from its official website. Here, You can use this link. 
https://dev.mysql.com/downloads/workbench/
### 3.After that you have to download MySql Connector/C . Here is the link where you can download as per your system specifications.
https://downloads.mysql.com/archives/c-c/
### 4.Then, on clicking the above folder(MySql Connector)  in the File Explorer, you  can see the files as:
![image](https://github.com/user-attachments/assets/bcdc1761-eed3-40ad-80b8-05dc54f23d28)
### 5.Next, you need to move to the lib folder.
![image](https://github.com/user-attachments/assets/3fa89353-1e91-46ae-9e2c-3f6d885ea91d)
### 6. Now, next step is to find the "libmysql.dll" file .. It is inside "vs12" folder. The only thing you have to do is to copy that file and paste it in your folder where you are working on.( I mean your project foler)
### 7.Then, You have to be back again in DEV C++ where you left off.Click on project and then project options as shown below:
![image](https://github.com/user-attachments/assets/dfdcb47b-8f12-4f07-92ba-27325ae92d98)
### 8.Move to the  directories->Library Directories. Here, you have to add the location of some folders which is mentioned below.
![image](https://github.com/user-attachments/assets/f16711eb-021f-48f0-9f18-a0eb96130641)
### 9.You have to find the MySQl folder again, Bydefault it is located on the C drive if  location is not altered.Click MYSQl Server X.X(X.X is thre version of the SQL). Then, Click on "Lib" and then add it to the path.
Below I  have visualized the process:
![image](https://github.com/user-attachments/assets/5c02c875-5264-4bf6-a51b-78f321c37ab8)
![image](https://github.com/user-attachments/assets/5d491032-9d79-42f6-ac56-c2bd79eda9dd)
![image](https://github.com/user-attachments/assets/9154fd3a-31da-486e-88d4-0eedc3836f98)
 ### After adding the location you can see it as:
![image](https://github.com/user-attachments/assets/8d6f1210-75d1-456e-9258-ae1e1a287246)
 ### Similarly, On the same Server folder you will find the include folder. Now in DEV C++ project->project options->Directories->Include Directories you have to add the path of "include" folder and in addition to that u need to add the path of the "mysql" folder. It is located inside the "include" folder.
 After doing so You wil get as shown in the screenshot.
 ![image](https://github.com/user-attachments/assets/ec531593-d1b7-4588-b18c-d166de2288f9)
 ### 10. Again, You have to go to the project->project options->parameters->linkers and add the command:
 `-lmysql` as shown:
 ![image](https://github.com/user-attachments/assets/30a6caa9-2ca5-4dac-bb11-3b8994ce8c00)
 ### 11. Now, create a C/C++ file on the same project.
 ### 12.Here, I had created the database and table using MySQL. I used C to do other operations. So, if u are followiing this completely then u need to make the database in MySql using the queries as shown:
 ![image](https://github.com/user-attachments/assets/6e7427fb-923c-4533-90e9-8923b56684b4)
 ### 13. At last u need to write a code in the .c file and compile and run it.Now u can code to insert, delete, update ... your datas directly from MySQL database using C program.<hr>
   # **Hope, U got all those and best of luck for your C+SQL projects.**
 
 


 
 

 
 








