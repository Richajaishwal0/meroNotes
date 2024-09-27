
# Diabetes Detection Using K-Nearest Neighbors (KNN) algorithm

## Overview
This project applies the K-Nearest Neighbors (KNN) algorithm to predict whether a person has diabetes, based on the Indian Diabetes dataset. The dataset contains health-related features, and the KNN classifier categorizes individuals as diabetic or non-diabetic.

### Libraries Used
```python
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler 
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, f1_score, accuracy_score
```

### Step 1: Load the Dataset
We load the dataset `diabetes.csv` to analyze health features for diabetes prediction.

```python
df = pd.read_csv('diabetes.csv')
print(len(df))
df.head()
```

### Step 2: Handling Missing Data
For columns like `'Glucose'`, `'BloodPressure'`, `'SkinThickness'`, `'BMI'`, and `'Insulin'`, zero values are replaced by the mean of the respective columns because zero is not a biologically plausible value for these metrics.

```python
zero_not_accepted = ['Glucose', 'BloodPressure', 'SkinThickness', 'BMI', 'Insulin']

for column in zero_not_accepted:
    df[column] = df[column].replace(0, np.NaN)
    mean = df[column].mean(skipna=True)  # Replace NaN values with the mean of the column
    df[column] = df[column].replace(np.NaN, mean)
```

### Step 3: Splitting the Dataset
We split the dataset into training and testing sets. The features (independent variables) are stored in `X`, and the target variable (dependent variable) in `Y`.

```python
X = df.iloc[:, 0:8]
Y = df.iloc[:, 8]
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, random_state=0, test_size=0.3)
```

### Step 4: Feature Scaling
Scaling is important for KNN as it is a distance-based algorithm. We standardize the features using `StandardScaler`.

```python
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)
```

### Step 5: Model Initialization
We initialize the KNN classifier with `n_neighbors=11` (based on the square root of test samples), `p=2` (Euclidean distance), and specify the `metric` as Euclidean.

```python
classifier = KNeighborsClassifier(n_neighbors=11, p=2, metric='euclidean')
```

### Step 6: Training the Model
The KNN model is trained using the training set (`X_train`, `Y_train`).

```python
classifier.fit(X_train, Y_train)
```

### Step 7: Predicting Results
The model is used to predict diabetes for the test set (`X_test`).

```python
y_pred = classifier.predict(X_test)
y_pred
```

### Step 8: Evaluating the Model
We evaluate the model using the confusion matrix, F1 score, and accuracy score.

```python
cm = confusion_matrix(Y_test, y_pred)
print(cm)
print(f1_score(Y_test, y_pred))
print(accuracy_score(Y_test, y_pred))
```
