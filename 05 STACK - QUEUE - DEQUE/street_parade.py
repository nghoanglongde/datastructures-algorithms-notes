# Link: https://www.spoj.com/problems/STPAR/
# Site: SPOJ
# Name: STPAR - Street Parade
# ======================================================

from collections import deque

def street_parade(li: list, n: int):
    sup_stack = deque()
    need = 1
    for i in range(0, n):
        while len(sup_stack) != 0 and sup_stack[-1] == need:
            sup_stack.pop()
            need += 1
        if li[i] == need:
            need += 1
        else:
            sup_stack.append(li[i])

    while len(sup_stack) != 0 and sup_stack[-1] == need:
        sup_stack.pop()
        need += 1

    if (need - 1) == n:
        print("yes")
    else:
        print("no")

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        li = list(map(int, input().split()))

        street_parade(li, n)
