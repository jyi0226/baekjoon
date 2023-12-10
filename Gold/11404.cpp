#include <iostream>
#include <vector>
using namespace std;
int INF=999999999;
int n,m,a,b,c;
int dist[101][101]={};

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
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    Floyd_Warshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF)cout<<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}
