#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;

int n, m;
int a, b, c;
bool vis[10101];
int cost[10101];
int root = 1;
int res = 0;
vector<pair<int, int>> path[10101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int j = 0; j < m; j++)
    {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }

    for (auto &e : path[root])
    {
        pq.push({-(e.second * 2 + cost[root] + cost[e.first]), {root, e.first}});
    }
    vis[root] = true;

    int pick = 1;
    while (!pq.empty() && pick < n)
    {
        auto [c, node] = pq.top();
        auto [cur, nxt] = node;
        pq.pop();
        if (vis[nxt])
            continue;

        vis[nxt] = true;
        res -= c;
        pick++;

        for (auto &e : path[nxt])
        {
            if (!vis[e.first])
                pq.push({-(e.second * 2 + cost[nxt] + cost[e.first]), {nxt, e.first}});
        }
    }
    sort(cost, cost + n + 1);
    cout << res + cost[1];
}