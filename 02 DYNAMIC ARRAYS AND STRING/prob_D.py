# Link: https://codeforces.com/problemset/problem/242/B
# Name: Big Segment
# ======================================================

import numpy as np
if __name__ == '__main__':
    n = int(input())
    li_seg = []
    for i in range(0, n):
        li_seg.append(list(map(int, input().split())))
    
    li_seg = np.asarray(li_seg)
    min_element = min(li_seg[:, 0])
    max_element = max(li_seg[:, 1])
    res = np.where((li_seg == (min_element, max_element)).all(axis=1))
    if len(res[0]) == 0:
        print(-1)
    else:
        print(res[0][0] + 1)