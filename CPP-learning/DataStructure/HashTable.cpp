#include<iostream>
#include<vector>
#include<fstream>
#include<map>
using namespace std;

//Mình sẽ ví dụ băm một array với các số nguyên
int hashFunc(int value){
    return value % 10;
}

//xử lý va chạm bằng separate chaining
void separateChaining(vector<int> hashtable[] ,vector<int> arr, int n){
    for(int i = 0;i < n;i++){
        int index = hashFunc(arr[i]);
        hashtable[index].push_back(arr[i]);
    }
}

//hàm search key
void search(vector<int> hashtable[], int key)
{
    //hash giá trị để tìm ra index của nó
    int index = hashFunc(key);
    for(int i = 0;i < hashtable[index].size();i++)
    {
        if(hashtable[index][i] == key)
        {
            cout << index << " " << key << endl;
            return;
        }
    }
    cout << "not found" << endl;
}

//=======================================================================================
//xử lý va chạm bằng linear probling
void linearProbling(vector<int> hashtable, vector<int> arr, int n){
    for(int i = 0;i < n;i++){
        int index = hashFunc(arr[i]);
        while(hashtable[index] != 0){
            index = (index + 1) % (n + n);
        }
        hashtable[index] = arr[i];
    }
}
//hàm tìm kiếm
void search2(vector<int> hashtable, int n, int key)
{
    int index = hashFunc(key);
    while(hashtable[index] != key && hashtable[index] != 0){
        index = (index + 1) % (n + n);
    }
    if(hashtable[index] == key)
        cout << index << key << endl;
    else
        cout << "not found" << endl;
}

//===========================================================================================
//search trong multimap
void searchMultimap(multimap<int,int> multi_map, int key){
    multimap<int, int> :: iterator itr;
    for (itr = multi_map.find(key); itr != multi_map.end(); itr++) {
        cout << itr->first << " " << itr->second << endl; 
    }
}

int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 
    vector<int> arr; //giả sử arr = [11, 13, 13, 14, 15]
    int n;
    fi >> n;// nhập số lượng phần tử array
    vector<int> hashtable[n + 1]; //tạo bảng băm
    for(int i = 0;i < n;i++){
        int temp;
        fi >> temp;
        arr.push_back(temp);
    }
    //kĩ thuật separate chaining(open hashing) xử lý va chạm
    separateChaining(hashtable ,arr, n);
    //tìm kiếm
    search(hashtable, 13);
    //======================================================================================
    vector<int> hashtable2(n + n, 0);
    //kĩ thuật linear probing (open addressing or closed hashing)
    linearProbling(hashtable2, arr, n);
    //hàm tìm kiếm
    search2(hashtable2, n, 13);
    //======================================================================================
    //ngoài ra còn các kĩ thuật khác như Double hashing hay Quadratic Probing, nó giống linear probling chỉ khác mỗi cách tính index
    //C++ có hỗ trợ các thư viện cho hash table như map, unodered_map hay multimap để xử lý va chạm
    //map và unodered_map có thể tự tìm hiểu, mình sẽ code multimap ở đây để xử lý va chạm
    //đối với các hàm có sẵn thì nó đã hash index cho mình sẵn, ko lo về việc cấu trúc hash function

    multimap<int, int> multi_map;        // empty multimap container 
  
    // insert elements in random order 
    multi_map.insert(pair <int, int> (1, 11)); 
    multi_map.insert(pair <int, int> (3, 13)); //index là 3
    multi_map.insert(pair <int, int> (3, 13));//2 giá trị 13 đều ở cùng index là 3
    multi_map.insert(pair <int, int> (4, 14)); 
    multi_map.insert(pair <int, int> (5, 15)); 
    searchMultimap(multi_map, 13);
    return 0;
  
}