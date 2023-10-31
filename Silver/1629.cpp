#include <iostream>
long long a,b,c;
using namespace std;

long long func(long long a,long long b,long long c){
    if(b==1)return a%c;
    long long cur=func(a,b/2,c);
    cur=cur*cur%c;
    if(b%2==0)return cur;
    return cur*a%c;
}

int main()
{
    cin>>a>>b>>c;
    cout<<func(a,b,c);
}
