# Write your MySQL query statement below
SELECT ROUND(100*AVG(d.order_date = d.customer_pref_delivery_date), 2) AS immediate_percentage
FROM delivery d
JOIN (
    SELECT customer_id, MIN(order_date) AS min_order
    FROM delivery
    GROUP BY customer_id
) m
    ON d.customer_id = m.customer_id
    AND m.min_order = d.order_date