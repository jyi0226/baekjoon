#include <bits/stdc++.h>
using namespace std;
string str;
int res = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> str;
    int size = str.size();
    for (int i = 0; i <= size - 4; i++)
    {
        if (str[i] == 'D' && str[i + 1] == 'K' && str[i + 2] == 'S' && str[i + 3] == 'H')
            res++;
    }
    cout << res;
}