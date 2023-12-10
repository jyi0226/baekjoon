#include <iostream>
#include <vector>
using namespace std;
long long dist[505];
int INF=999999999;
vector<pair<int,pair<int,int>>> v;
int tc,n,m,w,a,b,c;
int val;
void Bellman_Ford(){
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<v.size();j++){
            int st=v[j].second.first;
            int ed=v[j].second.second;
            int cost=v[j].first;
            
            if(dist[st]==INF)continue;
            if(dist[ed]>dist[st]+cost)dist[ed]=dist[st]+cost;
        }
    }
    
    for(int i=0;i<v.size();i++){
        int st=v[i].second.first;
        int ed=v[i].second.second;
        int cost=v[i].first;
        
        if(dist[st]==INF)continue;
        if(dist[ed]>dist[st]+cost){
            val=-1;
            return;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int j=0;j<m;j++){
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    Bellman_Ford();
    if(val==-1)cout<<-1;
    else{
        for(int i=2;i<=n;i++){
            if(dist[i]==INF)cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
    
}
