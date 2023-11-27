#include <iostream>
#include <queue>
using namespace std;
char board[55][55];
int sta[55][55]={};
bool visit_w[55][55]={};
bool visit_s[55][55]={};
queue<pair<int,int>> w,s;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int r,c;

int main()
{

    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]=='*'){
                visit_w[i][j]=1;
                w.push({i,j});
                sta[i][j]=-1;
            }
            else if(board[i][j]=='S'){
                visit_s[i][j]=1;
                s.push({i,j});
                sta[i][j]=1;
            }
            else if(board[i][j]=='D'){
                sta[i][j]=2;
            }
            else if(board[i][j]=='X')sta[i][j]=3;
        }
    }
    int cnt=0;
    while(1){
        int size_w=w.size();
        int size_s=s.size();
        
        if(size_s==0)break;
        
        for(int i=0;i<size_w;i++){
            int x=w.front().first;
            int y=w.front().second;
            w.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(nx<0||ny<0||nx>=r||ny>=c||visit_w[nx][ny]==1)continue;
                if(sta[nx][ny]==0||sta[nx][ny]==1){
                    sta[nx][ny]=-1;
                    visit_w[nx][ny]=1;
                    w.push({nx,ny});
                }
            }
        }
        for(int i=0;i<size_s;i++){
            int x=s.front().first;
            int y=s.front().second;
            s.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(nx<0||ny<0||nx>=r||ny>=c||visit_s[nx][ny]==1)continue;
                if(sta[nx][ny]==0||sta[nx][ny]==1){
                    sta[nx][ny]=1;
                    visit_s[nx][ny]=1;
                    s.push({nx,ny});
                }
                else if(sta[nx][ny]==2){
                    cout<<cnt+1;
                    return 0;
                }
            }
        }
        cnt++;
    }
    cout<<"KAKTUS";
}
