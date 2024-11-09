### The Windows operating system features over 280 commands for CMD (Command Prompt). Some commands are specific to Windows servers, while others are available for desktop versions. In both cases, CMD commands communicate directly with the OS and allow to perform various IT automation tasks.
# Common CMD Commands and Their Uses

## **File and Directory Management**

### 1. `dir`
- **Use**: Displays a list of files and directories in the current directory.

### 2. `cd` or `chdir`
- **Use**: Changes the current directory.

### 3. `cls`
- **Use**: Clears the command prompt screen.

### 4. `mkdir` or `md`
- **Use**: Creates a new directory.

### 5. `rmdir` or `rd`
- **Use**: Removes an empty directory.

### 6. `rename` or `ren`
- **Use**: Renames a file or directory.

---

## **File Creation and Editing**

### 7. `echo`
- **Use**: Displays messages or turns command echoing on/off.
- **File Creation Example**: Create a new file and add text:
    ```cmd
    echo Your content goes here > C:\path\to\folder\filename.txt
    ```
- **File Creation (Empty)**: 
    ```cmd
    echo. > C:\path\to\folder\filename.txt
    ```

### 8. `type`
- **Use**: Displays the contents of a text file.
    ```cmd
    type C:\path\to\folder\filename.txt
    ```

### 9. `copy`
- **Use**: Copies files from one location to another.
    ```cmd
    copy C:\path\to\source\file.txt C:\path\to\folder\file.txt
    ```

---

## **File Deletion and Manipulation**

### 10. `del`
- **Use**: Deletes one or more files.
    ```cmd
    del C:\path\to\folder\filename.txt
    ```

### 11. `move`
- **Use**: Moves files from one directory to another.
    ```cmd
    move C:\path\to\folder\file1.txt C:\path\to\new\folder
    ```

### 12. `xcopy`
- **Use**: Copies files and directories, including subdirectories.
    ```cmd
    xcopy C:\path\to\folder\ C:\path\to\destination\ /s /e
    ```

---

## **System and Network Utilities**

### 13. `ipconfig`
- **Use**: Displays network configuration information.

### 14. `ping`
- **Use**: Tests network connectivity to a remote system.

### 15. `netstat`
- **Use**: Displays active network connections and listening ports.

---

## **Process Management**

### 16. `tasklist`
- **Use**: Displays a list of currently running processes.

### 17. `taskkill`
- **Use**: Terminates a running process.

---

## **System Information and Maintenance**

### 18. `chkdsk`
- **Use**: Checks the disk for errors and repairs them.

### 19. `sfc /scannow`
- **Use**: Scans and repairs system files.

### 20. `shutdown`
- **Use**: Shuts down or restarts the computer.

### 21. `systeminfo`
- **Use**: Displays detailed system information.

---

## **Time and Date**

### 22. `time`
- **Use**: Displays or sets the system time.

### 23. `date`
- **Use**: Displays or sets the system date.

---

## **Networking and User Management**

### 24. `net user`
- **Use**: Displays or modifies user accounts.

### 25. `net start`
- **Use**: Starts a network service.

### 26. `net stop`
- **Use**: Stops a network service.

---

## **Miscellaneous**

### 27. `hostname`
- **Use**: Displays the computer's hostname.

### 28. `tree`
- **Use**: Displays the directory structure of a drive or path.

### 29. `attrib`
- **Use**: Displays or changes file attributes.

### 30. `fc`
- **Use**: Compares two files and displays differences.
