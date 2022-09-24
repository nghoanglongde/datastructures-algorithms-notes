-- Link: https://leetcode.com/problems/swap-salary/
-- Site: LeetCode
-- Name: Swap Salary
-- Easy
-- ======================================================

/* Write your T-SQL query statement below */
UPDATE Salary
SET sex = (CASE
                WHEN sex = 'm' THEN 'f'
                ELSE 'm'
           END);
         
