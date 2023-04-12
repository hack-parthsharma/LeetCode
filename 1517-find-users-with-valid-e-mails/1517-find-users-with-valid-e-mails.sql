select 
user_id,
name,
mail
from Users
where 
mail regexp "^[a-zA-Z]+[a-zA-Z0-9_\\./\\-]{0,}@leetcode\\.com$"
order by user_id