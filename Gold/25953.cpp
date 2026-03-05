#include <algorithm>
#include <iostream>
#include <vector>
#define INF 101010101
using namespace std;

int n, t, m;
int a, b, c;
int st, ed;

vector<tuple<int, int, int>> v[1010];
int dp[10101][1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t >> m;
    cin >> st >> ed;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b >> c;
            v[i].push_back({a, b, c});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[st][0] = 0;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
            dp[j][i] = dp[j][i - 1];
        for (auto &[a, b, c] : v[i])
        {
            dp[b][i] = min(dp[a][i - 1] + c, dp[b][i]);
            dp[a][i] = min(dp[b][i - 1] + c, dp[a][i]);
        }
    }
    if (dp[ed][t] == INF)
        cout << -1;
    else
        cout << dp[ed][t];
}