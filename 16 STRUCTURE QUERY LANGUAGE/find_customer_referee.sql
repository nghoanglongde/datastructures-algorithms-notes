-- Link: https://leetcode.com/problems/find-customer-referee/
-- Site: LeetCode
-- Name: Find Customer Referee
-- Easy
-- ======================================================

SELECT name
FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;
