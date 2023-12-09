#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,a,b,c,st,ed;
int dist[20202];
vector<pair<int,int>> vec[20202];
int INF=999999999;

void Dijkstra_Using_Heap(){
	priority_queue<pair<int,int>> pq;
	for(int i=1;i<=n;i++)dist[i]=INF;
	pq.push({0,st});
    dist[st]=0;
    while(!pq.empty()){
    	int cost=-pq.top().first;
    	int cur=pq.top().second;
    	pq.pop();
        if(dist[cur]<cost)continue;
        
    	for(int i=0;i<vec[cur].size();i++){
    	    int next=vec[cur][i].first;
    	    int ncost=vec[cur][i].second;
    	    
    	    if(dist[next]>cost+ncost){
    	        dist[next]=cost+ncost;
    	        pq.push({-dist[next],next});
    	    }
    	}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    cin>>st>>ed;
    Dijkstra_Using_Heap();
    
    cout<<dist[ed];
}
