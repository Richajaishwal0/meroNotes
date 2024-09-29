
# House Price Prediction Using XGBoost

This project aims to predict house prices using the **Boston House Price** dataset. It involves preprocessing the data, training an XGBoost Regressor model, and evaluating its performance.

## Libraries Used

The following Python libraries are used in this project:

- `pandas`: For handling data and creating data frames.
- `numpy`: For numerical operations.
- `matplotlib` and `seaborn`: For data visualization.
- `scikit-learn`: For data splitting and model evaluation.
- `xgboost`: For the regression model.

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn.datasets
from sklearn.model_selection import train_test_split
from xgboost import XGBRegressor
from sklearn import metrics
```

## 1. Loading the Dataset

We load the **Boston House Price dataset** from a CSV file:

```python
house_pd = pd.read_csv('boston.csv')
house_pd.head()
```

This displays the first five rows of the dataset. Each row represents a house, and the columns represent various features (like crime rate, number of rooms, etc.) that might influence the price of the house.

## 2. Checking for Missing Values

Before working with the dataset, we ensure there are no missing values:

```python
house_pd.isnull().sum()
```

The result shows that there are no missing values in the dataset.

## 3. Statistical Summary

A quick look at the dataset's statistical properties (mean, median, standard deviation, etc.) using the `describe()` method:

```python
house_pd.describe()
```

## 4. Correlation Analysis

Understanding the relationships between the features is important for prediction. We calculate the correlation matrix and visualize it using a heatmap:

```python
corr = house_pd.corr()
plt.figure(figsize=(10,10))
sns.heatmap(corr, cbar=True, square=True, fmt='.1f', annot=True, annot_kws={'size':8}, cmap='Blues')
plt.show()
```

## 5. Splitting the Data

We split the dataset into features (X) and target (Y), then into training and testing sets:

```python
X = house_pd.iloc[:, :-1]  # Features (all columns except the last one)
Y = house_pd.iloc[:, -1]  # Target (last column)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=2)
```

## 6. Model Training - XGBoost Regressor

We initialize and train the XGBoost Regressor model on the training data:

```python
model = XGBRegressor()
model.fit(X_train, Y_train)
```

## 7. Evaluation on Training Data

We evaluate the model on the training data by predicting the house prices and calculating performance metrics:

```python
pred = model.predict(X_train)
score_1 = metrics.r2_score(Y_train, pred)  # R-squared error
score_2 = metrics.mean_absolute_error(Y_train, pred)  # Mean absolute error
print(f"R-squared error: {score_1}")
print(f"Mean Absolute Error: {score_2}")
```

## 8. Evaluation on Test Data

Similarly, we predict the house prices on the test data and calculate the R-squared and mean absolute errors:

```python
pred = model.predict(X_test)
score_1 = metrics.r2_score(Y_test, pred)
score_2 = metrics.mean_absolute_error(Y_test, pred)
print(f"R-squared error: {score_1}")
print(f"Mean Absolute Error: {score_2}")
```

## 9. Visualizing the Results

Finally, we visualize the comparison between the actual and predicted prices:

```python
plt.scatter(Y_test, pred)
plt.xlabel('Actual Price')
plt.ylabel('Predicted Price')
plt.title('Actual vs Predicted Price')
plt.show()
```

## Conclusion

The XGBoost Regressor successfully predicts house prices with a reasonable level of accuracy. The visualization of actual vs predicted prices provides insight into how well the model performs.
