-- Link: https://leetcode.com/problems/combine-two-tables/
-- Site: LeetCode
-- Name: Combine Two Tables
-- Easy
-- ======================================================

/* Write your PL/SQL query statement below */
SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address ON Person.personId = Address.personId;