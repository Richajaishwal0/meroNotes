
# Sonar Rock vs. Mine Prediction

This project demonstrates the use of a logistic regression model to classify sonar signals as either 'Rock' (R) or 'Mine' (M). The dataset consists of 60 features, which are numerical measurements of sonar signals.

## 1. Data Collection and Preprocessing

We load the dataset directly from Google Drive into a pandas DataFrame. The dataset has no headers, so we specify `header=None`.

```python
import pandas as pd

url="https://drive.google.com/uc?id=1pQxtljlNVh0DHYg-Ye7dtpDTlFceHVfa"
df=pd.read_csv(url,header=None)
df.head()
```
![image](https://github.com/user-attachments/assets/1ceb4208-a128-4a21-a5de-0121c9960d1d)

### Data Exploration
We explore the dataset using various methods:

- `df.describe()`: Provides statistical measures (mean, standard deviation, etc.).
- `df[60].value_counts()`: Shows the distribution of the target variable (R for Rock and M for Mine).
- `df.groupby(60).mean()`: Gives the average of each feature for Rock and Mine categories.

```python
df.describe()
df[60].value_counts()
df.groupby(60).mean()
```
![image](https://github.com/user-attachments/assets/d211d601-1c1f-4bfa-be2d-e36d84a47c2e)
![image](https://github.com/user-attachments/assets/fd7dd070-76ad-4459-ba56-844e0587279e)

## 2. Splitting the Data
We split the dataset into features (X) and target (Y). The first 60 columns represent the features, and the 61st column (index 60) represents the labels (R or M).

```python
X=df.iloc[: ,0:60]
Y=df.iloc[:,-1]
```

Next, we divide the data into training and testing sets using `train_test_split()`. A stratified split ensures the proportion of Rock and Mine samples remains consistent.

```python
from sklearn.model_selection import train_test_split

X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=0.1, stratify=Y,random_state=1)
```

## 3. Scaling the Data (Optional)
Scaling the data can improve the model's performance, though in this case, it is optional. We use `StandardScaler` for this purpose, but the scaling part is commented out.

```python
# from sklearn.preprocessing import StandardScaler
# scaler=StandardScaler()
# X_train=scaler.fit_transform(X_train)
# X_test=scaler.transform(X_test)
```

## 4. Model Training
We use Logistic Regression as our classification model. The model is trained on the training set (`X_train` and `Y_train`).

```python
from sklearn.linear_model import LogisticRegression

model=LogisticRegression()
model.fit(X_train,Y_train)
```

## 5. Model Evaluation
After training the model, we evaluate its accuracy on the test data (`X_test` and `Y_test`). Accuracy score is a common metric to assess the performance of a classifier.

```python
from sklearn.metrics import accuracy_score

y_pred=model.predict(X_test)
accuracy=accuracy_score(Y_test,y_pred)
print("Accuracy:", accuracy)
```

## 6. Making a Predictive System
We now use the trained model to make predictions on new input data. For example, we take a tuple representing sonar signal features and predict whether it's Rock or Mine.

- First, the input data is converted into a NumPy array.
- It is then reshaped to match the format expected by the model.
- Finally, the model makes a prediction, and based on the result ('R' or 'M'), it prints whether the object is a Rock or a Mine.

```python
import numpy as np

input_data = (0.0189, 0.0308, 0.0197, 0.0622, 0.008, 0.0789, 0.144, 0.1451, 0.1789, 0.2522, 0.2607, 
              0.371, 0.3906, 0.2672, 0.2716, 0.4183, 0.6988, 0.5733, 0.2226, 0.2631, 0.7473, 0.7263, 
              0.3393, 0.2824, 0.6053, 0.5897, 0.4967, 0.8616, 0.8339, 0.4084, 0.2268, 0.1745, 0.0507, 
              0.1588, 0.304, 0.1369, 0.1605, 0.2061, 0.0734, 0.0202, 0.1638, 0.1583, 0.183, 0.1886, 
              0.1008, 0.0663, 0.0183, 0.0404, 0.0108, 0.0143, 0.0091, 0.0038, 0.0096, 0.0142, 0.019, 
              0.014, 0.0099, 0.0092, 0.0052, 0.0075)

input_data_as_array = np.asarray(input_data)
inp_reshaped = input_data_as_array.reshape(1, -1)

prediction = model.predict(inp_reshaped)

if prediction[0] == 'R':
    print("The object is Rock")
else:
    print("The object is Mine")
```
![image](https://github.com/user-attachments/assets/3b663f1a-3316-4644-9903-a0eb010f08ca)

## Conclusion
This project demonstrates how to build a logistic regression model to classify sonar signals as either Rock or Mine. The model can be further enhanced by scaling features, tuning hyperparameters, or trying more advanced algorithms such as Random Forest or Support Vector Machine (SVM).
