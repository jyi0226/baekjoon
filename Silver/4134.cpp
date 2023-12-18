#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long t,n,m,ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n==0||n==1||n==2){
            cout<<2<<"\n";
        }
        else{
            bool val=1;
            while(val){
                m=sqrt(n)+1;
                for(int i=2;i<=m;i++){
                    if(n%i==0){
                        n++;
                        break;
                    }
                    if(i==m){
                        val=0;
                    }
                }
            }
            cout<<n<<"\n";
        }
    }
    
}
