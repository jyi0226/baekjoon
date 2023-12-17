#include <iostream>
#include <string>
using namespace std;
int n,sum=1;
string s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cin>>n;
        if(n==-1)break;
        else{
            cout<<n;
            sum=1;
            s="1";
            for(int i=2;i<n;i++){
                if(n%i==0){
                    sum+=i;
                    s+=" + "+to_string(i);
                }
                if(sum>n)break;
            }
            if(sum==n)cout<<" = "<<s<<"\n";
            else cout<<" is NOT perfect.\n";
            
        }
    }
}
