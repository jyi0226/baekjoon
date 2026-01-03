#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[55][55];
int res = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = 0;
            for (int k = 1; k + j < m; k++)
            {
                if (board[i][j] == board[i][j + k])
                    val = k;
                if (i + val >= n)
                    continue;
                if (board[i][j] == board[i + val][j] && board[i][j] == board[i + val][j + val])
                {
                    res = max((val + 1) * (val + 1), res);
                }
            }
        }
    }
    cout << res;
}