SELECT Name
FROM Employee AS a JOIN
    (SELECT ManagerId
    FROM Employee
    GROUP BY ManagerId
    HAVING Count(ManagerId) >= 5) as b
    ON a.Id = b.ManagerId