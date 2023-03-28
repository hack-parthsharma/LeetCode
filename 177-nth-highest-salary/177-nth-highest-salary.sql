create function getNthHighestSalary(N int) returns int
begin
  return (
      select distinct salary as 'getNthHighestSalary(2)'
       from  (
          select salary,
                dense_rank() over(order by salary desc) as rnk
          from employee
      )  sal_rnk
      where rnk = n      
  );
end