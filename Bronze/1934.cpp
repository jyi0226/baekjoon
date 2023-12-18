#include <iostream>

using namespace std;
long long n, m;
int t;
long long gcd(long long n, long long m)
{
    while (m > 0)
    {
        long long r = m;
        m = n % m;
        n = r;
    }
    return n;
}


int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        cout<<(n*m)/gcd(n,m)<<"\n";
    }
    /*if (n == m)cout << n;
    else if (n > m)
    {
        if (n % m == 0)cout << n;
        else cout << (n * m) / gcd(n, m);
    }
    else
    {
        if (m % n == 0)cout << m;
        else cout << (n * m) / gcd(m, n);
    }*/
}
