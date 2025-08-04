#include <bits/stdc++.h>
using namespace std;
string a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> a >> b;

    if (a == "null")
        cout << "NullPointerException\nNullPointerException";
    else if (b == "null")
        cout << "false\nfalse";
    else
    {
        if (a == b)
            cout << "true\n";
        else
            cout << "false\n";

        if (a.size() == b.size())
        {
            int size = a.size();
            for (int i = 0; i < size; i++)
            {
                if (tolower(a[i]) != tolower(b[i]))
                {
                    cout << "false";
                    return 0;
                }
            }
            cout << "true";
        }
        else
            cout << "false";
    }
}