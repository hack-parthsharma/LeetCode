SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Employee.Salary

FROM
    Employee
JOIN -- default is inner join
    Department
ON Employee.DepartmentId = Department.Id

WHERE
    (Employee.DepartmentId , Employee.Salary) IN 
    (
        SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
    )
;