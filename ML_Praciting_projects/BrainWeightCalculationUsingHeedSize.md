
# Linear Regression Analysis on Head Size and Brain Weight

## Overview
This Jupyter notebook demonstrates how to perform linear regression analysis using a dataset containing information about head size and brain weight. The goal is to understand the relationship between these two variables and to create a predictive model.
## Introduction
In this analysis, we will:
- Load and explore the dataset.
- Define independent (head size) and dependent (brain weight) variables.
- Calculate the regression coefficients using the least squares method.
- Visualize the data and the regression line.
- Evaluate the model's accuracy using the R² score.
- Use Scikit-Learn to perform linear regression.

## Setting Up the Environment
```python
# Import necessary libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['figure.figsize']=(30.0,10.0)
```
- **Imports**: We import essential libraries:
  - `pandas`: For data manipulation and analysis.
  - `numpy`: For numerical operations.
  - `matplotlib.pyplot`: For data visualization.
- **Figure Size**: Sets the default figure size to 30 inches wide by 10 inches tall for better visibility.

## Reading the Data
```python
# Reading data
data=pd.read_csv('headbrain.csv')
print(data.shape)
data.head()
```
- **Loading Data**: The `pd.read_csv()` function reads the CSV file containing head size and brain weight data.
- **Data Shape**: `data.shape` returns the dimensions of the DataFrame (number of rows and columns).
- **Previewing Data**: `data.head()` displays the first 5 rows of the dataset to understand its structure.
![image](https://github.com/user-attachments/assets/a7214c0d-230f-4abf-84ad-ba9f3d2814c5)

## Defining Variables
```python
## Taking head size and brain weight as the independent and dependent variable
X=data['Head Size(cm^3)'].values
Y=data['Brain Weight(grams)'].values
```
- **Independent Variable (X)**: `X` contains the values for head size extracted from the DataFrame.
- **Dependent Variable (Y)**: `Y` contains the values for brain weight extracted from the DataFrame.

## Calculating the Regression Coefficients
```python
# Mean of X and Y
mean_x=np.mean(X)
mean_y=np.mean(Y)
# Counting the number of values
n=len(X)
# formula to find the value of m and c
numerator=0
denumerator=0
for i in range (n):
    numerator+=(X[i]-mean_x)*(Y[i]-mean_y)
    denumerator+=(X[i]-mean_x)**2
m=numerator/denumerator
c=mean_y-m*mean_x
print(m,c)
```
- **Mean Calculation**: `np.mean()` computes the mean of `X` and `Y`, which are needed for regression calculations.
- **Counting Data Points**: `len(X)` gives the total number of data points `n`.
- **Numerator and Denominator**: Initialize variables for calculating the slope `m` of the regression line.
- **For Loop**: Iterates through each data point to calculate:
  - **Numerator**: The sum of products of deviations from the mean for both `X` and `Y`.
  - **Denominator**: The sum of squared deviations from the mean for `X`.
- **Slope (m)**: The slope of the regression line is calculated as `numerator/denominator`.
- **Intercept (c)**: The y-intercept is calculated using the means and the slope.
- **Print Coefficients**: Displays the calculated slope and intercept.

## Plotting the Data and Regression Line
```python
# Plotting the values and Regression line
max_x=np.max(X)+100
min_x=np.min(X)-100
# Calculating line values x and y
x=np.linspace(min_x,max_x,1000)
y=m*x+c
# Plotting line
plt.plot(x,y,color="brown",label="Regression Line")
# Plotting the scatter plot
plt.scatter(X,Y,c="green",label="Scatter Plot")
plt.xlabel("Head Size in cm^3")
plt.ylabel("Brain Weight in grams")
plt.legend()
plt.show()
```
- **Max and Min Values**: Calculates the maximum and minimum values of `X` to set the limits for plotting.
- **Line Values**: Uses `np.linspace()` to create an array of 1000 evenly spaced values between `min_x` and `max_x` for plotting the regression line.
- **Plotting**:
  - `plt.plot()`: Plots the regression line in brown.
  - `plt.scatter()`: Creates a scatter plot of the original data points in green.
  - **Labels and Legend**: Adds x and y-axis labels, a legend, and shows the plot.
![image](https://github.com/user-attachments/assets/252e1467-6151-414b-8a12-3bac76fc5f36)

## Calculating the R² Score using formula
```python
# Calculating the r2 to check the accuracy of our line
nume=0
denom=0
for i in range (n):
      y_pred=m*X[i]+c
      nume+=(y_pred-mean_y)**2
      denom+=(Y[i]-mean_y)**2
r2=nume/denom
r2
```
- **R² Calculation**: The R² score is a measure of how well the regression line fits the data.
- **Predicted Values**: For each data point, calculate the predicted brain weight using the regression equation.
- **Numerator and Denominator**: Sum the squares of the differences between predicted values and the mean of `Y` for the numerator, and the squares of the differences between actual values and the mean for the denominator.
- **Final R² Score**: The R² score is calculated as the ratio of the numerator to the denominator.
![image](https://github.com/user-attachments/assets/1d226296-c93c-4397-b6b3-adc0ca4b913e)

## Using directlty  Scikit-Learn for Linear Regression
```python
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

m = X.shape[0]
X=X.reshape((m,1))

# Creating model
model=LinearRegression()
model=model.fit(X,Y)
y_pred=model.predict(X)
r2_score=model.score(X,Y)
r2_score
```
![image](https://github.com/user-attachments/assets/4c889b28-46c8-4276-be70-8fa3fd8b5453)

- **Importing Libraries**: We import the `LinearRegression` class from Scikit-Learn for linear regression and `mean_squared_error` for error calculation.
- **Reshaping X**: Reshape `X` to ensure it has the correct dimensions for Scikit-Learn (m rows and 1 column).
- **Creating and Fitting Model**: Instantiate the `LinearRegression` model and fit it using the reshaped `X` and `Y`.
- **Predictions**: Use the fitted model to predict brain weights based on head sizes.
- **R² Score**: Calculate the R² score using the model's `score` method, which assesses how well the model fits the data.

## Conclusion
In this notebook, we have successfully performed a linear regression analysis to understand the relationship between head size and brain weight. We calculated the regression coefficients, visualized the data along with the regression line, and evaluated the model's accuracy using the R² score. Additionally, we demonstrated how to leverage Scikit-Learn for linear regression, making the process more efficient and easier to manage.
