#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2020];
bool vis[2020];
int n, m, a, b;
int res = 0;
void bt(int cnt, int cur)
{
    if (res == 1)
        return;
    if (cnt >= 5)
    {
        res = 1;
        return;
    }
    for (auto e : v[cur])
    {
        if (!vis[e])
        {
            vis[e] = true;
            bt(cnt + 1, e);
            vis[e] = false;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        vis[i] = true;
        bt(1, i);
        vis[i] = false;
    }
    cout << res;
}