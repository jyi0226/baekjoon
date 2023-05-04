#include <bits/stdc++.h>
using namespace std;

queue<int> que;

int line[1010][1010];
bool visitd[1010];
bool visitb[1010];
int n,m,v;

void DFS(int v)
{
    visitd[v]=true;
    cout<<v<<" ";
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
    cout<<v<<" ";

    while(!que.empty())
    {
        v=que.front();
        que.pop();

        for(int i=1;i<=n;i++)
        {
            if(line[v][i]==1&&visitb[i]==0)
            {
                que.push(i);
                visitb[i]=true;
                cout<<i<<" ";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m>>v;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        line[a][b]=1;
        line[b][a]=1;
    }

    DFS(v);
    cout<<"\n";
    BFS(v);
}