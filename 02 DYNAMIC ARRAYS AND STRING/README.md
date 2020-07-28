# Dynamic Arrays and String Method
## Dynamic Arrays with Vector
Mình sẽ bày mn cách cấp phát động một mảng bằng **vector** vì nó phổ biến trong thi đấu, còn tại sao phải cấp phát động thì mn có thể search google, sử dụng mảng tĩnh hay động thì cái này tùy option của mn nhưng vẫn phải đảm bảo tiêu chí của đề nha, mình thì quen xài cấp phát động, đỡ rắc rối rồi sai tùm lum.

### Define
```c++
//Default: 
vector<kieu_du_lieu> vec([option_n, option_value])

//Define vector ko biết trước số lượng phần tử
vector<int> vec; 

//Define vector có biết trước số lượng phần tử
vector<int> vec(n); //vec = [0, 0, 0, 0,...,n]

//Define vector có biết trước số lượng phần tử rồi khởi gán giá trị luôn
vector<int> vec(n, 5); //vec = [5, 5, 5, 5,...,n]

//Define vector là mảng 2 chiều n x n với giá trị tại mỗi ô là 5 
vector<vector<int>> arr2D(n, vector<int>(n, 5))
```

### Các method thông dụng
```c++
vec.size(); //số lượng phần tử trong vector
vec.resize(); //tăng giảm kích thước vector
vec.front(); //phần tử đầu
vec.back(); //phần tử cuối
vec.begin(); // con trỏ đầu vector, dùng để lặp
vec.end(); //con trỏ cuối vector, dùng để lặp
vec.rbegin(); //con trỏ cuối vector, dùng để lặp
vec.rend(); //con trỏ đầu vector, dùng để lặp
vec.push_back(); //thêm phần tử vào cuối
vec.pop_back(); //loại bỏ phần tử cuối
vec.clear(); //làm rỗng vector
vec.empty(); //kiểm tra vector có rỗng hay ko
vec.insert(iterator, value); //thêm phần tử vào vị trí bất kì
```

### Thêm phần tử vào vector
```c++
vector<int> vec;
vec.push_back(4);
vec.push_back(3);

//vec = [4, 3]
```

### Truy cập phần tử trong vector
```c++
cout << vec.front(); // đầu tiên
cout << vec.back(); // cuối cùng
cout << vec[2]; // tại vị trí bất kì

//vec.begin(), vec.end() ko phải là phần tử đầu tiên và cuối cùng
//2 method này được dùng để duyệt vector, cout nó ra là error nha
```

### Xóa phần tử cuối
```c++
vec.pop_back();
```

### Xóa phần tử tại vị trí bất kì
```c++
vector<int>::iterator it; //hoàn toàn có thể thay bằng auto
it = vec.begin() + pos_del; //thay pos_del = chỉ số index
vec.erase(it);
```

### Xóa toàn bộ, làm rỗng
```c++
vec.clear();
```

### Chèn giá trị tại vị trí bất kì
```c++
//vec = [3, 2, 4, 1, 5]

vector<int>::iterator it; //hoàn toàn có thể thay cái này bằng auto
it = vec.begin() + 2 //có thể thay như sau: auto it = vec.begin() + 2;
vec.insert(it, 9);

//vec = [3, 2, 9, 4, 1, 5]

```

### Tăng giảm kích thức vector
```c++
vec.resize(7); // xin thêm 7
vec.resize(2); // giảm còn 2
```

### Kiểm tra vector rỗng
```c++
if(!vec.empty()){
	cout << "not empty";
}
else cout << "empty";
```

### Duyệt vector xuôi
```c++
//vec = [3, 2, 4, 9, 1, 5]

//duyệt toàn bộ vector bằng cách ngắn gọn như sau
for(auto value: vec){
	cout << value << " ";
}

//hoặc có thể viết tường minh như sau
for(int i = 0;i < vec.size();i++){
	cout << vec[i] << " ";
}

//hoặc
for(auto it = vec.begin();it != vec.end();it++){
	cout << *(it) << " ";
}

// Kiểu dữ liệu auto là kiểu tự định nghĩa, nó phụ thuộc vào giá trị gán
// ví dụ auto a = 5; thì auto = int
// ví dụ auto it = "demo"; thì auto string
// còn ở đây auto it = vec.begin() thì nó là một con trỏ, tường minh của nó sẽ
// là vector<int>::iterator it = vec.begin()
```

### Duyệt vector ngược
```c++
//Sử dụng index
for(int i = vec.size() - 1;i >= 0;i--){
	cout << vec[i] << " ";
}

// hoặc
for(auto it = vec.rbegin();it != vec.rend();it++){
	cout << *(it) << " ";
}
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