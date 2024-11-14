SELECT unique_id, name
FROM EmployeeUNI u
RIGHT JOIN Employees e
    ON u.id = e.id