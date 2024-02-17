#include <iostream>
#include <queue>
using namespace std;

int dir[2];

int ans[1010101];
bool vis[1010101];
int f,s,g,u,d;

void bfs(int s){
    queue<int> q;
    vis[s]=1;
    q.push(s);
    
    while(!q.empty()){
        int cs=q.front();
        q.pop();
        
        if(cs==g){
            cout<<ans[cs];
            return;
        }
        
        for(int i=0;i<2;i++){
            int ns=cs+dir[i];
            
            if(ns<=0||ns>f)continue;
            
            if(!vis[ns]){
                vis[ns]=1;
                q.push(ns);
                ans[ns]=ans[cs]+1;
            }
        }
    }
    cout<<"use the stairs";
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>f>>s>>g>>u>>d;
    dir[0]=u;
    dir[1]=-d;
    bfs(s);
}
