#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool prime[2020];
int n;
int num[55];
vector<int> L, R;
vector<int> res, v[1010], match;
vector<bool> vis;

bool dfs(int x)
{
    for (int i : v[x])
    {
        if (vis[i])
            continue;
        vis[i] = true;

        if (match[i] == -1 || dfs(match[i]))
        {
            match[i] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    for (int i = 2; i <= 2000; i++)
    {
        if (!prime[i])
        {
            for (int j = 2; j * i <= 2000; j++)
            {
                prime[i * j] = true;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    if (num[0] % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (num[i] % 2 == 0)
                L.push_back(num[i]);
            else
                R.push_back(num[i]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (num[i] % 2 != 0)
                L.push_back(num[i]);
            else
                R.push_back(num[i]);
        }
    }
    if (L.size() != R.size())
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < L.size(); i++)
    {
        for (int j = 0; j < R.size(); j++)
        {
            if (!prime[L[i] + R[j]])
                v[i].push_back(j);
        }
    }
    for (int i = 0; i < v[0].size(); i++)
    {
        int cnt = 0;
        match.assign(R.size(), -1);
        match[v[0][i]] = 0;
        for (int j = 1; j < L.size(); j++)
        {
            vis.assign(R.size(), false);
            vis[v[0][i]] = true;
            if (dfs(j))
                cnt++;
        }
        if (cnt == L.size() - 1)
            res.push_back(R[v[0][i]]);
    }
    int cnt = res.size();
    sort(res.begin(), res.end());
    for (int i = 0; i < cnt; i++)
        cout << res[i] << " ";

    if (res.empty())
        cout << -1;
}