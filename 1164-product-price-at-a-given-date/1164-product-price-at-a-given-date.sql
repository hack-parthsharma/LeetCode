select p1.product_id, p1.new_price as price
from Products p1
where p1.change_date <= '2019-08-16' and
    (product_id, datediff('2019-08-16', p1.change_date)) in
    (select product_id, min(datediff('2019-08-16', change_date))
    from Products
    where change_date <= '2019-08-16'
    group by product_id)

union

select product_id, 10 as price
from Products
group by product_id
having min(change_date) > '2019-08-16'
order by price desc