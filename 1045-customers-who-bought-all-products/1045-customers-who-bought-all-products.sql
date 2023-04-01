select customer_id
from Customer
group by customer_id
having sum(distinct product_key) = (
  select sum(product_key) from Product
);