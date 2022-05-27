# Sorting
![image](https://user-images.githubusercontent.com/43443323/124379543-ebfe5c80-dce1-11eb-9b18-7d62965fd028.png)

## Quick Sort Implement
```python
import random

def quick_sort(li, first, last):
    left = first
    right = last
    pivot = li[left + random.randint(first, last) % (right - left)]
    
    # 8 9 5 6 3 4 7
    while left <= right:
        while li[left] < pivot:
            left += 1
        while li[right] > pivot:
            right -= 1
        
        if left <= right:
            li[left], li[right] = li[right], li[left]
            left += 1
            right -= 1
    
    if first < right:
        quick_sort(li, first, right)
    if left < last:
        quick_sort(li, left, last)
```

## Merge Sort Implement
```python
def merge_sort(data, first, last):
    if len(data) == 1:
        return

    if first < last:
        mid = (first + last) // 2
        merge_sort(data, first, mid)
        merge_sort(data, mid + 1, last)

        left = first
        right = mid + 1
        temp = []

        while left <= mid or right <= last:
            if left > mid:
                temp.append(data[right])
                right = right + 1
            elif right > last:
                temp.append(data[left])
                left = left + 1
            elif data[left] < data[right]:
                temp.append(data[left])
                left = left + 1
            elif data[right] < data[left]:
                temp.append(data[right])
                right = right + 1
        
        for idx in range(len(temp)):
            data[first + idx] = temp[idx]
```


## Define
```python
# using method sort
list.sort([cmp, key, reverse=False])

# using method sorted
sorted(iterable, [cmp, key, reverse=False]) -> return sorted list
```

## Increase
```python
# sort method
li.sort()

# sorted method
li = sorted(li)

# class
# because in class, we have dunder method (__lt__), we can use it to sort a list, 
# ref: https://www.tutorialsteacher.com/python/magic-methods-in-python

class num:
    def __init__(self, number):
        self.number = number

li_num = []
li_num.append(num(4))
li_num.append(num(2))
li_num.append(num(1))
li_num.append(num(3))
li.sort() # 1 2 3 4
```
## Increase sublist
```python
li[start:end] = sorted(li[start:end])
```
## Increase structure
```python
# structure
class student:
    def __init__(self, id=0, score=0):
        self.id = id
        self.score = score
```
```python
# increase by two conditions in the normal way
li_stu = []
li_stu.append(1, 3)
li_stu.append(2, 1)
li_stu.append(3, 5)
li_stu.append(4, 4)
li_stu.append(5, 8)
li.sort(key=lambda x: (-x.score, x.id))

# increase using dunder method
class student:
    def __init__(self, id=0, score=0):
        self.id = id
        self.score = score
    def __lt__(self, other)
        if (self.score > other.score) or (self.id < other.id):
            return True
        else:
            return False
```

## Decrease
```python
# using reverse
li.sort(reverse=True)

li = sorted(li, reverse=True)

# using key
li.sort(key=lambda x: -x)

li = sorted(li, key=lambda x: -x)

# using class like increase
```
## Decrease sublist
```python
# using reverse
li[start:end] = sorted(li[start:end], reverse=True)

# using key
li[start:end] = sorted(li[start:end], key=lambda x: -x)
```

## Practice

[Chores](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/03%20SORTING/chores.py)

[Devu, the Dumb Guy](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/03%20SORTING/devu_the_dumb_guy.py)

[GukiZ and Contest](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/03%20SORTING/gukiZ_and_contest.py)
