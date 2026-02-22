#include <iostream>
#include <map>
#include <string>

using namespace std;
int num[33], t, n;
map<string, int> mp;
string a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            mp[b]++;
        }
        int res = 1;
        for (auto iter : mp)
        {
            res *= (iter.second + 1);
        }
        cout << res - 1 << "\n";
    }
}