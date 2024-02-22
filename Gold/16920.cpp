#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos{
    int x,y,cnt;
};

int n,m,p;
int Cnt[10];
int ans[10];
char board[1010][1010];
bool vis[1010][1010];
queue<pos> P[10];
bool flag[10];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};


void func(int idx){
    queue<pos> q=P[idx];
    while(!P[idx].empty())P[idx].pop();
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int ct=q.front().cnt;
        vis[cx][cy]=1;
        q.pop();        
        if(ct!=0){
            for(int i=0;i<4;i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                int nt=ct-1;
                
                if(nx<0||ny<0||nx>=n||ny>=m)continue;
                
                if(!vis[nx][ny]&&board[nx][ny]=='.'){
                    vis[nx][ny]=1;
                    ans[idx]++;
                    board[nx][ny]=idx+'0';
                    pos val;
                    val.x=nx;val.y=ny;val.cnt=Cnt[idx];
                    P[idx].push(val);
                    val.cnt=nt;
                    q.push(val);
                }
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
    for(int i=1;i<=p;i++)cin>>Cnt[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char word;
            cin>>word;
            board[i][j]=word;
            if(word!='.'&&word!='#'){
                pos val;val.x=i;val.y=j;val.cnt=Cnt[word-'0'];
                P[word-'0'].push(val);
                ans[word-'0']++;
            }
        }
    }
    while(1){
        bool val=1;
        for(int i=1;i<=p;i++){
            if(!P[i].empty()){
                func(i);
                val=0;
            }
        }
        if(val)break;
    }
    for(int i=1;i<=p;i++)cout<<ans[i]<<" ";
}
