-- Link: https://leetcode.com/problems/not-boring-movies/
-- Site: LeetCode
-- Name: Not Boring Movies
-- Easy
-- ======================================================

SELECT *
FROM Cinema
WHERE MOD(id, 2) != 0 AND (description != 'boring')
ORDER BY rating DESC;