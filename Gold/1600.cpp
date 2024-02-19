#include <iostream>
#include <queue>
using namespace std;

bool board[202][202],vis[202][202][33];
int ans[202][202][33];
struct pos{
    int x,y,z;
};

int k,n,m;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int hx[8]={-2,-2,2,2,-1,-1,1,1},hy[8]={-1,1,-1,1,-2,2,-2,2};

void func(int x,int y,int z){
    queue<pos> q;
    pos val;
    val.x=x;val.y=y;val.z=z;
    vis[x][y][z]=1;
    q.push(val);
    
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int cz=q.front().z;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nz=cz;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            if(!vis[nx][ny][nz]&&!board[nx][ny]){
                vis[nx][ny][nz]=1;
                ans[nx][ny][nz]=ans[cx][cy][cz]+1;
                pos val;
                val.x=nx;val.y=ny;val.z=nz;
                q.push(val);
            }
        }
        if(cz<k){
            for(int i=0;i<8;i++){
                int nx=cx+hx[i]; 
                int ny=cy+hy[i];
                int nz=cz+1;
                if(nx<0||ny<0||nx>=n||ny>=m)continue;
                
                if(!vis[nx][ny][nz]&&!board[nx][ny]){
                    vis[nx][ny][nz]=1;
                    ans[nx][ny][nz]=ans[cx][cy][cz]+1;
                    pos val;
                    val.x=nx;val.y=ny;val.z=nz;
                    q.push(val);
                } 
            }
        }
    }
}

int main()
{
    cin>>k>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>board[i][j];
    }
    func(0,0,0);
    int Min=99999999;
    bool val=0;
    for(int i=0;i<=k;i++){
        if(vis[n-1][m-1][i]){
            Min=min(Min,ans[n-1][m-1][i]);
            val=1;
        }
    }
    if(val)cout<<Min;
    else cout<<-1;
}
