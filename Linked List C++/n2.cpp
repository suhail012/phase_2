#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    string s;
    string num = "";
    j
        string num1 = "";
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n = s.length();
    string c;
    getline(cin, c);
    transform(c.begin(), c.end(), c.begin(), ::tolower);
    string num2 = "";
    int m = c.length();

    string w = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == c[j])
            {
                w += s[i];
                t = 1;
            }
        }
    }

    for (int i = 0; i < w.length(); i++)
    {
        if (w[i] - '0' >= 0 and w[i] - '0' <= 9)
        {
            num += w[i];
        }
    }
    for (int i = 0; i < w.length(); i++)
    {
        if (isdigit(w[i]))
        {
            w.erase(i, 1);
            i--;
        }
    }
    if (t == 0)
    {
        cout << w << " " << num;
    }
    else
    {
        cout << "New Language Error";
    }
    return 0;
}