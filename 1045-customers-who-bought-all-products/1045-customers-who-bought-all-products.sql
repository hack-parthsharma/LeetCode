select distinct customer_id
    from (
        select customer_id, count(distinct product_key) as product_count
            from Customer
            group by customer_id
    ) as customer_product_counts
    join (
        select count(distinct product_key) as product_count from Product
    ) as product_counts
    on customer_product_counts.product_count = product_counts.product_count;