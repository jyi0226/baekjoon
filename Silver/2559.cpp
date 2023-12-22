#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,a,b;
int num;
int sum[101010];
int res=-10000000;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num;
        if(i>1){
            sum[i]=sum[i-1]+num;
        }
        else sum[i]=num;
    }
    for(int i=0;i+m<=n;i++){
        res=max(sum[i+m]-sum[i],res);
    }
    cout<<res;
}
