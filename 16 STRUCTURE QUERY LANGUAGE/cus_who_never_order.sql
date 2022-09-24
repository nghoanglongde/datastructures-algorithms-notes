-- Link: https://leetcode.com/problems/customers-who-never-order/
-- Site: LeetCode
-- Name: Customers Who Never Order
-- Easy
-- ======================================================

SELECT name AS Customers
FROM Customers
WHERE NOT EXISTS(SELECT 1
                FROM Orders
                WHERE Customers.id = Orders.customerID);
