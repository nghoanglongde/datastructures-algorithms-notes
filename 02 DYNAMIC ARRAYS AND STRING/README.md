# Dynamic Arrays and String Method
## Dynamic Arrays
We have many ways to create an array, using python libary like numpy or we can initialize it by the normal way using Python's datatype **list**

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
One way is concatenate two array, but in numpy array we need to think that array are not 
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
### Các method thông dụng
```c++
string.size(); hoặc string.length() //độ dài chuỗi
string.empty(); //kiểm tra có phải chuỗi rỗng hay ko
string.insert(pos_insert, string); //insert một chuỗi vào vị trí bất kì
string.erase(pos_erase, b); //xóa n kí tự bắt đầu từ pos
string.substr(pos, n); //tách n kí tự bắt đầu từ pos
string.append(another_string, pos_start_anotherstring, n); //append n kí tự
```

### Chuyển chuỗi thành số
```c++
string num = "1712"
int convert = atoi(num.c_str());
```

### Chuyển số thành chuỗi
```c++
int num = 1712;
string convert = to_string(num);
```

### Đọc chuỗi có dấu cách
```c++
string s;
getline(cin, s);
```

### Chuyển kí tự thành số nguyên theo bảng mã ASCII
```c++
char c = 'z'; //ví dụ là z, ngoài ra có thể là '1', '0', 'a',...
int convert = c - 0; //122
```

### Chuyển số nguyên thành kí tự theo bảng mã ASCII
```c++
int ch = 122;
char convert = ch; //kí tự 'z'
```
