#include <iostream>
#include <queue>
using namespace std;

int board[22][22];
int num[22][22];
bool vis[22][22];
int dice[7]={0,1,2,3,4,5,6};
int n,m,k,idx=0,dir=0;
int score[404];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int X=0,Y=0;

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                int cur=board[i][j];
                num[i][j]=idx;
                int cnt=1;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    int cx=q.front().first;
                    int cy=q.front().second;
                    q.pop();
                    
                    for(int i=0;i<4;i++){
                        int nx=cx+dx[i];
                        int ny=cy+dy[i];
                        
                        if(nx<0||ny<0||nx>=n||ny>=m)continue;
                        
                        if(!vis[nx][ny]&&board[nx][ny]==cur){
                            q.push({nx,ny});
                            vis[nx][ny]=1;
                            num[nx][ny]=idx;
                            cnt++;
                        }
                    }
                }
                score[idx]=cnt;
                idx++;
            }
        }
    }
}

void print(){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<num[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<idx;i++)cout<<score[i]<<" ";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    bfs();
    
    while(k--){
        if(dir==0){
            if(Y+1>=m)Y-=1;
            else Y+=1;
            
            int val=dice[1];
        }
        else if(dir==1){
            
        }
        else if(dir==2){
            
        }
        else{
            
        }
    }
    //주사위 이동 구현하면 끝!
}
