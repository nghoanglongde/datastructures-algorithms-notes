# Sorting - Sắp xếp
Lưu ý: Dưới đây mình note lại cách sử dụng hàm có sẵn trong libary như ban đầu mình đã thông báo ở phần giới thiệu CheatSheet.
## Define
```c++
#include<algorithm> //libary

sort(iterator_1, iterator_2, option);

//iterator_1: con trỏ vị trí bắt đầu
//iterator_2: con trỏ vị trí kết thức
//option: sắp xếp tăng hoặc giảm
```

## Sắp xếp tăng dần
```c++
sort(vector.begin(), vector.end());

//hoặc

sort(vector.begin(), vector.end(), less<int>()); //với less<int>() là hàm có sẵn

//hoặc

bool opt(int a, int b){
	if(a < b) return true;
    else return false;
}
sort(vector.begin(), vector.end(), opt);
```

## Sắp xếp giảm dần
```c++
sort(vector.begin(), vector.end(), greater<int>()); //với greater<int>() có sẵn

//hoặc

bool opt(int a, int b){
	if(a > b) return true;
    else return false;
}
sort(vector.begin(), vector.end(), opt);
```

## Sắp xếp mảng con
```c++
//arr = [3, 2, 6, 1, 8]

sort(arr.begin() + 1, arr.begin() + 4); //sắp tăng dần từ arr[1..3]
```

## Sắp xếp struct

##### Cách 1 - Sử dụng option
```c++
struct STUDENT{
	int ID;
    string name;
};
bool opt(STUDENT a, STUDENT b){
	if(a.ID < b.ID) return true;
    else return false;
}
sort(arr.begin(), arr.end(), opt); //vector<STUDENT> arr;
```

##### Cách 2 - Sử dụng operator
```c++
struct STUDENT{
	int ID;
    string name;
    bool operator < (const STUDENT &b){
    	if(ID < b.ID) return true;
        else return false;
    }
};
sort(arr.begin(), arr.end()); //vector<STUDENT> arr;
```