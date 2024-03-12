#include <iostream>
#include <algorithm>
using namespace std;

bool vis[13];
int num[13],ans[6];
int k;

void func(int cnt,int cur){
    
    if(cnt==6){
        for(int i=0;i<6;i++)cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }
    
    for(int i=cur;i<k;i++){
        ans[cnt]=num[i];
        func(cnt+1,i+1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        cin>>k;
        if(k==0)break;
        for(int i=0;i<k;i++){
            cin>>num[i];
            vis[i]=0;
        }
        func(0,0);
        cout<<"\n";
    }
}
