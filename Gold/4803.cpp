#include <iostream>

using namespace std;
int n,m,a,b;
int idx=1;
int root[505];
bool cycle[505]={};

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
    while(1){
        cin>>n>>m;
        if(n==0&&m==0)break;
        
        for(int i=1;i<=n;i++){
            root[i]=i;
            cycle[i]=1;
        }
        
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(find_root(a)==find_root(b)){
                cycle[find_root(a)]=0;
            }
            else{
                if(!cycle[a]||!cycle[b]){
                cycle[find_root(a)]=0;
                cycle[find_root(b)]=0;
                }
                union_root(a,b);
            }
            
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cycle[find_root(root[i])]){
                cnt++;
                cycle[find_root(root[i])]=0;
            }
        }
        cout<<"Case "<<idx<<": ";
        if(cnt==0){
            cout<<"No trees.";
        }
        else if(cnt==1){
            cout<<"There is one tree.";
        }
        else{
            cout<<"A forest of "<<cnt<<" trees.";
        }
        cout<<"\n";
        idx++;
    }
    
    
}
