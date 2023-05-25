#include <bits/stdc++.h>
using namespace std;

int com[111]={0,1,0,};

typedef struct Connect{
int start;
int end;
}Connect;

bool comp(Connect a,Connect b)
{
    if(a.start==b.start)return a.end<b.end;
    return a.start<b.start;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,com_num;
    cin>>com_num>>n;
    Connect ct[10101];
    for(int i=0;i<n*2;i+=2)
    {
        cin>>ct[i].start>>ct[i].end;
        ct[i+1].start=ct[i].end;
        ct[i+1].end=ct[i].start;
    }
    sort(ct,ct+n*2,comp);
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<n*2;i++)
        {
            if(com[ct[i].end]!=1&&com[ct[i].start]==1)com[ct[i].end]=1;
            if(com[ct[i].start]!=1&&com[ct[i].end]==1)com[ct[i].start]=1;
        }
    }
    
    int cnt=0;
    for(int i=2;i<=com_num;i++)
    {
        if(com[i]==1)cnt++;
    }
    cout<<cnt;
}
