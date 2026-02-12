#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int res_x, res_y;
int res = 11;
char board[11][11];
bool vis[11][11][11][11];

queue<pair<pair<int, int>, int>> qR, qB;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'B')
            {
                qB.push({{i, j}, 0});
            }
            else if (board[i][j] == 'R')
            {
                qR.push({{i, j}, 0});
            }
            else if (board[i][j] == 'O')
            {
                res_x = i;
                res_y = j;
            }
        }
    }

    while (!qR.empty())
    {
        int crx = qR.front().first.first;
        int cry = qR.front().first.second;
        int cbx = qB.front().first.first;
        int cby = qB.front().first.second;

        int cnt = qR.front().second;
        qR.pop();
        qB.pop();
        if (cnt >= 10)
            continue;
        vis[crx][cry][cbx][cby] = true;

        for (int i = 0; i < 4; i++)
        {
            int nrx = crx, nry = cry, nbx = cbx, nby = cby;
            bool flagR = false, flagB = false;
            int cntR = 0;
            int cntB = 0;
            while (board[nrx + dx[i]][nry + dy[i]] != '#')
            {
                if (board[nrx + dx[i]][nry + dy[i]] == 'O')
                {
                    flagR = true;
                    break;
                }
                else
                {
                    cntR++;
                    nrx += dx[i];
                    nry += dy[i];
                }
            }
            while (board[nbx + dx[i]][nby + dy[i]] != '#')
            {
                if (board[nbx + dx[i]][nby + dy[i]] == 'O')
                {
                    flagB = true;
                    break;
                }
                else
                {
                    cntB++;
                    nbx += dx[i];
                    nby += dy[i];
                }
            }
            if (flagB)
                continue;
            else if (flagR && !flagB)
            {
                res = min(res, cnt + 1);
            }
            else if (!flagR && !flagB)
            {
                if (vis[nrx][nry][nbx][nby])
                    continue;
                else
                {
                    if (nrx == nbx && nry == nby)
                    {
                        if (cntR < cntB)
                        {
                            nbx -= dx[i];
                            nby -= dy[i];
                        }
                        else
                        {
                            nrx -= dx[i];
                            nry -= dy[i];
                        }
                    }
                    qR.push({{nrx, nry}, cnt + 1});
                    qB.push({{nbx, nby}, cnt + 1});
                }
            }
        }
    }
    if (res > 10)
        cout << -1;
    else
        cout << res;
}