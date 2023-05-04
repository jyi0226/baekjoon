#include <bits/stdc++.h>
using namespace std;

#define north 1
#define east 2
#define south 3
#define west 4

int board[111][111];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            if(i==0||i==n+1)board[i][j]=1;
            else
            {
                if(j==0||j==n+1)board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
    /*for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)cout<<board[i][j];
        cout<<"\n";
    }*/
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        board[x][y]=2;
    }

    int l;
    cin>>l;
    int time[111]={0,};
    char direc[111];
    for(int i=0;i<l;i++)cin>>time[i]>>direc[i];

    deque<int> x,y;
    x.push_back(1);
    y.push_back(1);
    board[x.front()][y.front()]=1;

   

    int dir=east;
    int cnt=0,cnt_t=0;
    while(1)
    {        
            
        if(dir==north)
        {
            if(board[x.front()-1][y.front()]==0)
            {
                x.push_front(x.front()-1);
                y.push_front(y.front());
                board[x.front()][y.front()]=1;
                board[x.back()][y.back()]=0;
                x.pop_back();
                y.pop_back();
                cnt++;       
            }
            else if(board[x.front()-1][y.front()]==2)
            {
                x.push_front(x.front()-1);
                y.push_front(y.front());
                board[x.front()][y.front()]=1;
                cnt++;                    
            }
            else break;
        }
            
        else if(dir==east)
        {
            if(board[x.front()][y.front()+1]==0)
            {
                x.push_front(x.front());
                y.push_front(y.front()+1);
                board[x.front()][y.front()]=1;
                board[x.back()][y.back()]=0;
                x.pop_back();
                y.pop_back();
                cnt++;                    
            }
            else if(board[x.front()][y.front()+1]==2)
            {
                x.push_front(x.front());
                y.push_front(y.front()+1);
                board[x.front()][y.front()]=1;
                cnt++;            
            }
            else break;
        }

        else if(dir==south)
        {
            if(board[x.front()+1][y.front()]==0)
            {
                x.push_front(x.front()+1);
                y.push_front(y.front());
                board[x.front()][y.front()]=1;
                board[x.back()][y.back()]=0;
                x.pop_back();
                y.pop_back();
                cnt++;        
            }
            else if(board[x.front()+1][y.front()]==2)
            {
                x.push_front(x.front()+1);
                y.push_front(y.front());
                board[x.front()][y.front()]=1;
                cnt++;    
            }
            else break;
        }

        else
        {
            if(board[x.front()][y.front()-1]==0)
            {
                x.push_front(x.front());
                y.push_front(y.front()-1);
                board[x.front()][y.front()]=1;
                board[x.back()][y.back()]=0;
                x.pop_back();
                y.pop_back();
                cnt++;                  
            }
            else if(board[x.front()][y.front()-1]==2)
            {
                x.push_front(x.front());
                y.push_front(y.front()-1);
                board[x.front()][y.front()]=1;
                cnt++;    
            }
            else break;
        }

        if(cnt==time[cnt_t])
        {
            if(direc[cnt_t]=='D')
            {
                if(dir==west)dir=north;
                else dir++;
            }
            else
            {
                if(dir==north)dir=west;
                else dir--;
            }
            cnt_t++;
        }
    }
    
    cout<<cnt+1;
    
}