# Link: https://codeforces.com/problemset/problem/242/B
# Site: Codeforces
# Name: Big Segment
# ======================================================

if __name__ == '__main__':
    n = int(input())
    li_seg = []
    min_element = 10e9
    max_element = 1
    for i in range(0, n):
        a, b = list(map(int, input().split()))
        li_seg.append([a, b])
        if a < min_element: min_element = a
        if b > max_element: max_element = b

    big_seg = list([min_element, max_element])
    if big_seg in li_seg:
        print(li_seg.index(big_seg) + 1)
    else:
        print(-1)
    