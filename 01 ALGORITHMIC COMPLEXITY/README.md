# Algorithmic Complexity - Độ phức tạp thuật toán

Độ phức tạp thuật toán được chia ra làm 2 loại  
- Độ phức tạp thời gian (Time complexity - thời gian chạy thuật toán)
- Độ phức tạp không gian (Space complexity - dung lượng memory sử dụng)

Để ước lượng độ phức tạp người ta còn có một số khái niệm sau:
- Big Oh (O): Code tệ, còn non, nên thời gian lâu nhất
- Big Omega (![](https://latex.codecogs.com/gif.latex?%5COmega)): Tay to, code khủng, rơi vào ngay case tốt nhất
- Big Theta (![](https://latex.codecogs.com/gif.latex?%5CTheta)): Bao gồm cả worst case and best case

Trong phạm vi bài viết này mình chỉ viết về những thứ liên quan tới Big O thoi nha. Có 3 trường hợp mà mn cần quan tâm:
- Worst - Case: trường hợp xấu nhất
- Average - Case: trường hợp trung bình
- Best - Case: trường hợp tốt nhất

## Time Complexity

**01 - Constant time complexity O(1):** Độ phức tạp hằng số là khi thực hiện các phép gán, phép tính trên một biến hay truy xuất phần tử trên mảng, ví dụ như sau:

```c++
int x = 5 // O(1)
int y = x + 10 // O(1)
cout << x + y << endl;
```

**02 - Logarithmic time complexity O(log(n)):** 
- Độ phức tạp loga ở đây có thể hiểu như sau, giả sử mn có 100 người, muốn tìm một đứa tên X, nếu cứ đi hỏi lần lượt thì sẽ tốn rất nhiều thời gian. Ta có cách giải quyết như sau, chia ra thành 2 phần, mỗi bên 50 người, vậy thì ta chỉ cần biết bên nào đang chứa thằng X thì ta đã có thể loại đi 1/2 số người đi rồi, chu trình lặp cứ giảm đi 1/2 như vậy cho đến khi ta tìm được thằng X, được gọi là đpt **O(log(n))** =))  

- Chú ý: log(n) ở đây có thể là ![](https://latex.codecogs.com/gif.latex?%5Clog_%7B10%7Dn%5C) hoặc ![](https://latex.codecogs.com/gif.latex?%5Clog_%7B2%7Dn%5C), lí do vì sao thì mn có thể xem ở [link](https://stackoverflow.com/questions/20709267/big-o-notation-log-base-2-or-log-base-10) này. Nhưng mà đang ví dụ giảm 1/2 thì thôi, cứ mặc định khi mình ghi log(n) thì nó tương đương với ![](https://latex.codecogs.com/gif.latex?%5Clog_%7B2%7Dn%5C) cho nó hợp lý.

```c++
int i = 8;
while(i >= 1){
	i = i / 2; //mỗi lần lặp nó sẽ giảm 1/2
}
```

**03 - Linear time complexity O(n):** Độ phức tạp tuyến tính là khi ta thấy số lần lặp = kích thước dữ liệu đầu vào, ví dụ như sau:

```c++
int n = 1000;
for(int i = 0;i < n;i++){
	cout << "loop n time" << endl; // O(n)
}
```

**04 - Log - Linear time complexity O(nlog(n)):** Độ phức tạp tuyến tính loga này thường xuất hiện nhiều trong thi đấu khi ta phải kết hợp kết quả của nhiều bài toán nhỏ được giải độc lập, ví dụ như sau:

```c++
int x = 1000;
while(x >= 1){
	for(int i = 0;i < 1000;i++){
    	cout << "This is O(n)" << endl;
    }
	x = x / 2; //This is O(logn)
}
```

**05 - Polynomial time complexity O(![](https://latex.codecogs.com/gif.latex?n%5E%7Bc%7D)):** Độ phức tạp đa thức (với c = 2, 3, 4...), đặc trưng hay thấy là các vòng lặp lồng nhau, ví dụ như sau:

```c++
int sum = 0;
for(int i = 0;i < n;++i){
	for(int j = 0;j < n;++j){
		sum = sum + i + j; //O(n^2)
    }
}
```

**06 - Exponential time complexity O(![](https://latex.codecogs.com/gif.latex?c%5E%7Bn%7D)):** Độ phức tạp hàm mũ, mn có thể hay thấy O(![](https://latex.codecogs.com/gif.latex?2%5E%7Bn%7D)) thì nó chính là cái này =)), thường gặp khi sử dụng đệ quy để giải bài toán fibonacci

![image](https://user-images.githubusercontent.com/43443323/88563277-018fee80-d05c-11ea-99b8-602f54263360.png)

```c++
//Sử dụng đệ quy
int Fibo(int n){
	if(n == 0) return 0;
    else if(n == 1) return 1;
    else return Fibo(n - 1) + Fibo(n - 2); //O(2^n)
}

//Minh họa tại sao lại 2^n theo dạng cây
					F(n)
                     |
            -----------------------
            |					  |
        F(n - 1)	           F(n - 2) ---------------> max = 2^1
            |					  |
   ----------------         -----------------
   |			  |         |				|
F(n - 2)	  F(n - 3)   F(n - 3)		 F(n - 4) -------------> max = 2^2

//Ta thấy nó sẽ tăng trưởng theo 2^n lần
//Đpt: O(2^n)
```

**07 - Factorial time complexity O(n!):** Độ phức tạp giai thừa cũng tựa đpt hàm mũ, thuộc vào lớp thuật toán có đpt lớn, thường gặp trong các bài quay lui, vét cạn

Giả sử ta có 3 ngôi nhà, vậy số cách đi lại qua 3 ngôi nhà này sẽ là 3!, bao gồm những trường hợp sau:  
1 -> 2 -> 3  
1 -> 3 -> 2  
2 -> 1 -> 3  
2 -> 3 -> 1  
3 -> 1 -> 2  
3 -> 2 -> 1  
Vậy nếu ta có n ngôi nhà, vậy sẽ có n! cách di chuyển -> O(n!) thời gian, giả sử n = 100 thì mn có thê thấy time sẽ mất = 100! = chắc cả thế kỷ để chạy xong =))

#### Các quy tắc tính toán độ phức tạp thời gian
**Quy tắc hằng số:**
- O(c * f(n)) = O(f(n))
- Ví dụ: O(1712n) = O(n)

**Quy tắc cộng:**
- O(f(n) + g(n)) = O(max(f(n), g(n))
- Ví dụ: O(n^2 + 3n + 2) = O(n^2)

**Quy tắc nhân:**
- O(f(n) * g(n)) = O(f(n)) * O(g(n))
- Ví dụ: O(n^2.log(n)) = O(n^2) * O(logn)

## Space Complexity
**01 - Constant space complexity O(1):** Độ phức tạp ko gian hằng số là khi ta chỉ cần thao tác trên một biến, dữ liệu không phải mảng, ví dụ như sau:

```c++
int s = 0; //O(1)
for(int i = 0;i < n;i++){
	s = s + i; //chỉ dùng 1 biến s, ko tạo biến mới
}
```

**02 - Linear space complexity O(n):** Độ phức tạp không gian tuyến tính, là khi ta thao tác trên mảng n phần tử, ví dụ như sau:

```c++
vector<int> arr(n);
for(int i = 0;i < n;i++){
	arr[i] = arr[i] + i;
}
```
