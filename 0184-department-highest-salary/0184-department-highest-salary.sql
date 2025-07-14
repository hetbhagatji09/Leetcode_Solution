select d.name as Department,e.name as Employee,salary as Salary from employee e join department d on e.departmentId =d.id
where (salary,departmentId) in (SELECT MAX(salary), departmentId
        FROM employee
        GROUP BY departmentId
    )