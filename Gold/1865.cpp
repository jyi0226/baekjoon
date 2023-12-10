#include <iostream>
#include <vector>
using namespace std;
int dist[505];
int INF=999999999;
vector<pair<int,pair<int,int>>> v;
int tc,n,m,w,a,b,c;
void Bellman_Ford(int n){
    for(int i=1;i<=n;i++)dist[i]=INF;

    for(int i=0;i<n;i++){
        for(int j=0;j<v.size();j++){
            int st=v[j].second.first;
            int ed=v[j].second.second;
            int cost=v[j].first;
            
            if(dist[ed]>dist[st]+cost)dist[ed]=dist[st]+cost;
        }
    }
    
    for(int i=0;i<v.size();i++){
        int st=v[i].second.first;
        int ed=v[i].second.second;
        int cost=v[i].first;
        
        if(dist[ed]>dist[st]+cost){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>tc;
    for(int i=0;i<tc;i++){
        v.clear();
        cin>>n>>m>>w;
        for(int j=0;j<m;j++){
            cin>>a>>b>>c;
            v.push_back({c,{a,b}});
            v.push_back({c,{b,a}});
        }
        for(int j=0;j<w;j++){
            cin>>a>>b>>c;
            v.push_back({-c,{a,b}});
        }
        Bellman_Ford(n);
    }
}
