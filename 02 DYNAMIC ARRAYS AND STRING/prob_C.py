# Link: https://codeforces.com/problemset/problem/673/A
# Name: Bear And Game
# ======================================================

if __name__ == '__main__':
    n = int(input())
    li_time = list(map(int, input().split()))

    sum_time = 0
    for i in range(0, n):
        if i == 0:
            if li_time[i] - 0 > 15:
                sum_time += 15
                break
            else: sum_time += li_time[i]
        else:
            if li_time[i] - li_time[i - 1] > 15:
                sum_time += 15
                break
            else:
                sum_time += (li_time[i] - li_time[i - 1])
    
    print(sum_time)