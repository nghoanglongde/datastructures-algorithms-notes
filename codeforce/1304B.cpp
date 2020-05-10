#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int maxN = 10000;

bool checkPal(string s)
{
    int j = s.length();
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[--j])
            return false;
    }
    return true;
}
int main()
{
    int n, m, dem = 0;
    bool tag = true;
    vector<string> s;
    stack<string> turn_back;
    bool T[maxN];
    queue<string> result;
    string finalre = "";
    string concate = "";
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string text;
        cin >> text;
        s.push_back(text);
        T[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (T[i])
        {
            for (int j = i + 1; j < n; j++)
            {
                string cons = "";
                cons.append(s[i]);
                cons.append(s[j]);
                if (checkPal(cons))
                {
                    dem = dem + m * 2;
                    result.push(s[i]);
                    turn_back.push(s[j]);
                    T[i] = T[j] = false;
                    break;
                }
            }
            if (T[i] && checkPal(s[i]) && tag)
            {
                tag = false;
                dem = dem + m;
                concate = s[i];
            }
        }
    }
    int length = result.size();
    if (length != 0)
    {
        for (int i = 1; i <= length * 2; i++)
        {
            if (i <= length)
            {
                finalre = finalre.append(result.front());
                result.pop();
                if (i == length && !concate.empty())
                {
                    finalre.append(concate);
                }
            }
            else
            {
                finalre.append(turn_back.top());
                turn_back.pop();
            }
        }
    }
    else if (length == 0 && !concate.empty())
    {
        finalre.append(concate);
    }
    cout << dem << endl;
    cout << finalre;

    return 0;
}