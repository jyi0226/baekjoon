#include <iostream>
#include <string>
#include <queue>
using namespace std;

string str1,str2;
int n,sx,sy,ex,ey,res=0;
char board[22][22];
bool vis[101][101][22][22];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int dir(char c){
    if(c=='U')return 0;
    else if(c=='D')return 2;
    else if(c=='L')return 3;
    else return 1;
}


bool func(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{sx,sy}});
    vis[0][0][sx][sy]=1;
    
    while(!q.empty()){
        int cid1=q.front().first.first;
        int cid2=q.front().first.second;
        int cx=q.front().second.first;
        int cy=q.front().second.second;
        
        if(cx==ex&&cy==ey){
            res=cid1+cid2;
            return 1;
        }
        
        q.pop();
        
        int nid1=cid1+1;
        if(nid1!=str1.size()){
            int nx=cx+dx[dir(str1[nid1])];
            int ny=cy+dy[dir(str1[nid1])];
            
            if(nx<0||ny<0||nx>=n||ny>=n){
                if(!vis[nid1][cid2][cx][cy]){
                    vis[nid1][cid2][cx][cy]=1;
                    q.push({{nid1,cid2},{cx,cy}});
                }
            }
            else{
                if(board[nx][ny]!='#'&&!vis[nid1][cid2][nx][ny]){
                    vis[nid1][cid2][nx][ny]=1;
                    q.push({{nid1,cid2},{nx,ny}});
                }
                else if(board[nx][ny]=='#'&&!vis[nid1][cid2][cx][cy]){
                    q.push({{nid1,cid2},{cx,cy}});
                    vis[nid1][cid2][cx][cy]=1;
                }
            }
        }
        int nid2=cid2+1;
        if(nid2!=str2.size()){
            int nx=cx+dx[dir(str2[nid2])];
            int ny=cy+dy[dir(str2[nid2])];
            
            if(nx<0||ny<0||nx>=n||ny>=n){
                if(!vis[cid1][nid2][cx][cy]){
                    vis[cid1][nid2][cx][cy]=1;
                    q.push({{cid1,nid2},{cx,cy}});
                }
            }
            else{
                if(board[nx][ny]!='#'&&!vis[cid1][nid2][nx][ny]){
                    vis[cid1][nid2][nx][ny]=1;
                    q.push({{cid1,nid2},{nx,ny}});
                }
                else if(board[nx][ny]=='#'&&!vis[cid1][nid2][cx][cy]){
                    q.push({{cid1,nid2},{cx,cy}});
                    vis[cid1][nid2][cx][cy]=1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(board[i][j]=='E'){
                ex=i;
                ey=j;
            }
        }
    }
    cin>>str1>>str2;
    str1="0"+str1;
    str2="0"+str2;
    if(func())cout<<res;
    else cout<<-1;
}
