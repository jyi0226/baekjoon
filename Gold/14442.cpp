#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x,y,z;
};
char board[1010][1010];
bool vis[1010][1010][11];
int len[1010][1010][11];

int n,m,k;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int func(int x,int y,int z){
    queue<pos> q;
    pos val;
    val.x=x;val.y=y;val.z=z;
    q.push(val);
    vis[x][y][z]=1;
    
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int cz=q.front().z;
        q.pop();
        
        if(cx==n-1&&cy==m-1)return len[cx][cy][cz]+1;
        
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nz=cz;
            
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            if(board[nx][ny]=='0'&&!vis[nx][ny][nz]){
                vis[nx][ny][nz]=1;
                len[nx][ny][nz]=len[cx][cy][cz]+1;
                pos val;
                val.x=nx;val.y=ny;val.z=nz;
                q.push(val);
            }
            if(board[nx][ny]=='1'){
                if(nz<k&&!vis[nx][ny][nz+1]){
                    nz++;
                    vis[nx][ny][nz]=1;
                    len[nx][ny][nz]=len[cx][cy][cz]+1;
                    pos val;
                    val.x=nx;val.y=ny;val.z=nz;
                    q.push(val);
                }
            }
        }        
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>board[i][j];
    }
    cout<<func(0,0,0);
}
