#include <iostream>
using namespace std;
int n,stu=0;
char board[10][10],board2[10][10];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

void teacher(int x,int y){
    for(int i=0;i<4;i++){
        int curX=x;
        int curY=y;
        while(1){
            curX+=dx[i];
            curY+=dy[i];
            if(curX<0||curX>=n||curY<0||curY>=n)break;
            if(board2[curX][curY]=='O')break;
            
            if(board2[curX][curY]==S||board2[curX][curY]=='X')board2[curX][curY]='t';
        }
    }
}

void sol(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)board2[i][j]=board[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board2[i][j]=='T'){
                teacher(i,j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board2[i][j]=='S')cnt++;
        }
    }
    if(cnt==stu)
    {
        cout<<"YES";
        exit(0);
    }
}

void wall(int cnt){
    if(cnt==3){
        sol();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='X'){
                board[i][j]='O';
                wall(cnt+1);
                board[i][j]='X';
            }
        }
    }
}



int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]=='S')stu++;
        }
    }
    wall(0);
    cout<<"NO";
}
