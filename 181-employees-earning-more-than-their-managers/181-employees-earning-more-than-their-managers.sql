# Write your MySQL query statement below
select a.name as employee
from Employee a
left join Employee b 
on (a.managerid = b.id)
where (a.salary > b.salary)