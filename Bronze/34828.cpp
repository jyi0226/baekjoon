#include <cmath>
#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    b /= 2;

    cout << min(min(a, b), c);
}
