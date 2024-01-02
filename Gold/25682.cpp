#include <iostream>

using namespace std;
int n,m,k;
char board[2020][2020];
int change[2020][2020];
int check[2020][2020];
int cnt=999999999;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2==0){
                if(board[i][j]!='B')check[i][j]=1;
                else check[i][j]=0;
            }
            else{
                if(board[i][j]!='W')check[i][j]=1;
                else check[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            change[i][j]=change[i-1][j]+change[i][j-1]-change[i-1][j-1]+check[i][j];
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<change[i][j]<<" ";
        cout<<"\n";
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>=k&&j>=k){
                int val=change[i][j]-change[i][j-k]-change[i-k][j]+change[i-k][j-k];
                //cout<<val;
                cnt=min(cnt,min(val,k*k-val));
            }
        }
    }
    cout<<cnt;
}
