#include <iostream>
#include <queue>
using namespace std;
int board[101][101];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,m;
bool air[101][101];
void dfs1(int x,int y){
    queue<pair<int,int>> q;
    board[x][y]=-1;
    q.push({x,y});
    while(!q.empty()){
        int curX=q.front().first,curY=q.front().second;
        q.pop();
        int nX,nY;
        for(int i=0;i<4;i++){
            nX=curX+dx[i];
            nY=curY+dy[i];
            if(nX<0||nY<0||nX>=n||nY>=m)continue;
            else{
                if(board[nX][nY]==0){
                    q.push({nX,nY});
                    board[nX][nY]=-1;
                }
            }
        }
    }
}
void air_ck(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==-1)air[i][j]=1;
        }
    }
}
int check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1)return 1;
        }
    }
    return 0;
}
int cheese(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(air[i][j]){
                int nx,ny;
                for(int k=0;k<4;k++){
                    nx=i+dx[k];
                    ny=j+dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=m)continue;
                    else{
                        if(board[nx][ny]==1){
                            board[nx][ny]=-1;
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
void change(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(air[i][j]){
                int nx,ny;
                for(int k=0;k<4;k++){
                    nx=i+dx[k];
                    ny=j+dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=m)continue;
                    else{
                        if(board[nx][ny]==0){
                            dfs1(nx,ny);
                            //board[nx][ny]=-1;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>board[i][j];
    }
    dfs1(0,0);
    air_ck();
    int res=0,val;
    while(1){
        
        //cout<<"\n";
        
        val=cheese();
        air_ck();
        change();
        air_ck();
        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<board[i][j]<<" ";
            cout<<"\n";
        }*/
        res++;
        
        if(check()==0){
            cout<<res<<"\n"<<val;
            break;
        }
    }
}
