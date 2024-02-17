#include <iostream>
#include <queue>
using namespace std;

int board[303][303];
bool vis[303][303];

int t,n;
int a,b,c,d;
int dx[8]={-2,-2,2,2,-1,1,-1,1};
int dy[8]={-1,1,-1,1,-2,-2,2,2};

void bfs(int x,int y){
    vis[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        if(cx==c&&cy==d){
            cout<<board[cx][cy]<<"\n";
            return;
        }
        
        for(int i=0;i<8;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=n)continue;
            if(!vis[nx][ny]){
                vis[nx][ny]=1;
                board[nx][ny]=board[cx][cy]+1;
                q.push({nx,ny});
            }
        }
    }
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
            board[i][j]=0;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    
    cin>>t;
    while(t--){
        cin>>n;
        reset();
        cin>>a>>b>>c>>d;
        bfs(a,b);
    }
}
