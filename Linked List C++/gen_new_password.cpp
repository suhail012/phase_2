#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    string s;
    string sub = "";
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n = s.length();
    string c;
    getline(cin, c);
    transform(c.begin(), c.end(), c.begin(), ::tolower);
    int m = c.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                t = 1;
            }
        }
    }

    string w = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == c[j])
            {
                w += s[i];
            }
        }
    }
    int g = w.length();

    for (int i = 0; i < g; i++)
    {
        if (w[i] - '0' >= 0 and w[i] - '0' <= 9)
        {
            sub += w[i];
        }
    }
    for (int i = 0; i < g; i++)
    {
        if (isdigit(w[i]))
        {
            w.erase(i, 1);
            i--;
        }
    }
    if (t == 0)
    {
        cout << w << " " << sub;
    }
    else
    {
        cout << "New Language Error";
    }
    return 0;
}