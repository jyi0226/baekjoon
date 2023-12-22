#include <iostream>

using namespace std;
int dp[22][22][22];

int func(int a,int b,int c){
    if(a<=0||b<=0||c<=0)return 1;
    
    if(a>20||b>20||c>20)return func(20,20,20);
    
    if(dp[a][b][c])return dp[a][b][c];
    
    if(a<b&&b<c){
        dp[a][b][c]=func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c);
        return dp[a][b][c];
    }
    
    dp[a][b][c]=func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1);
    return dp[a][b][c];
}

int main()
{
    
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)break;
        else cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<func(a,b,c)<<"\n";
    }
}
