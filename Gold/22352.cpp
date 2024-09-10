#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board1[33][33],board2[33][33];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool vis1[33][33],vis2[33][33];
int n,m;
int cnt1=0,cnt2=0;
int val=0;
queue<pair<int,int>> q1,q2;
int a[999],b[999];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis1[i][j]){
                vis1[i][j]=1;
                if(board1[i][j]!=board2[i][j])val++;
                
                q1.push({i,j});
                while(!q1.empty()){
                    int cx=q1.front().first;
                    int cy=q1.front().second;
                    q1.pop();
                    
                    for(int k=0;k<4;k++){
                        int nx=cx+dx[k];
                        int ny=cy+dy[k];
                        
                        if(nx<0||ny<0||nx>=n||ny>=m)continue;
                        
                        if(!vis1[nx][ny]&&board1[nx][ny]==board1[cx][cy]){
                            if(board2[nx][ny]!=board2[cx][cy]){
                                cout<<"NO";
                                return 0;
                            }
                            vis1[nx][ny]=1;
                            q1.push({nx,ny});
                        }
                    }
                }
            }
        } 
    }
    if(val>1)cout<<"NO";
    else cout<<"YES";
}
