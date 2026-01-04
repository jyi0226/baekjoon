#include <bits/stdc++.h>
using namespace std;
string a, b, c;
int x, y;
int main()
{
    cin >> a >> b;
    if (a.size() < b.size())
    {
        c = a;
        a = b;
        b = c;
    }
    x = a.size();
    y = b.size();
    int res = x + y;

    for (int i = y - 1; i > 0; i--)
    {
        bool val = true;
        for (int j = 0; j < y - i; j++)
        {
            if (a[j] == '2' && b[i + j] == '2')
            {
                val = false;
                break;
            }
        }
        if (val)
        {
            res = min(res, x + i);
        }
    }
    for (int i = 0; i < y; i++)
    {
        bool val = true;
        for (int j = x - 1 - i; j < x; j++)
        {
            if (a[j] == '2' && b[j - x + 1 + i] == '2')
            {
                val = false;
                break;
            }
        }
        if (val)
        {
            res = min(res, x + y - i - 1);
        }
    }
    for (int i = 0; i <= x - y; i++)
    {
        bool val = true;
        for (int j = 0; j < y; j++)
        {
            if (a[i + j] == '2' && b[j] == '2')
            {
                val = false;
                break;
            }
        }
        if (val)
        {
            res = x;
            break;
        }
    }
    cout << res;
}
