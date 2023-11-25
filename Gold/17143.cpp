#include <iostream>
#include <queue>
using namespace std;
int n,m,shark_cnt;
int board[111][111]={0,};
int shark[10101][5];
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};
void shark_place(){
    for(int i=0;i<shark_cnt;i++){
        board[shark[i][0]][shark[i][1]]=shark[i][4];
    }
}

void shark_check(){
    for(int i=0;i<shark_cnt;i++){
        if(board[shark[i][0]][shark[i][1]]!=shark[i][4])shark[i][4]=0;
    }
}
void shark_move(){
    int newboard[111][111]={0,};
    for(int i=0;i<shark_cnt;i++){
        if(shark[i][4]>0){
            int x=shark[i][0];
            int y=shark[i][1];
            int dir=shark[i][3];
            int speed=shark[i][2];
            if(dir==1||dir==2){
                speed%=(n-1)*2;
                for(int j=0;j<speed;j++){
                   int nx=x+dx[dir];
                   
                   if(nx<1){
                       dir=2;
                       nx+=2;
                   }
                   if(nx>n){
                       dir=1;
                       nx-=2;
                   }
                   x=nx;
               } 
            }

            else{
                speed%=(m-1)*2;
                for(int j=0;j<speed;j++){
                   int ny=y+dy[dir];
                   
                   if(ny<1){
                       dir=3;
                       ny+=2;
                   }
                   if(ny>m){
                       dir=4;
                       ny-=2;
                   }
                   y=ny;
               } 
            }
            shark[i][0]=x;
            shark[i][1]=y;
            shark[i][3]=dir;
            if(newboard[x][y]>shark[i][4])shark[i][4]=0;
            else newboard[x][y]=shark[i][4];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)board[i][j]=newboard[i][j];
    }
}
void pri(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main()
{
    cin>>n>>m>>shark_cnt;
    for(int i=0;i<shark_cnt;i++){
        cin>>shark[i][0]>>shark[i][1]>>shark[i][2]>>shark[i][3]>>shark[i][4];
    }
    shark_place();
    //pri();
    int res=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(board[i][j]!=0){
                res+=board[i][j];
                board[i][j]=0;
                shark_check();
                break;
            }
        }
        shark_move();
        shark_check();
        //pri();
    }
    cout<<res;
    //pri
}
