#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define BASE (int)1e6

class BigInt{
    private:
        vector<int> my_vector;
    public:
        //default constructor
        BigInt(){
            return;
        }
        //Constructor
        BigInt(string s){
            this->Integer(s);
        }

        // Get/Set
        void setVec(int num, int value){
            for(int i = 0;i < num;i++){
                this->my_vector.push_back(value);
            }
        }

        //method
        void Integer(string s){
            BigInt ans;
            if (s[0] == '-') 
                return; //nếu là số âm kết thúc hàm
            if (s.size() == 0){
                ans.my_vector.push_back(0); 
                this->my_vector = ans.my_vector;
            }
            while (s.size() % 6 != 0) {
                //thêm số 0 vào trước cho đủ chuỗi 6 số
                s = '0' + s;
            }
            for (int i = 0;i < s.size();i+=6) {
                //mỗi lần lấy 6 số, bỏ các số 0 ở đầu rồi push vào vector
                int v = 0;
                for (int j = i;j < i + 6;j++){
                    v = v * 10 + (s[j] - '0');
                }
                ans.my_vector.insert(ans.my_vector.begin(), v);
            }
            this->my_vector = ans.my_vector;
        }
        void Interger(long long x){
            string s = "";
            while (x > 0){
                long long temp = x % 10 + '0'; // + '0' để ép kiểu về char theo bảng mã ASCII
                s = char(x % 10 + '0') + s;
                x /= 10;
            }
            this->Integer(s);
        }
        //Operator overloading
        BigInt operator + (const BigInt b) {
            BigInt ans;
            long long carry = 0LL;
            for (int i = 0; i < this->my_vector.size() || i < b.my_vector.size(); i++) {
                if (i < this->my_vector.size()) 
                    carry = carry + this->my_vector[i];
                if (i < b.my_vector.size()) 
                    carry = carry + b.my_vector[i];
                ans.my_vector.push_back(carry % BASE); 
                carry = carry / BASE;
            }
            if (carry) 
                ans.my_vector.push_back(carry);
            return ans;
        }
        BigInt operator - (const BigInt b) {
            BigInt ans;
            long long carry = 0;
            for (int i = 0; i < this->my_vector.size(); i++) {
                long long s = this->my_vector[i] - carry;
                if (i < b.my_vector.size()) 
                    s = s - b.my_vector[i];
                if (s < 0){ 
                    s = s + BASE;
                    carry = 1;
                }
                else
                    carry = 0;
                ans.my_vector.push_back(s);
            }
            while (*ans.my_vector.rbegin() == 0 && ans.my_vector.size() > 1){
                //xóa những phần tử bằng 0 ở đầu
                ans.my_vector.pop_back(); 
            }

            return ans;
        }
        BigInt operator * (const BigInt b){
            BigInt ans;
            ans.setVec(this->my_vector.size() + b.my_vector.size() + 5, 0);
            for (int i = 0; i < this->my_vector.size(); i++) {
                int carry = 0;
                for (int j = 0; j < b.my_vector.size(); j++) {
                    int k = i + j; 
                    ans.my_vector[k] = ans.my_vector[k] + this->my_vector[i] * b.my_vector[j] + carry;
                    carry = ans.my_vector[k] / BASE; 
                    ans.my_vector[k] = ans.my_vector[k] % BASE;
                }
                if (carry) 
                    ans.my_vector[i + b.my_vector.size()] += carry;
            }
            while (*ans.my_vector.rbegin() == 0 && ans.my_vector.size() > 1) 
                ans.my_vector.pop_back(); 
            
            return ans;
        }
        // I/O
        void Print(){
            if(this->my_vector.size() == 0)
                cout << 0;
            else{
                for(int i = this->my_vector.size() - 1;i >= 0;i--){
                    cout << this->my_vector[i];
                }
            }
        }
};

int main()
{
    //string num; cin >> num;
    BigInt A("12345897");
    BigInt B("2567829");
    BigInt result = A + B;
    result.Print();
    return 0;
}