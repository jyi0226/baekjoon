#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    if (n == 1)
        cout << "Either";
    else if (n == 2)
        cout << "Odd";
    else if (n == 10 || n == 6)
        cout << "Odd";
    else if (n % 2 == 0)
        cout << "Even";
    else
        cout << "Either";
}