# Write your MySQL query statement below
SELECT
    stock_name,
    SUM(price * IF(operation = "Buy", -1, 1)) AS capital_gain_loss
FROM stocks
GROUP BY stock_name