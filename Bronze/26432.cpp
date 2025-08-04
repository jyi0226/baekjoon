#include <bits/stdc++.h>
using namespace std;
int t, n, m, p;
int board[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> m >> n >> p;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }

        int Max;
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            Max = 0;
            for (int j = 1; j <= m; j++)
            {
                Max = max(Max, board[j][i]);
            }
            total += (Max - board[p][i]);
        }

        cout << "Case #" << tc << ": " << total << "\n";
    }
}
