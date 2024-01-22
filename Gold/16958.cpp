#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int INF=999999999;
int n,t,m,b,c;
bool a;
int dist[1010][1010]={};
vector<pair<bool,pair<int,int>>> v;
void Floyd_Warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    v.push_back({0,{0,0}});
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        v.push_back({a,{b,c}});
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int len=abs(v[i].second.first-v[j].second.first)+abs(v[i].second.second-v[j].second.second);
            if(v[i].first&&v[j].first){
                dist[i][j]=min(t,len);
                dist[j][i]=min(t,len);
            }
            else{
                dist[i][j]=len;
                dist[j][i]=len;
            }
        }
    }
    Floyd_Warshall();
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b>>c;
        cout<<dist[b][c]<<"\n";
    }
    
}
