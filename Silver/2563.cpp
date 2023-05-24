#include <bits/stdc++.h>
using namespace std;

int board[111][111];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    for(int i=1;i<101;i++)
    {
        for(int j=1;j<101;j++)board[i][j]=0;
    }
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        for(int i=x;i<x+10;i++)
        {
            for(int j=y;j<y+10;j++)
            {
                board[i][j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<101;i++)
    {
        for(int j=1;j<101;j++)
        {
            if(board[i][j]==1)cnt++;
        }
    }
    cout<<cnt;
}
