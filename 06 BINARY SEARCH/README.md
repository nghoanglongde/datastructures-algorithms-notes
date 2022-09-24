# Binary Search
## Python implementation
```
Search key x in list n elements which sorted
Time complexity: O(logn)
```

### find the position which matches target
```python
# left = 0 and right = len(li) - 1
# to catch problem about overflow, instead of using mid = (left + right) // 2
# we can handle it by using mid = left + (right - left) // 2
# and the result always in left or right position

def binary_search(left, right, li, target):
    while left <= right:
        mid = left + (right - left) // 2
        if li[mid] == target:
            return mid
        elif li[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1
```

### find the first position which matches the target
```python
def binary_search(left, right, li, target):
    while left <= right:
        mid = left + (right - left) // 2
        if li[mid] == target and (mid == left or target > li[mid - 1]):
            return mid
        elif li[mid] >= target:
            right = mid - 1
        else:
            left = mid + 1
    return -1
```

### find the last position which matches the target
```python
def binary_search(left, right, li, target):
    while left <= right:
        mid = left + (right - left) // 2
        if li[mid] == target and (mid == right or target <> li[mid + 1]):
            return mid
        elif li[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1
```

## Python built-in function
Python doesnt have binary search built-in function, but it has some useful built-in function we can see here
### bisect.bisect_left(li, target, [left_subsequence, end_subsequence])
This function return position in the sorted list, where value at that position greater (>) or equal (=) the target. If the target greater than each of element in the list, the position will be equal **len(li) + 1**
```python
import bisect
if __name__ == '__main__':
    li = [2, 2, 3, 4, 6, 7, 8, 8]
    res = bisect.bisect_left(li, 2, 0, len(li))
```

### bisect.bisect_right(li, target, [left_subsequence, end_subsequence])
This function return position in the sorted list, where value at that position greater (>) than the target. If the target greater than each of element in the list, the position will be equal **len(li) + 1**
```python
import bisect 
if __name__ == '__main__':
    li = [2, 2, 3, 4, 6, 7, 8, 8]
    res = bisect.bisect_right(li, 3, 0, len(li))
```

## Practice

[Search in Rotated Sorted Array](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/06%20BINARY%20SEARCH/search_in_rst.py)

[Search Insert Position](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/06%20BINARY%20SEARCH/search_ins_position.py)

[Two Sum II - Input array is sorted](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/06%20BINARY%20SEARCH/two_sum_arrays.py)

[Special Array With X Elements Greater Than or Equal X](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/06%20BINARY%20SEARCH/special_arr.py)

[First Bad Version](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/06%20BINARY%20SEARCH/first_bad_version.py)