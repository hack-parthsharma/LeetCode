# Write your MySQL query statement below
select
    employee_id
from Employees
where manager_id is not NULL and manager_id not in (select employee_id from Employees) and salary < 30000
order by 1
