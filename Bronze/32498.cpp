#include <bits/stdc++.h>
using namespace std;
int n, num, res = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2 != 0)
            res++;
    }
    cout << res;
}