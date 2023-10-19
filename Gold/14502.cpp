#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[8][8],board_copy[8][8];
int dir[2][4]={{0,1,0,-1},{1,0,-1,0}};
int n,m,ans=0;

void bfs(){
    
    for(int k=0;k<n;k++){
        for(int l=0;l<m;l++)board_copy[k][l]=board[k][l];
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board_copy[i][j]==2)q.push({i,j});
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dir[0][i];
            int ny=y+dir[1][i];
            
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(board_copy[nx][ny]==0){
                board_copy[nx][ny]=2;
                q.push({nx,ny});
            }
        }
    }
    
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board_copy[i][j]==0)cnt++;
        }
    }
    ans=max(ans,cnt);
}

void wall(int cur){
    if(cur==3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0){
                board[i][j]=1;
                wall(cur+1);
                board[i][j]=0;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0){
                board[i][j]=1;
                wall(1);
                board[i][j]=0;
            }
        }
    }
    cout<<ans;
}
