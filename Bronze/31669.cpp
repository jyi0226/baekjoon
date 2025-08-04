#include <bits/stdc++.h>
using namespace std;
int n, m;
char c, board[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[j][i] == 'O')
                break;
            if (j == n)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << "ESCAPE FAILED";
}
