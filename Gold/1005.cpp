#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T,n,k,X,Y,W;
int Time[1010];
int dp[1010];
int degree[1010];
vector<int> graph[1010];
queue<int> q;

void topology_sort(){
	for(int i=1;i<=n;i++){
		if(degree[i]==0){
		    dp[i]=Time[i];
		    q.push(i);
	    }
	}
    for(int i=0;i<n;i++){
    	int cur=q.front();
    	q.pop();
    	for(int j=0;j<graph[cur].size();j++){
    		int next=graph[cur][j];
    		degree[next]--;
    		dp[next]=max(dp[next],dp[cur]+Time[next]);
    		if(degree[next]==0)q.push(next);
    	}
    }
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(NULL);  
    cout.tie(NULL);
    
    cin>>T;
    while(T--){
        for(int i=1;i<=n;i++)graph[i].clear();
        
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>Time[i];
            degree[i]=0;
            dp[i]=0;
        }
        for(int i=0;i<k;i++){
            cin>>X>>Y;
            graph[X].push_back(Y);
            degree[Y]++;
        }
        cin>>W;
        topology_sort();
        cout<<dp[W]<<"\n";
    }
}
