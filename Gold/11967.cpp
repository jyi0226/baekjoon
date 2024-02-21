#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int a,b,c,d;
vector<pair<int,int>> v[101][101];
bool lit[101][101];

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int func(){
    bool vis[101][101]={};
    
    queue<pair<int,int>> q;
    q.push({1,1});
    lit[1][1]=1;
    vis[1][1]=1;
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        //cout<<cx<<" "<<cy<<" :\n";
        
        if(!v[cx][cy].empty()){
            for(int i=0;i<v[cx][cy].size();i++){
                lit[v[cx][cy][i].first][v[cx][cy][i].second]=1;
            }
            v[cx][cy].clear();
            return -1;
        }
        
        /*for(int i=0;i<v[cx][cy].size();i++){
            lit[v[cx][cy][i].first][v[cx][cy][i].second]=1;
        }*/
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<=0||ny<=0||nx>n||ny>n)continue;
            
            if(!vis[nx][ny]&&lit[nx][ny]){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(lit[i][j])cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        v[a][b].push_back({c,d});
    }
    
    while(1){
        int ans=func();
        if(ans!=-1){
            cout<<ans<<"\n";
            break;
        }
    }
    
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<lit[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}
