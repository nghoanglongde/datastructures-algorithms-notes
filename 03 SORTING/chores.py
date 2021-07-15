# Link: https://codeforces.com/problemset/problem/169/A
# Site: Codeforces
# Name: Chores
# ======================================================

if __name__ == '__main__':
    n, a, b = list(map(int, input().split()))
    li = list(map(int, input().split()))
    li = sorted(li)

    res = li[-a] - li[b - 1]
    print(res)