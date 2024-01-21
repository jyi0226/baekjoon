#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool board[2020][2020];
bool vis[2020][2020];
int n,a,b,c,d;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int func(){
    int cnt=0;
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            if(!vis[i][j]&&board[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                cnt++;
                while(!q.empty()){
                    int cx=q.front().first;
                    int cy=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=cx+dx[k];
                        int ny=cy+dy[k];
                        if(nx<0||ny<0||nx>2000||ny>2000)continue;
                        if(!vis[nx][ny]&&board[nx][ny]){
                            q.push({nx,ny});
                            vis[nx][ny]=1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        a=2*(a+500);
        b=2*(b+500);
        c=2*(c+500);
        d=2*(d+500);
        for(int j=a;j<=c;j++){
            board[b][j]=1;
            board[d][j]=1;
        }
        for(int j=b;j<=d;j++){
            board[j][a]=1;
            board[j][c]=1;
        }
    }
    int res=func();
    if(board[1000][1000])res--;
    cout<<res;
}
