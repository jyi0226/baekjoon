#include <bits/stdc++.h>
using namespace std;
int n;
string k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int num = k.back() - '0';
        if (num % 2 == 0)
            cout << "even\n";
        else
            cout << "odd\n";
    }
}
