#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,X,Y,Z,res=0;
int degree[10101];
vector<int> graph[10101];
int t[10101];
int dp[10101];
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
        for(int j=0;j<Y;j++){
            cin>>Z;
            graph[Z].push_back(i);
            degree[i]++;
        }
    }
    topology_sort();
    for(int i=1;i<=n;i++)res=max(res,dp[i]);
    cout<<res;
}
