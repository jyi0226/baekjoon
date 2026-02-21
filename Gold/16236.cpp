#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<pair<int, int>, int>> q;
vector<pair<pair<int, int>, int>> v;

bool vis[22][22];
int board[22][22];
int n, s = 2;
int res = 0;
int cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
    {
        if (a.first.first < b.first.first)
            return true;
        else if (a.first.first == b.first.first)
        {
            if (a.first.second < b.first.second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int bfs()
{
    v.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            vis[i][j] = false;
    }
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int t = q.front().second;
        q.pop();
        vis[cx][cy] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (!vis[nx][ny] && board[nx][ny] <= s)
            {
                if (board[nx][ny] == 0 || board[nx][ny] == s)
                {
                    q.push({{nx, ny}, t + 1});
                    vis[nx][ny] = true;
                }
                else
                {
                    v.push_back({{nx, ny}, t + 1});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    if (cnt + 1 == s)
    {
        s++;
        cnt = 0;
    }
    else
        cnt++;
    if (v.empty())
        return 0;

    sort(v.begin(), v.end(), comp);
    board[v[0].first.first][v[0].first.second] = 0;
    q.push({{v[0].first.first, v[0].first.second}, 0});
    return v[0].second;
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
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                q.push({{i, j}, 0});
                board[i][j] = 0;
            }
        }
    }
    while (1)
    {
        int var = bfs();
        if (var == 0)
            break;
        else
            res += var;
    }
    cout << res;
}