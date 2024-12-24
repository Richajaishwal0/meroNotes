```
npm init \\ use to create a package.json file 
```
- After running npm init these informations has to be filled as given below:

![image](https://github.com/user-attachments/assets/d12331dc-e9bc-492a-8d1c-90737648e60f)
-  package.json file will be created with the details as:
  ```json
{
  "name": "tut69",
  "version": "1.0.0",
  "description": "This is the best package",
  "main": "tut69.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [
    "great"
  ],
  "author": "\"Richa\"",
  "license": "ISC"
}

```
- If any dependencies is installed the it will be reflected in the json file ex:
  ```
   npm install express
  ```
  
    ```json
  {
  "name": "tut69",
  "version": "1.0.0",
  "description": "This is the best package",
  "main": "tut69.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [
    "great"
  ],
  "author": "\"Richa\"",
  "license": "ISC",
  "dependencies": {
    "express": "^4.21.2"
  } }
  // ==========

  {  "name": "tut69",
  "version": "1.0.0",
  "description": "This is the best package",
  "main": "tut69.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [
    "great"
  ],
  "author": "\"Richa\"",
  "license": "ISC",
  "dependencies": {
    "express": "^4.21.2"
  },
  "devDependencies": {
    "nodemon": "^3.1.9"
  }
  }
  ```
## Some important knowledges
Inorder to install nodemon (a package to run server) gloablly 
```
npm install nodemon --global
```
and locally 
```
npm install nodeman --save-dev
```
check the version of dependencies in npm
``` npm view modulename version
```
