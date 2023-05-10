#include <bits/stdc++.h>
using namespace std;
//ccw 알고리즘
int ccw(int a,int b,int c,int d,int x,int y)
{
    int result=(c-a)*(y-b)-(x-a)*(d-b);
    if(result>0)return -1;
    else if(result<0)return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(a>c)
    {
        int num=a;
        a=c;
        c=num;
        num=b;
        b=d;
        d=num;
    }
    if(e>g)
    {
        int num=e;
        e=g;
        g=num;
        num=f;
        f=h;
        h=num;
    }
    int value=ccw(a,b,c,d,e,f)*ccw(a,b,c,d,g,h);
    if(value<0)cout<<1;
    else cout<<0;
    
}
