select u.name as name, if(r.distance is null, 0, sum(r.distance)) as travelled_distance
from Users u
left join Rides r
on u.id = r.user_id
group by u.id
order by travelled_distance desc, name