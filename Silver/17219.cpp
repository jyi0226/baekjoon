#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, string> mp;
string a, b;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mp[a] = b;
    }
    for (int j = 0; j < m; j++)
    {
        cin >> a;
        cout << mp[a] << "\n";
    }
}