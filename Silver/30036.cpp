#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int I,n,k;
int x,y,cnt=1,val=0;
string ink,ord;
char board[101][101];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>I>>n>>k;
    cin>>ink;
    ink=ink[I-1]+ink;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]=='@'){
                x=i;
                y=j;
            }
        }
    }
    cin>>ord;
    
    for(int i=0;i<k;i++){
        int nx=x,ny=y;
        
        if(ord[i]=='J'){
            for(int j=val*-1;j<=val;j++){
                for(int l=val*-1;l<=val;l++){
                    
                    if(abs(j)+abs(l)<=val){
                        nx=x+j;
                        ny=y+l;
                        
                        if(nx<0||ny<0||nx>=n||ny>=n)continue;
                        if(board[nx][ny]=='.'||board[nx][ny]=='@')continue;
                            
                        board[nx][ny]=ink[cnt];
                    }
                }
            }
            val=0;
            cnt=(cnt+1)%I;
        }
        else if(ord[i]=='j'){
            val++;
        }
        else{
            if(ord[i]=='U'){
                nx--;
            }
            else if(ord[i]=='D'){
                nx++;
            }
            else if(ord[i]=='R'){
                ny++;
            }
            else if(ord[i]=='L'){
                ny--;
            }
            if(nx<0||ny<0||nx>=n||ny>=n)continue;
            
            if(board[nx][ny]=='.'){
                board[x][y]='.';
                board[nx][ny]='@';
                x=nx;
                y=ny;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}
