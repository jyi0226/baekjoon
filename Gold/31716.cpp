#include <iostream>
#include <vector>
using namespace std;

char board[2][101010];
long long n,k,cnt=0,ans;
vector<int> v;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cin>>board[i][j];
    }
    for(int i=0;i<n-1;i++){
        if(board[0][i]=='#'&&board[1][i+1]=='#'){
            cout<<-1;
            return 0;
        }
    }
    for(int i=0;i<n-1;i++){
        if(board[1][i]=='#'&&board[0][i+1]=='#'){
            cout<<-1;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(board[1][i]=='#'&&board[0][i]=='#'){
            cout<<-1;
            return 0;
        }
    }
    if(k>1&&((board[0][0]=='#'&&board[1][n-1]=='#')||(board[1][0]=='#'&&board[0][n-1]=='#'))){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(board[0][i]=='#')v.push_back(0);
        if(board[1][i]=='#')v.push_back(1);
    }
    if(v.size()<=1){
        cout<<n*k-1;
        return 0;
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i]!=v[i+1])cnt++;
    }
    ans=n*k-1+cnt*k;
    //cout<<ans<<"\n";
    if(v.size()!=0&&v[v.size()-1]!=v[0])ans+=k-1;
    cout<<ans;
}
