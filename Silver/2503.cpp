#include <iostream>
#include <string>
using namespace std;

int n, b, c;
string a;
bool vis[1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 123; i <= 987; i++)
    {

        string str = to_string(i);
        if (str[0] == '0' || str[1] == '0' || str[2] == '0' || str[0] == str[1] ||
            str[2] == str[1] || str[0] == str[2])
        {
            vis[i] = false;
            continue;
        }
        else
            vis[i] = true;
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        for (int j = 123; j <= 987; j++)
        {
            string str = to_string(j);
            int strike = 0, ball = 0;
            if (vis[j])
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (a[k] == str[l])
                        {
                            if (k == l)
                                strike++;
                            else
                                ball++;
                        }
                    }
                }
                if (strike != b || ball != c)
                {
                    vis[j] = false;
                    continue;
                }
            }
        }
    }
    int res = 0;
    for (int i = 123; i <= 987; i++)
        if (vis[i])
            res++;

    cout << res;
}