#include <bits/stdc++.h>
using namespace std;
int n;
int board[11];
bool vis[11];
int res[11];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> board[i];

    for (int i = 1; i <= n; i++)
    {
        int idx = board[i];
        int val = 0;
        for (int j = 0; j < n; j++)
        {

            if (vis[j])
                continue;
            if (idx == val)
            {
                res[j] = i;
                vis[j] = 1;
                break;
            }
            else
            {
                if (res[j] == 0)
                    val++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}
