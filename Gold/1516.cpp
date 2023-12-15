#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,X,Y;
int degree[505];
vector<int> graph[505];
int t[505];
int dp[505];
queue<int> q;

void topology_sort(){
	for(int i=1;i<=n;i++){
		if(degree[i]==0){
		    q.push(i);
	    }
	}
    for(int i=0;i<n;i++){
    	int cur=q.front();
    	q.pop();
    	for(int j=0;j<graph[cur].size();j++){
    		int next=graph[cur][j];
    		degree[next]--;
    		dp[next]=max(dp[next],dp[cur]+t[next]);
    		if(degree[next]==0)q.push(next);
    	}
    }
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(NULL);  
    cout.tie(NULL);
	
    cin>>n;
    
    for(int i=1;i<=n;i++){
        degree[i]=0;
        cin>>X>>Y;
        t[i]=X;
        dp[i]=X;
        while(Y!=-1){
            graph[Y].push_back(i);
            degree[i]++;
            cin>>Y;
        }
    }
    topology_sort();
    for(int i=1;i<=n;i++)cout<<dp[i]<<"\n";
}
