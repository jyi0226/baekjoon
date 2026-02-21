#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int n;
vector<pair<int, int>> v;
int res = 0, a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), Comp);
    int s = v.size();
    a = v[0].first;
    b = v[0].second;
    for (int i = 1; i < s; i++)
    {
        if (v[i].first <= b)
        {
            if (b <= v[i].second)
                b = v[i].second;
        }

        else
        {
            res += (b - a);
            a = v[i].first;
            b = v[i].second;
        }
    }
    cout << res + b - a;
}