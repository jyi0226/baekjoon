#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t;
long long a,b;
long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<a/gcd(a,b)*b<<"\n"; 
    }
    
}
