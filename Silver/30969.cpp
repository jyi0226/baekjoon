#include <bits/stdc++.h>
using namespace std;
int price[1111];
int n, idx;
long long val;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    while (n--)
    {
        cin >> s >> val;
        if (s == "jinju")
            idx = val;
        if (val > 1000)
            price[1001]++;
        else
            price[val]++;
    }
    long long res = 0;
    for (int i = idx + 1; i <= 1001; i++)
    {
        res += price[i];
    }
    cout << idx << "\n" << res;
}