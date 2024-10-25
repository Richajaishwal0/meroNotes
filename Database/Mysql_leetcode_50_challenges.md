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
