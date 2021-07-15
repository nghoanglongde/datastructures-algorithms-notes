# Link: https://codeforces.com/problemset/problem/439/B
# Site: Codeforces
# Name: Devu, the Dumb Guy
# ======================================================

if __name__ == '__main__':
    n, x = list(map(int, input().split()))
    li = list(map(int, input().split()))

    li = sorted(li)
    res = 0
    for value in li:
        res += (value * x)
        if x > 1:
            x -= 1
    print(res)