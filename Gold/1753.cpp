#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v,e,a,b,c,k;
int dist[20202];
vector<pair<int,int>> vec[20202];
int INF=999999999;

void Dijkstra_Using_Heap(){
	priority_queue<pair<int,int>> pq;
	pq.push({0,k});

    while(!pq.empty()){
    	int cost=-pq.top().first;
    	int cur=pq.top().second;
    	pq.pop();
    
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
    
    cin>>v>>e>>k;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    for(int i=1;i<=v;i++)dist[i]=INF;
    Dijkstra_Using_Heap();
    for(int i=1;i<=v;i++){
        if(i==k){
            cout<<"0\n";
            continue;
        }
        if(dist[i]==INF)cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
}
