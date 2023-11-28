#include <iostream>
#include <queue>
using namespace std;
int n,l,r;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int board[55][55];
int sum=0;
bool visit[55][55];
queue<pair<int,int>> group,q;

void clear_vis(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)visit[i][j]=0;
    }
}
void clear_group(){
    while(!group.empty())group.pop();
}
void bfs(int i,int j){
    visit[i][j]=1;
    q.push({i,j});
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        
        q.pop();
        for(int k=0;k<4;k++){
            int nx = cx + dx[k];
			int ny = cy + dy[k];
			if(nx<0||ny<0||nx>=n||ny>=n)continue;
			if(!visit[nx][ny]){
			    if(abs(board[cx][cy]-board[nx][ny])>=l&&abs(board[cx][cy]-board[nx][ny])<=r){
			        q.push({nx,ny});
			        visit[nx][ny]=true;
			        sum+=board[nx][ny];
			        group.push({nx,ny});
			    }
			}
        }
    }
}

int main()
{
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>board[i][j];
    }
    bool val=1;
    int t=0;
    clear_vis();
    while(val){
        val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visit[i][j]){
                    clear_group();
                    group.push({i,j});
                    sum=board[i][j];
                    bfs(i,j);
                }
                int size=group.size();
                //cout<<size<<"\n";
                if(size>=2){
                    val=1;
                    for(int k=0;k<size;k++){
                        board[group.front().first][group.front().second]=sum/size;
                        group.pop();
                    }
                }
            }
        }
        if(val)t++;
        
        clear_vis();
    }
    cout<<t;
}
