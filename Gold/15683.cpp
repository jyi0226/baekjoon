#include <iostream>
#include <vector>
using namespace std;

int n,m,cnt_cctv=0,res=80;
int board[8][8],board2[8][8];
vector<pair<int,int>> cctv;
int dir_x[4]={-1,0,1,0};
int dir_y[4]={0,1,0,-1};

void update_board(int dir,int x,int y){
    dir%=4;
    while(1){
        x+=dir_x[dir];
        y+=dir_y[dir];
        if(x<0||x>=n||y<0||y>=m||board2[x][y]==6)return;
        if(board2[x][y]==0)board2[x][y]=7;
    }
}

void print_board(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board2[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]>0&&board[i][j]<6){
                cnt_cctv++;
                cctv.push_back({i,j});
            }
        }
    }
    for(int tmp=0;tmp<(1<<(2*cnt_cctv));tmp++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)board2[i][j]=board[i][j];
        }
        int brute=tmp;
        
        for(int i=0;i<cnt_cctv;i++){
            int x=cctv[i].first;
            int y=cctv[i].second;
            int dir=brute%4;
            brute/=4;
            
            if(board[x][y]==1){
                update_board(dir,x,y);
            }
            else if(board[x][y]==2){
                update_board(dir,x,y);
                update_board(dir+2,x,y);
            }
            else if(board[x][y]==3){
                update_board(dir,x,y);
                update_board(dir+1,x,y);
            }
            else if(board[x][y]==4){
                update_board(dir,x,y);
                update_board(dir+1,x,y);
                update_board(dir+2,x,y);
            }
            else{
                update_board(dir,x,y);
                update_board(dir+1,x,y);
                update_board(dir+2,x,y);
                update_board(dir+3,x,y);
            }
        }
        int val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board2[i][j]==0)val++;
            }
        }
        if(res>val){
            res=val;
            //print_board();
            //cout<<"\n";
        }
    }
    cout<<res;
}
