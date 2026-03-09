# Write your MySQL query statement below
with NextTable as (
    select Num, lead(Num, 1) over(order by id) as next, lead(Num, 2) over(order by id) as next_next from Logs
)
select distinct Num as 'ConsecutiveNums' from NextTable where Num = next and Num = next_next;