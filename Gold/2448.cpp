#include <iostream>
using namespace std;
char board[3535][6666];
int n;

void func(int cnt,int x,int y){
    //cout<<cnt<<" "<<x<<" "<<y<<"\n";
    if(cnt==3){
        board[x][y]='*';
        board[x+1][y+1]='*';
        board[x+1][y-1]='*';
        for(int i=y-2;i<=y+2;i++)board[x+2][i]='*';
        return;
    }
    func(cnt/2,x,y);
    func(cnt/2,x+cnt/2,y-cnt/2);
    func(cnt/2,x+cnt/2,y+cnt/2);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    func(n,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(board[i][j]=='*')cout<<board[i][j];
            else cout<<" ";
        }
        cout<<"\n";
    }
}
