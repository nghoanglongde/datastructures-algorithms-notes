//Bài toán xóa k chữ số sao cho chuỗi n là dãy số nhỏ nhất

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

string buildLowestNumber(string num, int k)
{
    int n = num.length();
    if (k >= n)
        return "0";
    string s = "";
    for (char ch : num)
    {
        while (s.length() && s.back() > ch && k)
            s.pop_back(), k--;

        if (s.length() || ch != '0')
            s.push_back(ch);
    }

    while (s.length() && k--)
        s.pop_back();

    return s.length() != 0 ? s : "0";
}
int main()
{
    string text;
    cin >> text;
    int k;
    cin >> k;
    cout << buildLowestNumber(text, k) << endl;
    return 0;
}