#include <iostream>
using namespace std;
char board[66][66];
int n;

void func(int x,int y,int size){
    if(board[x][y]=='1'){
        for(int i=x;i<x+size;i++){
            for(int j=y;j<y+size;j++){
                if(board[i][j]=='0'){
                    cout<<"(";
                    func(x,y,size/2);
                    func(x,y+size/2,size/2);
                    func(x+size/2,y,size/2);
                    func(x+size/2,y+size/2,size/2);
                    cout<<")";
                    return;
                }
            }
        }
        cout<<"1";
    }
    else{
        for(int i=x;i<x+size;i++){
            for(int j=y;j<y+size;j++){
                if(board[i][j]=='1'){
                    cout<<"(";
                    func(x,y,size/2);
                    func(x,y+size/2,size/2);
                    func(x+size/2,y,size/2);
                    func(x+size/2,y+size/2,size/2);
                    cout<<")";
                    return;
                }
            }
        }
        cout<<"0";
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>board[i][j];
    }
    func(1,1,n);
}
