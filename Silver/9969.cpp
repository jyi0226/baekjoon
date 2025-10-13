#include <bits/stdc++.h>
using namespace std;
int n, st_size, ed_size;
string p, st, ed, s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    cin >> p;
    for (int i = 0; p[i] != '*'; i++)
    {
        st += p[i];
    }

    for (int i = p.size() - 1; p[i] != '*'; i--)
    {
        ed += p[i];
    }
    st_size = st.size();
    ed_size = ed.size();
    while (n--)
    {
        bool flag = 1;
        cin >> s;
        for (int i = 0; i < st_size; i++)
        {
            if (st[i] != s[i])
            {
                flag = 0;
                break;
            }
        }
        for (int j = 0; j < ed_size; j++)
        {
            if (ed[j] != s[s.size() - 1 - j])
            {
                flag = 0;
                break;
            }
        }
        if (p.size() - 1 > s.size())
            cout << "NE\n";
        else
        {
            if (flag)
                cout << "DA\n";
            else
                cout << "NE\n";
        }
    }
}