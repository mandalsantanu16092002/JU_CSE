
-- > Q1 >> START
CREATE TABLE EMP(
    EMP_CODE CHAR(5) PRIMARY KEY,
    EMP_NAME CHAR(20),
    DEPT_CODE CHAR(5),
    DESIG_CODE CHAR(5),
    SEX CHAR(1),
    ADDRESS CHAR(25),
    CITY CHAR(20),
    STATE CHAR(20),
    PIN CHAR(6),
    BASIC INT,
    JN_DT DATE
);

CREATE TABLE DESIGNATION (
    DESIG_CODE CHAR(5),
    DESIG_DESC CHAR(20),
    PRIMARY KEY(DESIG_CODE)
);

CREATE TABLE DEPARTMENT (
    DEPT_CODE CHAR(5) PRIMARY KEY,
    DEPT_NAME CHAR(15)
);

-- > Q1 >> END
-- .....................................................
-- Q2 >> START  Display the structure of each table.
DESCRIBE EMP;

DESCRIBE DESIGNATION;

DESCRIBE DEPARTMENT;

-- Q2 >> END
-- .....................................................
-- Q3 >> START
-- ... DESIGNATION INSERTION >> START Manager, Executive, officer, clerk and helper
INSERT INTO
    DESIGNATION
VALUES
    ('1', 'Manager');

INSERT INTO
    DESIGNATION
VALUES
    ('2', 'Executive');

INSERT INTO
    DESIGNATION
VALUES
    ('3', 'Officer');

INSERT INTO
    DESIGNATION
VALUES
    ('4', 'Clerk');

INSERT INTO
    DESIGNATION
VALUES
    ('5', 'Helper');

-- ... DESIGNATION INSERTION >> END
-- ... DEPARTMENT INSERTION >> START  Personnel, Production, Purchase, Finance, Research department
INSERT INTO
    DEPARTMENT
VALUES
    ('1', 'Personnel');

INSERT INTO
    DEPARTMENT
VALUES
    ('2', 'Production');

INSERT INTO
    DEPARTMENT
VALUES
    ('3', 'Purchase');

INSERT INTO
    DEPARTMENT
VALUES
    ('4', 'Finance');

INSERT INTO
    DEPARTMENT
VALUES
    ('5', 'Research');

-- ... DEPARTMENT INSERTION >> END
-- ... EMP INSERTION >> START
INSERT INTO
    EMP
VALUES
    (
        '1',
        'GEORGE KELLERMAN',
        (
            SELECT
                DEPT_CODE
            FROM
                DEPARTMENT
            WHERE
                DEPT_NAME = 'Personnel'
        ),
        (
            SELECT
                DESIG_CODE
            FROM
                DESIGNATION
            WHERE
                DESIG_DESC = 'Manager'
        ),
        'M',
        'Santoshpur',
        'Kolkata',
        'West Bengal',
        '700075',
        1000000,
        '2022-02-02'
    );

INSERT INTO
    EMP
VALUES
    (
        '2',
        'JONATHAN LARSON',
        (
            SELECT
                DEPT_CODE
            FROM
                DEPARTMENT
            WHERE
                DEPT_NAME = 'Research'
        ),
        (
            SELECT
                DESIG_CODE
            FROM
                DESIGNATION
            WHERE
                DESIG_DESC = 'Executive'
        ),
        'M',
        'New York',
        'New York',
        'Washington',
        '100002',
        5000000,
        '2022-01-02'
    );

INSERT INTO
    EMP
VALUES
    (
        '3',
        'BRUCE WAYNE',
        (
            SELECT
                DEPT_CODE
            FROM
                DEPARTMENT
            WHERE
                DEPT_NAME = 'Personnel'
        ),
        (
            SELECT
                DESIG_CODE
            FROM
                DESIGNATION
            WHERE
                DESIG_DESC = 'Manager'
        ),
        'M',
        'GOTHAM CITY',
        'GOTHAM',
        'GOTHAM',
        '700023',
        10000000,
        '2022-01-01'
    );
