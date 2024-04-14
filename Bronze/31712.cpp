#include <bits/stdc++.h>
using namespace std;
int cu,du,cd,dd,cp,dp,h,t=0;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>cu>>du>>cd>>dd>>cp>>dp>>h;
    h-=(du+dd+dp);
    while(h>0){
        t++;
        if(t%cu==0)h-=du;
        if(t%cd==0)h-=dd;
        if(t%cp==0)h-=dp;
    }
    cout<<t;
}
