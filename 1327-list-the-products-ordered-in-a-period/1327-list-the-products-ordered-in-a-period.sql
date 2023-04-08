select  prod.product_name, prod.unit
from
    (select p.product_name, 
        sum(o.unit) as unit
    from Products p
    left join Orders o
    on p.product_id = o.product_id and 
        datediff(order_date, '2020=02-01') >= 0 and
        datediff('2020-03-01', order_date) > 0 
    group by p.product_id) prod
where prod.unit >= 100