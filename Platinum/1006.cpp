#include <algorithm>
#include <iostream>

using namespace std;

int a[10101], b[10101], c[10101];
int board[10101][2];
int n, w, tc;

void Clear(int x)
{
    for (int i = 0; i < x; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        board[i][0] = 0;
        board[i][1] = 0;
    }
}

void dp(int x)
{
    for (int i = x; i < n; i++)
    {
        a[i + 1] = min(b[i] + 1, c[i] + 1);
        if (board[i][0] + board[i][1] <= w)
            a[i + 1] = min(a[i + 1], a[i] + 1);
        if (i > 0 && board[i - 1][0] + board[i][0] <= w && board[i - 1][1] + board[i][1] <= w)
            a[i + 1] = min(a[i + 1], a[i - 1] + 2);
        if (i < n - 1)
        {
            b[i + 1] = a[i + 1] + 1;
            if (board[i][0] + board[i + 1][0] <= w)
                b[i + 1] = min(b[i + 1], c[i] + 1);
            c[i + 1] = a[i + 1] + 1;
            if (board[i][1] + board[i + 1][1] <= w)
                c[i + 1] = min(c[i + 1], b[i] + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while (tc--)
    {
        int res = 99999999;
        cin >> n >> w;
        Clear(n);

        for (int i = 0; i < n; i++)
            cin >> board[i][0];
        for (int i = 0; i < n; i++)
            cin >> board[i][1];

        a[0] = 0;
        b[0] = 1;
        c[0] = 1;
        dp(0);
        res = min(res, a[n]);

        if (n > 1 && board[0][0] + board[n - 1][0] <= w)
        {
            a[1] = 1;
            b[1] = 2;
            c[1] = (board[0][1] + board[1][1] <= w) ? 1 : 2;
            dp(1);
            res = min(res, c[n - 1] + 1);
        }
        if (n > 1 && board[0][1] + board[n - 1][1] <= w)
        {
            a[1] = 1;
            b[1] = (board[0][0] + board[1][0] <= w) ? 1 : 2;
            c[1] = 2;
            dp(1);
            res = min(res, b[n - 1] + 1);
        }
        if (n > 1 && board[0][0] + board[n - 1][0] <= w && board[0][1] + board[n - 1][1] <= w)
        {
            a[1] = 0;
            b[1] = 1;
            c[1] = 1;
            dp(1);
            res = min(res, a[n - 1] + 2);
        }
        cout << res << "\n";
    }
}