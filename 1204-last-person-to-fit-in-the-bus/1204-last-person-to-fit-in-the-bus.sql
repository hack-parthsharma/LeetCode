select person_name 
from queue a
where (select sum(weight) 
       from queue 
       where a.turn >= turn) <= 1000
order by turn desc 
limit 1