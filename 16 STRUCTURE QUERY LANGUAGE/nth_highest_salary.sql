-- Link: https://leetcode.com/problems/nth-highest-salary/
-- Site: LeetCode
-- Name: Nth Highest Salary
-- Medium
-- ======================================================

CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    SELECT filtered.salary into result
    FROM (SELECT DISTINCT(salary), DENSE_RANK() OVER(ORDER BY salary DESC) AS rank
          FROM Employee) filtered
    WHERE filtered.rank = N;
    RETURN result;
END;