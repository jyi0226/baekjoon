#include <iostream>

using namespace std;
long long a,b,c,d;
long long gcd(long long n, int m)
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
    cin>>a>>b>>c>>d;
    long long num=(b*d)/gcd(b,d);
    long long num2=a*num/b+c*num/d;
    long long num3=gcd(num,num2);
    //cout<<num2<<" "<<num<<" "<<num3;
    cout<<num2/num3<<" "<<num/num3;
}
