#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int board[55][55];
int order[7][3];
int res=999999;
bool visited[7];
void turn(int r,int c,int s){
    int x1=r-s,y1=c-s,x2=r+s,y2=c+s;
    while(1){
        if(x1==x2&&y1==y2)break;
        int val=board[x2][y1];
        for(int i=y1;i<y2;i++)board[x2][i]=board[x2][i+1];
        for(int i=x2;i>x1;i--)board[i][y2]=board[i-1][y2];
        for(int i=y2;i>y1;i--)board[x1][i]=board[x1][i-1];
        for(int i=x1;i<x2-1;i++)board[i][y1]=board[i+1][y1];
        board[x2-1][y1]=val;
        x1++;
        y1++;
        x2--;
        y2--;
    }
}
void turn_back(int r,int c,int s){
    int x1=r-s,y1=c-s,x2=r+s,y2=c+s;
    while(1){
        if(x1==x2&&y1==y2)break;
        int val=board[x2][y1];
        for(int i=x2;i>x1;i--)board[i][y1]=board[i-1][y1];
        for(int i=y1;i<y2;i++)board[x1][i]=board[x1][i+1];
        for(int i=x1;i<x2;i++)board[i][y2]=board[i+1][y2];
        for(int i=y2;i>y1+1;i--)board[x2][i]=board[x2][i-1];
        board[x2][y1+1]=val;
        x1++;
        y1++;
        x2--;
        y2--;
    }
}
void pri(){
    cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    
}
void func(int cur){
    if(cur==k){
        int Min=999999;
        for(int i=1;i<=n;i++){
            int val=0;
            for(int j=1;j<=m;j++){
                val+=board[i][j];
            }
            Min=min(val,Min);
        }
        res=min(Min,res);
    }
    for(int i=0;i<k;i++){
        if(!visited[i]){
            turn(order[i][0],order[i][1],order[i][2]);
            visited[i]=1;
            //pri();
            func(cur+1);
            turn_back(order[i][0],order[i][1],order[i][2]);
            visited[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>board[i][j];
    }
    for(int i=0;i<k;i++)cin>>order[i][0]>>order[i][1]>>order[i][2];
    func(0);
    cout<<res;
}
