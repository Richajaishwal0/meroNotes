## Types of subquery
### Scalar Subquery: It always returns always one row and one column.
ex: Find the employee whose salary is highest than the average salary.
``` sql
ex: select * from employee where salary> (select avg(salary) from employee);
```
### Multiple row Subquery: It is further divided into 2 types:
- Multiple column and Multiple row
  ex: Find the employees who earn the highest salary in each department.
```sql
ex:
select employe_name  from emplpyee where (dept_name,Salary) in (select dept_name,max(salary) from employee group by dept_name)
```
- Single column and multiple rows:
  ex: Find the dept name who dont have any employee.
  ```sql
  select dept_name from dept where dept_name not in (select distinct dept_name from employee);
  ```
Correlated Subquery
