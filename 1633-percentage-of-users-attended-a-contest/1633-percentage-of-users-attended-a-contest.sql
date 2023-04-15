select r.contest_id as contest_id, 
    round(100*count(distinct r.user_id)/count(distinct u.user_id), 2) as percentage
from Register r, Users u
group by r.contest_id
order by percentage desc, contest_id