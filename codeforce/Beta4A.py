#Link: https://codeforces.com/contest/4/problem/A

def main():
    n = int(input())
    if n % 2 != 0:
        print('NO')
    else:
        for i in range(2,n,2):
            temp = n - i
            if temp % 2 == 0:
                print('YES')
                return
        print('NO')

main()