#include <iostream>
#include <queue>
using namespace std;
int n,m,num=1;
bool mv[1010][1010]={};
char board[1010][1010];
int space[1010][1010];
int zero_num[10101010];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void bfs(){
    queue<pair<int,int>> q;
    bool visit[1010][1010]={};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='0'&&!visit[i][j]){
                q.push({i,j});
                int cnt=1;
                visit[i][j]=1;
                space[i][j]=num;
                while(!q.empty()){
                    int cx=q.front().first;
                    int cy=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=cx+dx[k];
                        int ny=cy+dy[k];
                        
                        if(nx<0||ny<0||nx>=n||ny>=m)continue;
                        if(!visit[nx][ny]&&board[nx][ny]=='0'){
                            q.push({nx,ny});
                            space[nx][ny]=num;
                            visit[nx][ny]=1;
                            cnt++;
                        }
                    }
                }
                zero_num[num]=cnt;
                num++;
            }
        }
    }
}
void check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<board[i][j];
        cout<<"\n";
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<space[i][j];
        cout<<"\n";
    }
    for(int i=1;i<num;i++)cout<<zero_num[i]<<" ";*/
}
void func(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='1'){
                int cnt=1;
                bool visit[num]={};
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                        
                    if(nx<0||ny<0||nx>=n||ny>=m)continue;
                    if(space[nx][ny]!=0&&!visit[space[nx][ny]]){
                        cnt+=zero_num[space[nx][ny]];
                        visit[space[nx][ny]]=1;
                    }
                }
                cnt%=10;
                board[i][j]=cnt+'0';
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    bfs();
    func();
    
    check();
}
