#include <iostream>
using namespace std;
int n, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    cin >> n >> a >> b;

    int F = 0, B = 0, FB = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % a == 0 && i % b == 0)
            FB++;
        else if (i % a == 0)
            F++;
        else if (i % b == 0)
            B++;
    }
    cout << F << " " << B << " " << FB;
}

// int GCD(int a, int b) {
//     if(a == 0) return b;
//     return GCD(b % a, a);
// }

// int LCM(long long a, long long b) {
//     return (a * b) / GCD(a, b);
// }

// int main()
// {
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
//     cin>>n>>a>>b;

//     int FB=n/LCM(a,b);
//     int F=n/a;
//     int B=n/b;

//     cout<<F-FB<<" "<<B-FB<<" "<<FB;
// }
