#include <iostream>
using namespace std;
int p[1010101];
bool vis[1010101]={};
int find_p(int x){
    if(x==p[x])return p[x];
    return p[x]=find_p(p[x]);
}

void union_p(int x,int y){
    x=find_p(x);
    y=find_p(y);
    
    if(x<y)p[x]=y;
    else p[y]=x;
}

char board[1010][1010];
int num[1010][1010];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            p[cnt]=cnt;
            vis[cnt]=0;
            num[i][j]=cnt++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='S'){
                union_p(num[i][j],num[i+1][j]);
            }
            else if(board[i][j]=='N'){
                union_p(num[i][j],num[i-1][j]);
            }
            else if(board[i][j]=='W'){
                union_p(num[i][j],num[i][j-1]);
            }
            else if(board[i][j]=='E'){
                union_p(num[i][j],num[i][j+1]);
            }
        }
    }
    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[find_p(num[i][j])]){
                vis[find_p(num[i][j])]=1;
                cnt++;
            }
        }
    }
    cout<<cnt;
}
