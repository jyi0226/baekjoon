#include <bits/stdc++.h>
using namespace std;

queue<int> que;

int line[1010][1010];
bool visitd[1010];
bool visitb[1010];
int n,m,cnt=0;

void DFS(int v)
{
    visitd[v]=true;
    //cout<<v<<" ";
    for(int i=1;i<=n;i++)
    {
        if(line[v][i]==1&&visitd[i]==0)
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    que.push(v);
    visitb[v]=true;

    while(!que.empty())
    {
        v=que.front();
        que.pop();
        cnt++;
        for(int i=1;i<=n;i++)
        {
            if(line[v][i]==1&&visitb[i]==0)
            {
                que.push(i);
                visitb[i]=true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        line[u][v]=1;
        line[v][u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(visitd[i]!=1)
        {
            DFS(i);
            cnt++;
        }
    }
    cout<<cnt;
}
