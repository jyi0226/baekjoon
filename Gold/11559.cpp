#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int py=0;
char board[12][6];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool value;
bool puyo(int x,int y,char c){
    queue<pair<int,int>> q;
    bool visit[12][6]={};
    visit[x][y]=1;
    q.push({x,y});
    int cnt=1;
    while(!q.empty()){
        int cx=q.front().first,cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i],ny=cy+dy[i];
            if(nx<0||ny<0||nx>=12||ny>=6)continue;
            if(board[nx][ny]==c&&!visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny]=1;
                cnt++;
            }
        }
    }
    if(cnt>=4){
        bool visit[12][6]={};
        visit[x][y]=1;
        board[x][y]='.';
        q.push({x,y});
        while(!q.empty()){
            int cx=q.front().first,cy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=cx+dx[i],ny=cy+dy[i];
                if(nx<0||ny<0||nx>=12||ny>=6)continue;
                if(board[nx][ny]==c&&!visit[nx][ny]){
                    q.push({nx,ny});
                    visit[nx][ny]=1;
                    board[nx][ny]='.';
                }
            }
        }
        return 1;
    }
    return 0;
}
void down(){
    for(int j=0;j<6;j++){
        int val=1;
        for(int i=11;i>=0;i--){
            if(board[i][j]=='.'){
                if(i-val<0)continue;
                while(i-val>0&&board[i-val][j]=='.')val++;
                board[i][j]=board[i-val][j];
                board[i-val][j]='.';
            }
        }
    }
}
int main()
{
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++)cin>>board[i][j];
    }

    while(1){
        value=0;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(board[i][j]!='.'){
                    if(puyo(i,j,board[i][j]))value=1;
                }
            }
        }
        if(value){
            py++;
            down();
        }
        else break;
    }
        

    /*for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }*/
    cout<<py;
}
