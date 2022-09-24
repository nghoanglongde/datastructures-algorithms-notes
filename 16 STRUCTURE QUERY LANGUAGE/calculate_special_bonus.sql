-- Link: https://leetcode.com/problems/calculate-special-bonus/
-- Site: LeetCode
-- Name: Calculate Special Bonus
-- Easy
-- ======================================================

SELECT employee_id, 
CASE
    WHEN employee_id % 2 = 0 OR name LIKE 'M%' THEN 0
    ELSE salary 
END AS bonus
FROM Employees;
