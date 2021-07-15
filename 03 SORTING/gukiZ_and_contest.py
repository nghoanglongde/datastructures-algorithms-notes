# Link: https://codeforces.com/problemset/problem/551/A
# Site: Codeforces
# Name: GukiZ and Contest
# ======================================================

if __name__ == '__main__':
    n = int(input())
    li = list(map(int, input().split()))

    li_sorted = sorted(li, key=lambda x: -x)
    for value in li:
        print(li_sorted.index(value) + 1, end=" ") 