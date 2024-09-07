# Dynamic Arrays and String Method
## Array Initialization
### Numpy
It have more than 40 built-in function for creating python array with numpy, refer: [Link](https://numpy.org/doc/stable/user/basics.creation.html#arrays-creation)
```python
# create with numpy arange
li = np.arange(start, stop, step, dtype)

li = np.arange(n)

# create with numpy ones
li = np.ones(shape,[dtype,...])

# create with numpy zeros
li = np.zeros(shape,[dtype,...])
```

### Data types - List
Read more than at: [Link](https://www.programiz.com/python-programming/methods/built-in/list)
```python
li = []

li = list([iterable]) # iterable = [string, tuple, set, dictionary, anything have iter,...]
```

### Add element to array
```c++
li = []
li.append(x)

# append: because append method just only take copy of array and append to that copy, so we 
# need assign it to the variable
# ref: https://numpy.org/doc/stable/reference/generated/numpy.append.html
li = np.arange(5)
res = li.append(4)

# using insert or concatenate to insert value to specific postion k
# insert
li = np.arange(4)
li = np.insert(li, 2, 8) -> [0 1 8 2 3]

# faster way is using cocatenate
li = np.arange(4)
li = np.concatenate((li[:2], [8], li[2:]))
```


### Get number element of array
```python
li = [1, 2, 3, 4]
len(li)

li = np.arange(4)
li.shape
len(li)
```

### Access value of array
Read more about access value of numpy array: [Link](https://numpy.org/doc/stable/user/basics.indexing.html)
```python
li = [1, 2, 3, 4]
li = np.arange(n)

li[x]
```

### Delete value of array
```python
# Delete at end of numpy array
np.delete(li, -1)

# Delete at index k of numpy array
np.delete(li, k)

# Delete all value
li = np.arange(4)
li = np.array([])

# Delete at end of array
li.pop()

# Delete at index k
li.pop(k)

# Delete all value
li.clear()
```

### Extend size of array
```python
# numpy array
# One way is concatenate two array, but in numpy array we need to think that array are not 
# expandable. Once the array is defined, the space it occupies in memory

vec = [3, 2, 4, 1, 5]
vec.extend(2*[0]) # [3, 2, 4, 1, 5, 0, 0]

```

### Check array is empty
```python
# numpy array
if li.size == 0:
    # do nothing

if len(li) == 0
    # do nothing

# list
if len(li) == 0
    # do nothing
```

### Forward traverse
```python
li = [3, 2, 4, 9, 1, 5]
li = np.array([3, 2, 4, 9, 1, 5])

for value in li:
    print(value)
    
for i in range(len(li)):
    print(li[i])
```

### Backward traverse
```python
li = [3, 2, 4, 9, 1, 5]
for value in reversed(li):
    print(value)

for i in range(len(li)-1, -1, -1):
    print(li[i])
```

## String method
### Popular method
```python
# get length of string
len(s)

# check s is empty string, recommend using if not s
if len(s) == 0 or if not s

# clear some string by reassign it to empty string
s = ""

# concatenate string or delete substring
string_0 = string0[:pos] + string_1 + string0[pos:]

# find substring
index = string.find(substring)

# get ASCII number of specific character
ascii_num = ord(char)
```

### Converting between number and string
```python
# convert string to int
num = int(string)

# convert string to float
num = float(string)

# convert number to string
con_str = str(number)
```

## Common problem
### Two pointers
Ref knowledge: [Link](https://interviewing.io/two-pointers-interview-questions)

Typically, we use Two pointers technique when:
1. **Searching pairs in a sorted array:** The pointers can start at both ends of the array and move inward until they meet, eliminating possible pairs along the way. This method is faster than using a nested loop to check all pairs -> **Sorted array, not the unordered array**
2. **Checking for palindromes:** The pointers can start at both ends and move inward, checking if the mirrored characters are the same.
3. **Applying a sliding window:** One pointer marks the start of the window, the other the end. The window can then be 'slid' through the array to check for conditions.

And the thing you need to know that, **two pointers can start from anywhere**, it literally means, the first pointer can start from the beginning and the second can start from the mid or some stuff like that

### Sliding window
Ref knowledge: [Link](https://interviewing.io/sliding-window-interview-questions)

Typically, we use Sliding window technique when:
1. Asking to solve the problem related to substring, subarray but not subsequence though. Subarrays and substrings refer to contiguous segments of the original data. For example, in the array [1, 2, 3, 4, 5], [1, 2, 3] and [4, 5] are subarrays. On the other hand, subsequences can contain elements that are not contiguous. In the same array [1, 3, 5] is a subsequence

## Practice

[Arrays](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/arrays.py)

[Bear and Game](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/bear_and_game.py)

[Big Segment](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/big_segment.py)

[Find Numbers with Even Number of Digits](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/find_numbers_with_even_number_of_digits.py)

[Max Consecutive Ones](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/max_consecutive_ones.py)

[Merge Sorted Array](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/merge_sorted_array.py)

[Fashion in Berland](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/fashion_in_berland.py)

[Keyboard row](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/keyboard_row.py)

[Longest Substring](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/longest_substring.py)

[Palindrome Number](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/palindrome_number.py)

[Subarray Product Less Than K](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/subarray_less_than_k.py)

[Maximum Average Subarray I](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/02%20DYNAMIC%20ARRAYS%20AND%20STRING/maximum_average_subarray.py)