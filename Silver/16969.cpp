#include <bits/stdc++.h>
using namespace std;
string str;
long long res = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> str;
    int size = str.size();

    if (str[0] == 'c')
        res = 26;
    else
        res = 10;

    for (int i = 1; i < size; i++)
    {
        if (str[i] == 'c')
        {
            if (str[i - 1] == 'c')
                res = (res * 25) % 1000000009;
            else
                res = (res * 26) % 1000000009;
        }
        else
        {
            if (str[i - 1] == 'c')
                res = (res * 10) % 1000000009;
            else
                res = (res * 9) % 1000000009;
        }
    }
    cout << res;
}