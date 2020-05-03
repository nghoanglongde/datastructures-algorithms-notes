//Bài toán xóa k chữ số sao cho chuỗi n là dãy số nhỏ nhất

class Solution {
public:
    string removeKdigits(string num, int k) {
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
};