#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,p,num;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
vector<pair<int,int>> P[10];
char board[1010][1010];
bool vis[1010][1010];
int cnt[10];
void func(){
    queue<pair<int,int>> q;
    for(int i=1;i<=p;i++){
        for(int j=0;j<P[i].size();j++){
            q.push(P[i][j]);
            vis[P[i][j].first][P[i][j].second]=1;
            cnt[i]++;
        }
    }
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        char val=board[cx][cy];
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            if(!vis[nx][ny]&&board[nx][ny]=='.'){
                board[nx][ny]=val;
                cnt[val-'0']++;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>p;
    for(int i=0;i<p;i++)cin>>num;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]!='.'&&board[i][j]!='#'){
                P[board[i][j]-'0'].push_back({i,j});
            }
        }
    }
    func();
    
}
