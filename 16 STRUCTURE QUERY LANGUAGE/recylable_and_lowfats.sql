-- Link: https://leetcode.com/problems/recyclable-and-low-fat-products/
-- Site: LeetCode
-- Name: Recyclable and Low Fat Products
-- Easy
-- ======================================================

select product_id
from Products
where low_fats = 'Y' and recyclable = 'Y'