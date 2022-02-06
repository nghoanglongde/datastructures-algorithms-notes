-- Link: https://leetcode.com/problems/consecutive-numbers/
-- Site: LeetCode
-- Name: Consecutive Numbers
-- Medium
-- ======================================================

/* Write your PL/SQL query statement below */
SELECT DISTINCT(first_num) AS ConsecutiveNums
FROM (SELECT TAB1.num AS first_num, TAB2.num AS sc_num, TAB3.num AS thr_num
      FROM Logs TAB1
      INNER JOIN Logs TAB2 ON TAB1.id = TAB2.id - 1
      INNER JOIN Logs TAB3 ON TAB1.id = TAB3.id - 2
     )
WHERE first_num = sc_num AND sc_num = thr_num AND first_num = thr_num;
