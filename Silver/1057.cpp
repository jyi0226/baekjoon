#include <iostream>
using namespace std;

int n, a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;

    int cnt = 1;
    while (1)
    {
        if (a / 2 + a % 2 == b / 2 + b % 2)
            break;
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        cnt++;
    }
    cout << cnt;
}