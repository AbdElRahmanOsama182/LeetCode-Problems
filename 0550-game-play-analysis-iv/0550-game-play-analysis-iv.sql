# Write your MySQL query statement below
-- SELECT a.player_id
SELECT ROUND(AVG(a.player_id IS NOT NULL), 2) AS fraction
FROM Activity a
RIGHT JOIN (
    SELECT player_id, MIN(event_date) AS mn
    FROM Activity
    GROUP BY player_id
) b
    ON a.player_id = b.player_id
    AND DATEDIFF(a.event_date, b.mn) = 1