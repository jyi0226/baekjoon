#include <bits/stdc++.h>
using namespace std;
unsigned long long num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    while (cin >> num)
    {
        set<int> s;
        unsigned long long t = 1;
        string str;

        while (1)
        {
            str = to_string(num * t);
            // cout << str << "\n";

            int size = str.size();
            for (int i = 0; i < size; i++)
            {
                if (s.count(str[i] - '0') == 0)
                    s.insert(str[i] - '0');
            }

            if (s.size() == 10)
            {
                cout << t << "\n";
                break;
            }
            t++;
        }
    }
}
