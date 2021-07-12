# Link: https://codeforces.com/problemset/problem/691/A
# Site: Codeforces
# Name: Fashion in Berland
# ======================================================

if __name__ == '__main__':
    n = int(input())
    li = list(map(int, input().split()))
    sum_li = sum(li, 0)
    res = None
    if n == 1:
        if sum_li == 1:
            res = "YES"
        else:
            res = "NO"
    else:
        if sum_li == (n - 1):
            res = "YES"
        else:
            res = "NO"
    print(res)
