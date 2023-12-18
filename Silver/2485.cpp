#include <iostream>

using namespace std;
long long n,num[101010];
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
    cin>>n;
    int val,val2;
    for(int i=1;i<=n;i++)cin>>num[i];
    val=num[2]-num[1];
    for(int i=2;i<n;i++){
        val2=num[i+1]-num[i];
        val=gcd(val,val2);
    }
    cout<<(num[n]-num[1])/val-n+1;
}
