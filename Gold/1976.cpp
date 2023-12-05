#include <iostream>
using namespace std;

int n,m;
int a,b,city,root;
bool ord;
int parent[202]={};
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
    if(x>y){
        parent[x]=y;
    }
    else {
        parent[y]=x;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ord;
            if(ord)union_root(i,j);
        }
        
    }
    cin>>city;
    root=find_root(city);
    for(int i=1;i<m;i++){
        cin>>city;
        if(root!=find_root(city)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
