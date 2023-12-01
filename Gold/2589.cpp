#include <iostream>
#include <queue>
using namespace std;
char board[55][55];
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int bfs(int x,int y){
    queue<pair<pair<int,int>,int>> q;
    bool visit[55][55]={};
    int Max=0;
    q.push({{x,y},0});
    visit[x][y]=1;
    while(!q.empty()){
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int val=q.front().second;
        Max=max(Max,val);
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            if(!visit[nx][ny]&&board[nx][ny]=='L'){
                visit[nx][ny]=1;
                q.push({{nx,ny},val+1});
            }
        }
    }
    return Max;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>board[i][j];
    }
    int Max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='L'){
                int val=bfs(i,j);
                Max=max(val,Max);
            }
        }
    }
    cout<<Max;
}
