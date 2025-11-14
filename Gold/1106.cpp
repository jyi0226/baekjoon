#include <bits/stdc++.h>
using namespace std;
int n, m;
int city[22][2];
int res[1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> city[i][0] >> city[i][1];
    }
    for (int i = 1; i <= n; i++)
        res[i] = 111111111;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + city[j][1] > n)
                res[n] = min(res[n], res[i] + city[j][0]);
            else
                res[i + city[j][1]] = min(res[i + city[j][1]], res[i] + city[j][0]);
        }
    }
    cout << res[n];
}