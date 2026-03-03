#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 1111111111
using namespace std;

int n, m, a, b, c;
vector<pair<int, int>> path[101010];
int dist[101010];
int dijk(int st, int ed)
{
    dist[st] = INF;
    priority_queue<pair<int, int>> pq;
    pq.push({dist[st], st});

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (cost < dist[cur])
            continue;

        for (auto &e : path[cur])
        {
            int nxt = e.first;
            int ncost = min(cost, e.second);
            if (dist[nxt] < ncost)
            {
                dist[nxt] = ncost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist[ed];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++)
        dist[i] = 0;
    cin >> a >> b;
    cout << dijk(a, b);
}