#include <iostream>
#include <queue>
using namespace std;

int board[20][20];
int dice[7]={0,};
int n,m,x,y,k,ord,val;
int nx,ny;
int main()
{
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin>>ord;
        if(ord==1){
            nx=x;
            ny=y+1;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            val=dice[1];
            dice[1]=dice[4];
            dice[4]=dice[6];
            dice[6]=dice[3];
            dice[3]=val;
            if(board[nx][ny]==0){
                board[nx][ny]=dice[6];
                }
            else{
                dice[6]=board[nx][ny];
                board[nx][ny]=0;
            }
            x=nx;
            y=ny;
            cout<<dice[1]<<"\n";
        }
        else if(ord==2){
            nx=x;
            ny=y-1;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            val=dice[1];
            dice[1]=dice[3];
            dice[3]=dice[6];
            dice[6]=dice[4];
            dice[4]=val;
            if(board[nx][ny]==0){
                board[nx][ny]=dice[6];
            }
            else{
                dice[6]=board[nx][ny];
                board[nx][ny]=0;
            }
            x=nx;
            y=ny;
            cout<<dice[1]<<"\n";
        }
        else if(ord==3){
            nx=x-1;
            ny=y;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            val=dice[1];
            dice[1]=dice[5];
            dice[5]=dice[6];
            dice[6]=dice[2];
            dice[2]=val;
            if(board[nx][ny]==0){
                board[nx][ny]=dice[6];
                }
            else{
                dice[6]=board[nx][ny];
                board[nx][ny]=0;
            }
            x=nx;
            y=ny;
            cout<<dice[1]<<"\n";
        }
        else{
            nx=x+1;
            ny=y;
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            
            val=dice[1];
            dice[1]=dice[2];
            dice[2]=dice[6];
            dice[6]=dice[5];
            dice[5]=val;
            if(board[nx][ny]==0){
                board[nx][ny]=dice[6];
                }
            else{
                dice[6]=board[nx][ny];
                board[nx][ny]=0;
            }
            x=nx;
            y=ny;
            cout<<dice[1]<<"\n";
        }
    }
}
