#include <bits/stdc++.h>
using namespace std;

int board[555][555];

int one(int board[][555],int i,int j)
{
    int a=board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3];
    int b=board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j];
    return max({a,b});
}
int two(int board[][555],int i,int j)
{
    return board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j];
}
int three(int board[][555],int i,int j)
{
    int a=board[i][j]+board[i+1][j]+board[i+2][j]+board[i+2][j+1];
    int b=board[i][j]+board[i+1][j]+board[i+2][j]+board[i+2][j-1];
    int c=board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j];
    int d=board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+1][j+2];
    int e=board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+2][j+1];
    int f=board[i][j]+board[i+1][j]+board[i+2][j]+board[i][j+1];
    int g=board[i][j]+board[i][j+1]+board[i][j+2]+board[i-1][j+2];
    int h=board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+2];
    return max({a,b,c,d,e,f,g,h});
}
int four(int board[][555],int i,int j)
{
    int a=board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+2][j+1];
    int b=board[i][j]+board[i][j+1]+board[i+1][j]+board[i-1][j+1];
    int c=board[i][j]+board[i][j+1]+board[i-1][j+1]+board[i-1][j+2];
    int d=board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j+2];
    return max({a,b,c,d});
}
int five(int board[][555],int i,int j)
{
    int a=board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i][j+2];
    int b=board[i][j]+board[i][j+1]+board[i-1][j+1]+board[i][j+2];
    int c=board[i-1][j]+board[i][j]+board[i+1][j]+board[i][j+1];
    int d=board[i][j]+board[i-1][j+1]+board[i][j+1]+board[i+1][j+1];
    return max({a,b,c,d});
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=m+1;j++)cin>>board[i][j];
    }
    for(int i=0;i<=n+5;i++)
    {
        for(int j=0;j<=m+4;j++)
        {
            if(i<2||i>n+1)board[i][j]=0;
            else
            {
                if(j<2||j>m+1)board[i][j]=0;
            }
        }
    }
    /*for(int i=0;i<=n+3;i++)
    {
        for(int j=0;j<=m+4;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int Max=0;
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=m+1;j++)
        {
            Max=max({one(board,i,j),two(board,i,j),three(board,i,j),four(board,i,j),five(board,i,j),Max});
        }
    }
    cout<<Max;
}