#include <algorithm>
#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

int n, m;
int a, b, c;
vector<int> path[202][202];
vector<pair<int, int>> p;
int dist[202][202];
double res = INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(1);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        path[a][b].push_back(c);
        path[b][a].push_back(c);
        p.push_back({a, b});
    }

    for (auto e : p)
    {
        int a = e.first;
        int b = e.second;

        sort(path[a][b].begin(), path[a][b].end());
        dist[a][b] = path[a][b][0];
        dist[b][a] = path[a][b][0];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        double var = 0;
        for (auto e : p)
        {
            int a = e.first;
            int b = e.second;

            for (auto k : path[a][b])
            {
                var = max(var, (double)(dist[i][a] + dist[i][b] + k) / 2);
            }
        }
        res = min(res, var);
    }

    cout << res;
}