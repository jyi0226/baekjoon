#include <iostream>
#include <algorithm>
using namespace std;
int n,res=0;
int building[55],cnt[55];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>building[i];
    for(int i=0;i<n-1;i++){
        long double Max=-1000000000;
        
        for(int j=i+1;j<n;j++){
            long double y=building[j]-building[i];
            long double x=j-i;
            long double m=y/x;
            
            if(Max>=m)continue;
            
            Max=m;
            cnt[i]++;
            cnt[j]++;
        }
    }
    sort(cnt,cnt+n);
    cout<<cnt[n-1];
}
