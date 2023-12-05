#include <iostream>
using namespace std;

int n,m,k;
int a,b;
int parent[10101][2]={};
//int node_rank[1010101]={};
int find_root(int x){
    if(x==parent[x][0])return x;
    return parent[x][0]=find_root(parent[x][0]);
}
void union_root(int x,int y){
    x=find_root(x);
    y=find_root(y);
    
    /*if(x!=y){
        if(node_rank[x]<node_rank[y])parent[x]=y;
        else parent[y]=x;
    }
    
    if(node_rank[x]==node_rank[y]){
        parent[x]=y;
        node_rank[x]++;
    }*/
    if(x>y){
        parent[x][0]=y;
        parent[y][1]=min(parent[y][1],parent[x][1]);
    }
    else {
        parent[y][0]=x;
        parent[x][1]=min(parent[y][1],parent[x][1]);
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        parent[i][0]=i;
        cin>>parent[i][1];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        union_root(a,b);
    }
    int sum=0;
    bool vis[10101]={};
    for(int i=1;i<=n;i++){
        int val=find_root(i);
        if(!vis[val]){
            sum+=parent[val][1];
            vis[val]=1;
        }
    }
    if(sum<=k)cout<<sum;
    else cout<<"Oh no";
}
