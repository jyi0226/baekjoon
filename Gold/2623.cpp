#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,X,Y;
int degree[1010];
vector<int> graph[1010];
queue<int> stage;
queue<int> q;
void topology_sort(){
	for(int i=1;i<=n;i++){
		if(degree[i]==0){
		    q.push(i);
	    }
	}
    for(int i=0;i<n;i++){
    	if(q.empty()){
    	    return;
    	}
    	
    	int cur=q.front();
    	stage.push(cur);
    	q.pop();
    	
    	for(int j=0;j<graph[cur].size();j++){
    		int next=graph[cur][j];
    		degree[next]--;
    		if(degree[next]==0)q.push(next);
    	}
    }
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(NULL);  
    cout.tie(NULL);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        degree[i]=0;
    }
    
    for(int i=0;i<m;i++){
        cin>>X;

        for(int j=0;j<X;j++){
            cin>>Y;
            stage.push(Y);
        }
        while(!stage.empty()){
            int s=stage.front();
            stage.pop();
            if(stage.empty())break;
            int e=stage.front();
            graph[s].push_back(e);
            degree[e]++;
        }
    }
    topology_sort();
    if(stage.size()==n){
        while(!stage.empty()){
            cout<<stage.front()<<"\n";
            stage.pop();
        }
    }
    else cout<<0;
}
