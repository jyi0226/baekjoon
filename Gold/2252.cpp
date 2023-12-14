#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,X,Y;
int degree[32323];
vector<int> graph[32323];
queue<int> q;

void topology_sort(){
	for(int i=1;i<=n;i++){
		if(degree[i]==0){
		    q.push(i);
	    }
	}
    for(int i=0;i<n;i++){
    	int cur=q.front();
    	cout<<cur<<" ";
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
        cin>>X>>Y;
        graph[X].push_back(Y);
        degree[Y]++;
    }
    topology_sort();
}
