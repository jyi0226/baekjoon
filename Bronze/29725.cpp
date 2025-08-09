#include <bits/stdc++.h>
using namespace std;
char c;
int res = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            if (c == 'P')
                res++;
            else if (c == 'p')
                res--;
            else if (c == 'N')
                res += 3;
            else if (c == 'n')
                res -= 3;
            else if (c == 'B')
                res += 3;
            else if (c == 'b')
                res -= 3;
            else if (c == 'R')
                res += 5;
            else if (c == 'r')
                res -= 5;
            else if (c == 'Q')
                res += 9;
            else if (c == 'q')
                res -= 9;
        }
    }
    cout << res;
}