SELECT COUNT(*) FROM 'lead_mgnt_sys'; 

-- EMP INSERTION >> END
-- Q3 >> END
-- .....................................................
-- Q4 >> START 
-- ... INSERTION INTO EMP TABLE WITHOUT DEPT_CODE AND BASIC
INSERT INTO
    EMP(
        EMP_CODE,
        EMP_NAME,
        DESIG_CODE,
        SEX,
        ADDRESS,
        CITY,
        STATE,
        PIN,
        JN_DT
    )
VALUES
    (
        '3',
        'MICHAEL SCOFIELD',
        (
            SELECT
                DESIG_CODE
            FROM
                DESIGNATION
            WHERE
                DESIG_DESC = 'Helper'
        ),
        'M',
        'GOTHAM CITY',
        'GOTHAM',
        'GOTHAM',
        '700023',
        '2022-01-01'
    );

-- Q4 >> END
-- .....................................................
-- Q5 >> START
-- Find the rows with unassigned DEPT_CODE
SELECT
    *
FROM
    EMP;

WHERE
    DEPT_CODE IS NULL;

-- Q5 >> END
-- .....................................................
-- Q6 >> START
--  Find the rows with BASIC equal to zero
SELECT
    *
FROM
    EMP
WHERE
    BASIC = 0;

-- ... OUTPUT >> START
-- ... +----------+----------------+-----------+------------+-----+---------+-----------+-------+--------+-------+------------+
-- ... | EMP_CODE | EMP_NAME       | DEPT_CODE | DESIG_CODE | SEX | ADDRESS | CITY      | STATE | PIN    | BASIC | JN_DT      |
-- ... +----------+----------------+-----------+------------+-----+---------+-----------+-------+--------+-------+------------+
-- ... | 5        | MARTHA KENT    | NULL      | 5          | M   | DALI    | NEW TEXAS | TEXAS | 200023 |     0 | 2022-01-01 |
-- ... | 6        | ZERO BASIC     | NULL      | 5          | M   | DALI    | NEW TEXAS | TEXAS | 200023 |     0 | 2022-01-01 |
-- ... | 7        | ZERO BASIC TWO | NULL      | 4          | M   | DALI    | NEW TEXAS | TEXAS | 200023 |     0 | 2022-01-01 |
-- ... +----------+----------------+-----------+------------+-----+---------+-----------+-------+--------+-------+------------+
-- ... OUTPUT >> END
-- Q6 >> END
-- .....................................................
-- Q7 >> START
-- Find the rows with unassigned Basic [note down the difference between the results obtained in Q.6 and  Q.7] 
SELECT
    *
FROM
    EMP
WHERE
    BASIC IS NULL;

-- ... OUTPUT >> START
-- ... +----------+------------------+-----------+------------+-----+-------------+--------+--------+--------+-------+------------+
-- ... | EMP_CODE | EMP_NAME         | DEPT_CODE | DESIG_CODE | SEX | ADDRESS     | CITY   | STATE  | PIN    | BASIC | JN_DT      |
-- ... +----------+------------------+-----------+------------+-----+-------------+--------+--------+--------+-------+------------+
-- ... | 4        | MICHAEL SCOFIELD | NULL      | 5          | M   | GOTHAM CITY | GOTHAM | GOTHAM | 700023 |  NULL | 2022-01-01 |
-- ... +----------+------------------+-----------+------------+-----+-------------+--------+--------+--------+-------+------------+
-- ... OUTPUT >> END
-- Q7 >> END
-- .....................................................
-- Q8 >> START
-- ... QUESTION >> Find the average basic of the employees.
SELECT
    AVG(BASIC)
FROM
    EMP;

