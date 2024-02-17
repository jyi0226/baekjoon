#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x,y,z;  
};

char board[33][33][33];
int t[33][33][33];
bool vis[33][33][33];

int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int l,r,c;

void bfs(int z,int x,int y){
    queue<pos> q;
    pos val;
    val.x=x;val.y=y;val.z=z;
    q.push(val);
    
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int cz=q.front().z;
        q.pop();
        
        for(int i=0;i<6;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nz=cz+dz[i];
            
            if(nx<0||ny<0||nz<0||nx>=r||ny>=c||nz>=l)continue;
            
            if(!vis[nz][nx][ny]&&board[nz][nx][ny]!='#'){
                vis[nz][nx][ny]=1;
                t[nz][nx][ny]=t[cz][cx][cy]+1;
                pos val;
                val.x=nx;val.y=ny;val.z=nz;
                q.push(val);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cin>>l>>r>>c;
        if(l==0&&r==0&&c==0)break;
        int stz,stx,sty,edz,edx,edy;
        
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    vis[i][j][k]=0;
                    t[i][j][k]=0;
                    cin>>board[i][j][k];
                    if(board[i][j][k]=='S'){
                        stx=j;
                        sty=k;
                        stz=i;
                    }
                    else if(board[i][j][k]=='E'){
                        edx=j;
                        edy=k;
                        edz=i;
                    }
                }
            }
        }
        
        bfs(stz,stx,sty);
        
        if(t[edz][edx][edy]!=0){
            cout<<"Escaped in "<<t[l-1][edx][edy]<<" minute(s).\n";
        }
        else cout<<"Trapped!\n";
    }
    
}
