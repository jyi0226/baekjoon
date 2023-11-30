#include <iostream>

using namespace std;
char boardset[11][11];
int board[11][11]={};
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
bool visit[11][11]={};

int move(){
    int val=0;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(board[i][j]==2&&visit[i][j]){
                for(int k=0;k<8;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<=0||ny<=0||nx>8||ny>8)continue;
                    if(nx==1&&ny==8)return 2;
                    if(board[nx][ny]==0){
                        board[nx][ny]=2;
                        //visit[nx][ny]=1;
                        val=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(board[i][j]==2&&!visit[i][j])visit[i][j]=1;
        }
    }
    return val;
}
void move_wall(){
    for(int i=1;i<=8;i++){
        if(board[8][i]==1)board[8][i]=0;
    }
    for(int i=8;i>0;i--){
        for(int j=1;j<=8;j++){
            if(board[i-1][j]==1){
                if(board[i][j]==2)visit[i][j]=0;
                board[i][j]=1;
                board[i-1][j]=0;
            }
        }
    }
    
}
void pri(){
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++)cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}
int main()
{
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>boardset[i][j];
            if(boardset[i][j]=='#')board[i][j]=1;
            else board[i][j]=0;
        }
    }
    visit[8][1]=1;
    board[8][1]=2;
    int val=1;
    while(1){
        val=move();
        move_wall();
        
        if(val==0){
            cout<<0;
            return 0;
        }
        else if(val==2){
            cout<<1;
            return 0;
        }
    }
}
