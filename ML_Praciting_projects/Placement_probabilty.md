# Logistic Regression Model for Placement Prediction

This project implements a logistic regression model to predict student placement based on `CGPA` and `IQ`. The following steps outline the process:

## 1. Data Preprocessing

The dataset is loaded, and unnecessary columns are removed.

```python
import pandas as pd
import numpy as np

df = pd.read_csv('/content/placement.csv')
df = df.iloc[:, 1:]  # Remove unnecessary columns
df.head()  # Display the first 5 rows of the dataset
df.shape  # Display the shape of the dataset
df.info()  # Show dataset information
```
![image](https://github.com/user-attachments/assets/1d0f1d02-4ae7-4e40-8322-eeb080041717)
![image](https://github.com/user-attachments/assets/3030ac8d-a79d-4778-9773-e563d270ce89)
![image](https://github.com/user-attachments/assets/76de6f8f-2612-4ce6-9969-d8d20ce5289e)
![image](https://github.com/user-attachments/assets/977d33c0-d4a3-4c99-9141-8e4830dd9b75)

## 2. Exploratory Data Analysis (EDA)

We visualize the relationship between `CGPA`, `IQ`, and `Placement` using a scatter plot.

```python
import matplotlib.pyplot as plt

plt.scatter(df['cgpa'], df['iq'], c=df['placement'])
plt.xlabel('CGPA')
plt.ylabel('IQ')
plt.show()
```
![image](https://github.com/user-attachments/assets/e661bf9d-8af3-482f-96a0-5c8fc549f037)

## 3. Feature Selection

We select `CGPA` and `IQ` as the input features (`X`) and `Placement` as the output (`Y`).

```python
X = df.iloc[:, 0:2]  # Select 'cgpa' and 'iq' columns
Y = df.iloc[:, -1]   # Select the 'placement' column as output
X.shape  # Shape of input features
Y.shape  # Shape of the output
```

## 4. Train-Test Split

We split the dataset into training and test sets, using 10% of the data for testing.

```python
from sklearn.model_selection import train_test_split

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1)
```

## 5. Scaling the Values

The input features are scaled using `StandardScaler` to normalize the values, which helps improve model performance.

```python
from sklearn.preprocessing import StandardScaler

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
```

## 6. Model Training (Logistic Regression)

We use the logistic regression model from `sklearn` to train on the preprocessed data.

```python
from sklearn.linear_model import LogisticRegression

clf = LogisticRegression()
clf.fit(X_train, Y_train)  # Train the model
```

## 7. Model Evaluation

The model's accuracy is evaluated by predicting the test set and comparing it with the actual values.

```python
y_pred = clf.predict(X_test)  # Predict the output for the test set
from sklearn.metrics import accuracy_score

accuracy = accuracy_score(Y_test, y_pred)
print(f"Accuracy: {accuracy * 100:.2f}%")
```
![image](https://github.com/user-attachments/assets/ae2f9981-97e1-43b7-a88f-923da4ca5cbd)
## 8. Visualizing Decision Regions

We visualize the decision regions formed by the logistic regression model to understand how it separates different classes.

```python
from mlxtend.plotting import plot_decision_regions

plot_decision_regions(X_train, Y_train.values, clf=clf, legend=2)
plt.show()
```
![image](https://github.com/user-attachments/assets/63ce0357-012b-4b53-a332-18b0b3494985)

## 9. Saving the Model

The trained model is saved as a pickle file for future use.

```python
import pickle

pickle.dump(clf, open('model.pkl', 'wb'))  # Save the model
```
