SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM myNumbers
    GROUP BY num
        HAVING COUNT(num) = 1
) AS mx
