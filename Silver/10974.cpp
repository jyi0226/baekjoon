#include <iostream>
using namespace std;
int n;
int num[10];
bool vis[10];

void bt(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
            cout << num[i] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            num[cur] = i;
            bt(cur + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    bt(0);
}