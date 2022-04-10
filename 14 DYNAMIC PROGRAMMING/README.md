# Acknowledge
Khi giải QHĐ, ta cần xác định được 3 thứ:
1. Giá trị nền (giá trị khởi tạo cho bài toán con nhỏ nhất)
2. Công thức truy hồi (các bài toán nhỏ trong bài toán lớn)
3. Bảng giá trị các bài toán con để thực hiện truy vết

## Bài toán 1
Cho các đồng xu với giá tiền 1, 3 và 5. Và S = 11. Tìm số đồng xu nhỏ nhất, để tổng bằng S

**Xây dựng:** Với mỗi j, Vj≤i, tìm số đồng xu nhỏ nhất để tổng bằng i−Vj. Giả sử nó bằng m. Nếu m+1 nhỏ hơn số lượng đồng xu hiện tại cho tổng i thì ta cập nhập nó bằng m+1
```python
total = [1e6] * S
total[0] = 0
coins = [1, 3, 5]
for s in range(1, S + 1):
	for coin_val in coins:
		if s - coin_val >= 0:
			total[s] = min(total[s], total[s - coin_val] + 1)
```
Ta có 3 thứ đã hoàn thành:
1. Giá trị nền = total[0] (bài toán con nhỏ nhất)
2. Công thức truy hồi
3. Bảng giá trị các bài toán con để thực hiện truy vết = total
  
## Bài toán 2
Cho một dãy N số (5, 3, 4, 8, 6, 7). Tìm dãy con không giảm dài nhất

**Xây dựng:** Với j < i, nếu tồn tại A[j] ≤ A[i] (tức là dãy ko giảm). Khi đó seq[i] = Max(seq[i], seq[j] + 1). Tiếp tục tính như vậy cho đến khi đến được trạng thái seq[N]
```python
seq = [1] * N
nums = [5, 3, 4, 8, 6, 7]
for idx in range(N):
	for j in range(idx + 1):
		if j < idx and nums[j] <= nums[idx]:
			seq[idx] = max(seq[idx], seq[j] + 1) 
```
Ta có 3 thứ đã hoàn thành:

1.  Giá trị nền = seq[0] (bài toán con nhỏ nhất)
2.  Công thức truy hồi
3.  Bảng giá trị các bài toán con để thực hiện truy vết = seq

## Bài toán 3
Cho hai xâu ký tự. Tìm độ dài xâu con chung nhỏ nhất giữa chúng. Ví dụ với 2 xâu "quetzalcoatl" và "tezcatlipoca" thì xâu con chung dài nhất sẽ là "ezaloa" với độ dài 6

**Xây dựng:** Với bài toán này, chúng ta sẽ lần lượt giải các bài toán con như sau:

Lấy i ký tự đầu tiên từ xâu thứ nhất và j ký tự đầu tiên từ xâu thứ hai và tìm độ dài xâu chung dài nhất giữa 2 xâu con được lấy ra đó. Dễ dàng thấy được rằng, lời giải của mỗi bài toán con sẽ phụ thuộc vào i và j,  `dp(i, j)`. Và bài toán lớn sẽ được giải bằng cách lần lượt giải các bài toán con lần lượt từ  `dp(0, 0)`  và tăng dần độ dài xâu được lấy ra cho đến khi chúng ta lấy ra toàn bộ xâu của đề bài.

Chúng ta hãy bắt đầu lần lượt các bài toán con. Đương nhiên, nếu một trong hai xâu là rỗng thì xâu con chung của chúng cũng rỗng. Vậy  `dp(0, j) = dp(i, 0) = 0`. Nếu cả i và j đều dương, chúng ta cần suy xét một vài trường hợp.

1.  Nếu ký tự cuối cùng của xâu thứ nhất không có mặt trong xâu con chung dài nhất, nó có thể bị bỏ qua mà không ảnh hưởng gì đến kết quả. Công thức ở đây sẽ là  `dp(i, j) = dp(i - 1, j)`.
2.  Tương tự như trường hợp trên, ký tự cuối cùng của xâu thứ hai không ảnh hưởng đến kết quả thì  `dp(i, j) = dp(i, j - 1)`.
3.  Trường hợp cuối cùng, nếu hai ký tự cuối cùng của hai xâu  `x1, x2`  đều có mặt trong xâu con chung dài nhất. Dĩ nhiên là hai ký tự này phải là một thì điều này mới xảy ra, tức là  `x1 == x2`. Trong trường hợp này, khi xoá đi bất cứ một ký tự nào trong hai ký tự đó đều khiến xâu con chung dài nhất ngắn đi 1 ký tự. Vậy rõ ràng là  `dp(i, j) = dp(i - 1, j - 1) + 1`

```python
t =  [[0]  *  (len(s2)  +  1)  for _ in  range(len(s1)  +  1)]  
for i, x1 in  enumerate(s1,  1):  
	for j, x2 in  enumerate(s2,  1):  
		if x1 == x2: 
			t[i][j]  = t[i -  1][j -  1]  +  1  
		else: 
			t[i][j]  =  max(t[i][j -  1], t[i -  1][j])
```
**Lưu ý:** Tham khảo thêm output tại [Link](https://viblo.asia/p/quy-hoach-dong-mot-thuat-toan-than-thanh-E375zy01lGW)