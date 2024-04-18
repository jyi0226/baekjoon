#include <iostream>
#include <queue>
using namespace std;

char board[2][101010];
int n,k;
int dx[3]={0,-1,1},dy[3]={1,0,0};
int a=9999,b=9999,c=9999,d=9999;
int res=0;
bool vis[2][101010]={0,};
int dist[2][101010]={0,};

int bfs(int st,int ed){
    
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
            dist[i][j]=0;
        }
    }
    
    queue<pair<int,int>> q;
    q.push({st,0});
    vis[st][0]=1;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i=0;i<3;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0||nx>=2||ny>=n)continue;
            
            if(board[nx][ny]!='#'&&!vis[nx][ny]){   
                vis[nx][ny]=1;
                q.push({nx,ny});
                dist[nx][ny]=dist[cx][cy]+1;
            }
        }
    }
    /*
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cout<<dist[i][j];
        cout<<"\n";
    }*/
    if(dist[ed][n-1]==0)return 9999;
    else return dist[ed][n-1];
}

void func(){
    if(board[0][0]!='#'){
        a=bfs(0,0);
        b=bfs(0,1);
    }
    if(board[1][0]!='#'){
        c=bfs(1,0);
        d=bfs(1,1);
    }
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cin>>board[i][j];
    }
    func();
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    if(board[0][0]=='.'&&board[0][n-1]=='.'&&board[1][0]=='.'&&board[1][n-1]=='.'){
        res=min(a,d)*k+k-1;
    }
    else if(board[0][0]=='.'&&board[0][n-1]=='.'&&(board[1][0]!='.'||board[1][n-1]!='.')){
        res=a*(k-1)+k-1+min(a,b);
    }
    else if(board[1][0]=='.'&&board[1][n-1]=='.'&&(board[0][0]!='.'||board[0][n-1]!='.')){
        res=d*(k-1)+k-1+min(c,d);
    }
    else{
        if(k==1){
            res=min(min(a,b),min(c,d));
        }
        else res=0;
    }
    if(res==0)cout<<-1;
    else cout<<res;
}
//31716 cpp
