#include <bits/stdc++.h>
using namespace std;
int t, n;
string word, str[10101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> word;
        int wsize = word.size();
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> str[i];
        int idx = 0;
        int Max = 200;
        for (int i = 0; i < n; i++)
        {
            int val = 0;
            for (int j = 0; j < wsize; j++)
            {
                if (word[j] != str[i][j])
                    val++;
            }
            if (val < Max)
            {
                Max = val;
                idx = i;
            }
        }
        cout << str[idx] << "\n";
    }
}