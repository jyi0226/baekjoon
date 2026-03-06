#include <algorithm>
#include <iostream>

using namespace std;

int n;
int path[11][11];
bool vis[11];
int val = 0;
int res = 10000000;
int st;

void bt(int cur, int cnt)
{
    if (cnt == n)
    {
        if (path[cur][st] != 0)
        {
            res = min(res, val + path[cur][st]);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && path[cur][i] != 0)
        {
            vis[i] = true;
            val += path[cur][i];
            bt(i, cnt + 1);
            vis[i] = false;
            val -= path[cur][i];
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> path[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        st = i;
        vis[i] = true;
        bt(i, 1);
        vis[i] = false;
    }
    cout << res;
}