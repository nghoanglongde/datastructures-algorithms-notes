-- Link: https://leetcode.com/problems/big-countries/
-- Site: LeetCode
-- Name: Big Countries
-- Easy
-- ======================================================

select
    name,
    population,
    area
from World
where area >= 3000000 or population >= 25000000