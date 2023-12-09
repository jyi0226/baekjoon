#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,a,b,c;
vector<pair<int,int>> line[10101];
int Max_node=0,Max=0;
bool vis[10101]={};
void tree(int cur,int dis){
    for(int i=0;i<line[cur].size();i++){
        int next=line[cur][i].first;
        int ndis=line[cur][i].second;
        if(!vis[next]){
            vis[next]=1;
            tree(next,dis+ndis);
            vis[next]=0;
        }
    }
    if(Max<dis){
        Max_node=cur;
        Max=dis;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        line[a].push_back({b,c});
        line[b].push_back({a,c});
    }
    vis[1]=1;
    tree(1,0);
    for(int i=1;i<=n;i++)vis[i]=0;
    vis[Max_node]=1;
    tree(Max_node,0);
    cout<<Max;
}
