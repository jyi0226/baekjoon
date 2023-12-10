#include <iostream>
#include <vector>
using namespace std;
int INF=999999999;
int n,m,r,a,b,c;
int dist[101][101]={};
int item[101];
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
    
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++)cin>>item[i];
    for(int i=0;i<r;i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    Floyd_Warshall();
    int res=0;
    for(int i=1;i<=n;i++){
        int val=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]>m)continue;
            else val+=item[j];
        }
        res=max(res,val);
    }
    cout<<res;
}
