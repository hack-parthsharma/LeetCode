select if(mod(id, 2) = 0, id - 1, if(id < (select max(id) from seat), id + 1, id)) as id, student
from seat
order by id;