# Importing dataset from kaggle to 
- We can use Kaggle, which offers datasets and Jupyter notebooks for machine learning, alongside Google Colab, which provides GPUs for deep learning.
- While deep learning typically requires powerful GPUs, Google Colab serves our learning needs with its available GPU resources.
- However, we need to import datasets from Kaggle.
## Here, I have mentioned how to import the dataset from the kaggle to the google colab.
![image](https://github.com/user-attachments/assets/494a783b-8eae-44a0-898e-346a6b987a48)
![image](https://github.com/user-attachments/assets/10cae18e-273a-46ef-8ae4-1918acc1de84)
![image](https://github.com/user-attachments/assets/279d1303-7b11-4dfa-996f-98eed1559235)
## Upload the dataset in Google colab from the system.
![image](https://github.com/user-attachments/assets/a77174b0-85e6-498a-8dc7-2ffd49f99eec)
![image](https://github.com/user-attachments/assets/b9568d27-bd67-441d-8509-9bb99a01f356) <hr>
## We can use the dataset in google coplab directly by importing it from  kaggle. Here are the process to upload the dataset in Google colab from the kaggle directly.
- Go to the kaggle account and create a new token<br>
![image](https://github.com/user-attachments/assets/3743c034-b1db-4e08-9dc3-15ccca7a9114) #Link of the dataset
- Kaggle.json file will be downloaded in the sytem.
- Upload that file in Google colab.
- Install the packages opendatasets and pandas
### Command
```bash
pip install opendatasets as od
pip install pandas as pd
```
- Next copy the link of the dataset from the kaggle and run the following command
### Command
```bash
od.download("https://www.kaggle.com/datasets/andrewmvd/face-mask-detection")
```
- After execution of this code It will ask  to input the username and key that has been provided in that kaggle.json file. Simply, input those information and the dataset will be downloaded in the google colab without downloading in the system.
![image](https://github.com/user-attachments/assets/e59e9057-5509-4d18-885d-04de59c1c734)
