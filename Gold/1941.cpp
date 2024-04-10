#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> v;
char board[30][30];
bool vis[30][30];
bool check[30][30];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int res=0;
void func(int cur,int cnt){
    if(cnt==7){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                check[i][j]=0;
                vis[i][j]=0;
            }
        }
        int val=0;
        for(int i=0;i<7;i++){
            int X=v[i].first;
            int Y=v[i].second;
            
            check[X][Y]=1;
            if(board[X][Y]=='S')val++;
        }
        if(val>=4){
            int ct=1;
            vis[v[0].first][v[0].second]=1;
            queue<pair<int,int>> q;
            q.push({v[0].first,v[0].second});
            
            while(!q.empty()){
                int cx=q.front().first;
                int cy=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx=cx+dx[i];
                    int ny=cy+dy[i];
                    
                    if(nx<0||ny<0||nx>=5||ny>=5)continue;
                    
                    if(!vis[nx][ny]&&check[nx][ny]){
                        vis[nx][ny]=1;
                        ct++;
                        q.push({nx,ny});
                    }
                }
            }
            if(ct==7)res++;
            else return;
        }
        else return;
        
        return;
    }
    for(int i=cur;i<25;i++){
        v.push_back({i/5,i%5});
        func(i+1,cnt+1);
        v.pop_back();
    }
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>board[i][j];
        }
    }
    func(0,0);
    cout<<res;
}
