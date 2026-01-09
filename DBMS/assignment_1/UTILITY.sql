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
        BASIC,
        JN_DT
    )
VALUES
    (
        '',
        'Lowercase Name',
        (
            SELECT
                DESIG_CODE
            FROM
                DESIGNATION
            WHERE
                DESIG_DESC = 'Clerk'
        ),
        'M',
        'DALI',
        'NEW TEXAS',
        'TEXAS',
        '200023',
         500000,
        '2022-01-01'
    );


INSERT INTO
    EMP
VALUES
    (
        '12',
        'Lowercase Name Two',
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
        'F',
        'Santoshpur',
        'Kolkata',
        'West Bengal',
        '700075',
        10000,
        '1980-01-06'
    );