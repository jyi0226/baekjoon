#include <iostream>
using namespace std;

int n, b, c;
int a[1010101];

long long res = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> b >> c;

    for (int i = 0; i < n; i++)
    {
        a[i] -= b;
        res++;
        if (a[i] > 0)
        {
            res += a[i] / c;
            if (a[i] % c != 0)
                res++;
        }
    }
    cout << res;
}