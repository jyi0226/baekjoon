#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x,y,z,cnt;
    bool day;
};
char board[1010][1010];
bool vis[1010][1010][11];

int n,m,k;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int func(int x,int y,int z){
    queue<pos> q;
    pos val;
    val.x=x;val.y=y;val.z=z;val.cnt=1;val.day=1;
    q.push(val);
    vis[x][y][z]=1;
    
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int cz=q.front().z;
        bool cd=q.front().day;
        int ct=q.front().cnt;
        q.pop();
        
        if(cx==n-1&&cy==m-1)return ct;
        
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nz=cz;
            int nt=ct+1;
            bool nd;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            if(board[nx][ny]=='0'&&!vis[nx][ny][nz]){
                vis[nx][ny][nz]=1;
                pos val;
                val.x=nx;val.y=ny;val.z=nz;val.cnt=nt;
                if(cd)nd=0;
                else nd=1;
                val.day=nd;
                q.push(val);
            }
            else if(board[nx][ny]=='1'){
                if(cz<k&&!vis[nx][ny][nz+1]){
                    if(cd){
                        nz++;
                        vis[nx][ny][nz]=1;
                        pos val;
                        val.x=nx;val.y=ny;val.z=nz;val.cnt=nt;val.day=0;
                        q.push(val);
                    }
                    else{
                        pos val;
                        val.x=cx;val.y=cy;val.z=cz;val.cnt=nt;val.day=1;
                        q.push(val);
                    }
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
