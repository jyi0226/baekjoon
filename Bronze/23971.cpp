#include <iostream>
#include <cmath>
using namespace std;
double a,b,c,d;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>a>>b>>c>>d;
    long long x=ceil(a/(c+1));
    long long y=ceil(b/(d+1));
    
    cout<<x*y;
}
