 # Here are the list of new information that i got to know during this challenge .
 ### Built in functions 
 1. CHAR_LENGTH(). This can be used to find the length of the character in the string in any row of the table.

 ## Self joining can  be used to compare between two rows of the same table
 ex: 
 
 ![image](https://github.com/user-attachments/assets/f82340e4-5c5f-41f8-8ce2-3683264b067f)
In this table if we want to display the id of all dates where the temperature is higher as compared to the previous temperature than we need self join.
```sql
select w1.id from weather w1 join weather w2 on //self join
w1.recordData=DATE_FORMAT(w2.recordDate, INTERVAL 1 DAY,%Y-%m-%d) //joining on the basis of differnce of two dates that is one day
where w1.temperature >w2.temperature; //selecting only the rows where the current temperature is greater than the previous temperature.
```
# Confusion related to the groupby clause that i faced
- group by clause cannot only be used to count the number of unique items but we can also use it to find the average,sum etc of the unique items grouped together using the aggregate functions.
ex:

| machine_id | process_id | activity_type | timestamp |
|------------|------------|---------------|-----------|
| 0          | 0          | start         | 0.712     |
| 0          | 0          | end           | 1.520     |
| 0          | 1          | start         | 3.140     |
| 0          | 1          | end           | 4.120     |
| 1          | 0          | start         | 0.550     |
| 1          | 0          | end           | 1.550     |
| 1          | 1          | start         | 0.430     |
| 1          | 1          | end           | 1.420     |
| 2          | 0          | start         | 4.100     |
| 2          | 0          | end           | 4.512     |
| 2          | 1          | start         | 2.500     |
| 2          | 1          | end           | 5.000     |

```sql
select machine_id,avg(timestamp) from activity group by machine_id;
```
### This will calculate the avg of all the timestamp having same machine_id and display it as soon below.

| machine_id | avg(timestamp) |
|------------|----------------|
| 0          | 2.3730000      |
| 1          | 0.9875000      |
| 2          | 4.0280000      |

