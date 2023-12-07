#include <iostream>

using namespace std;
int n,m;
int root[505050];

int find_root(int x){
    if(x==root[x])return x;
    return root[x]=find_root(root[x]);
}

void union_root(int x,int y){
    x=find_root(x);
    y=find_root(y);
    
    if(x<y)root[y]=x;
    else root[x]=y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)root[i]=i;
    
    int a,b,res=0;
    bool val=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(find_root(a)==find_root(b)){
            res=i+1;
            val=1;
            break;
        }
        if(!val)union_root(a,b);
    }
    
    cout<<res;
}
