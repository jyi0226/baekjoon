#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int board[9][9];
bool isNum[9][10];
bool isNum2[9][10];
bool isNum3[3][3][10];
int val,x,y;
bool sta=0;
void func(){
    if(sta)return;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(!isNum[i][k]&&!isNum2[j][k]&&!isNum3[i/3][j/3][k]){
                        isNum[i][k]=1;
                        isNum2[j][k]=1;
                        isNum3[i/3][j/3][k]=1;
                        board[i][j]=k;
                        func();
                        if(sta)return;
                        isNum[i][k]=0;
                        isNum2[j][k]=0;
                        isNum3[i/3][j/3][k]=0;
                        board[i][j]=0;
                    }
                    if(k==9)return;
                }
            }
            if(sta)return;
            if(i==8&&j==8){
                for(int n=0;n<9;n++){
                    for(int m=0;m<9;m++){
                        cout<<board[n][m]<<" ";
                    }
                    cout<<"\n";
                }
                sta=1;
                return;
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
            val=board[i][j];
            if(val!=0){
                isNum[i][val]=1;
                isNum2[j][val]=1;
                isNum3[i/3][j/3][val]=1;
            }
        }
    }
    //cout<<"\n";
    func();
}
