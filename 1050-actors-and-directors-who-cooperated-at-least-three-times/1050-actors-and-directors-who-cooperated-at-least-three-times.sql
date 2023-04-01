# Write your MySQL query statement below
# select actor_id, director_id
# from (
#   select actor_id, director_id, count(*) as cnt
#   from ActorDirector
#   group by actor_id, director_id
#   having cnt >= 3) as e;

select actor_id, director_id
from ActorDirector
group by actor_id, director_id
having count(*) >= 3;
