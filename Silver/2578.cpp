#include <bits/stdc++.h>
using namespace std;

int board[10][10];

int bingo(int board[][10])
{
    
    int cnt=0;
    for(int i=0;i<5;i++)
    {
        if(board[i][0]==0&&board[i][1]==0&&board[i][2]==0&&board[i][3]==0&&board[i][4]==0)cnt++;
        if(board[0][i]==0&&board[1][i]==0&&board[2][i]==0&&board[3][i]==0&&board[4][i]==0)cnt++;
    }
    if(board[0][0]==0&&board[1][1]==0&&board[2][2]==0&&board[3][3]==0&&board[4][4]==0)cnt++;
    if(board[4][0]==0&&board[3][1]==0&&board[2][2]==0&&board[1][3]==0&&board[0][4]==0)cnt++;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>board[i][j];
        }
    }
    for(int i=0;i<25;i++)
    {
        int num;
        cin>>num;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(board[j][k]==num)
                {
                    board[j][k]=0;
                    break;
                }
            }
        }
        if(bingo(board)>=3)
        {
            cout<<i+1;
            break;
        }
    }
}
