select query_name, 
    round(sum(rating/position)/count(query_name), 2) as quality,
    round(100*sum(if(rating < 3, 1, 0))/count(query_name), 2) as poor_query_percentage
from Queries
group by query_name
