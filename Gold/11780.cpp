#include <iostream>
#include <vector>
using namespace std;
int INF=999999999;
int n,m,a,b,c;
int dist[101][101]={};
int route[101][101];
vector<int> v;

void Floyd_Warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    route[i][j]=k;
                }
            }
        }
    }
}
void find_route(int Start,int End){
    if(route[Start][End]==0){
        v.push_back(Start);
        v.push_back(End);
        return;
    }
    find_route(Start,route[Start][End]);
    v.pop_back();
    find_route(route[Start][End],End);
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
    cout<<"\n";
    Floyd_Warshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF)cout<<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||dist[i][j]==INF){
                cout<<0<<"\n";
                continue;
            }
            find_route(i,j);
            cout<<v.size()<<" ";
            for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
            v.clear();
            cout<<"\n";
        }
    }
}
