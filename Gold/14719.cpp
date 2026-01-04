#include <bits/stdc++.h>
using namespace std;

bool board[505][505];
int n, m;
int num;
int res = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            board[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int st = 0, ed = 0, val = 0;
        for (int j = 1; j <= m; j++)
        {
            if (board[j][i] && st == 0)
            {
                ed = 0;
                val = 0;
                st = j;
                continue;
            }

            if (board[j][i] && ed == 0)
            {
                st = j;
                res += val;
                ed = 0;
                val = 0;
            }

            if (!board[j][i])
                val++;
        }
    }
    cout << res;
}
