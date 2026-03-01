#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int a, b, c;

int pick = 0;
int ans = 0;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> line[1010];
bool vis[1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }

    for (auto &e : line[1])
    {
        pq.push({-e.second, e.first});
    }
    pick++;
    vis[1] = true;

    while (!pq.empty() && pick < n)
    {
        auto [cost, nxt] = pq.top();
        pq.pop();
        if (vis[nxt])
            continue;

        ans -= cost;
        vis[nxt] = true;
        pick++;

        for (auto &e : line[nxt])
        {
            if (vis[e.first])
                continue;
            pq.push({-e.second, e.first});
        }
    }
    cout << ans;
}