#Link: https://codeforces.com/contest/4/problem/B

def main():
    d, sumtime = map(int, input().split())
    mi_time = []
    ma_time = []
    for _ in range(d):
        mintime, maxtime = map(int, input().split())
        mi_time.append(mintime)
        ma_time.append(maxtime)
    a = sum(mi_time)
    b = sum(ma_time)
    if a <= sumtime and sumtime <= b:
        print('YES')
        deficit = sumtime - a
        for i in range(d):
            if deficit > 0:
                extra = min(deficit, ma_time[i] - mi_time[i]) #những ngày đầu hãy chọn những số lớn nhất có thể
                deficit = deficit - extra
                print(mi_time[i] + extra, end=' ')
            else:
                print(mi_time[i], end=' ') #những ngày đầu đã chọn những số lớn nhất nên giờ ko cần thêm chi phí deficit nữa
    else:
        print('NO')


if __name__ == "__main__":
    main()
