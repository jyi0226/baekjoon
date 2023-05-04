#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,f[303],d[303],game[303];
    cin>>n;
    for(int i=0;i<n;i++)cin>>f[i];
    for(int i=0;i<n;i++)cin>>d[i];
    
    if(f[0]==1)
    {
        if(d[0]==2)
        {
            game[0]=0;
        }
        else
        {
            game[0]=1;
        }
    }
    else if(f[0]==2)
    {
        if(d[0]==3)
        {
            game[0]=0;
        }
        else
        {
            game[0]=1;
        }
    }
    else
    {
        if(d[0]==1)
        {
            game[0]=0;
        }
        else
        {
            game[0]=1;
        }
    }

    for(int i=1;i<n;i++)
    {
        if(f[i]==d[i])
        {
            if(game[i-1]==0)game[i]=1;
            else game[i]=0;
        }
        else
        {
            if(f[i]==1)
            {
                if(d[i]==2)
                {
                    game[i]=0;
                }
                else
                {
                    game[i]=1;
                }
            }
            else if(f[i]==2)
            {
                if(d[i]==3)
                {
                    game[i]=0;
                }
                else
                {
                    game[i]=1;
                }
            }
            else
            {
                if(d[i]==1)
                {
                    game[i]=0;
                }
                else
                {
                    game[i]=1;
                }
            }
        }
    }

    int win[303];
    int cnt=1;
    for(int i=0;i<n-1;i++)
    {
        if(game[i]==game[i+1])
        {
            cnt++;
            win[i]=0;
        }
        else
        {
            win[i]=cnt;
            cnt=1;
        }
    }
    win[n-1]=cnt;
    sort(win,win+n,comp);
    cout<<win[0];
}