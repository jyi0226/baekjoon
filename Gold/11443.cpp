#include <iostream>
#include <map>
using namespace std;
int mod=1000000007;
map<long,long> m;
long long n;

long long fib(long long num){
    if(m[num])return m[num];
    long long res;
    if(num%2==0)res=(fib(num/2)*(fib(num/2+1)+fib(num/2-1)))%mod;
    else res=((fib((num-1)/2)*fib((num-1)/2))%mod+(fib((num+1)/2)*fib((num+1)/2))%mod)%mod;
    
    return m[num]=res%mod;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    m[0]=0;
    m[1]=1;
    m[2]=1;
    cin>>n;
    if(n%2==0){
        cout<<(fib(n+1)-1)%mod;
    }
    else{
        cout<<(fib(n)-1)%mod;    
    }
}
