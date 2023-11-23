#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
int board[303][303];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool ice[303][303];

void melt(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<4;k++){
                if(i+dx[k]<0||j+dy[k]<0||i+dx[k]>=n||j+dy[k]>=m)continue;
                if(!ice[i+dx[k]][j+dy[k]])cnt++;
            }
            if(board[i][j]>cnt)board[i][j]-=cnt;
            else board[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0)ice[i][j]=0;
        }
    }
}

int mass(){
    bool visit[303][303]={};
    int val=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j]&&ice[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                visit[i][j]=1;
                //cout<<i<<" "<<j<<"\n";
                while(!q.empty()){
                    int cx=q.front().first,cy=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=cx+dx[k],ny=cy+dy[k];
                        if(nx<0||ny<0||nx>=n||ny>=m)continue;
                        if(ice[nx][ny]&&!visit[nx][ny]){
                            visit[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                val++;
            }
        }
    }

    return val;
}

void pri(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<board[i][j];
        cout<<"\n";
    }
    cout<<"\n";
}
void pri_ice(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<ice[i][j];
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]!=0)ice[i][j]=1;
        }
    }

    int tim=0;
    while(1){
        melt();
        tim++;
        int num=mass();
        if(num==0){
            cout<<0;
            break;
        }
        else if(num>=2){
            cout<<tim;
            break;
        }
    }
}
