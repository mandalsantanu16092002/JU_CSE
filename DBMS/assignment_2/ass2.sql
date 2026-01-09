-- Q1 >> START
-- Question > 1.  From  the  EMP  table  show  the  minimum,  maximum  
--                and  average  basic  for  each department (show dept. Code). 
--                
SELECT
    MIN(BASIC) AS MINIMUM,
    MAX(BASIC) AS MAXIMUM,
    AVG(BASIC) AS AVERAGE,
    DEPT_CODE
FROM
    EMP
GROUP BY
    DEPT_CODE;

-- Q1 >> END
-- 
-- 
-- 
-- 
-- 
-- Q2 >> START
-- 2.  Find the number of female employees in each department (show dept. Code). 
SELECT
    COUNT(*) AS 'FEMALE EMPLOYEE COUNT',
    DEPT_CODE AS DEPARTMENT_CODE,
    (
        SELECT
            DEPT_NAME
        FROM
            DEPARTMENT
        WHERE
            DEPT_CODE = DEPARTMENT_CODE
    ) AS DEPARTMENT_NAME
FROM
    EMP
WHERE
    UPPER(SEX) = 'F'
GROUP BY
    DEPT_CODE;

-- Q2 >> END
-- 
-- 
-- 
-- 
-- 
-- Q3 >> START
-- 3.  Find the city wise no. of employees for each department (show dept. Code). 
SELECT
    COUNT(*) AS COUNT,
    DEPT_CODE,
    CITY
FROM
    EMP
GROUP BY
    CITY;

-- Q3 >> END
-- 
-- 
-- 
-- 
-- 
-- Q4 >> START
-- 4.  Show the designation wise no of employees who have joined in the year 2000 in each 
--     department. The listing should appear in the ascending order of no. of employees. 
SELECT
    DESIG_CODE AS 'DESIGNATION CODE',
    COUNT(*) AS 'YEAR 2000 EMPLOYEE COUNT'
FROM
    EMP
WHERE
    YEAR(JN_DT) = 2000
GROUP BY
    DESIG_CODE
ORDER BY
    COUNT(*);

-- +------------------+--------------------------+
-- | DESIGNATION CODE | YEAR 2000 EMPLOYEE COUNT |
-- +------------------+--------------------------+
-- | DPT05            |                        2 |
-- | DPT01            |                        3 |
-- | DPT03            |                        3 |
-- | DPT04            |                        3 |
-- | DPT02            |                        4 |
-- +------------------+--------------------------+
-- Q4 >> END
-- 5.  Find the department code wise total basic of male employees only for the departments 
-- for  which  such  total  is  more  than  50,000  and  the  listing  should  appear  in  the 
-- descending order of total basic. 
SELECT
    DEPT_CODE,
    SUM(BASIC)
FROM
    EMP
GROUP BY
    DEPT_CODE
WHERE
    SUM(BASIC) > 1000000;

-- 6.  Show the employee name, Designation description and basic for all employees. 
SELECT
    EMP.EMP_NAME,
    EMP.DESIG_CODE,
    -- DESIGNATION.DESIG_DESC,
    DESIGNATION.DESIG_CODE,
    EMP.BASIC
FROM
    EMP,
    DESIGNATION
WHERE
    EMP.DESIG_CODE=DESIGNATION.DESIG_CODE
;
--select emp.emp_name, designation.desig_desc, emp.basic from emp,designation where emp.desig_code=designation.desig_code;

-- 7.  Show the employee name, Designation description, Department Name & Basic for all 
-- employees. 

-- 8.  Find the department Codes in which no employee works. 
-- 9.  Find the department names where at least one employee works. 
-- 10. Find the department names where at least 10 employees work. 
-- 11. Find the department code in which employee with highest Basic works. 
-- 12. Find the Designation description of the employee with highest basic. 
-- 13. Find the no. of managers in each department. 
-- 14. Find the maximum basic from EMP table without using MAX(). 
-- 15. Find the minimum basic from EMP table without using MIN(). 
-- 16. Find the name of the department with highest total basic. Do the same for highest 
-- average basic and maximum no. of employee. 
-- 17. Insert  same  rows  into  EMP  table  with  designation  code  not  existing  in 
-- DESIGNATION table. 
-- 18. Delete the rows from EMP table with invalid DESIG_CODE. 
-- 19. Find the name of the female employees with basic greater than the average basic of 
-- their respective department. 
-- 20. Find the number of female managers.