#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int Max_model,Max_value=0;
int board[20][101];
int ans[101];
int cur_zero[101];
int cur_one[101];
bool res=0;
bool use[20];
vector<pair<int,int>> v;

void func(int cur,int mod){
    //if(res)return;
    if(cur>n){
        if(mod%2==0)return;
        for(int i=0;i<m;i++){
            cur_zero[i]=0;
            cur_one[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(use[i]){
                //cout<<i<<" ";
                for(int j=0;j<m;j++){
                    if(board[i][j]==0)cur_zero[j]++;
                    else cur_one[j]++;
                }
            }
        }
        int cnt=0;
        for(int j=0;j<m;j++){
            
            if(cur_one[j]>cur_zero[j]){
                if(1==ans[j])cnt++;
            }
            else{
                if(0==ans[j])cnt++;
            }
        }
        //cout<<cnt<<"\n";
        if(cnt>Max_value)res=1;
        return;
    }
    use[cur]=1;
    func(cur+1,mod+1);
    use[cur]=0;
    func(cur+1,mod);
    
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    v.push_back({0,0});
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>ans[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++)cin>>board[i][j];
    }    
    Max_value=0;        
    Max_model=1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(ans[j]==board[i][j])cnt++;
        }
        if(cnt>Max_value){
            Max_value=cnt;
            Max_model=i;
        }
    }

    func(1,0);
    //cout<<Max_model<<" "<<Max_value<<"\n";
    if(res)cout<<1;
    else cout<<0;
}
