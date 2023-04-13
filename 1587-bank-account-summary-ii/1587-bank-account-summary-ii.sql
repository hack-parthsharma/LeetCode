select name, balance
from (select account, sum(amount) as balance
    from Transactions
    group by account
    having sum(amount) > 10000) t
join Users u
on u.account = t.account;