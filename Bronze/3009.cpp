#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d,e,f,x,y;
    cin>>a>>b>>c>>d>>e>>f;
    if(a==c)x=e;
    else if(a==e)x=c;
    else x=a;
    if(b==d)y=f;
    else if(b==f)y=d;
    else y=b;
    cout<<x<<" "<<y;
}
