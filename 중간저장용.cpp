#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,g,r;
int res=0;
int board[55][55];
int water[55][55];
int color[55][55];
bool vis[55][55];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
vector<pair<int,int>> v,R,G;

int bfs(){
    int cnt=0;
    queue<pair<int,int>> q;
    for(int i=0;i<R.size();i++){
        q.push(R[i]);
        vis[R[i].first][R[i].second]=1;
        water[R[i].first][R[i].second]=1;
        color[R[i].first][R[i].second]=1;
    }
    for(int i=0;i<G.size();i++){
        q.push(G[i]);
        vis[G[i].first][G[i].second]=1;
        water[G[i].first][G[i].second]=1;
        color[G[i].first][G[i].second]=2;
    }
    
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            else{
                if(board[nx][ny]==0)continue;
                else{
                    if(!vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        water[nx][ny]=water[cx][cy]+1;
                        color[nx][ny]=color[cx][cy];
                    }
                    else{
                        if(water[nx][ny]==water[cx][cy]+1&&color[nx][ny]==1&&color[cx][cy]==2){
                            color[nx][ny]=3;
                            cnt++;
                        }
                    } 
                }
            }
        }
    }
    
    /*cout<<"\n"<<R.size()<<" "<<G.size()<<" "<<cnt<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<water[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<color[i][j]<<" ";
        cout<<"\n";
    }*/
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            water[i][j]=0;
            vis[i][j]=0;
            color[i][j]=0;
        }
    }
    return cnt;
}

void red(int rcur,int rcnt){
    if(rcnt==r){
        res=max(res,bfs());
        return;
    }
    for(int i=rcur;i<v.size();i++){
        if(water[v[i].first][v[i].second]==0){
            R.push_back({v[i].first,v[i].second});
            red(i+1,rcnt+1);
            R.pop_back();
        }
    }
}

void func(int gcur,int gcnt){
    if(gcnt==g){
        red(0,0);
        return;
    }
    for(int i=gcur;i<v.size();i++){
        G.push_back({v[i].first,v[i].second});
        func(i+1,gcnt+1);
        G.pop_back();
    }
}

int main()
{
    cin>>n>>m>>g>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==2)v.push_back({i,j});
        }
    }
    func(0,0);
    cout<<res;
}
//18809
//10번예제만 해결하면 끝!