-- ... OUTPUT >> START
-- ... +--------------+
-- ... | AVG(BASIC)   |
-- ... +--------------+
-- ... | 2357142.8571 |
-- ... +--------------+
-- ... OUTPUT >> END
-- ... Q8 >> END
-- .....................................................
-- Q9 >> START
--Replace the BASIC with 0 for the rows with unassigned Basic 
UPDATE
    EMP
SET
    BASIC = 0
WHERE
    BASIC IS NULL;

-- Query OK, 1 row affected (0.0158 sec)
-- Rows matched: 1  Changed: 1  Warnings: 0
-- Q9 >> END
-- .....................................................
-- Q10 >> START
-- Again , find  the average Basic . (Note the difference of result obtained in Q.8 & Q.10.
SELECT
    AVG(BASIC)
FROM
    EMP;

-- +--------------+
-- | AVG(BASIC)   |
-- +--------------+
-- | 2062500.0000 |
-- +--------------+
-- Q10 >> END
-- .....................................................
-- Q11 >> START
-- 11. Delete the rows with unassigned DEPT_CODE 
DELETE FROM
    EMP
WHERE
    DEPT_CODE IS NULL;

-- Q11 >> END
-- Q12 >> START
-- 12. Say, Net pay of an employee= Basic+HRA+DA where HRA is 50% of the Basic & DA is 40% of  
--      Basic.  Show the employee name & Net pay for all employees. 
SELECT
    EMP_NAME,
    ((BASIC * 190) / 100) AS 'NET PAY'
FROM
    EMP;

-- Q12 >> END
-- Q13 >> START
-- 13. Show the EMP_NAME & BASIC in the ascending order of DEPT_CODE. The employee name must 
-- appear  in uppercase . 
SELECT
    EMP_NAME,
    BASIC
FROM
    EMP
ORDER BY
(
        DEPT_CODE;

-- +--------------------+----------+
-- | EMP_NAME           | BASIC    |
-- +--------------------+----------+
-- | GEORGE KELLERMAN   |  1000000 |
-- | BRUCE WAYNE        | 10000000 |
-- | Lowercase Name One |    10000 |
-- | Lowercase Name Two |    10000 |
-- | JONATHAN LARSON    |  5000000 |
-- +--------------------+----------+
SELECT
    UPPER(EMP_NAME),
    BASIC
FROM
    EMP
ORDER BY
(
        DEPT_CODE;

-- +--------------------+----------+
-- | UPPER(EMP_NAME)    | BASIC    |
-- +--------------------+----------+
-- | GEORGE KELLERMAN   |  1000000 |
-- | BRUCE WAYNE        | 10000000 |
-- | LOWERCASE NAME ONE |    10000 |
-- | LOWERCASE NAME TWO |    10000 |
-- | JONATHAN LARSON    |  5000000 |
-- +--------------------+----------+
-- Q13 >> END
-- Q14 >> START
-- 14. Find the employees who have joined after 1st January 1990. 
SELECT
    *
FROM
    EMP
WHERE
    JN_DT > '1990-01-01';

-- Q14 >> END
-- Q15 >> START
-- 15. Find, how many employees have joined in the month of January? 
SELECT
    *
FROM
    EMP
WHERE
    MONTH(JN_DT) = '01';
-- +----------+--------------------+-----------+------------+-----+-------------+----------+-------------+--------+----------+------------+
-- | EMP_CODE | EMP_NAME           | DEPT_CODE | DESIG_CODE | SEX | ADDRESS     | CITY     | STATE       | PIN    | BASIC    | JN_DT      |
-- +----------+--------------------+-----------+------------+-----+-------------+----------+-------------+--------+----------+------------+
-- | 10       | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1990-01-06 |
-- | 11       | Lowercase Name Two | 4         | 3          | F   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1990-01-06 |
-- | 12       | Lowercase Name Two | 5         | 2          | F   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1980-01-06 |
-- | 2        | JONATHAN LARSON    | 5         | 2          | M   | New York    | NEW YORK | Washington  | 100002 |  5000000 | 2022-01-02 |
-- | 3        | BRUCE WAYNE        | 1         | 1          | M   | GOTHAM CITY | GOTHAM   | GOTHAM      | 700023 | 10000000 | 2022-01-01 |
-- | 8        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1985-01-02 |
-- | 9        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1985-01-03 |
-- +----------+--------------------+-----------+------------+-----+-------------+----------+-------------+--------+----------+------------+
-- Q15 >> END
-- Q16 >> START
-- 16. Find the maximum & minimum Basic. 
SELECT
    MAX(BASIC) AS 'MAX BASIC',
    MIN(BASIC) AS 'MIN BASIC'
FROM
    EMP;
-- +-----------+-----------+
-- | MAX BASIC | MIN BASIC |
-- +-----------+-----------+
-- |  10000000 |     10000 |
-- +-----------+-----------+
-- Q16 >> END
-- Q17 >> START
-- 17. Find how many Female employees are there? 
SELECT
    COUNT(*) AS 'FEMALE EMPLOYEE COUNT'
FROM
    EMP
WHERE
    SEX = 'F';
-- +-----------------------+
-- | FEMALE EMPLOYEE COUNT |
-- +-----------------------+
-- |                     2 |
-- +-----------------------+
-- Q17 >> END
-- Q18 >> START
-- 18. Replace CITY with existing value converted into uppercase for all rows. 
UPDATE
    EMP
SET
    CITY = (UPPER(CITY));

-- Q18 >> END
-- Q19 >> START
-- 19. Find in how many different cities various employees are residing?
-- calculate frequency
SELECT
    CITY,
    COUNT(*) AS FREQ
FROM
    EMP
GROUP BY
    CITY;

-- +----------+------+
-- | CITY     | FREQ |
-- +----------+------+
-- | KOLKATA  |   10 |
-- | NEW YORK |    1 |
-- | GOTHAM   |    1 |
-- +----------+------+
-- Q19 >> END
-- Q20 >> START
-- 20. Display the employee information in the  ascending order of DEPT_CODE
--  and with in a Department, it 
-- should be in the descending order of BASIC .
SELECT
    *
FROM
    EMP
ORDER BY
    DEPT_CODE ASC,
    BASIC DESC;
-- +----------+--------------------+-----------+------------+-----+-------------+----------+-------------+--------+----------+------------+
-- | EMP_CODE | EMP_NAME           | DEPT_CODE | DESIG_CODE | SEX | ADDRESS     | CITY     | STATE       | PIN    | BASIC    | JN_DT      |
-- +----------+--------------------+-----------+------------+-----+-------------+----------+-------------+--------+----------+------------+
-- | 3        | BRUCE WAYNE        | 1         | 1          | M   | GOTHAM CITY | GOTHAM   | GOTHAM      | 700023 | 10000000 | 2022-01-01 |
-- | 1        | GEORGE KELLERMAN   | 1         | 1          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |  1000000 | 2022-02-02 |
-- | 10       | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1990-01-06 |
-- | 11       | Lowercase Name Two | 4         | 3          | F   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1990-01-06 |
-- | 4        | Lowercase Name One | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 2022-02-02 |
-- | 5        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 2022-02-02 |
-- | 6        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1980-02-02 |
-- | 7        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1985-02-02 |
-- | 8        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1985-01-02 |
-- | 9        | Lowercase Name Two | 4         | 3          | M   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1985-01-03 |
-- | 2        | JONATHAN LARSON    | 5         | 2          | M   | New York    | NEW YORK | Washington  | 100002 |  5000000 | 2022-01-02 |
-- | 12       | Lowercase Name Two | 5         | 2          | F   | Santoshpur  | KOLKATA  | West Bengal | 700075 |    10000 | 1980-01-06 |
-- Q20 >> END