# Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
# Site: LeetCode
# Name: Evaluate Reverse Polish Notation
# Medium
# ======================================================

from collections import deque

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = deque()
        for value in tokens:
            if value.lstrip("-").isdigit():
                stack.append(int(value))
                print(value)
            else:
                num_first = stack.pop()
                num_second = stack.pop()
                if value == "+":
                    res = num_second + num_first
                elif value == "-":
                    res = num_second - num_first
                elif value == "*":
                    res = num_second * num_first
                else:    
                    res = num_second / num_first
                stack.append(int(res))
        return stack.pop()