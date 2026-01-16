# Write your MySQL query statement below
WITH RankedSalaries AS (
  SELECT 
    salary, 
    DENSE_RANK() OVER (
      ORDER BY 
        salary desc
    ) AS r4nk 
  FROM 
    Employee
) 
SELECT 
  MAX(salary) AS SecondHighestSalary 
from 
  RankedSalaries 
WHERE 
  r4nk = 2;
