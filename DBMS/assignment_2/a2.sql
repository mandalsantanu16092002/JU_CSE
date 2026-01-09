--1) From the EMP table show the minimum, maximum and average basic for each department (show dept. Code).
select min(basic) , max(basic), avg(basic) from emp group by dept_code;

--2)Find the number of female employees in each department (show dept. Code).
select count(*) as No_of_females, dept_code from emp where sex='F' group by dept_code;

--3) Find the city wise no. of employees for each department (show dept. Code). 
select count(*),city,dept_code from emp group by city, dept_code;

--4. Show the designation wise no of employees who have joined in the year 2000 in each department. The listing should appear in the ascending order of no. of employees.
select count(*) as count,desig_code,city from emp where substr(jn_dt,1,4)='2017' group by desig_code,city order by count asc;

--5. Find the department code wise total basic of male employees only for the departments for which such total is more than 50,000 and the listing should appear in the descending order of total basic.
select sum(basic) as total_basic,dept_code from emp where sex='M' and basic>=50000 group by dept_code order by total_basic desc;

--
select emp_name,desig_desc,basic from emp,designation where emp.desig_code = designation.desig_code;

--7
select emp_name,desig_desc,dept_name,basic from emp,designation,department where emp.desig_code = designation.desig_code and department.dept_code = emp.dept_code;

--8
select dept_code from department d where not exists (select emp.dept_code from emp where emp.dept_code=d.dept_code);
--8 2nd method
select department.dept_code from department left join emp on department.dept_code = emp.dept_code where emp.dept_code is null;

--9
select dept_code from department d where exists (select emp.dept_code from emp where emp.dept_code=d.dept_code);
--9 2nd method
select department.dept_code from department left join emp on department.dept_code = emp.dept_code where emp.dept_code is not null group by department.dept_code;

--10
select department.dept_code from department left join emp on department.dept_code = emp.dept_code where emp.dept_code is not null group by dept_code having count(*)>=10;


--11
select dept_code from emp where basic=(select max(basic) from emp);

--12
select desig_desc from emp,designation where basic=(select max(basic) from emp) and emp.desig_code = designation.desig_code;

--13
select count(*),dept_code from emp where desig_code='MGR' group by dept_code;

--14
select basic from emp order by basic desc limit 1;

--15
select basic from emp order by basic asc limit 1;

--16
select sum(basic) as total,dept_code from emp group by dept_code order by basic desc limit 1;

--17,18
delete from emp where desig_code is null;

--19


--20
elect count(*) from emp where sex='F' and desig_code='MGR';