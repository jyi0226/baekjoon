#include <cmath>
#include <iostream>

using namespace std;

int a, b, n, m, h;
int line[33][11];
int res = 9999;

bool isTrue()
{
    for (int i = 1; i <= n; i++)
    {
        int st = i, cur = st;
        for (int j = 1; j <= h; j++)
        {
            if (line[j][cur] != 0)
            {
                cur = line[j][cur];
            }
        }
        if (cur != st)
            return false;
    }
    return true;
}

void bt(int x, int cnt)
{
    if (cnt > 3)
        return;

    if (isTrue())
    {
        res = min(res, cnt);
        return;
    }

    for (int i = x; i <= h; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (line[i][j] == 0 && line[i][j + 1] == 0)
            {
                line[i][j] = j + 1;
                line[i][j + 1] = j;
                bt(i, cnt + 1);
                line[i][j] = 0;
                line[i][j + 1] = 0;
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        line[a][b] = b + 1;
        line[a][b + 1] = b;
    }

    bt(1, 0);
    if (res == 9999)
        cout << -1;
    else
        cout << res;
}