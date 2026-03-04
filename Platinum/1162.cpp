#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000001;
using namespace std;

int n, m, k;
int a, b, c;
vector<pair<int, int>> p[10101];
priority_queue<pair<long long, pair<int, int>>> pq;
long long dist[10101][22];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        p[a].push_back({b, c});
        p[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dist[i][j] = INF;
        }
    }

    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        auto [cur, cur_k] = node;

        pq.pop();
        if (-cost > dist[cur][cur_k])
            continue;

        for (auto &e : p[cur])
        {
            int nxt = e.first;
            long long ncost1 = -cost + e.second;
            long long ncost2 = -cost;

            if (dist[nxt][cur_k] > ncost1)
            {
                dist[nxt][cur_k] = ncost1;
                pq.push({-dist[nxt][cur_k], {nxt, cur_k}});
            }

            if (cur_k < k)
            {
                if (dist[nxt][cur_k + 1] > ncost2)
                {
                    dist[nxt][cur_k + 1] = ncost2;
                    pq.push({-dist[nxt][cur_k + 1], {nxt, cur_k + 1}});
                }
            }
        }
    }

    long long res = INF;
    for (int i = 0; i <= k; i++)
    {
        res = min(res, dist[n][i]);
    }

    cout << res;
}