//Bài toán tìm dãy con chung dài nhất trong 2 chuỗi cho trước(Longest Common Substring)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

int LCS(string s1, string s2){
    int length_s1 = s1.length();
    int length_s2 = s2.length();
    vector<vector<int>> DP(length_s1 + 1,vector<int>(length_s2 + 1,0));
    for(int i = 1;i <= length_s1;i++){
        for(int j = 1;j <= length_s2;j++){
            if(s1[i - 1] == s2[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j],DP[i][j - 1]);
        }
    }
    return DP[length_s1][length_s2];
}

int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 

    string s1;
    string s2;
    fi >> s1 >> s2;
    cout <<  LCS(s1,s2);
    return 0;
}