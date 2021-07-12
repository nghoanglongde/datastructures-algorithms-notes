# Link: https://codeforces.com/problemset/problem/572/A
# Site: Codeforces
# Name: Arrays
# ======================================================

if __name__ == '__main__':
    nA, nB = list(map(int, input().split()))
    k, m = list(map(int, input().split()))
    li_A = list(map(int, input().split()))
    li_B = list(map(int, input().split()))

    if li_A[k - 1] < li_B[-1*m]:
        print("YES")
    else:
        print("NO")
    