#include <bits/stdc++.h>
using namespace std;
bool board[11][11];
bool up[40],down[40];
int n,res=0;

void func(int cur,int cnt){
    if(cur>=2*n-1){
        res=max(cnt,res);
    }
    else{
        bool flag=0;
        
        if(cur<=n){
            for(int i=0;i<=cur;i++){
                int x=cur-i;
                int y=i;

                if(board[x][y]&&!up[cur]&&!down[x-y+n]){
                    flag=1;
                    up[cur]=1;
                    down[x-y+n]=1;
                    func(cur+1,cnt+1);
                    up[cur]=0;
                    down[x-y+n]=0;
                }
            }
        }
        else{
            for(int i=cur-n+1;i<n;i++){
                int x=cur-i;
                int y=i;

                if(board[x][y]&&!up[cur]&&!down[x-y+n]){
                    flag=1;
                    up[cur]=1;
                    down[x-y+n]=1;
                    func(cur+1,cnt+1);
                    up[cur]=0;
                    down[x-y+n]=0;
                }
            }
        }
        if(!flag)func(cur+1,cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>board[i][j];
    }
    func(0,0);
    cout<<res;
}
