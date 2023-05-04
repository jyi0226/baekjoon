#include <bits/stdc++.h>
using namespace std;

char board[20][10];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<6;j++)cin>>board[i][j];
    }
    int status=0;
    int cnt=0;
    while(status==0)
    {
        stack<int,int> stk;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(board[i][j]!='.')
                {
                    
                }
            }
        }
    }
}
