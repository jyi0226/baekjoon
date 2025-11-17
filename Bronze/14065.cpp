#include <bits/stdc++.h>
using namespace std;
float n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(7);

    cin >> n;
    float a = 1.609344 * n;
    float b = 3.785411784;
    float c = 100 / a;
    cout << c * b;
}