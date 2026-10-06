# Write your MySQL query statement below
with 
  EmployeeAndDepartment as (
    select 
      e.id as Eid, 
      e.name as Employee, 
      e.salary as Salary, 
      e.departmentId as EdepartmentId, 
      d.id as Did, 
      d.name as Department, 
      DENSE_RANK() OVER (
        PARTITION BY d.name 
        order by 
          e.salary desc
      ) as ranking 
    from 
      Employee as e 
      join Department as d on e.departmentId = d.id
  ) 
select 
  Department, 
  Employee, 
  Salary 
from 
  EmployeeAndDepartment 
where 
  ranking <= 3;
