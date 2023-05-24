#include <bits/stdc++.h>
using namespace std;

int board[111][111],board2[111][111];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            board2[i][j]=board[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0||i==n-1)board[i][j]=-1;
            if(j==0||j==m-1)board[i][j]=-1;
        }
    }
    for(int k=0;k<100;k++)
    {
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(board[i][j]==0&&(board[i-1][j]==-1||board[i+1][j]==-1||board[i][j-1]==-1||board[i][j+1]==-1))
                {
                    board[i][j]=-1;
                }
            }
        } 
    }
    
    
    int Max=0;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(board[i][j]==1&&((board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j-1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i+1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1)||(board[i-1][j]==-1&&board[i][j-1]==-1)||(board[i-1][j]==-1&&board[i][j+1]==-1)||(board[i+1][j]==-1&&board[i][j-1]==-1)||(board[i+1][j]==-1&&board[i][j+1]==-1)||(board[i][j-1]==-1&&board[i][j+1]==-1)))
            {
                board[i][j]=-2;
            }
        }
    }
    Max++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]<0)board2[i][j]=-1;
            else board2[i][j]=board[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            board[i][j]=board2[i][j];
        }
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }*/
 

    for(int k=2;k<=100;k++)
    {
        int status=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1)
                {
                    status=1;
                    break;
                }
            }
            if(status==1)break;
        }
        if(status==0)break;
        else
        {
            Max=k;
            for(int l=0;l<50;l++)
            {
                for(int i=1;i<n-1;i++)
                {
                    for(int j=1;j<m-1;j++)
                    {
                        if(board[i][j]==0&&(board[i-1][j]==-1||board[i+1][j]==-1||board[i][j-1]==-1||board[i][j+1]==-1))
                        {
                            board[i][j]=-1;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    board2[i][j]=board[i][j];
                }
            }
            for(int i=1;i<n-1;i++)
            {
                for(int j=1;j<m-1;j++)
                {
                    if(board[i][j]==1&&((board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j-1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i+1][j]==-1&&board[i][j-1]==-1&&board[i][j+1]==-1)||(board[i-1][j]==-1&&board[i+1][j]==-1)||(board[i-1][j]==-1&&board[i][j-1]==-1)||(board[i-1][j]==-1&&board[i][j+1]==-1)||(board[i+1][j]==-1&&board[i][j-1]==-1)||(board[i+1][j]==-1&&board[i][j+1]==-1)||(board[i][j-1]==-1&&board[i][j+1]==-1)))
                    {
                        board[i][j]=-(k+1);
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]<0)board2[i][j]=-1;
                    else board2[i][j]=board[i][j];
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    board[i][j]=board2[i][j];
                }
            }
        }
    }
    
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<Max;
}
