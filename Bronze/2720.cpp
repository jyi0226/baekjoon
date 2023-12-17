#include <iostream>
using namespace std;
int t,n,a,b,c,d;
int main()
{
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        a=n/25;
        n%=25;
        b=n/10;
        n%=10;
        c=n/5;
        n%=5;
        d=n;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    }
}
