#include <bits/stdc++.h>
using namespace std;
int t,a,b;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>a>>b;
        int res=9999;
        int c;
        for(int i=a;i<=1000;i++){
            if(b>i*4)continue;
            else if(b<i*3)c=i*3-b;
            else c=0;
            res=min(res,i-a+c);
        }
        cout<<res<<"\n";
    }
}
