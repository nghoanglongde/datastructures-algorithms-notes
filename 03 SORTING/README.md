# Sorting
![image](https://user-images.githubusercontent.com/43443323/124379543-ebfe5c80-dce1-11eb-9b18-7d62965fd028.png)
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

[Chores](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/arrays.py)

[Devu, the Dumb Guy](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/bear_and_game.py)

[GukiZ and Contest](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/big_segment.py)
