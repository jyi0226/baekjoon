#include <bits/stdc++.h>
using namespace std;
char board[1515][1515];
int p[3333333];
bool vis[1515][1515];
vector<pair<int,int>> swan;
queue<pair<int,int>> water;
int r,c,cnt=0;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int find_p(int x){
    if(p[x]!=x)p[x]=find_p(p[x]);
    return p[x];
}
void merge(int x,int y){
    x=find_p(x);
    y=find_p(y);

    if(x<y)p[y]=x;
    else p[x]=y;
}
int func(int x,int y){
    return x*c+y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>r>>c;

    for(int i=0;i<r*c;i++)p[i]=i;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]!='X'){
                vis[i][j]=1;
                water.push({i,j});
                if(board[i][j]=='L')swan.push_back({i,j});
            }
        }
    }

    while(!water.empty()){
        int size=water.size();
        //cout<<"size "<<size<<"\n";
        for(int i=0;i<size;i++){
            int cx=water.front().first;
            int cy=water.front().second;
            water.pop();
            int a=func(cx,cy);
            for(int j=0;j<4;j++){
                int nx=cx+dx[j];
                int ny=cy+dy[j];

                if(nx<0||ny<0||nx>=r||ny>=c)continue;
                if(vis[nx][ny]){
                    int b=func(nx,ny);
                    merge(a,b);
                }
            }
            water.push({cx,cy});
        }

        if(find_p(func(swan[0].first,swan[0].second))==find_p(func(swan[1].first,swan[1].second))){
            //cout<<"res: "<<cnt;
            cout<<cnt;
            break;
        }
        cnt++;

        for(int i=0;i<size;i++){
            int cx=water.front().first;
            int cy=water.front().second;
            water.pop();

            for(int j=0;j<4;j++){
                int nx=cx+dx[j];
                int ny=cy+dy[j];

                if(nx<0||ny<0||nx>=r||ny>=c)continue;
                if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    water.push({nx,ny});
                }
            }
        }
    }
}
