## **1. Key Libraries**
### Python Libraries to Import
```python
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import StandardScaler, PolynomialFeatures
```

---

## **2. Quick Workflow for Regression Models**
### Minimal Steps to Build and Evaluate:
```python
# 1. Load and split your data
X = data.drop('target', axis=1)
y = data['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 2. Standardize features if required
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 3. Train a model (Linear Regression as an example)
model = LinearRegression()
model.fit(X_train, y_train)

# 4. Make predictions
y_pred = model.predict(X_test)

# 5. Evaluate
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print(f"MSE: {mse}, R2 Score: {r2}")
```

---

## **3. Time-Saving Tips**
1. **Use Default Hyperparameters Initially**:
   - Start with default parameters (e.g., `LinearRegression()` or `RandomForestRegressor()`) and tune later if needed.
   - Example for Random Forest:
     ```python
     model = RandomForestRegressor(random_state=42)
     model.fit(X_train, y_train)
     ```

2. **Automate Model Selection**:
   - Use **`GridSearchCV`** or **`RandomizedSearchCV`** for hyperparameter tuning.
   ```python
   from sklearn.model_selection import GridSearchCV

   param_grid = {'n_estimators': [100, 200], 'max_depth': [10, 20]}
   grid = GridSearchCV(RandomForestRegressor(), param_grid, cv=3, scoring='r2')
   grid.fit(X_train, y_train)
   print(grid.best_params_)
   ```

3. **Use Prebuilt Pipelines**:
   - Combine preprocessing and modeling into a single pipeline to save time.
   ```python
   from sklearn.pipeline import Pipeline

   pipeline = Pipeline([
       ('scaler', StandardScaler()),
       ('model', LinearRegression())
   ])
   pipeline.fit(X_train, y_train)
   y_pred = pipeline.predict(X_test)
   ```

4. **Focus on Feature Importance**:
   - Use Random Forest or Gradient Boosting to quickly identify important features.
   ```python
   model = RandomForestRegressor()
   model.fit(X_train, y_train)
   importance = model.feature_importances_
   print(sorted(zip(X.columns, importance), key=lambda x: x[1], reverse=True))
   ```

5. **Use Polynomial Features for Nonlinear Relationships**:
   ```python
   poly = PolynomialFeatures(degree=2)
   X_poly = poly.fit_transform(X)
   model = LinearRegression().fit(X_poly, y)
   ```

---

## **4. Quick Commands for Evaluation**
### Metrics to Evaluate:
- **Mean Squared Error (MSE):**
  ```python
  from sklearn.metrics import mean_squared_error
  mse = mean_squared_error(y_test, y_pred)
  print(f"MSE: {mse}")
  ```
- **R² Score:**
  ```python
  from sklearn.metrics import r2_score
  r2 = r2_score(y_test, y_pred)
  print(f"R2 Score: {r2}")
  ```

---

## **5. Ready-to-Use Models**
### 1. Linear Regression:
```python
model = LinearRegression().fit(X_train, y_train)
```

### 2. Ridge Regression (for Regularization):
```python
from sklearn.linear_model import Ridge
ridge = Ridge(alpha=1.0).fit(X_train, y_train)
```

### 3. Lasso Regression (Feature Selection):
```python
from sklearn.linear_model import Lasso
lasso = Lasso(alpha=0.1).fit(X_train, y_train)
```

### 4. Random Forest Regressor (Quick Baseline):
```python
from sklearn.ensemble import RandomForestRegressor
rf = RandomForestRegressor(n_estimators=100, random_state=42).fit(X_train, y_train)
```

---

## **6. Shortcuts for Feature Engineering**
1. **Handle Missing Values in One Line**:
   ```python
   data.fillna(data.median(), inplace=True)
   ```

2. **Convert Categorical Variables**:
   ```python
   data = pd.get_dummies(data, drop_first=True)
   ```
ex: 
```py
   import pandas as pd
   
   # Original DataFrame
   df = pd.DataFrame({
       'ID': [1, 2, 3, 4],
       'Color': ['Red', 'Blue', 'Green', 'Red']
   })
   
   # Apply get_dummies
   df_dummies = pd.get_dummies(df['Color'])
   
   # Result
   print(df_dummies)
```
3. **Check for Multicollinearity**:
   - Use a correlation matrix to identify highly correlated features.
   ```python
   corr_matrix = data.corr()
   print(corr_matrix)
   ```

4. **Feature Scaling**:
   - Scale only numerical features:
   ```python
   scaler = StandardScaler()
   X_scaled = scaler.fit_transform(X)
   ```

---

## **7. Common Pitfalls to Avoid**
1. **Overfitting**:
   - Use regularization models like Ridge or Lasso.
   - Cross-validate your model using `cross_val_score`.
   ```python
   from sklearn.model_selection import cross_val_score
   scores = cross_val_score(model, X_train, y_train, cv=5, scoring='r2')
   print(f"Cross-validated R2 Scores: {scores.mean()}")
   ```

2. **Data Leakage**:
   - Always split data **before preprocessing** (e.g., scaling).

3. **Ignoring Outliers**:
   - Use boxplots or Z-scores to identify and handle outliers:
   ```python
   from scipy.stats import zscore
   data = data[(np.abs(zscore(data)) < 3).all(axis=1)]
   ```

---

## **8. Pre-Trained Regression Models**
- Use pre-trained models for quick results on standard datasets.
```python
from sklearn.datasets import load_diabetes
data = load_diabetes(as_frame=True)
X, y = data.data, data.target

model = RandomForestRegressor()
model.fit(X, y)
```

---

## **9. Useful One-Liners**
- **Check Dataset Shape**:  
  ```python
  print(data.shape)
  ```

- **Check for Null Values**:  
  ```python
  print(data.isnull().sum())
  ```

- **Describe Dataset**:  
  ```python
  print(data.describe())
  ```

- **Plot Actual vs Predicted**:  
  ```python
  import matplotlib.pyplot as plt
  plt.scatter(y_test, y_pred)
  plt.xlabel("Actual")
  plt.ylabel("Predicted")
  plt.show()
  ```
