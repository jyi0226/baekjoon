#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,m;
int board[55][55];
bool visit_v[55][55];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int res=99999;
void virus(int cur){
    if(cur==m){
        int board2[55][55];
        bool visited[55][55];
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit_v[i][j]){
                    board[i][j]=0;
                    q.push({i,j});
                }
                else{
                    if(board[i][j]==1)board2[i][j]=-1;
                    else board[i][j]=-2;
                }
            }
        }
        int Max=0;
        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                if(!visited[nx][ny]&&board2[nx][ny]==-2){
                    visited[ny][ny]=1;
                    board[nx][ny]=board[cx][cy]+1;
                    q.push({nx,ny});
                    Max=max(Max,board[nx][ny]);
                }
            }
        }
        //모든칸에 못퍼지는경우 구현해야함
        res=min(res,Max);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==2&&!visit_v[i][j]){
                visit_v[i][j]=1;
                virus(cur+1);
                visit_v[i][j]=0;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>board[i][j];
    }
    virus(0);
    cout<<res;
}
