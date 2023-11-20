#include <iostream>
#include <algorithm>
using namespace std;
int board[22][22][11]={};
int n,tot_res=2,a,b;
void update_board(int dir,int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)board[i][j][num+1]=board[i][j][num];
    }
    if(dir==0){
        for(int j=0;j<n;j++){
            for(int i=0;i<n-1;i++){
                for(int k=i+1;k<n;k++){
                    if(board[i][j][num+1]!=0&&board[k][j][num+1]!=0){
                        if(board[i][j][num+1]==board[k][j][num+1]){
                            board[i][j][num+1]*=2;
                            board[k][j][num+1]=0;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            int cnt=1;
            for(int i=0;i<n;i++){
                if(board[i][j][num+1]!=0)continue;
                else{
                    if(i+cnt>n-1)continue;
                    while(i+cnt<n-1&&board[i+cnt][j][num+1]==0)cnt++;
                    board[i][j][num+1]=board[i+cnt][j][num+1];
                    board[i+cnt][j][num+1]=0;
                }
            }
        }
    }
    else if(dir==1){
        for(int j=0;j<n;j++){
            for(int i=n-1;i>0;i--){
                for(int k=i-1;k>=0;k--){
                    if(board[i][j][num+1]!=0&&board[k][j][num+1]!=0){
                        if(board[i][j][num+1]==board[k][j][num+1]){
                           board[i][j][num+1]*=2;
                            board[k][j][num+1]=0;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            int cnt=1;
            for(int i=n-1;i>=0;i--){
                if(board[i][j][num+1]!=0)continue;
                else{
                    if(i-cnt<0)continue;
                    while(i-cnt>0&&board[i-cnt][j][num+1]==0)cnt++;
                    board[i][j][num+1]=board[i-cnt][j][num+1];
                    board[i-cnt][j][num+1]=0;
                }
            }
        }
    }
    else if(dir==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(board[i][j][num+1]!=0&&board[i][k][num+1]!=0){
                        if(board[i][j][num+1]==board[i][k][num+1]){
                            board[i][j][num+1]*=2;
                            board[i][k][num+1]=0;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if(board[i][j][num+1]!=0)continue;
                else{
                    if(j+cnt>n-1)continue;
                    while(j+cnt<n-1&&board[i][j+cnt][num+1]==0)cnt++;
                    board[i][j][num+1]=board[i][j+cnt][num+1];
                    board[i][j+cnt][num+1]=0;
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=n-1;j>0;j--){
                for(int k=j-1;k>=0;k--){
                    if(board[i][j][num+1]!=0&&board[i][k][num+1]!=0){
                        if(board[i][j][num+1]==board[i][k][num+1]){
                            board[i][j][num+1]*=2;
                            board[i][k][num+1]=0;  
                            break;
                        }
                        else break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=n-1;j>=0;j--){
                if(board[i][j][num+1]!=0)continue;
                else{
                    if(j-cnt<0)continue;
                    while(j-cnt>0&&board[i][j-cnt][num+1]==0)cnt++;
                    board[i][j][num+1]=board[i][j-cnt][num+1];
                    board[i][j-cnt][num+1]=0;
                }
            }
        }
    }
    /*
    4
    32 64 0 0
    4 128 256 0
    128 4 16 2
    4 128 32 32
    답은 256인데 512 출력
    */
}
void reset(int cur){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j][cur]=0;
        }
    }
}

void func(int cur){
    if(cur==10){
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res<board[i][j][cur])res=board[i][j][cur];
            }
        }
        if(tot_res<res)tot_res=res;
        return;
    }
    for(int i=0;i<4;i++){
        update_board(i,cur);
        func(cur+1);
        reset(cur+1);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>board[i][j][0];
    }
    

    
    /*for(int k=0;k<4;k++){
        cout<<"\n";
        update_board(k,k);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<board[i][j][k+1]<<" ";
            cout<<"\n";
        } 
    }
    cout<<"\n";
    update_board(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<board[i][j][1]<<" ";
        cout<<"\n";
    }*/
    
    
    func(0);
    cout<<tot_res;
}
