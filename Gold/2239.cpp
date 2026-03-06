#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
bool x[10][10], y[10][10], z[10][10];
int board[10][10];
int num;
bool flag = false;
string str[10];

void func(int idx)
{
    if (flag)
        return;
    if (idx == (int)v.size())
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        flag = true;
        return;
    }

    auto [i, j] = v[idx];
    int zidx = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;

    for (int k = 1; k <= 9; k++)
    {
        if (!x[i][k] && !y[j][k] && !z[zidx][k])
        {
            x[i][k] = true;
            y[j][k] = true;
            z[zidx][k] = true;
            board[i][j] = k;
            func(idx + 1);
            x[i][k] = false;
            y[j][k] = false;
            z[zidx][k] = false;
            board[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
        cin >> str[i];

    for (int i = 1; i <= 9; i++)
    {
        board[i][0] = 9;
        board[0][i] = 9;
        for (int j = 1; j <= 9; j++)
        {
            board[i][j] = str[i - 1][j - 1] - '0';
            num = board[i][j];
            if (num == 0)
                v.push_back({i, j});
            x[i][num] = true;
            y[j][num] = true;
            int zidx = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
            z[zidx][num] = true;
        }
    }
    func(0);
}