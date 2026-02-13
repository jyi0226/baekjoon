#include <iostream>
using namespace std;

int n, l;
int board[101][101];
int board2[101][101];
bool x[101][101], y[101][101];
int res = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            board2[j][i] = board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j + 1] - board[i][j] == 1)
            {
                if (j - l < -1)
                {
                    flag = false;
                    break;
                }
                else
                {
                    for (int k = j - l + 1; k <= j; k++)
                    {
                        if (x[i][k] || board[i][j + 1] - board[i][k] != 1)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            x[i][k] = true;
                        }
                    }
                }
            }
            else if (board[i][j + 1] - board[i][j] == -1)
            {
                if (j + l >= n)
                {
                    flag = false;
                    break;
                }
                else
                {
                    for (int k = j + 1; k <= j + l; k++)
                    {
                        if (x[i][k] || board[i][j] - board[i][k] != 1)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            x[i][k] = true;
                        }
                    }
                }
            }
            else if (board[i][j + 1] - board[i][j] == 0)
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res++;
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (board2[i][j + 1] - board2[i][j] == 1)
            {
                if (j - l < -1)
                {
                    flag = false;
                    break;
                }
                else
                {
                    for (int k = j - l + 1; k <= j; k++)
                    {
                        if (y[i][k] || board2[i][j + 1] - board2[i][k] != 1)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            y[i][k] = true;
                        }
                    }
                }
            }
            else if (board2[i][j + 1] - board2[i][j] == -1)
            {
                if (j + l >= n)
                {
                    flag = false;
                    break;
                }
                else
                {
                    for (int k = j + 1; k <= j + l; k++)
                    {
                        if (y[i][k] || board2[i][j] - board2[i][k] != 1)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            y[i][k] = true;
                        }
                    }
                }
            }
            else if (board2[i][j + 1] - board2[i][j] == 0)
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res++;
    }
    cout << res;
}