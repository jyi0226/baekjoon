#include <bits/stdc++.h>
using namespace std;
int n, m;
int month[15];
string s[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    cin >> n >> m;

    month[1] = 0;
    month[2] = 31 * 1;
    month[3] = 31 * 1 + 28 * 1;
    month[4] = 31 * 2 + 28 * 1;
    month[5] = 31 * 2 + 30 * 1 + 28 * 1;
    month[6] = 31 * 3 + 30 * 1 + 28 * 1;
    month[7] = 31 * 3 + 30 * 2 + 28 * 1;
    month[8] = 31 * 4 + 30 * 2 + 28 * 1;
    month[9] = 31 * 5 + 30 * 2 + 28 * 1;
    month[10] = 31 * 5 + 30 * 3 + 28 * 1;
    month[11] = 31 * 6 + 30 * 3 + 28 * 1;
    month[12] = 31 * 6 + 30 * 4 + 28 * 1;

    cout << s[(month[n] + m - 1) % 7];
}
