#include <iostream>
#include <string>
using namespace std;

bool vis[2525];
string str, duck = "quack";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int s = str.size();
    if (s % 5 != 0)
    {
        cout << -1;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < s; i++)
    {
        if (!vis[i])
        {
            int idx = 0;
            for (int j = i; j < s; j++)
            {
                if (!vis[j])
                {
                    if (str[j] == duck[idx])
                    {
                        vis[j] = true;
                        idx = (idx + 1) % 5;
                    }
                }
            }
            if (idx != 0)
            {
                cout << -1;
                return 0;
            }
            res++;
        }
    }
    for (int i = 0; i < s; i++)
        if (!vis[i])
            res = -1;
    cout << res;
}