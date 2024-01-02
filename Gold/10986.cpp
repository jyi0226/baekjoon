#include <iostream>

using namespace std;
int n,m;
long long sum[1010101];
long long divnum[1010];
int num;
long long cnt;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num;
        sum[i]=num+sum[i-1];
        divnum[sum[i]%m]++;
    }
    cnt=divnum[0];
    for(int i=0;i<m;i++){
        if(divnum[i]>1){
            cnt+=(divnum[i]*(divnum[i]-1)/2);
        }
    }
    cout<<cnt;
}
