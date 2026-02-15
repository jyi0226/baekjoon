#include <cmath>
#include <iostream>

using namespace std;

long long a, b;
int res = 0;
bool vis[1010101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    for (long long i = 2; i <= sqrt(b); i++)
    {
        for (long long j = a / (i * i); (i * i) * j <= b; j++)
        {
            if (i * i * j >= a)
                vis[i * i * j - a] = true;
        }
    }
    for (long long i = a; i <= b; i++)
        if (!vis[i - a])
            res++;
    cout << res;
}