#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool vis_b[11][11];
int board[11][11];

int line[11][11];
bool vis[11];
int i_cnt = 1;
int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = i_cnt;
    vis_b[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (vis_b[nx][ny])
                continue;

            if (board[nx][ny] == 1)
            {
                board[nx][ny] = i_cnt;
                vis_b[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis_b[i][j] && board[i][j] == 1)
            {
                bfs(i, j);
                i_cnt++;
            }
        }
    }

    for (int i = 1; i < i_cnt; i++)
    {
        for (int j = 1; j < i_cnt; j++)
            line[i][j] = 999;
    }

    for (int i = 0; i < n; i++)
    {
        int st = 0;
        int cnt = 0;
        int ed = 0;
        for (int j = 0; j < m - 1; j++)
        {
            if (board[i][j] != 0 && board[i][j + 1] == 0)
            {
                st = board[i][j];
                cnt = j;
            }
            if (board[i][j] == 0 && board[i][j + 1] != 0)
            {
                ed = board[i][j + 1];
                cnt = j - cnt;

                if (cnt >= 2)
                {
                    line[st][ed] = min(cnt, line[st][ed]);
                    line[ed][st] = min(cnt, line[ed][st]);
                }
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        int st = 0;
        int cnt = 0;
        int ed = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (board[i][j] != 0 && board[i + 1][j] == 0)
            {
                st = board[i][j];
                cnt = i;
            }
            if (board[i][j] == 0 && board[i + 1][j] != 0)
            {
                ed = board[i + 1][j];
                cnt = i - cnt;
                if (cnt >= 2)
                {
                    line[st][ed] = min(cnt, line[st][ed]);
                    line[ed][st] = min(cnt, line[ed][st]);
                }
            }
        }
    }
    priority_queue<pair<int, int>> pq;
    int root = 1;
    vis[root] = true;
    for (int i = 1; i < i_cnt; i++)
    {
        if (line[root][i] != 999)
            pq.push({-line[root][i], i});
    }
    int var = 1;
    while (!pq.empty() && var < i_cnt - 1)
    {
        auto [cnt, nxt] = pq.top();
        pq.pop();

        if (vis[nxt])
            continue;

        ans -= cnt;
        vis[nxt] = true;
        var++;

        for (int i = 1; i < i_cnt; i++)
        {
            if (!vis[i] && line[nxt][i] != 999)
                pq.push({-line[nxt][i], i});
        }
    }

    if (var != i_cnt - 1)
        ans = -1;
    cout << ans;
}