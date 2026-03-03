#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999
using namespace std;

vector<pair<int, int>> p[1010];
priority_queue<pair<int, int>> pq;
priority_queue<int> kpath[1010];
int n, m, k;
int a, b, c;
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        p[a].push_back({b, c});
    }

    pq.push({0, 1});
    kpath[1].push(0);

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        for (auto &e : p[cur])
        {
            int nxt = e.first;
            int ncost = -cost + e.second;

            int s = kpath[nxt].size();
            if (s < k)
            {
                kpath[nxt].push(ncost);
                pq.push({-ncost, nxt});
            }
            else if (ncost < kpath[nxt].top())
            {
                kpath[nxt].pop();
                kpath[nxt].push(ncost);
                pq.push({-ncost, nxt});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int s = kpath[i].size();

        if (s < k)
            cout << "-1\n";
        else
            cout << kpath[i].top() << "\n";
    }
}