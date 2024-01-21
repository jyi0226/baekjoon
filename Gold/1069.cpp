#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int x,y,d,t;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(9);
    cin>>x>>y>>d>>t;
    long double len=sqrt(x*x+y*y);
    long double T=0;
    if(d<t)cout<<len;
    else{
        while(len>d*2){
            len-=d;
            T+=t;
        }
        if(len==d*2)T+=2*t;
        else{
            long double T1,T2,T3;
            if(d<len){
                T1=t*2;
                T2=t+len-d;
                T3=t*3;
            }
            else{
                T1=t*2;
                T2=t+d-len;
                T3=len;
            }
            T+=min({T1,T2,T3});
        }
        cout<<T;
    }
}
