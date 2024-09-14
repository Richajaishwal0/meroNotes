# Create, Activate, Deactivate, Delete virtual environment on the anaconda
## Install Anaconda and open the Anaconda prompt
## Create the virtual environment
### Command
```bash
conda create --name campusx(name of virtual environment)
```
![image](https://github.com/user-attachments/assets/97da8b38-f53d-4066-8ad4-7d0a4c6059f9)
## Type 'y'
![image](https://github.com/user-attachments/assets/d76f4c4e-4c75-4973-a40b-aab0167f24b0)
## Activate the created environment
### Command
```bash
conda activate campusx
```
### Install Jupyter notebook and its dependencies
## To use the jupyter notebook in the virtual environment , install jupyter  notebook.
### Command
```bash
conda install -c anaconda jupyter
```
## Deactivate the virtual environment 
### Command
```bash
deactivate
```
## Delete the virtual environment 
### Command
```bash
conda remove --name campusx --all
```
