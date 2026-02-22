#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, a, b;
vector<pair<int, int>> line;
vector<int> r;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        line.push_back({a, b});
    }
    sort(line.begin(), line.end());
    pq.push(line[0].second);

    for (int i = 1; i < n; i++)
    {
        int st = line[i].first;
        int ed = line[i].second;

        if (!pq.empty() && pq.top() <= st)
        {
            pq.pop();
        }
        pq.push(ed);
    }
    cout << pq.size();
}