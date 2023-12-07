#include <iostream>

using namespace std;
int r,c,res=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char board[22][22];
bool alp[26]={};
char word;

void func(int x,int y,int num){
    
    res=max(res,num);
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=r||ny>=c)continue;

        if(!alp[board[nx][ny]-'A']){
            alp[board[nx][ny]-'A']=1;
            func(nx,ny,num+1);
            alp[board[nx][ny]-'A']=0;
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)cin>>board[i][j];
    }
    alp[board[0][0]-'A']=1;
    func(0,0,1);
    cout<<res;
}
