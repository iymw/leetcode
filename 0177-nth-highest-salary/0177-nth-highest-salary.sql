CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT DETERMINISTIC BEGIN DECLARE num INT;
SET 
  num = N - 1;
RETURN (
  # Write your MySQL query statement below.
  select 
    distinct(salary) 
  from 
    Employee 
  order by 
    salary desc 
  limit 
    1 offset num
);
END
