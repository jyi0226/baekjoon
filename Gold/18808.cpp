#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int r,c;
int board[44][44]={};
int paper[11][11];

void rotate(){
    int tmp[12][12];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)tmp[i][j]=paper[i][j];
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++)paper[i][j]=tmp[r-j-1][i];
    }
    int cur=r;
    r=c;
    c=cur;
}

bool able(int x,int y){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[x+i][y+j]==1&&paper[i][j]==1)return 0;
        }
    }
    return 1;
}

void paste(int x,int y){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[x+i][y+j]==0)board[x+i][y+j]=paper[i][j];
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    while(k--){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)cin>>paper[i][j];
        }
        
        for(int dir=0;dir<4;dir++){
            bool val=0;
            for(int i=0;i<=n-r;i++){
                if(val)break;
                for(int j=0;j<=m-c;j++){
                    if(able(i,j)){
                        paste(i,j);
                        for(int i=0)
                        val=true;
                        break;
                        
                    }
                }
            }
            rotate();
        }
        
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<" ";
            cnt+=board[i][j];
        }
        cout<<"\n";
    }
    cout<<cnt;
}
