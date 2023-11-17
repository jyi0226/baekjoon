#include <iostream>

using namespace std;
int board[11][11];
int c,sum=0,res=0;
bool visited[11];
void func(int cur){
    if(cur==11){
        if(res<sum)res=sum;
        return;
        //cout<<"!\n";
    }
    else if(cur<11){
        for(int i=0;i<11;i++){
            if(!visited[i]&&board[cur][i]!=0){
                visited[i]=true;
                sum+=board[cur][i];
                func(cur+1);
                sum-=board[cur][i];
                visited[i]=false;
            }
        }  
    }
    return;
}
int main()
{
    cin>>c;
    for(int t=0;t<c;t++){
        sum=0;
        res=0;
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++)cin>>board[i][j];
        }
        func(0);
        cout<<res<<"\n";
    }
    
}
