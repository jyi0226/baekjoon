#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[101010];
int n,x,y,z;
int res=0,cnt=0;
vector<pair<int,pair<int,int>>> line;
vector<pair<int,int>> X,Y,Z;

int find_p(int x){
    if(x==p[x])return x;
    return p[x]=find_p(p[x]);
}

void union_p(int x,int y){
    x=find_p(x);
    y=find_p(y);
    
    if(x<y)p[y]=x;
    else p[x]=y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        p[i+1]=i+1;
        cin>>x>>y>>z;
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());
    
    for(int i=0;i<n-1;i++){
        int st1=X[i].second;
        int ed1=X[i+1].second;
        int cost1=abs(X[i].first-X[i+1].first);
        int st2=Y[i].second;
        int ed2=Y[i+1].second;
        int cost2=abs(Y[i].first-Y[i+1].first);
        int st3=Z[i].second;
        int ed3=Z[i+1].second;
        int cost3=abs(Z[i].first-Z[i+1].first);
        
        line.push_back({cost1,{st1,ed1}});
        line.push_back({cost2,{st2,ed2}});
        line.push_back({cost3,{st3,ed3}});
    }
    sort(line.begin(),line.end());
    
    for(int i=0;i<line.size();i++){
        int st=line[i].second.first;
        int ed=line[i].second.second;
        int cost=line[i].first;
        
        if(find_p(st)==find_p(ed))continue;
        
        res+=cost;
        union_p(st,ed);
        cnt++;
        if(cnt==n-1)break;
    }
    cout<<res;
}
