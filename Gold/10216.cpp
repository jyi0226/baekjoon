#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int t,n;
long double x,y,r;
vector<pair<long double,pair<long double,long double>>> v;
int parent[3030]={};
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
bool func(pair<long double,pair<long double,long double>> a,pair<long double,pair<long double,long double>> b){
    long double x1=a.second.first,x2=b.second.first,y1=a.second.second,y2=b.second.second,r1=a.first,r2=b.first;
    long double len=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(r1+r2<len)return 0;
    else return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        v.clear();
        v.push_back({0,{0,0}});
        bool area[3030]={};
        cin>>n;
        for(int i=1;i<=n;i++){
            parent[i]=i;
            cin>>x>>y>>r;
            v.push_back({r,{x,y}});
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(func(v[i],v[j])){
                    union_root(find_root(i),find_root(j));
                }
            }
        }
        for(int i=1;i<=n;i++){
            //cout<<find_root(i)<<" ";
            area[find_root(i)]=1;
        }
        //cout<<"\n";
        int cnt=0;
        for(int i=1;i<=n;i++){
            //cout<<area[i]<<" ";
            if(area[i])cnt++;
        }
        //cout<<"\n";
        cout<<cnt<<"\n";
    }
}
