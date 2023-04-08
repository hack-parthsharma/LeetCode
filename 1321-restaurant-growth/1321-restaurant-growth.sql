# Write your MySQL query statement below
select c1.visited_on, sum(c2.amount) as amount, 
    round(avg(c2.amount), 2) as average_amount
from (select visited_on, sum(amount) as amount 
      from customer group by visited_on) c1
join (select visited_on, sum(amount) as amount 
      from customer group by visited_on) c2
on datediff(c1.visited_on, c2.visited_on) between 0 and 6
group by c1.visited_on
having count(c2.amount) = 7
