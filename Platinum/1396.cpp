#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, l;
int a, b, c;
int idx;

vector<pair<int, pair<int, int>>> path;
vector<int> child[202020];
int res[202020];
int parent[202020];
int rep[202020];
int value[202020];
int par[202020];
int depth[202020];
int up[20][202020];

int find_p(int x)
{
    if (parent[x] != x)
        return parent[x] = find_p(parent[x]);
    else
        return x;
}

void Union(int a, int b)
{
    int x = find_p(a);
    int y = find_p(b);

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
    return;
}

void KRT()
{
    int s = path.size();

    for (int i = 0; i < s; i++)
    {
        int a = path[i].second.first;
        int b = path[i].second.second;
        int c = path[i].first;

        int x = find_p(a);
        int y = find_p(b);

        if (x != y)
        {
            idx++;
            value[idx] = c;
            child[idx].push_back(rep[x]);
            child[idx].push_back(rep[y]);

            res[idx] = res[rep[x]] + res[rep[y]];

            Union(x, y);
            int r = find_p(x);
            rep[r] = idx;
        }
    }

    vector<int> roots;
    for (int i = 1; i <= n; i++)
    {
        int r = find_p(i);
        roots.push_back(rep[r]);
    }
    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end()), roots.end());

    for (int i = 1; i <= idx; i++)
    {
        par[i] = 0;
        depth[i] = 0;
        up[0][i] = 0;
    }

    queue<int> q;
    for (int rt : roots)
    {
        par[rt] = 0;
        depth[rt] = 0;
        up[0][rt] = 0;
        q.push(rt);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nxt : child[cur])
            {
                par[nxt] = cur;
                depth[nxt] = depth[cur] + 1;
                up[0][nxt] = cur;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= idx; j++)
        {
            int mid = up[i - 1][j];
            up[i][j] = (mid ? up[i - 1][mid] : 0);
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < 20; i++)
    {
        if (diff & (1 << i))
            a = up[i][a];
    }

    if (a == b)
        return a;

    for (int i = 20 - 1; i >= 0; i--)
    {
        if (up[i][a] != up[i][b])
        {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    idx = n;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        path.push_back({c, {a, b}});
    }
    sort(path.begin(), path.end());
    for (int i = 1; i <= 2 * n; i++)
    {
        parent[i] = i;
        if (i <= n)
        {
            rep[i] = i;
            res[i] = 1;
        }
    }

    KRT();

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        cin >> a >> b;
        if (find_p(a) != find_p(b))
            cout << "-1\n";
        else
        {
            int v = LCA(a, b);
            cout << value[v] << " " << res[v] << "\n";
        }
    }
}