# Write your MySQL query statement below
SELECT 
    user_id,
    COUNT(prompt) AS prompt_count,
    ROUND(AVG(tokens*1.0), 2) AS avg_tokens
FROM
    prompts
GROUP BY
    user_id
HAVING 
    count(prompt) > 2 AND max(tokens) > avg(tokens)
ORDER BY
    avg_tokens DESC