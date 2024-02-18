#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int t,n,num[101];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>t;
    while(t--){
        long long cnt=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>num[i];
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                cnt+=gcd(num[i],num[j]);
            }
        }
        cout<<cnt<<"\n";
    }
}
