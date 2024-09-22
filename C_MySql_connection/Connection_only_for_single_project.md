# Connecting MySQL with Dev C++ for C/C++ Programming

## Steps to Connect Dev C++ with MySQL by Creating a Project

### 1. Create a New Project in Dev C++
First, create a new project in Dev C++ inside a designated folder. Below are some references for creating the project:

![Project Creation Step 1](https://github.com/user-attachments/assets/a7b7305b-d0be-4100-8f17-3e742725159c)
![Project Creation Step 2](https://github.com/user-attachments/assets/a2a37017-c7b2-413a-a05c-95364550ba4c)

### 2. Install MySQL
Next, install MySQL from its official website. You can use the following link:

[MySQL Download](https://dev.mysql.com/downloads/workbench/)

### 3. Download MySQL Connector/C
Download MySQL Connector/C according to your system specifications using the link below:

[MySQL Connector/C Download](https://downloads.mysql.com/archives/c-c/)

### 4. Locate Files in MySQL Connector Folder
After downloading, navigate to the MySQL Connector folder in File Explorer. You should see the following files:

![MySQL Connector Files](https://github.com/user-attachments/assets/bcdc1761-eed3-40ad-80b8-05dc54f23d28)

### 5. Move to the 'lib' Folder
Proceed to the 'lib' folder within the MySQL Connector.

![Lib Folder](https://github.com/user-attachments/assets/3fa89353-1e91-46ae-9e2c-3f6d885ea91d)

### 6. Copy 'libmysql.dll' File
Inside the 'vs12' folder, locate the `libmysql.dll` file. Copy this file and paste it into your project folder.

### 7. Configure Project in Dev C++
Return to Dev C++ where you created your project. Click on `Project` -> `Project Options` as shown below:

![Project Options](https://github.com/user-attachments/assets/dfdcb47b-8f12-4f07-92ba-27325ae92d98)

### 8. Add Library Directories
Navigate to `Directories` -> `Library Directories` and add the path to the required folders.

![Library Directories](https://github.com/user-attachments/assets/f16711eb-021f-48f0-9f18-a0eb96130641)

### 9. Locate MySQL Folder
Locate the MySQL folder (usually in the C drive if not altered), go to `MySQL Server X.X` (X.X being the version installed), then click on `lib`, and add this path.

![Library Folder](https://github.com/user-attachments/assets/5c02c875-5264-4bf6-a51b-78f321c37ab8)
![Path Added](https://github.com/user-attachments/assets/5d491032-9d79-42f6-ac56-c2bd79eda9dd)
![Library Path Added](https://github.com/user-attachments/assets/9154fd3a-31da-486e-88d4-0eedc3836f98)

Click the 'Add' button to include the path. You should see the added location as shown:

![Added Library Path](https://github.com/user-attachments/assets/8d6f1210-75d1-456e-9258-ae1e1a287246)

### 10. Add Include Directories
In the same `MySQL Server..` folder, locate the `include` folder. Go to `Project` -> `Project Options` -> `Directories` -> `Include Directories` and add the paths of the `include` folder and the `mysql` folder inside it.

![Include Directories](https://github.com/user-attachments/assets/ec531593-d1b7-4588-b18c-d166de2288f9)

### 11. Add Linker Command
Go to `Project` -> `Project Options` -> `Parameters` -> `Linker` and add the following command: 

```bash
-lmysql
```
`### 12. Create a C/C++ File in the Project
Create a new C/C++ file within the same project.

### 13. Create Database and Tables in MySQL
Create your database and tables using MySQL. Use the appropriate SQL queries in MySQL to set up your database structure, as shown below:

![Database Creation](https://github.com/user-attachments/assets/6e7427fb-923c-4533-90e9-8923b56684b4)

### 14. Write, Compile, and Run Your C Code
Write your C code in the `.c` file. Compile and run the code to interact with the MySQL database directly from your C program. You can now perform operations such as insert, delete, update, and more using C.

---

# **Hope you find this guide helpful, and best of luck with your C + SQL projects!**


