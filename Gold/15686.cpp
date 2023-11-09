#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int board[55][55];
int n,m,chi_cnt=0;
vector<pair<int,int>> house,chi;
int res=101010101;

void func(int cur,int cnt){
    if(cnt==chi_cnt-m){
        int sum=0;
        for(int i=0;i<house.size();i++){
            int val=101010101;
        
            for(int j=0;j<chi.size();j++){
                if(chi[j].first==-1&&chi[j].second==-1)continue;
                else val=min({abs(chi[j].first-house[i].first)+abs(chi[j].second-house[i].second),val});
            }
            sum+=val;
        }
        res=min({res,sum});    
    }
    
    for(int i=cur;i<chi_cnt;i++){
        if(chi[i].first!=-1&&chi[i].second!=-1){
            int chi_x=chi[i].first,chi_y=chi[i].second;
            chi[i].first=-1;
            chi[i].second=-1;
            func(i,cnt+1);
            chi[i].first=chi_x;
            chi[i].second=chi_y;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                chi.push_back({i,j});
                chi_cnt++;
            }
            if(board[i][j]==1)house.push_back({i,j});
        }
    }
    func(0,0);
    cout<<res;
}
