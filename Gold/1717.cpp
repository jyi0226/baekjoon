#include <iostream>
using namespace std;

int n,m;
int ord,a,b;
int parent[1010101]={};
//int node_rank[1010101]={};
int find_root(int x){
    if(x==parent[x])return x;
    return parent[x]=find_root(parent[x]);
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
    if(x>y)parent[x]=y;
    else parent[y]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=0;i<m;i++){
        cin>>ord>>a>>b;
        if(ord==0)union_root(a,b);
        else{
            if(find_root(a)==find_root(b))cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
}
