# Write your MySQL query statement below
SELECT 
    book_id,
    title,
    author, 
    genre,
    pages,
    MAX(session_rating) - MIN(session_rating) AS rating_spread,
    ROUND(SUM(IF(session_rating<=2, 1.0, IF(session_rating>=4, 1.0, 0))) / COUNT(session_rating), 2) AS polarization_score
FROM books
JOIN reading_sessions s USING (book_id)
GROUP BY book_id 
    HAVING COUNT(*) > 4
    AND SUM(session_rating >= 4) > 0
    AND SUM(session_rating <= 2) > 0
    AND polarization_score >= 0.6
ORDER BY
    polarization_score DESC,
    title DESC;
