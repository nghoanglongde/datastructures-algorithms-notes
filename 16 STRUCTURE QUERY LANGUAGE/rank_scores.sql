-- Link: https://leetcode.com/problems/rank-scores/
-- Site: LeetCode
-- Name: Rank Scores
-- Medium
-- ======================================================

SELECT S1.score score, COUNT(S2.score) rank
FROM Scores S1
INNER JOIN (SELECT DISTINCT score FROM Scores) S2 ON S1.score <= S2.score
GROUP BY S1.id, S1.score
ORDER BY RANK ASC;

-- Sử dụng Dense rank
SELECT Score,
DENSE_RANK() OVER (ORDER BY Score DESC) AS "Rank"
FROM Scores