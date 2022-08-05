#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    char arr[n];
    long long int cntoc = 0;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 'O')
            cntoc++;
    }
    if (cntoc == 0 || cntoc == n)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    long long int curcnt = 0;
    for (long long int j = 0; j < cntoc; j++)
    {
        if (arr[j] == 'O')
            curcnt++;
    }
    long long int fincnt = curcnt;
    long long int mulfac = 1;
    for (long long int i = cntoc; i < n; i++)
    {
        if (arr[i] == 'O')
            curcnt++;
        if (arr[i - cntoc] == 'O')
            curcnt--;
        if (curcnt > fincnt)
        {
            mulfac = 0;
            fincnt = curcnt;
        }
        if (curcnt == fincnt)
            mulfac++;
    }
    long long int ans1 = cntoc - fincnt;
    cout << ans1 << " " << mulfac;
    return 0;
}