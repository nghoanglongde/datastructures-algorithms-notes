# Link: https://codeforces.com/problemset/problem/673/A
# Name: Bear and Game
# ======================================================

if __name__ == '__main__':
    n = int(input())
    li_time = list(map(int, input().split()))

    ans = 0
    tag = True
    for i in range(0, n):
        if i == 0:
            if li_time[i] > 15:
                ans = 0
                tag = False
                break
            else: ans = li_time[i]
        else:
            if li_time[i] - li_time[i - 1] > 15:
                tag = False
                ans = li_time[i - 1]
                break
            else:
                ans = li_time[i]
    if tag:
        # moi vi tri [i - 1] - [i] <= 15
        if 90 - ans > 15:
            print(ans + 15)
        else:
            print(90)
    else:
        print(ans + 15)