#include <iostream>
using namespace std;

char board[10101][505];
int cnt=0,r,c;
int dx[3]={-1,0,1},dy=1;
bool vis[10101][505];
void print_vis(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)cout<<vis[i][j];
        cout<<"\n";
    }
}
bool dfs(int x,int y){
    if(y==c-1){
        vis[x][y]=1;
        cnt++;
        return true;
    }
    vis[x][y]=1;
    for(int i=0;i<3;i++){
        int nx=x+dx[i];
        int ny=y+dy;
        if(nx<0||nx>=r)continue;
        if(vis[nx][ny])continue;
        if(dfs(nx,ny))return true;
    }
    return false;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]=='x')vis[i][j]=1;
        }
    }
    
    for(int i=0;i<r;i++){
        bool val=dfs(i,0);
    }
    //print_vis();
    cout<<cnt;
}
