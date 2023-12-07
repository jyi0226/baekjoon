#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v,e,a,b,c;
int p[10101];
vector<pair<int,pair<int,int>>> line;

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
    
    cin>>v>>e;
    for(int i=1;i<=v;i++)p[i]=i;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        line.push_back({c,{a,b}});
    }
    
    sort(line.begin(),line.end());
    int a,b,res=0,cnt=0;
    for(int i=0;i<line.size();i++){
        a=line[i].second.first;
        b=line[i].second.second;
        
        if(find_p(a)==find_p(b))continue;
        
        res+=line[i].first;
        union_p(a,b);
        cnt++;
        
        if(cnt==v-1)break;
    }
    cout<<res;
}
