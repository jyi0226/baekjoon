#include <bits/stdc++.h>
using namespace std;

int board[55][55];

int func(int board[][55],int r,int c,int d)
{
    
    if(d==0)
    {
        if(board[r-1][c]!=0&&board[r][c-1]!=0&&board[r][c+1]!=0&&board[r+1][c]!=0)
        {
            if(board[r+1][c]==1)return 4;
            else return 3;
        }
        else
        {
            if(board[r][c-1]!=0)return 2;
            else return 1;
        }
    }
    else if(d==1)
    {
        if(board[r-1][c]!=0&&board[r][c-1]!=0&&board[r][c+1]!=0&&board[r+1][c]!=0)
        {
            if(board[r][c-1]==1)return 4;
            else return 3;
        }
        else
        {
            if(board[r-1][c]!=0)return 2;
            else return 1;
        }
    }
    else if(d==2)
    {
        if(board[r-1][c]!=0&&board[r][c-1]!=0&&board[r][c+1]!=0&&board[r+1][c]!=0)
        {
            if(board[r-1][c]==1)return 4;
            else return 3;
        }
        else
        {
            if(board[r][c+1]!=0)return 2;
            else return 1;
        }
    }
    else
    {
        if(board[r-1][c]!=0&&board[r][c-1]!=0&&board[r][c+1]!=0&&board[r+1][c]!=0)
        {
            if(board[r][c+1]==1)return 4;
            else return 3;
        }
        else
        {
            if(board[r+1][c]!=0)return 2;
            else return 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,m,r,c,d;
    cin>>n>>m>>r>>c>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>board[i][j];
    }
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(i==0||i==n+1)board[i][j]=1;
            else
            {
                if(j==0||j==m+1)board[i][j]=1;
            }
        }
    }
    int status=0;
    r++;
    c++;
    board[r][c]=2;
    while(status!=4)
    {
        status=func(board,r,c,d);
        if(status==1)
        {
            if(d==0)
            {
                d=3;
                c-=1;
            }
            else if(d==1)
            {
                d=0;
                r-=1;
            }
            else if(d==2)
            {
                d=1;
                c+=1;
            }
            else
            {
                d=2;
                r+=1;
            }
            board[r][c]=2;
        }
        else if(status==2)
        {
            if(d==0)d=3;
            else d-=1;
        }
        else if(status==3)
        {
            if(d==0)
            {
                r+=1;
            }
            else if(d==1)
            {
                c-=1;
            }
            else if(d==2)
            {
                r-=1;
            }
            else
            {
                c+=1;
            }
        }
        else
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    //cout<<board[i][j];
                    if(board[i][j]==2)cnt++;
                }
                //cout<<"\n";
            }
            //cout<<r<<" "<<c<<" "<<d<<" ";
            cout<<cnt;
            return 0;
        }
    }
}