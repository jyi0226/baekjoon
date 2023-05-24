#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];
int dis[102][102];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    queue<pair<int, int>> que;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)dis[i][j] = -1;
    }
    dis[0][0] = 0;
    que.push({ 0, 0 });

    while (!que.empty())
    {
        pair<int, int> cur = que.front(); que.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (dis[nx][ny] >= 0 || board[nx][ny] != '1')continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            que.push({ nx,ny });
        }
    }
    cout << dis[n - 1][m - 1] + 1;
}
