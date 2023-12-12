#include <iostream>
#include <queue>
#include <queue>
using namespace std;

int tc,n,m,cnt;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool val;
char board[101][101];
bool visited[101][101];
bool key[26]={};
string str;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            if(board[nx][ny]=='*')continue;
            if(!visited[nx][ny]){
                if(board[nx][ny]=='.'){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
                else if(board[nx][ny]=='$'){
                    visited[nx][ny]=1;
                    board[nx][ny]='.';
                    q.push({nx,ny});
                    cnt++;
                }
                else{
                    int num=board[nx][ny]-'A';
                    if(num>=0&&num<26){
                        if(key[num]){
                            visited[nx][ny]=1;
                            board[nx][ny]='.';
                            q.push({nx,ny});
                        }
                    }
                    else{
                        key[board[nx][ny]-'a']=1;
                        visited[nx][ny]=1;
                        board[nx][ny]='.';
                        q.push({nx,ny});
                        val=1;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    cin>>tc;
    while(tc!=0){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>board[i][j];
                visited[i][j]=0;
            }
        }
        for(int i=0;i<26;i++)key[i]=0;

        cin>>str;
        for(int i=0;i<str.size();i++)key[str[i]-'a']=1;
        
        val=1;
        cnt=0;
        
        while(val){
            val=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)visited[i][j]=0;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0||j==0||i==n-1||j==m-1){
                        if(!visited[i][j]){
                            if(board[i][j]=='.')bfs(i,j);
                            else if(board[i][j]=='$'){
                                board[i][j]='.';
                                cnt++;
                                i=-1;
                                j=m;
                                continue;
                            }
                            else{
                                int num=board[i][j]-'a';
                                if(num>=0&&num<26){
                                    key[board[i][j]-'a']=1;
                                    board[i][j]='.';
                                    //cout<<key[0]<<"\n";
                                    bfs(i,j);
                                    i=-1;
                                    j=m;
                                    continue;
                                }
                                else{
                                    if(key[board[i][j]-'A']){
                                        board[i][j]='.';
                                        bfs(i,j);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
        tc--;
    }
}
